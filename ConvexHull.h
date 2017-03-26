/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConvexHull.h
 * Author: ammy_
 *
 * Created on March 19, 2017, 7:46 PM
 */

#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include "Map.h"
#include <vector>

class ConvexHull {
public:
    ConvexHull();
    ConvexHull(const ConvexHull& orig);
    virtual ~ConvexHull();
    void operator()(Map&, CoordinateSet&);
private:
    Coordinate anchor, tail;

	bool isCCW(Coordinate a, Coordinate b, Coordinate c);
};

#endif /* CONVEXHULL_H */

