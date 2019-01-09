//
//  non_abundant_sums.cpp
//  euler
//
//  Created by David Yanni on 1/8/19.
//  Copyright © 2019 David Yanni. All rights reserved.
//

#include "non_abundant_sums.hpp"
#include <set>
#include <cmath>
#include <list>
using namespace std;

// recursive search for prime divisors
multiset <int> prime_divisors(int n){
    multiset <int> factors;
    if(n==2){
        factors.insert(2);
        return(factors);
    }
    else if(n==1){
        return(factors);
    }
    int i=2;
    while(1==1){
        if(n % i == 0){
            factors.insert(i);
            multiset <int> new_factors = prime_divisors(n/i);
            factors.insert(new_factors.begin(),new_factors.end());
            break;
        }
        i++;
    }
    return(factors);
}

// sum of proper divisors from prime factors
int sum_of_divisors(int n){
    multiset <int> l = prime_divisors(n);
    multiset <int> :: iterator it;
    it = l.begin();
    int skips = 0;
    int sod = 1;
    while(it!=l.end()){
        skips = l.count(*it);
        sod = sod * (pow(*it,skips+1)-1)/(*it-1);
        advance(it,skips);
    }
    sod = sod - n;
    return(sod);
}

// ############## EULER 23 ######################
/*
 
 A perfect number is a number for which the sum of its proper divisors is exactly
 equal to the number. For example, the sum of the proper divisors of 28 would be
 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
 A number n is called deficient if the sum of its proper divisors is less than n
 and it is called abundant if this sum exceeds n.
 
 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number
 that can be written as the sum of two abundant numbers is 24. By mathematical
 analysis, it can be shown that all integers greater than 28123 can be written as
 the sum of two abundant numbers. However, this upper limit cannot be reduced any
 further by analysis even though it is known that the greatest number that cannot be
 expressed as the sum of two abundant numbers is less than this limit.
 
 Find the sum of all the positive integers which cannot be written as
 the sum of two abundant numbers.
 
*/

/*
 my approach is to calculate all abundant numbers and put them in a list
 the list will be sorted. Then initialize a counter non_abundant_sum to m*(m+1)/2
 m=28123. And for each number in range (24,28123) check the list to see if two
 abundant numbers add up to it. If so, subtract it from the non_abundant_sum
 
 A bit slow, should take O(m+ n^2) for m = 28123 and n = num_abundant_numbers
 */
long int non_abundant_sums(){
    long int nas = ((28123)*(28124))/2; //non_abundant_sum
    list <int> abundant_numbers;
    list <int>:: iterator b;
    list <int>:: iterator e;
    int s;
    
    for(int n=1;n<28124;n++){
        if(sum_of_divisors(n)>n){
            abundant_numbers.push_back(n);
        }
    }
    
    for(int m=1;m<28124;m++){
        b = abundant_numbers.begin();
        e = abundant_numbers.end();
        while(*e>=*b && b!=abundant_numbers.end() && e!=abundant_numbers.begin()){
            s = *b + *e;
            if (s<m){
                b++;
            }
            else if (s>m){
                e--;
            }
            else if (s==m){
                nas = nas-m;
                break;
            }
        }
    }
    return(nas);
}
