//NOTE: THIS IS GOING TO BE BROKEN FOR A VERY LONG TIME
//This is essentially a copy-paste from assignemnt 8 with almost no variation until I rewrite all of the functions
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include"HashMap.h"

//EDGE
Edge::Edge() {

}

Edge::Edge(Mountain* destination, int& in_weight) {
	next = destination;
}

Edge::~Edge() {
	if (next != nullptr)
		delete next;
};


//MOUNTAIN
Mountain::Mountain(std::string& in_name) {
	//If there is no name, there is no need to make a mountain
	//this is the closest thing to a default constructor that Mountain will get.
	// -1 means no value passed
	rank = -1;
	name = in_name;
	elevation = -1;
	range = "none assigned";
	coordinates.latitude = -1;
	coordinates.N_S = ' ';
	coordinates.latitude = -1;
	coordinates.E_W = ' ';
	have_visited = false;
	distance = MAX_DISTANCE;
}

Mountain::Mountain(int& in_rank, std::string& in_name, double& in_elevation, std::string& in_range, double& in_lat, char& NS, double& in_long, char& EW) {
	//Clean-cut assignment
	rank = in_rank;
	name = in_name;
	elevation = in_elevation;
	range = in_range;
	coordinates.latitude = in_lat;
	coordinates.N_S = NS;
	coordinates.latitude = in_long;
	coordinates.E_W = EW;
	have_visited = false;
	distance = MAX_DISTANCE;
}

Mountain::~Mountain() {};


Graph::Graph() {

}

Graph::~Graph() {

}


//HASHMAP
HashMap::HashMap() {
	hashTable = new HashTable_Perfect<Mountain>*[PRIMARY_SIZE];
	for (unsigned int i = 0; i < PRIMARY_SIZE; i++) {
		hashTable[i] = nullptr;
	}
}

HashMap::~HashMap() {
	if (size > 0)
		delete[]hashTable;
}


void HashMap::insertMountain(int& in_rank, std::string& in_name, double& in_elevation, std::string& in_range, double& in_lat, char& ns, double& in_long, char& ew) {
	Mountain* mountain = new Mountain(in_rank, in_name, in_elevation, in_range, in_lat, ns, in_long, ew);
	unsigned int* keys = nullptr;
	keys = populateKeys(in_name);
	*this[*keys][*++keys] = *mountain;
}


void HashMap::deleteMountain(std::string& in_name) {
	unsigned int* keys = nullptr;
	keys = populateKeys(in_name);
	delete this[*keys][*++keys];

}

