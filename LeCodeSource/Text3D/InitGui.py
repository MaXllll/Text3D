# Text3D gui init module
# (c) 2001 Juergen Riegel LGPL

class Text3DWorkbench ( Workbench ):
	"Text3D workbench object"
	Icon = """
        /* XPM */
 			static const char *test_icon[]={
 			"16 16 2 1",
 			"a c #000000",
 			". c None",
 			"................",
 			"................",
 			"..############..",
 			"..############..",
 			"..############..",
 			"......####......",
 			"......####......",
 			"......####......",
 			"......####......",
 			"......####......",
 			"......####......",
 			"......####......",
 			"......####......",
 			"......####......",
 			"................",
 			"................"};
 			"""
	MenuText = "Text3D"
	ToolTip = "Text3D workbench"
	def Initialize(self):
		# load the module
		import Text3DGui
	def GetClassName(self):
		return "Text3DGui::Workbench"

Gui.addWorkbench(Text3DWorkbench())
