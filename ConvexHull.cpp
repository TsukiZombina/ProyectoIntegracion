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
	/*
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
		cs.push_back(down[i]);*/

	int n = map.getCoordinateSet().size(), k = 0;
	if (n == 1) return;
	//vector<Point> H(2 * n);
	cs.resize(2 * n);
	// Sort points lexicographically
	map.sortXthenY();
	Coordinate c;
	// Build lower hull
	for (int i = 0; i < n; ++i) {
		c.x = map.getCoordinateSet()[i].x;
		c.y = map.getCoordinateSet()[i].y;
		while (k >= 2 && cross(cs[k - 2], cs[k - 1], c) <= 0) k--;
		cs[k++] = map.getCoordinateSet()[i];
	}

	// Build upper hull
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		c.x = map.getCoordinateSet()[i].x;
		c.y = map.getCoordinateSet()[i].y;
		while (k >= t && cross(cs[k - 2], cs[k - 1], c) <= 0) k--;
		cs[k++] = map.getCoordinateSet()[i];
	}

	cs.resize(k - 1);
}

bool ConvexHull::isCCW(Coordinate& a, Coordinate& b, Coordinate& c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

double ConvexHull::cross(Coordinate& o, Coordinate& a, Coordinate& b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
