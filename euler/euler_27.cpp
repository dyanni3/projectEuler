//
//  euler_27.cpp
//  euler
//
//  Created by David Yanni on 1/14/19.
//  Copyright © 2019 David Yanni. All rights reserved.
//

#include "euler_27.hpp"
#include <cmath>
using namespace std;

long int evaluate(long int n, int a, int b){
    return(pow(n,2)+n*a+b);
}

bool isPrime(long int n){
    if(n<0){
        n = n*-1;
    }
    if (n ==1){
        return false;
    }
    for(int i=2; i<n;i++){
        if (n % i == 0){
            return false;
        }
    }
    return(true);
}

int max_n_consecutives(int a, int b){
    long int n = 0;
    while(isPrime(evaluate(n,a,b))){
        n++;
    }
    return(n);
}

long int euler_27(int minr, int maxr){
    int max_count = 0;
    int this_count = 0;
    long int prod = 0;
    for(int a = minr; a<maxr; a++){
        for(int b = minr; b<maxr; b++){
            this_count = max_n_consecutives(a, b);
            if(this_count>max_count){
                max_count = this_count;
                prod = a*b;
            }
        }
    }
    return(prod);
}
