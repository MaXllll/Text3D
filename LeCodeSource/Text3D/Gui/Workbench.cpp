/***************************************************************************
 *   Copyright (c) YEAR YOUR NAME         <Your e-mail address>            *
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
#endif

#include "Workbench.h"
#include <Gui/MenuManager.h>
#include <Gui/ToolBarManager.h>

using namespace Text3DGui;

/// @namespace Text3DGui @class Workbench
TYPESYSTEM_SOURCE(Text3DGui::Workbench, Gui::StdWorkbench)

Workbench::Workbench()
{
}

Workbench::~Workbench()
{
}

// Setup the buttons in the Menu bar above the screen
Gui::MenuItem* Workbench::setupMenuBar() const
{
    // Retrieve a reference to the MenuItem from StdWorkbench
    Gui::MenuItem* root = StdWorkbench::setupMenuBar();

    // Add butons to the MenuItem ref
    // Use the shapeString method from the Draft module to create a 2D text
    Gui::MenuItem* Drafting = new Gui::MenuItem(root);
    Drafting->setCommand("&Drafting");
    *Drafting << "Draft_ShapeString";
    
    // Use the Extrude method from Part module to create a 3D text from 2D text
    Gui::MenuItem* part = new Gui::MenuItem(root);
    part->setCommand("&Part");
    *part << "Part_Extrude";

    return root;
}

//Setup the buttons in the tool bar
Gui::ToolBarItem* Workbench::setupToolBars() const
{
    //Retrieve a reference to the ToolBarItem from StdWorkbench
    Gui::ToolBarItem* root = StdWorkbench::setupToolBars();

    // Add butons to the ToolBarItem ref
    // Use the shapeString method from the Draft module to create a 2D text
    Gui::ToolBarItem* Drafting = new Gui::ToolBarItem( root );
    Drafting->setCommand("Drafting");
    *Drafting << "Draft_ShapeString";
    
    // Use the Extrude method from Part module to create a 3D text from 2D text
    Gui::ToolBarItem* part_design = new Gui::ToolBarItem( root );
    part_design->setCommand("Part");
    *part_design << "Part_Extrude";

	Gui::ToolBarItem*  vase = new Gui::ToolBarItem( root );
    vase->setCommand("Vase");
    *vase << "Vase_Create";

    return root;
}
