/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Match.h
 * Author: ammy_
 *
 * Created on February 26, 2017, 11:59 PM
 */

#ifndef MATCH_H
#define MATCH_H

#include "Map.h"
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include "ConvexHull.h"

typedef std::vector<std::pair<Coordinate, Coordinate> > MatchSet;

class Match {
public:
    Match(const char*);
    
    void computeWindroseMatches();
    void computeConvexHullMatches();
	void makeMatch(MatchSet&);
	void makeMatch(MatchSet&, CoordinateSet&);
private:
    Map map;
    std::string filename;
    
    void saveData(MatchSet&, const char* extension);
    double totalDistance(MatchSet&);
};

#endif /* MATCH_H */

