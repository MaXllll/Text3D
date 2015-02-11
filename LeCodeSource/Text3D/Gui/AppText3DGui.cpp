 /*   Copyright (c) YEAR YOUR NAME         <Your e-mail address>            *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"
#ifndef _PreComp_
# include <Python.h>
#endif

#include <Base/Console.h>
#include <Base/Interpreter.h>
#include <Gui/Application.h>
#include <Gui/WorkbenchManager.h>
#include <Gui/Language/Translator.h>

#include "Workbench.h"

#include <Mod/Text3D/App/CompleteConfiguration.h>

// use a different name to CreateCommand()
void CreateVaseCommands(void);


/* registration table  */
extern struct PyMethodDef Text3DGui_methods[];

PyDoc_STRVAR(module_Text3DGui_doc,
"This module is the Text3DGui module.");


/* Python entry */
extern "C" {
void Text3DGuiExport initText3DGui()
{
    if (!Gui::Application::Instance) {
        PyErr_SetString(PyExc_ImportError, "Cannot load Gui module in console application.");
        return;
    }

	  CreateVaseCommands();
   

    try {

        //Import Part workbench
        Base::Interpreter().loadModule("PartGui");
        Base::Interpreter().loadModule("PartDesignGui");

#       ifdef COMPLETE_USE_DRAFTING
        Py::Module module(PyImport_ImportModule("FreeCADGui"),true);
        Py::Callable method(module.getAttr(std::string("getWorkbench")));

        //Import Draft workbench
        Py::Tuple args(1);
        args.setItem(0,Py::String("DraftWorkbench"));
        Py::Object handler(method.apply(args));

        std::string type;
        if (!handler.hasAttr(std::string("__Workbench__"))) {
            // call its GetClassName method if possible
            Py::Callable method(handler.getAttr(std::string("GetClassName")));
            Py::Tuple args;
            Py::String result(method.apply(args));
            type = result.as_std_string();
            if (type == "Gui::PythonWorkbench") {
                Gui::Workbench* wb = Gui::WorkbenchManager::instance()->createWorkbench("DraftWorkbench", type);
                handler.setAttr(std::string("__Workbench__"), Py::Object(wb->getPyObject(), true));
            }

            // import the matching module first
            Py::Callable activate(handler.getAttr(std::string("Initialize")));
            activate.apply(args);
        }

        // Get the CompleteWorkbench handler
        args.setItem(0,Py::String("CompleteWorkbench"));
#       endif    
    }
    catch(const Base::Exception& e) {
        PyErr_SetString(PyExc_ImportError, e.what());
        return;
    }
    catch (Py::Exception& e) {
        Py::Object o = Py::type(e);
        if (o.isString()) {
            Py::String s(o);
            Base::Console().Error("%s\n", s.as_std_string().c_str());
        }
        else {
            Py::String s(o.repr());
            Base::Console().Error("%s\n", s.as_std_string().c_str());
        }
        // Prints message to console window if we are in interactive mode
        PyErr_Print();
    }

    // instanciating the commands
   Text3DGui::Workbench::init();

    (void) Py_InitModule3("Text3DGui", Text3DGui_methods, module_Text3DGui_doc);   /* mod name, table ptr */
    Base::Console().Log("Loading GUI of Text3D module... done\n");
}

} // extern "C"
