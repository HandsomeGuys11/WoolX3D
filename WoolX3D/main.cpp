#include "hello_maya.h"
#include <maya/MFnPlugin.h>
// define EXPORT for exporting dll functions
#define EXPORT _declspec(dllexport)
// Maya Plugin creator function
void* helloMaya::creator()
{
	return new helloMaya;
}
// Plugin doIt function
MStatus helloMaya::doIt(const MArgList& argList)
{
	MStatus status;
	MGlobal::displayInfo("Hello World!");
	// <<<your code goes here>>>
	MString name = "Please add a name with -name";
	MString id = "Please add an id with -id";

	int index;
	index = argList.flagIndex("name");
	argList.get(index + 1, name);

	index = argList.flagIndex("id");
	argList.get(index + 1, id);

	MString finalString = MString() + "confirmDialog -title \"Hello Maya\"" + " -message" + "\"" + "Name: " + name + " \\n ID: " + id + "\"";
	MGlobal::executeCommand(finalString);
	return status;
}
// Initialize Maya Plugin upon loading
EXPORT MStatus initializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj, "CIS660", "1.0", "Any");
	status = plugin.registerCommand("helloMaya", helloMaya::creator);
	if (!status)
		status.perror("registerCommand failed");
	return status;
}
// Cleanup Plugin upon unloading
EXPORT MStatus uninitializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj);
	status = plugin.deregisterCommand("helloMaya");
	if (!status)
		status.perror("deregisterCommand failed");
	return status;
}
