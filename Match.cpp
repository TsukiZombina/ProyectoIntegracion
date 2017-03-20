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

Match::Match(const char* filename): map(filename){
    this->filename = filename;
}

void Match::makeMatch(MatchSet& matchSet) {
    std::pair<Coordinate, Coordinate> match;
    for(auto it = map.begin(); it != map.end(); it++){
        match.first = *it;
        match.second = *(++it);
        matchSet.push_back(match);
    }
}

double Match::totalDistance(MatchSet& matchSet) {
    double totalDist = 0.0;
    for(auto& match: matchSet){
        totalDist += match.first.computeDistance(match.second);
    }
    return totalDist;
}

void Match::saveData(MatchSet& matches) {
    std::string result = filename + ".wr";
    std::ofstream ofs(result.c_str());
    if(ofs.is_open()) { 
        for(auto& match: matches)
            ofs << match.first.x << " " << match.first.y << " " 
                    << match.second.x << " " << match.second.y << std::endl;
    }
    ofs.close();
}

void Match::computeWindroseMatches(){
    MatchSet matchSets[4];
    double distances[4];
    Map::SortAlgorithm* sort = map.getSortAlgorithm();
    for(int i = 0; i < 4 ; i++) {
        sort[i](map);
        makeMatch(matchSets[i]);
        distances[i] = totalDistance(matchSets[i]);
    }
/*
    map.sortX();
    makeMatch(matchSets[0]);
    distances[0] = totalDistance(matchSets[0]);
    map.sortY();
    makeMatch(matchSets[1]);
    distances[1] = totalDistance(matchSets[1]);
    map.sortXY();
    makeMatch(matchSets[2]);
    distances[2] = totalDistance(matchSets[2]);
    map.sortYX();
    makeMatch(matchSets[3]);
    distances[3] = totalDistance(matchSets[3]);
*/
    int matchSetIndex = std::distance(distances, std::max_element(distances, distances + 3));
    saveData(matchSets[matchSetIndex]);
}

