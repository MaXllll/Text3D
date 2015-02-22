/*

# settings


# variables


	

doc.recompute()*/


#include "PreCompiled.h"
#ifndef _PreComp_
#endif

#include <Base/Console.h>
#include <App/Document.h>
#include <Gui/Application.h>
#include <Gui/Command.h>
#include <Gui/BitmapFactory.h>
#include <Gui/MainWindow.h>
#include <Base/Interpreter.h>

#include <Base/PyObjectBase.h>
#include <Base/Interpreter.h>
#include <Base/Exception.h>
#include <Base/FileInfo.h>
#include <Base/GeometryPyCXX.h>
#include <Base/VectorPy.h>
#include <App/Application.h>
#include <App/DocumentObjectPy.h>

#include <math.h>
#include <iostream>
#include <string>
#include <sstream>

//#include <../../Part/App/TopoDS_Compound.hxx>

/*#include "../../Part/App/FT2FC.h"
//#include "../../Part/App/PartFeature.h"
#include "../../Part/App/TopoShape.h"/*
#include "../../Part/App/TopoShapePy.h"
#include "../../Part/App/opoShapeEdgePy.h"
#include "../../	Part/App/TopoShapeWirePy.h"*/

//#include <Part/partfeatures.h>
//#include <Part/Tools.h>


//using namespace Part;
//===========================================================================
// Part_Extrude
//===========================================================================
DEF_STD_CMD_A(Vase);

Vase::Vase()
	:Command("Vase")
{
    sAppModule    = "Vase";
    sGroup        = QT_TR_NOOP("Vase");
    sMenuText     = QT_TR_NOOP("Vase");
    sToolTipText  = QT_TR_NOOP("Vase");
    sWhatsThis    = QT_TR_NOOP("Vase");
    sStatusTip    = QT_TR_NOOP("Vase");
    sPixmap       = "Vase";
    sAccel        = "CTRL+H";
}

bool Vase::isActive(void)
{
	return true;
}

void Vase::activated(int iMsg)
{
	
	//Base::Console().Message("Edit an image !/n");
}

DEF_STD_CMD_A(CmdVaseCreate);

CmdVaseCreate::CmdVaseCreate()
:Command("Vase_Create")
{
	 sAppModule    = "Vase_Create";
    sGroup        = QT_TR_NOOP("Vase_Create");
    sMenuText     = QT_TR_NOOP("Vase_Create");
    sToolTipText  = QT_TR_NOOP("Vase_Create");
    sWhatsThis    = QT_TR_NOOP("Vase_Create");
    sStatusTip    = QT_TR_NOOP("Vase_Create");
    sPixmap       = "Vase_Create";
    sAccel        = "CTRL+2";
}

void CmdVaseCreate::activated(int iMsg)
{

   /* Base::Console().Message("BLLAAAAAAA2");


    Py_UNICODE *unichars;
	Py_ssize_t pysize;
	const char* fontspec;
	double height;
	double track;

	unichars = new Py_UNICODE('A') ;
	pysize = 1;
	fontspec = "/Library/Fonts/Futura.ttc";
	height = 5;
	track = 0;

	PyObject* WireList = Part::FT2FC(unichars,pysize,fontspec,height,track);*/

	//PyObject* circle = Part::TopoShape::();//Circle((0,0,0),Normal,Radius;
	//PyObject* Cylinde = Part::CylinderPy();
	//Cylinde = Part::Cy
	

    
	Gui::Command::doCommand(Gui::Command::Doc, "import FreeCAD");
	Gui::Command::doCommand(Gui::Command::Doc, "import FreeCADGui");
	Gui::Command::doCommand(Gui::Command::Doc, "from FreeCAD import Base, Vector, Draft");
	Gui::Command::doCommand(Gui::Command::Doc, "import math");

	std::string str = "J'aime le foie gras du terrroir";
    //std::string font = "C:/ThisDossier/arial.ttf";
	Gui::Command::doCommand(Gui::Command::Doc, "path = FreeCAD.ConfigGet(\"AppHomePath\")");
	Gui::Command::doCommand(Gui::Command::Doc, "path+= \"Mod/Text3D/fonts/arial.ttf\"");
	//std::string font = "/Library/Fonts/Futura.ttc";
	//Base::Console().Message(font);
    
	Gui::Command::doCommand(Gui::Command::Doc, "radius = 6");
	Gui::Command::doCommand(Gui::Command::Doc, "fontSize = 5");
	Gui::Command::doCommand(Gui::Command::Doc, "thickness = 1");

	float fontSize = 5;
	float thickness = 1;


	Gui::Command::doCommand(Gui::Command::Doc, "currentAngle = 0");
	Gui::Command::doCommand(Gui::Command::Doc, "lastLetterWidth = 0");
	Gui::Command::doCommand(Gui::Command::Doc, "zAxisPush = 0");
	
	std::string letter;

	std::string command;
	std::stringstream out;
	out << fontSize;
	std::stringstream out2;
	out2 << thickness;

	

	for(unsigned int i = 0; i < str.length();++i)
	{
		letter = str[i];
		if (!letter.compare(" "))
		{
			command = "spaceWidth = 2";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "squareRadius = radius * radius";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
			command = "opposedSide = (lastLetterWidth * 0.5) + (spaceWidth * 0.5)";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "stepAngle = math.degrees(math.acos((2 * squareRadius - (opposedSide * opposedSide)) / (2 * squareRadius)))";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
			

			command = "currentAngle = stepAngle + currentAngle";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "lastLetterWidth = spaceWidth";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
			command = "zAxisPush += 0.05";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
		} else {
			command = "objectLetter = Draft.makeShapeString(\""+letter+"\", path, Size="+out.str()+",Tracking=0)";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "objectLetter = Draft.extrude( objectLetter, Base.Vector(0,0,"+out2.str()+"))" ;
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "boundingBox = objectLetter.Shape.BoundBox";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "squareRadius = radius * radius";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "opposedSide = (lastLetterWidth * 0.5) + (boundingBox.XLength * 0.5) + 0.1";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "stepAngle = math.degrees(math.acos((2 * squareRadius - (opposedSide * opposedSide)) / (2 * squareRadius)))";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "currentAngle += stepAngle";		
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "lastLetterWidth = boundingBox.XLength";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "offset = Vector(-boundingBox.XLength * 0.5, 0, 0)";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "Draft.move(objectLetter, offset, copy=False)";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
			
			command = "Draft.rotate(objectLetter, 90, Base.Vector(0,0,0), Base.Vector(1,0,0))";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
			command = "Draft.rotate(objectLetter, currentAngle, Base.Vector(0,0,0), Base.Vector(0,0,1))";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
			

			command = "position = Vector(math.sin(math.radians(currentAngle)), -math.cos(math.radians(currentAngle)), -zAxisPush)";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
			command = "position *= radius";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
			command = "Draft.move(objectLetter, position, copy=False)";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

			command = "zAxisPush += 0.05";
			Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
		}
	}
	
	command = "App.ActiveDocument.addObject(\"Part::Cylinder\",\"Cylinder\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.ActiveDocument.ActiveObject.Label = \"Cylinder\"";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder\").Radius = '6 mm'";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder\").Placement = App.Placement(App.Vector(0,0,-10),App.Rotation(App.Vector(0,0,1),0))";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder\").Height = '15 mm'";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "App.ActiveDocument.addObject(\"Part::Cylinder\",\"Cylinder2\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.ActiveDocument.ActiveObject.Label = \"Cylinder2\"";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder2\").Radius = '7 mm'";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder2\").Placement = App.Placement(App.Vector(0,0,-10),App.Rotation(App.Vector(0,0,1),0))";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder2\").Height = '15 mm'";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "App.activeDocument().addObject(\"Part::Cut\",\"Cut\")";
		Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.activeDocument().Cut.Base = App.activeDocument().Cylinder2";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.activeDocument().Cut.Tool = App.activeDocument().Cylinder";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "Gui.activeDocument().hide('Cylinder')";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().hide('Cylinder2')";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "Gui.ActiveDocument.Cut.ShapeColor=Gui.ActiveDocument.Cylinder.ShapeColor";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Cut.DisplayMode=Gui.ActiveDocument.Cylinder.DisplayMode";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "App.activeDocument().addObject(\"Part::MultiFuse\",\"Fusion\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.activeDocument().Fusion.Shapes = [App.activeDocument().Extrusion024,App.activeDocument().Extrusion001,App.activeDocument().Extrusion,App.activeDocument().Extrusion002,App.activeDocument().Extrusion003,App.activeDocument().Extrusion005,App.activeDocument().Extrusion007,App.activeDocument().Extrusion006,App.activeDocument().Extrusion004,App.activeDocument().Extrusion012,App.activeDocument().Extrusion011,App.activeDocument().Extrusion015,App.activeDocument().Extrusion014,App.activeDocument().Extrusion013,App.activeDocument().Extrusion010,App.activeDocument().Extrusion008,App.activeDocument().Extrusion009,App.activeDocument().Extrusion017,App.activeDocument().Extrusion019,App.activeDocument().Extrusion023,App.activeDocument().Extrusion016,App.activeDocument().Extrusion021,App.activeDocument().Extrusion018,App.activeDocument().Extrusion020,App.activeDocument().Extrusion022,]";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "Gui.activeDocument().Extrusion024.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion001.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion002.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion003.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion005.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion007.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion006.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion004.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion012.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion011.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion015.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion014.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion013.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion010.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion008.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion009.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion017.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion019.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion023.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion016.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion021.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion018.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion020.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion022.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Fusion.ShapeColor=Gui.ActiveDocument.Extrusion024.ShapeColor";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Fusion.DisplayMode=Gui.ActiveDocument.Extrusion024.DisplayMode";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "App.activeDocument().addObject(\"Part::MultiCommon\",\"Common\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.activeDocument().Common.Shapes = [App.activeDocument().Fusion,App.activeDocument().Cut,]";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Fusion.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Cut.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Common.ShapeColor=Gui.ActiveDocument.Fusion.ShapeColor";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Common.DisplayMode=Gui.ActiveDocument.Fusion.DisplayMode";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());


	Gui::Command::doCommand(Command::Doc,"App.activeDocument().recompute()" );


	/*command = "App.ActiveDocument.addObject(\"Part::Cylinder\",\"Cylinder\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.ActiveDocument.ActiveObject.Label = \"Cylinder\"";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder\").Radius = '6 mm'";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder\").Placement = App.Placement(App.Vector(0,0,-10),App.Rotation(App.Vector(0,0,1),0))";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder\").Height = '15 mm'";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "App.ActiveDocument.addObject(\"Part::Cylinder\",\"Cylinder2\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.ActiveDocument.ActiveObject.Label = \"Cylinder2\"";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder2\").Radius = '6 mm'";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder2\").Placement = App.Placement(App.Vector(0,0,-10),App.Rotation(App.Vector(0,0,1),0))";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "FreeCAD.getDocument(\"Unnamed\").getObject(\"Cylinder2\").Height = '15 mm'";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "App.activeDocument().addObject(\"Part::Cut\",\"Cut\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.activeDocument().Cut.Base = App.activeDocument().Cylinder";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.activeDocument().Cut.Tool = App.activeDocument().Cylinder2";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "Gui.activeDocument().hide('Cylinder')";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().hide('Cylinder2')";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "Gui.ActiveDocument.Cut.ShapeColor=Gui.ActiveDocument.Cylinder.ShapeColor";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Cut.DisplayMode=Gui.ActiveDocument.Cylinder.DisplayMode";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "App.activeDocument().addObject(\"Part::MultiFuse\",\"Fusion\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.activeDocument().Fusion.Shapes = [App.activeDocument().Extrusion024,App.activeDocument().Extrusion001,App.activeDocument().Extrusion,App.activeDocument().Extrusion002,App.activeDocument().Extrusion003,App.activeDocument().Extrusion005,App.activeDocument().Extrusion007,App.activeDocument().Extrusion006,App.activeDocument().Extrusion004,App.activeDocument().Extrusion012,App.activeDocument().Extrusion011,App.activeDocument().Extrusion015,App.activeDocument().Extrusion014,App.activeDocument().Extrusion013,App.activeDocument().Extrusion010,App.activeDocument().Extrusion008,App.activeDocument().Extrusion009,App.activeDocument().Extrusion017,App.activeDocument().Extrusion019,App.activeDocument().Extrusion023,App.activeDocument().Extrusion016,App.activeDocument().Extrusion021,App.activeDocument().Extrusion018,App.activeDocument().Extrusion020,App.activeDocument().Extrusion022,]";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "Gui.activeDocument().Extrusion024.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion001.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion002.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion003.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion005.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion007.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion006.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion004.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion012.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion011.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion015.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion014.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion013.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion010.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion008.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion009.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion017.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion019.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion023.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion016.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion021.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion018.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion020.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Extrusion022.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Fusion.ShapeColor=Gui.ActiveDocument.Extrusion024.ShapeColor";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Fusion.DisplayMode=Gui.ActiveDocument.Extrusion024.DisplayMode";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	command = "App.activeDocument().addObject(\"Part::MultiCommon\",\"Common\")";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "App.activeDocument().Common.Shapes = [App.activeDocument().Fusion,App.activeDocument().Cut,]";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Fusion.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.activeDocument().Cut.Visibility=False";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Common.ShapeColor=Gui.ActiveDocument.Fusion.ShapeColor";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());
	command = "Gui.ActiveDocument.Common.DisplayMode=Gui.ActiveDocument.Fusion.DisplayMode";
	Gui::Command::doCommand(Gui::Command::Doc, command.c_str());

	Gui::Command::doCommand(Command::Doc,"App.activeDocument().recompute()" );*/
}

bool CmdVaseCreate::isActive(void)
{
	return true;
}


void CreateVaseCommands(void)
{

	Gui::CommandManager &rcCmdMgr = Gui::Application::Instance->commandManager();
    rcCmdMgr.addCommand(new Vase());
	rcCmdMgr.addCommand(new CmdVaseCreate());
}

