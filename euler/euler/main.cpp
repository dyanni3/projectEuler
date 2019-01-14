//
//  main.cpp
//  euler
//
//  Created by David Yanni on 1/8/19.
//  Copyright © 2019 David Yanni. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "counting_sundays.hpp"
#include "non_abundant_sums.hpp"
#include "triangle_contains.hpp"
#include "euler_27.hpp"
using namespace std;


int main() {
    clock_t s = clock();
    long int prod = euler_27(-999,999);
    clock_t e = clock();
    cout<<"product: "<<prod<<"\nTime elaspsed: "<<double(e-s)/CLOCKS_PER_SEC<<"\n";
}
