/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConvexHull.cpp
 * Author: ammy_
 * 
 * Created on March 19, 2017, 7:46 PM
 */

#include "ConvexHull.h"

ConvexHull::ConvexHull() {
}

ConvexHull::ConvexHull(const ConvexHull& orig) {
}

ConvexHull::~ConvexHull() {
}


void ConvexHull::operator()(Map& map, CoordinateSet& cs) {
	map.sortXthenY();
	CoordinateSet up, down;
	const CoordinateSet& sortedMap = map.getCoordinateSet();
	anchor = sortedMap[0];
	tail = sortedMap.back();
    up.push_back(anchor);
	down.push_back(anchor);

    for (int i = 1; i < (int) sortedMap.size(); i++) {
        if (i == (int) sortedMap.size() - 1 || !isCCW(tail, anchor, sortedMap[i])) {
            while ((int) up.size() >= 2 && isCCW(up[up.size()-2], up.back(), sortedMap[i]))
                up.pop_back();
            up.push_back(sortedMap[i]);
        }
        if (i == (int) sortedMap.size() - 1 || isCCW(tail, anchor, sortedMap[i])) {
            while ((int) down.size() >= 2 && !isCCW(down[down.size()-2], down.back(), sortedMap[i]))
                down.pop_back();
            down.push_back(sortedMap[i]);
        }
    }

    cs.clear();
    for (int i = 0; i < (int) up.size(); i++) 
		cs.push_back(up[i]);
    for (int i = (int) down.size() - 2; i > 0; i--) 
		cs.push_back(down[i]);
}

bool ConvexHull::isCCW(Coordinate a, Coordinate b, Coordinate c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
