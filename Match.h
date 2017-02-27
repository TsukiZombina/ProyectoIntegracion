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

#include "Coordinate.h"
#include <utility>
#include <vector>
#include <list>

class Match {
public:
    std::list<std::pair<Coordinate, Coordinate>>& computeWindrose(std::vector<Coordinate>&, std::list<std::pair<Coordinate, Coordinate>>&);
private:
};

#endif /* MATCH_H */

