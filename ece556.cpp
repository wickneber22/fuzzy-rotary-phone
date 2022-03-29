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
    int blocks  = (int)bufferString - (int)'0';

    rst.numEdges = (rst.gx)*(rst.gy - 1) + (rst.gy)*(rst.gx - 1);

    // need to implement an edgeID formula
    //

  };

  return 1;
}

int solveRouting(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/

  return 1;
}

int writeOutput(const char *outRouteFile, routingInst *rst){
	
	/* check for null parameters */
  if( outRouteFile == NULL || rst == NULL )
  {
    printf("Argument file or routingInst is null");
    return 0;
  }
	
  /* Open output file to begin writing */	
  outFile = fopen(outRouteFile, "w");
  
  /* Parent loop for number of nets in routingInst*/
  for (int i = 0; i < rst->numNets; i++){
	  
	  /* Print net number */
	  fprintf(outFile,"n" + i + "\n");
	  
	  for (int m = 0; m < rst->nets[i].nroute.numSegs.; m++){
		  
		  for (int n = 0; n < rst->nets[i].nroute.segments[m].numEdges; n++){
			  
			  edgeEnds(&p1, &p2, rst, rst -> nets[i].segments[m].edges[n]);
		  
				/* variable to hold number of edges */
				edgeAmount = rst->nets[i].nroute.segments[m].numEdges;
		  
				/* Print case for if only one edge is used in route */
				if(rst->nets[i].nroute.segments[m].numEdges == 1)
				{
				fprintf(outFile, "(" + p1.x + "," + p1.y + ")-(" + p2.x + "," + p2.y + ")");
				}
		    }
		  
	    }	  
	  
    }

  return 1;
}
}


int release(routingInst *rst){
  /*********** TO BE FILLED BY YOU **********/

  return 1;
}
  
/* Function to retrive edge endpoints for writeOutput */
void edgeEnds(point *p1, point *p2, routingInst *rst, int iD ){
	
	/* Variable to determine if edge is vertical or horizontal */
	int edgeID_VorH = iD - ((rst -> gy) * ((rst -> gx) - 1))
	
	/* If edge is horizontal */
	if(edgeID_VorH <= 0){
		
		/* Assign values to p1,p2 y values */
		p1->y = floor((iD - 1) / ((rst->gx) - 1));
		p2->y = (p1->y);
		
		/* Assign values to p1,p2 x values, variables switched for compilation order */
		p2->x = iD - (((rst->gx) - 1)*(p2->y));
		p1->x = (p2->x) - 1;
	}
	/* If edge is vertical */
	else{
		
		/* Assign values to p1,p2 x values */
		p1->x = floor((edgeID_VorH - 1) / ((rst->gy) - 1));
		p2->x = p1->x;
		
		/* Assign values to p1,p2 y values */
		p2->y = edgeID_VorH - ((p2->x) * (rst->gy - 1));
		p1->y = (p2->y) - 1;	
	}
	}
