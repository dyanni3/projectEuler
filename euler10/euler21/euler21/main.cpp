//
//  main.cpp
//  euler21
//
//  Created by David Yanni on 1/7/19.
//  Copyright © 2019 David Yanni. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <list>
#include <iterator>
using namespace std;

list <int> prime_divisors(int n){
    list <int> factors;
    if(n==2){
        factors.push_back(2);
        return(factors);
    }
    else if(n==1){
        return(factors);
    }
    int i=2;
    while(1==1){
        if(n % i == 0){
            factors.push_back(i);
            factors.sort();
            factors.merge(prime_divisors(n/i));
            break;
        }
        i++;
    }
    factors.sort();
    return(factors);
}

int e21_main() {
    int test_n = 120;
    list <int> test_divisors = prime_divisors(test_n);
    list<int>::iterator<int> it;
    for(it=test_divisors.begin();it!=test_divisors.end();++it){
        cout<<it;
    }
}
