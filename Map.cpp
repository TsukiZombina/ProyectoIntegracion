/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.cpp
 * Author: ammy_
 * 
 * Created on January 24, 2017, 11:54 PM
 */

#include "Map.h"
#include "Coordinate.h"
#include <fstream>

Map::Map(const char* filename) {
    int n;
    Coordinate coordinate;
    std::ifstream infile;
    infile.open (filename);
    getline(infile,n);
    while(!infile.eof) // To get you all the lines.
    {
        infile >> coordinate.x >> coordinate.y;
        map.push_back(coordinate);
        
    }
    infile.close();
}

Map::~Map() {
}

