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
using namespace std;

int main() {
    clock_t s = clock();
    //cout<<count_sundays();
    long int nas = non_abundant_sums();
    clock_t e = clock();
    cout<<"non abundant sum: "<<nas<<"\nTime elaspsed: "<<double(e-s)/CLOCKS_PER_SEC<<"\n";
}
