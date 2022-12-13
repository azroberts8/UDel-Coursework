#include "Dijkstra.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Dijkstra::Dijkstra(string fname) {
	readFile(fname);
	Interface();
    runDijkstra();
    printPath();
}

// WRITE THIS (10 pts)
void Dijkstra::runDijkstra(){
//For this method, you should set the distance to the starting 
//vertex to 0 (the starting vertex is the index in the start 
//field)and set the visited array to true for the start index.
//Then initialize the distances of the cost of going to each node 
//from the start index (this is done using the adjacency  matrix 
// - matrixGraph.  
//Once you've initialized the starting values based on the start
//index, loop until every vertex has been visited, calling the 
//methods minDistance to find the next unvisited vertex with the 
//minimum distance, and then calling setDistances method for 
//every vertex to update distances for the unvisited vertices.
//
//Note that I also called printInfoSoFar in the loop so I could 
//see all the updates as we went along.
	distances[start] = 0;
	visited[start] = 1;

	setDistances(start);
	int current = minDistance();
	printInfoSoFar();

	while(current > -1) {
		setDistances(current);
		visited[current] = 1;
		printInfoSoFar();
		current = minDistance();
	}
}

//WRITE THIS (12 pts)
void Dijkstra::setDistances(int latestVert) {
// This method updates the distances array with the costs being
//updated to either their cost so far, or the cost of
//traveling through the recently visited vertex + the cost of
//traveling from that vertex to the new vertex (whichever is the
//minimum). If the minimum is through the recently visited 
//vertex, then update the previous array so that it holds the 
//latest visited vertex's index number
	for(int i = 0; i < numOfCities; i++) {
		if(distances[latestVert] + matrixGraph[latestVert][i] < distances[i]) {  // if directional calculations are wrong swap coords on matrixGraph
			distances[i] = distances[latestVert] + matrixGraph[latestVert][i];
			prev[i] = latestVert;
		}
	}
}

//WRITE THIS (8pts)
int Dijkstra::minDistance() {
//This method finds the next unvisited vertex with the minimum
//distance.
//Once the minimum is found (along with its index in the distance
//array), the visited array at that index is set to True and that 
//index is returned from this method.
	int minIndex = -1;
	for(int i = 0; i < numOfCities; i++) {
		if(minIndex == -1 && !visited[i]) minIndex = i;
		else if(distances[i] < distances[minIndex] && !visited[i]) minIndex = i;
	}
	cout << "Minimum: " << minIndex << endl;
	return minIndex;
}



//WRITE THIS (12 pts)
void Dijkstra::printPath() {
//This function gives you the final shortest path from the start 
//index (aka city) to the end index (aka city).  It is very 
//simple code!!  You must understand how it works, though, in 
//order to be able to write it.
//
//To write this, you'll use the prev array.  Start at the end 
//index.  Find the prev city (to be used as an index) at that end
//index.  The prev city becomes your next index.  Find the prev 
//city for that index.  Continue to find the prev cities until 
//the city (aka index) is the start city.
//THEN print out the path in reverse order!  (To do this, I stuck
//each city in an array as I worked my way from end to start, and 
//then printed out the cities in reverse order.

	int steps = 0;
	int current = end;
	int path[numOfCities] = { 0 };

	// Creates an array of the steps taken in reverse order
	while(current != start) {
		path[steps] = current;
		current = prev[current];
		steps++;
	}
	path[steps] = current;

	// Prints the array in correct order
	cout << Cities[path[steps]];
	for(int i = steps-1; i >= 0; i--) {
		cout << " -> " << Cities[path[i]];
	}
	cout << endl;
}
/************************************************************/
/* That's the end of what you have to write                 */
/************************************************************/

// A utility function to print the constructed distance array
void Dijkstra::printMatrix() {
	cout <<"********************************************" << endl << "Adjacency Matrix (of Cities and Distances):"<<endl;
	for (int i = 0; i< numOfCities;i++) {
		for (int j = 0; j < numOfCities; j++) {
			cout << matrixGraph[i][j] << "\t";
		}
		cout << endl;
	}
	cout <<"********************************************" << endl;
}

//Another utility method to print out the different arrays so far
//so you can see their content
void Dijkstra::printInfoSoFar() {
	cout <<"\t";
	for (int i = 0; i < numOfCities; i++) {
		cout << "\t"<<i;
	}
	cout << endl;
	cout << "Dist:\t";
	for (int i = 0; i < numOfCities; i++) {
		cout << "\t"<<distances[i];
	}
	cout << endl;
	cout << "Prev:\t";
	for (int i = 0; i < numOfCities; i++) {
		cout << "\t"<<prev[i];
	}
	cout << endl;
	cout << "Visited:";
	for (int i = 0; i < numOfCities; i++) {
		cout << "\t"<<visited[i];
	}
	cout << endl;
	cout << endl;
}





/*************************************************************/
/* This is the user interface that allows you to choose your 
/* start and end city you're traveling through.  You should not
/* need to touch this.
/*************************************************************/
void Dijkstra::Interface() {
	cout << "Choose from the following: "<<endl;
	for (int i = 0; i < numOfCities; i++) {
		cout << "\t" << i << ": " << Cities[i] << endl;
	}
	cout << endl;
	cout << "Choose your starting city (with the city's corresponding number"<<endl;
	cin >> start;
	cout << "Choose your end destination (with the city's corresponding number"<< endl;
	cin >> end;
}

/*************************************************************/
/* This method reads in the different Map files and initializes 
/* all your arrays along with the adjacency matrix.  It
/* initializes the following:
/*
/* numOfCities: the number of cities in the adjacency matrix
/*
/* Cities: an array filled with the list of cities - the index in 
/* the array is the number corresponding with each city (which 
/* can be utilized when printing out the path
/* 
/* visited: set to false for all cities (indices) to start
/*
/* prev: set to -1 (aka no previous city) for each index to start
/*
/* distance: set to a really large number for all indices to 
/* start
/*
/* matrixGraph: this is your adjacency matrix that holds the 
/* distance from each city to each city.  It is initialized in 
/* here with values read in from the different Map***.txt files
/*
/* If you want to make sure you're reading in your files 
/* correctly (aka make sure the files are in the correct place),
/* there are a number of print statements in here you can 
/* uncomment out.  Otherwise You should not need to touch this.
/*************************************************************/
void Dijkstra::readFile(string fn) {
	ifstream file(fn.c_str());
	int numcities;
	file>>numcities;
	//cout << numcities<<endl;
	numOfCities = numcities;
	Cities = new string[numOfCities];
	visited = new bool[numOfCities];
	prev = new int[numOfCities];
	distances = new int[numOfCities];
	matrixGraph = new int*[numOfCities];
	for (int i = 0; i < numOfCities; i++) {
		matrixGraph[i] = new int[numOfCities];
        distances[i] = 100000;
    	visited[i] = false;
    	prev[i] = -1;
	}
	string abbr;
	string city;
	string abbrCity;
	for (int i = 0; i < numOfCities; i++) {
		file >> abbr;
		file >> city;
		abbrCity = abbr + " "+city;
		//cout << abbrCity << ", ";
		Cities[i] = abbrCity;
	}
	//cout << endl;
	for (int ct = 0; ct < numOfCities; ct++)  {
		file >> abbr;
		//cout << abbr << ", ";
		file>>city;
		//cout << city << ": ";
		for (int i = 0; i < numOfCities; i++) {
			int x;
			file >> x;
			//cout << x << ", ";
			if (x == -1) {
				matrixGraph[ct][i] = 100000;
			}
			else matrixGraph[ct][i] = x;
		}
		//cout << endl;
	}
	//cout << "here" << endl;
    printMatrix();
	return;
}







