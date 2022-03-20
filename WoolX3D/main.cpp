#include "hello_maya.h"
#include <maya/MFnPlugin.h>
#include <list>
#include <iostream>
#include <vector>
#include <string>
// define EXPORT for exporting dll functions
#define EXPORT _declspec(dllexport)
// Maya Plugin creator function
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
