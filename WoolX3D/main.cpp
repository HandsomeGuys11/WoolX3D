#include "hello_maya.h"
#include <maya/MFnPlugin.h>
#include <list>
#include <iostream>
#include <vector>
#include <string>
// define EXPORT for exporting dll functions
#define EXPORT _declspec(dllexport)
// Maya Plugin creator function

#define User 0  // Shubham: 0, Sebastian :1
void* WoolXMain::creator()
{
	return new WoolXMain;
}

WoolXMain::~WoolXMain()
{
}

const char* matrixFlag = "-m", * matrixLongFlag = "-Matrix";

MSyntax WoolXMain::createSyntax() {
	MSyntax syntax;
	syntax.addFlag(matrixFlag, matrixLongFlag, MSyntax::kString);
	return syntax;
}


void GenerateMayaKnit(int i)
{
	MString cmmnd = MString() +
		// Cool green Loop ----------------------------
		+"circle - c 0 0 0 - nr 0 1 0 - sw 360 - r 0.3 - d 3 - ut 0 - tol 0.01 - s 8 - ch 1;"
		+ "curve - p - 0.65 0 - 0.990 - p - 0.546 0 0.963 - p - 2.990 0 4.474 - p 0.062 0 6.349 - p 3.348 0 4.296 - p 0.628 0 0.893 - p 0.65 0 - 1.021 - name curve" + i + ";"
		+ "select - r nurbsCircle1 curve" + i + ";"
		+ "extrude - ch true - rn false - po 1 - et 2 - ucp 1 - fpt 1 - upn 1 - rotation 0 - scale 1 - rsp 1 nurbsCircle1 curve" + i + ";"
		+ "polySmooth - mth 0 - sdt 2 - ovb 1 - ofb 3 - ofc 0 - ost 0 - ocr 0 - dv 1 - bnr 1 - c 1 - kb 1 - ksb 1 - khe 0 - kt 1 - kmb 1 - suv 1 - peh 0 - sl 1 - dpe 1 - ps 0.1 - ro 1 - ch 1 extrudedSurface" + i + ";"
		+ "polySmooth - mth 0 - sdt 2 - ovb 1 - ofb 3 - ofc 0 - ost 0 - ocr 0 - dv 1 - bnr 1 - c 1 - kb 1 - ksb 1 - khe 0 - kt 1 - kmb 1 - suv 1 - peh 0 - sl 1 - dpe 1 - ps 0.1 - ro 1 - ch 1 extrudedSurface" + i + ";"
		+ "polyNormal - normalMode 0 - userNormalMode 0 - ch 1 extrudedSurface" + i + ";";

	// Red Loop 1 ----------------------------

	//curve - p - 4.658 0 1.716 - p - 2.662 0 1.655 - p - 2.019 0.993 2.669 - p 0.137 - 0.928 2.222 - p - 0.352 - 0.520 4.891 - p - 0.770 0.692 3.477 - p - 0.65 0 8.299 - name curve2;
	//extrude - ch true - rn false - po 1 - et 2 - ucp 1 - fpt 1 - upn 1 - rotation 0 - scale 1 - rsp 1 nurbsCircle1 curve2;
	//polySmooth - mth 0 - sdt 2 - ovb 1 - ofb 3 - ofc 0 - ost 0 - ocr 0 - dv 1 - bnr 1 - c 1 - kb 1 - ksb 1 - khe 0 - kt 1 - kmb 1 - suv 1 - peh 0 - sl 1 - dpe 1 - ps 0.1 - ro 1 - ch 1 extrudedSurface2;
	//polySmooth - mth 0 - sdt 2 - ovb 1 - ofb 3 - ofc 0 - ost 0 - ocr 0 - dv 1 - bnr 1 - c 1 - kb 1 - ksb 1 - khe 0 - kt 1 - kmb 1 - suv 1 - peh 0 - sl 1 - dpe 1 - ps 0.1 - ro 1 - ch 1 extrudedSurface2;
	//polyNormal - normalMode 0 - userNormalMode 0 - ch 1 extrudedSurface2;

	//// Red Loop 2 ----------------------------

	//curve - p 4.658 0 1.716 - p 2.662 0 1.655 - p 2.019 0.993 2.669 - p - 0.137 - 0.928 2.222 - p 0.352 - 0.520 4.891 - p 0.770 0.692 3.477 - p 0.65 0 8.299 - name curve3;
	//extrude - ch true - rn false - po 1 - et 2 - ucp 1 - fpt 1 - upn 1 - rotation 0 - scale 1 - rsp 1 nurbsCircle1 curve3;
	//polySmooth - mth 0 - sdt 2 - ovb 1 - ofb 3 - ofc 0 - ost 0 - ocr 0 - dv 1 - bnr 1 - c 1 - kb 1 - ksb 1 - khe 0 - kt 1 - kmb 1 - suv 1 - peh 0 - sl 1 - dpe 1 - ps 0.1 - ro 1 - ch 1 extrudedSurface3;
	//polySmooth - mth 0 - sdt 2 - ovb 1 - ofb 3 - ofc 0 - ost 0 - ocr 0 - dv 1 - bnr 1 - c 1 - kb 1 - ksb 1 - khe 0 - kt 1 - kmb 1 - suv 1 - peh 0 - sl 1 - dpe 1 - ps 0.1 - ro 1 - ch 1 extrudedSurface3;
	//polyNormal - normalMode 0 - userNormalMode 0 - ch 1 extrudedSurface3;

	//// Select all created objects

	//select - r nurbsCircle1 curve1 extrudedSurface1 curve2 extrudedSurface2 curve3 extrudedSurface3;

	//// Group

	//group - name Knit;

	////Delete History
	//DeleteHistory;

	////Setting the scale and centering
	//setAttr "Knit.scaleX" 0.108;
	//setAttr "Knit.scaleY" 0.108;
	//setAttr "Knit.scaleZ" 0.108;
	//setAttr "Knit.translateZ" - 3.755;

	////Reset transformation
	//select - r Knit;
	//makeIdentity - apply true - t 1 - r 1 - s 1 - n 0 - pn 1;

	MGlobal::executeCommand(cmmnd);
}

void GenerateKnitThreads(std::vector<float> &matrixVals)
{
	int numKnits = matrixVals.size() / 16;
	
	for (int i = 0; i < numKnits; i++)
	{
		std::string Matrix = "";
		for (int j = 0; j < 16; j++)
		{
			Matrix += std::to_string(matrixVals[i + j]);
			if (i != numKnits - 1)
			{
				Matrix += " ";
			}
		}
		//One string contructed Call the mel Command 
		GenerateMayaKnit(i);
	}
}

// Plugin doIt function
MStatus WoolXMain::doIt(const MArgList& argList)
{
	MStatus status;
	MGlobal::displayInfo("Hello World!ytytuygyuty");
	// <<<your code goes here>>>
	//MString name = "Please add a name with -name";
	//MString id = "Please add an id with -id";

	MString transformString = "";

	MArgDatabase argData(syntax(), argList);


	//grammar 
	if (argData.isFlagSet(matrixFlag))
		argData.getFlagArgument(matrixFlag, 0, transformString);
	if (argData.isFlagSet(matrixLongFlag))
		argData.getFlagArgument(matrixLongFlag, 0, transformString);
	
	MStringArray splittedValues;

	transformString.split(' ', splittedValues);

	std::string abc = "";
	for (int i = 0; i < splittedValues.length(); i++)
	{
		abc += splittedValues[i].asChar();
	}

	std::vector<float> matrixVals;

	for (int i = 0; i < splittedValues.length(); i++)
	{
		matrixVals.push_back(std::stof(splittedValues[i].asChar()) );
	}
	GenerateKnitThreads(matrixVals);
	MString finalString = MString() + "confirmDialog -title \"Hello Maya\"" + " -message" + "\"" + "Matrix: " + transformString + "\"";
	MGlobal::executeCommand(finalString);
	return status;
}
// Initialize Maya Plugin upon loading
EXPORT MStatus initializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj, "WoolXDepartment", "0.1", "Any");
	status = plugin.registerCommand("wx3d", WoolXMain::creator, WoolXMain::createSyntax);

	MString GuiCommand;
	if (User == 0) //Shubham
	{
		GuiCommand = "source \"" + plugin.loadPath() + "/mycommand.txt\"";
	}
	if (User == 1) //Sebastian
	{
		GuiCommand = "source \"" + plugin.loadPath() + "/mycommand.txt\"";
	}

	//status = plugin.registerUI("createWoolXMenu", "deleteWoolXMenu");

	MGlobal::executeCommand(GuiCommand);

	if (!status)
		status.perror("registerCommand failed");
	return status;
}
// Cleanup Plugin upon unloading
EXPORT MStatus uninitializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj);
	status = plugin.deregisterCommand("WoolXMain");
	if (!status)
		status.perror("deregisterCommand failed");
	return status;
}
