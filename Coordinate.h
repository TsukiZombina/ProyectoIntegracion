/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coordinate.h
 * Author: ammy_
 *
 * Created on January 24, 2017, 11:55 PM
 */

#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>

class Coordinate {
public:
    double x;
    double y;
    Coordinate();
    Coordinate(double a, double b):x(a),y(b){}
    double computeDistance(Coordinate);
	bool operator==(const Coordinate&);
private:
};

#endif /* COORDINATE_H */

