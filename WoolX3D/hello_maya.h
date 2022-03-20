#pragma once
#ifndef WoolXMain_H
#define WoolXMain_H
#include <maya/MArgList.h>
#include <maya/MObject.h>
#include <maya/MGlobal.h>
#include <maya/MPxCommand.h>
#include <string>
#include <maya/MSyntax.h>
#include <maya/MArgDatabase.h>

// custom Maya command
class WoolXMain : public MPxCommand
{
public:
	WoolXMain() {};
	virtual MStatus doIt(const MArgList& args);
	static void* creator();
	static MSyntax createSyntax();
	~WoolXMain();
};
#endif