/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Match.cpp
 * Author: ammy_
 * 
 * Created on February 26, 2017, 11:59 PM
 */

#include "Match.h"

std::list<std::pair<Coordinate, Coordinate>>& Match::computeWindrose(std::vector<Coordinate>& sortedMap, std::list<std::pair<Coordinate, Coordinate> >& matches){
    std::pair<Coordinate, Coordinate> match;
    for(auto it = sortedMap.begin(); it != sortedMap.end(); it++){
        match.first = *it;
        match.second = *(++it);
        matches.push_back(match);
    }
}

