/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coordinate.cpp
 * Author: ammy_
 * 
 * Created on January 24, 2017, 11:55 PM
 */

#include <complex>

#include "Coordinate.h"

Coordinate::Coordinate() {
    x = 0.0;
    y = 0.0;
}

double Coordinate::computeDistance(Coordinate a){
    return std::sqrt(std::pow((a.x - this->x),2) + std::pow((a.y - this->y),2));
}

bool Coordinate::operator==(const Coordinate & rhs)
{
	return this->x == rhs.x && this ->y == rhs.y;
}

