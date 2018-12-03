#pragma once

#include <iostream>
#include <vector>
#include "Drawing.h"

using namespace std;

// DRAWOBJECT CLASS
class DrawObject
{
public:
	DrawObject();										// Default contructor	
	DrawObject(COLOUR temp)								// COLOUR constructor - accepts a colour
	{
		colour = temp;
	}
	virtual ~DrawObject() {}
	
	// draw method - pure virtual, returns void and accepts reference to a Drawing object
	virtual void draw(Drawing &drawingReference) = 0;
	
	// getColour method - returns the colour
	COLOUR getColour()
	{
		return colour;
	}

private:
	COLOUR colour;										// colour member variable

protected:
	vector<COORD> vectorCOORD;							// vectorCOORD member variable
};

// POINT CLASS
class Point : public DrawObject
{
public:
	Point(COLOUR colour, COORD coord) : DrawObject(colour)					// Constructor
	{
		vectorCOORD.push_back(coord);
	}	void draw(Drawing &drawingReference) 
	{
		drawingReference.setPixel(vectorCOORD.at(0), getColour());
	}
};

// LINE CLASS
class Line : public DrawObject
{
public:
	Line(COLOUR colour, COORD start, COORD end) : DrawObject(colour) 		// Constructor
	{
		vectorCOORD.push_back(start);
		vectorCOORD.push_back(end);
	}

	// draw method - draw a line from the first COORD to the second COORD 
	// using COLOUR from the base class getter
	void draw(Drawing &drawingReference)
	{
		drawingReference.drawLine(vectorCOORD.at(0), vectorCOORD.at(1), getColour());
	}
};


class Shape : public DrawObject
{
public:
	Shape(COLOUR colour) : DrawObject(colour)								// Constructor
	{
		shapeCounter++;
	}
	~Shape()																// Destructor
	{ 
		shapeCounter--; 
	}

	void draw(Drawing &drawingReference)
	{
		for (int i = 0; i < vectorCOORD.size(); i++)
		{
			if (i == vectorCOORD.size() - 1)
			{
				drawingReference.drawLine(vectorCOORD.at(i), vectorCOORD.at(0), getColour());
				break;
			}
			
			drawingReference.drawLine(vectorCOORD.at(i), vectorCOORD.at(i+1), getColour());
		}
	}

	// addCOORD method - accepts a COORD object and adds it to the base class vector<COORD>
	void addCOORD(COORD coord)
	{
		vectorCOORD.push_back(coord);
	}

	// getNumberOfShapes method - returns the number of shapes (shapeCounter)
	static int getNumberOfShapes()
	{
		return shapeCounter;
	}

private:
	static int shapeCounter;							// shapeCounter to keep track of shapes
};

int Shape::shapeCounter = 0;							// Defining shapeCounter static variable