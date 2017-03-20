/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ammy_
 *
 * Created on January 24, 2017, 11:56 PM
 */

#include <vector>
#include <utility>
#include <iostream>

#include "Map.h"
#include "Match.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Match match("x01f.rnd");
    match.computeWindroseMatches();
    return 0;
}

