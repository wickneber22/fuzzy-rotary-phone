// ECE556 - Copyright 2014 University of Wisconsin-Madison.  All Rights Reserved.

#include "ece556.h"
#include <iostream>
#include <fstream>
#include <string>

int readBenchmark(const char *fileName, routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/
  std::ifstream inputFile;
  inputFile.open(fileName);

  std::string inputString;
  std::string bufferString;
  if (inputFile.is_open() ) { //parse through file
    inputFile >> bufferString; // skip "grid"
    inputFile >> bufferString;
    rst.gx = (int)bufferString - (int)'0'; // save grid dimensions
    inputFile >> bufferString;
    rst.gy = (int)bufferString - (int)'0';

    inputFile >> bufferString; // skip "capacity"
    rst.cap = (int)bufferString - (int)'0';

    inputFile >> bufferString; // skip "num"
    inputFile >> bufferString; // skip "net"
    inputFile >> bufferString;
    rst.numNets = (int)bufferString - (int)'0';

    net nets_array[rst.numNets] = {};
    
    for (int i = 0; i < rst.numNets; ++i) { // create array of nets
      net temp;
      int id = i;

      int numPins;
      inputFile >> bufferString; // skip "n#"
      inputFile >> bufferString; 
      numPins = (int)bufferString - (int)'0';

      point points_array[numPins] = {};
      
      for (int j = 0; j < numPins; ++j) { // create array of points
	inputFile >> bufferString;
	int x = (int)bufferString - (int)'0';

	inputFile >> bufferString;
	int y = (int)bufferString - (int)'0';

	points_array[j] = {x, y};
	
      };

      temp = {i, numPins, *points_array, NULL);
      nets_array[i] = *temp; // add completed net to array
    };

    rst.nets = *nets_array; // assign completed net array

    inputFile >> bufferString;
    rst.numEdges = (int)bufferString - (int)'0';
    
  };

  return 1;
}

int solveRouting(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/

  return 1;
}

int writeOutput(const char *outRouteFile, routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/

  return 1;
}


int release(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/

  return 1;
}
  

