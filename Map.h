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

class Map {
public:
    Map(const char* filename);
    virtual ~Map();
private:
    std::vector<Coordinate> map;
};

#endif /* MAP_H */

