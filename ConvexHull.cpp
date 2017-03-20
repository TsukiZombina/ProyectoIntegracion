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

/*
CoordinateSet ConvexHull::operator()(CoordinateSet& cs) {
    p.erase(unique(p.begin(), p.end(), eq), p.end());

    vector <point> up, down;
    point head = p[0], tail = p.back();
    up.push_back(head);     down.push_back(head);

    for (int i = 1; i < (int) p.size(); i++) {
        if (i == (int) p.size() - 1 || !isCCW(tail, head, p[i])) {
            while ((int) up.size() >= 2 && isCCW(up[up.size()-2], up.back(), p[i]))
                up.pop_back();
            up.push_back(p[i]);
        }
        if (i == (int) p.size() - 1 || isCCW(tail, head, p[i])) {
            while ((int) down.size() >= 2 && !isCCW(down[down.size()-2], down.back(), p[i]))
                down.pop_back();
            down.push_back(p[i]);
        }
    }

    h.clear();
    for (int i = 0; i < (int) up.size(); i++) h.push_back(up[i]);
    for (int i = (int) down.size() - 2; i > 0; i--) h.push_back(down[i]);
}
*/
