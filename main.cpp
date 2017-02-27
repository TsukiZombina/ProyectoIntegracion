/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ammy_
 *
 * Created on January 24, 2017, 11:56 PM
 */

#include <vector>
#include <iostream>

#include "Map.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Map map("x01f.rnd");
    std::vector<Coordinate> mapxy;
    map.sortXY(mapxy);
    for(auto& coord: mapxy){
        std::cout << coord.x << " " << coord.y << std::endl;
    }
    return 0;
}

