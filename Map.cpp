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

Map::Map(const char* filename) {
    int n;
    Coordinate coordinate;
    std::ifstream infile;
    infile.open (filename);
    infile >> n;
    while(infile >> coordinate.x >> coordinate.y)
    {
        map.push_back(coordinate);
//        std::cout << coordinate.x << " " << coordinate.y << " coordenada" <<std::endl;
//        std::cout << map.back().x << " " << map.back().y << " mapa" << n <<std::endl;
    }
    infile.close();
}

Map::~Map() {
}

std::vector<Coordinate>& Map::sortX(std::vector<Coordinate>& points){
    points = map;
    std::sort(points.begin(), points.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return a.x < b.x;
    });
    return points;
}

std::vector<Coordinate>& Map::sortY(std::vector<Coordinate>& points){
    points = map;
    std::sort(points.begin(), points.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return a.y < b.y;
    });
    return points;
}

std::vector<Coordinate>& Map::sortXY(std::vector<Coordinate>& points){
    points = map;
    std::sort(points.begin(), points.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return (a.x*cos(315*PI/180) - a.y*sin(315*PI/180)) < (b.x*cos(315*PI/180) - b.y*sin(315*PI/180));
    });
    return points;
}

std::vector<Coordinate>& Map::sortYX(std::vector<Coordinate>& points){
    points = map;
    std::sort(points.begin(), points.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return (a.x*sin(315*PI/180) + a.y*cos(315*PI/180)) < (b.x*sin(315*PI/180) + b.y*cos(315*PI/180));
    });
    return points;
}