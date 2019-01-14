//
//  triangle_contains.cpp
//  euler
//
//  Created by David Yanni on 1/11/19.
//  Copyright © 2019 David Yanni. All rights reserved.
//

#include "triangle_contains.hpp"
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

double angle(double a[2], double b[2]){
    double mag_a = pow(a[0],2)+pow(a[1],2);
    mag_a = pow(mag_a,0.5);
    double mag_b = pow(b[0],2)+pow(b[1],2);
    mag_b = pow(mag_b,0.5);
    double dot = a[0]*b[0]+a[1]*b[1];
    return(acos(dot/(mag_a*mag_b)));
}

bool contains_origin(double a[2], double b[2], double c[2]){
    double aob = angle(a,b);
    double aoc = angle(a,c);
    double boc = angle(b,c);
    
    if(aoc+aob+boc - 2*M_PI<0.001){
        return(true);
    }
    else{
        return(false);
    }
}

double euler_102(){
    return(5.0);
}
