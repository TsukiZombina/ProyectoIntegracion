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
        coordinateSet.push_back(coordinate);
//        std::cout << coordinate.x << " " << coordinate.y << " coordenada" <<std::endl;
//        std::cout << map.back().x << " " << map.back().y << " mapa" << n <<std::endl;
    }
    infile.close();
    sortAlg[0] = &Map::sortX;
    sortAlg[1] = &Map::sortY;
    sortAlg[2] = &Map::sortXY;
    sortAlg[3] = &Map::sortYX;
}

Map::~Map() {
}

Map::SortAlgorithm* Map::getSortAlgorithm() {
    return sortAlg;
}

const CoordinateSet & Map::getCoordinateSet()
{
	const CoordinateSet& ref = coordinateSet;
	return ref;
}

CoordinateSetIterator Map::erase(CoordinateSetIterator eras)
{
	auto it = coordinateSet.erase(eras);
	return it;
}

void Map::sortX(){
    std::sort(coordinateSet.begin(), coordinateSet.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return a.x < b.x;
    });
}

void Map::sortY(){
    std::sort(coordinateSet.begin(), coordinateSet.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return a.y < b.y;
    });
}

void Map::sortXY(){
    std::sort(coordinateSet.begin(), coordinateSet.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return (a.x*cos(315*PI/180) - a.y*sin(315*PI/180)) < (b.x*cos(315*PI/180) - b.y*sin(315*PI/180));
    });
}

void Map::sortYX(){
    std::sort(coordinateSet.begin(), coordinateSet.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return (a.x*sin(315*PI/180) + a.y*cos(315*PI/180)) < (b.x*sin(315*PI/180) + b.y*cos(315*PI/180));
    });
}

void Map::sortXthenY(){
    std::sort(coordinateSet.begin(), coordinateSet.end(), [](const Coordinate& a, const Coordinate& b) -> bool{
        return (a.x < b.x || (a.x == b.x && a.y < b.y));
    });
}