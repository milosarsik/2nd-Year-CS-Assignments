#include <iostream>
#include <string>
#include <forward_list>

#include "Drawing.h"
#include "Drawable.h"

// FILE PATH -> C:\Users\milos\Documents\A-Z\C\CS1037-ComputerScienceFundamentalsII\assn3\Debug\assn3 test.bmp 200 100 127 127 127 S 255 0 0 4 10 10 10 190 90 190 90 10 S 0 255 0 3 50 100 55 105 55 95 L 0 0 255 60 30 80 100 L 0 0 255 80 100 60 170 P 0 0 0 25 70 P 0 0 0 25 130
		
using namespace std;

int main(int argc, char *argv[])
{
	// Variables
	forward_list <DrawObject*> objects;
	string bitmapFileName;
	int width, height;
	int toNextObject = 0;
	COLOUR backgroundColour;
	COLOUR tempColour;

	// 1. Create a Drawing object based on the program arguments
		
		// Get bitmap file name
	bitmapFileName = argv[1];

		// Get width and height in pixels of the image
	width =  atoi(argv[2]);
	height = atoi(argv[3]);

		// Get RGB values for the background
	backgroundColour.rgb[0] = atoi(argv[4]);
	backgroundColour.rgb[1] = atoi(argv[5]);
	backgroundColour.rgb[2] = atoi(argv[6]);

		// Create drawing object
	Drawing drawing(width, height, backgroundColour);

	// 2. Create as many specific DrawObjects (Line,Point,Shape) as are requested by the program arguments,
	//    and store each of them in a single forward_list<DrawObject *>
	for (int i = 7; i < argc; i = i + toNextObject)
	{
		if (*argv[i] == 'P')
		{
			// Getting and assigning the RGB values to the COLOUR structure
			tempColour.rgb[0] = atoi(argv[i+1]);
			tempColour.rgb[1] = atoi(argv[i+2]);
			tempColour.rgb[2] = atoi(argv[i+3]);

			// Creating a COORD structure
			COORD tempCoord = {atoi(argv[i+4]), atoi(argv[i+5])};
			
			// Creating a new Point object and passing the address to the forward list
			objects.push_front(new Point(tempColour, tempCoord));

			// This variable tells us how much to increment the i counter by, this is for a point
			toNextObject = 6;
		}
		else if (*argv[i] == 'L')
		{
			// Getting and assigning the RGB values to the COLOUR structure
			tempColour.rgb[0] = atoi(argv[i + 1]);
			tempColour.rgb[1] = atoi(argv[i + 2]);
			tempColour.rgb[2] = atoi(argv[i + 3]);

			// Creating a COORD structures for start and end of the line
			COORD startCoord = { atoi(argv[i + 4]), atoi(argv[i + 5]) };
			COORD endCoord = { atoi(argv[i + 6]), atoi(argv[i + 7]) };

			// Creating a new Line object and passing the address to the forward list
			objects.push_front(new Line(tempColour, startCoord, endCoord));

			// This varaible tells us how much to increment the i counter by, this is for a line
			toNextObject = 8;
		}
		else if (*argv[i] == 'S')
		{
			// Getting and assigning the RGB values to the COLOUR structure
			tempColour.rgb[0] = atoi(argv[i + 1]);
			tempColour.rgb[1] = atoi(argv[i + 2]);
			tempColour.rgb[2] = atoi(argv[i + 3]);

			// Getting the number of coordinates that will follow in the array
			int numberOfCoord = atoi(argv[i + 4]);

			// This will give us the position of the start coordinate
			int coordPosition = i + 5;

			// Creating a Shape pointer and instantiating it to the colour
			Shape *pointer = new Shape(tempColour);

			// For loop to add all of the coordinates to the Shape object
			for (int k = 0; k < numberOfCoord; k++)
			{
				COORD tempCoord = { atoi(argv[coordPosition]), atoi(argv[coordPosition+1]) };
				
				(*pointer).addCOORD(tempCoord);
				coordPosition += 2;
			}

			// Passing the addess of the Shape pointer to the forward list
			objects.push_front(pointer);

			// This varaible tells us how much to increment the i counter by, this is for a shape and depends on how many COORDS there are
			toNextObject = 5 + (2*numberOfCoord);
		}
		else
		{
			// This is simply for error checking
			cout << "PROBLEM IN ARGUMENTS" << endl;
		}
	}

	// 3. Print out the number of Shapes that were created, using the static function you coded
	cout << "Number of shapes: " << Shape::getNumberOfShapes() << endl;

	// 4. Call the draw function for each DrawObject, remove it from the forward_list, and free the object memory
	while (!(objects.empty()))
	{
		// Accessing each object and calling the draw method for each
		(objects.front())->draw(drawing);

		// Freeing the dynamic memory
		delete (objects.front());

		// Pop of the front object because it is empty, now in the next iteration we can access the next object
		objects.pop_front();
	}

	// 5. Save your image using the file name specified in the arguments, print out a message if it was
	//    successful or not
	drawing.saveBMP(bitmapFileName);

	// 6. Print out the number of Shapes that remain, using the static function you coded
	cout << "Number of shapes: " << Shape::getNumberOfShapes() << endl;
		
		// Outputting that the bitmap file has been succesfully saved
	cout << bitmapFileName << " saved succesfully" << endl;

	// 7. Keeping the window open, by prompting for a character
	char c;
	cin >> c;
}