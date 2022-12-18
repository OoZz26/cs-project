#pragma once
#include "Shape.h"
#include<fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(Point p) const; //Search for a shape given a point inside the shape
	shape* GetSelected();
	void SetSelected(shape* sh);
	bool setFilled(bool state);
	virtual void Save(ofstream& savefile, string filename, string fcl, string drc, string pnw);		//Save all shapes to a file
	void DeleteShape();
//void load(ifstream& inputfile);	//Load all shapes from a file

};
