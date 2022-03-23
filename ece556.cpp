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
    rst.gx << (int)bufferString - (int)'0'; // save grid dimensions
    inputFile >> bufferString;
    rst.gy << (int)bufferString - (int)'0';

    inputFile >> bufferString; // skip "capacity"
    rst.cap << (int)bufferString - (int)'0';

    inputFile >> bufferString; // skip "num"
    inputFile >> bufferString; // skip "net"
    inputFile >> bufferString;
    rst.numNets << (int)bufferString - (int)'0';

    for (int i = 1; i <= rst.numNets; ++i) {
      net temp 

  }

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
  

