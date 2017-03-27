/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.h
 * Author: ammy_
 *
 * Created on January 24, 2017, 11:54 PM
 */

#ifndef MAP_H
#define MAP_H

#include "Coordinate.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <functional>

#define PI 3.14159265358979323846

typedef std::vector<Coordinate> CoordinateSet;
typedef std::vector<Coordinate>::iterator CoordinateSetIterator;

class Map {
public:
    Map(const char* filename);
    
    virtual ~Map();
    void sortX();
    void sortY();
    void sortXY();
    void sortYX();
    void sortXthenY();
	void pop_back();
    typedef std::function<void(Map&)> SortAlgorithm;
    CoordinateSetIterator begin(){return coordinateSet.begin();}
    CoordinateSetIterator end(){return coordinateSet.end();}
    SortAlgorithm* getSortAlgorithm();
	const CoordinateSet& getCoordinateSet();
	CoordinateSetIterator erase(CoordinateSetIterator);
    
private:
    CoordinateSet coordinateSet;
    SortAlgorithm sortAlg[4];
};

#endif /* MAP_H */

