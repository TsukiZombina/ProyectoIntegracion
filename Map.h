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

#define PI 3.14159265358979323846

class Map {
public:
    Map(const char* filename);
    virtual ~Map();
    std::vector<Coordinate>& sortX(std::vector<Coordinate>&);
    std::vector<Coordinate>& sortY(std::vector<Coordinate>&);
    std::vector<Coordinate>& sortXY(std::vector<Coordinate>&);
    std::vector<Coordinate>& sortYX(std::vector<Coordinate>&);
private:
    std::vector<Coordinate> map;
};

#endif /* MAP_H */

