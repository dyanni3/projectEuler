//
//  main.cpp
//  euler10
//
//  Created by David Yanni on 1/5/19.
//  Copyright © 2019 David Yanni. All rights reserved.
//

// Calculates the sum of all primes less than 2 million

#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include <iterator>
#include <ctime>

using namespace std;
 
int main(){
 //timing
 clock_t begin = clock();
 
 //declarations
 bool isPrime;
 list <int> primes_list; //used to keep track of primes found so far
 primes_list.push_back(2);
 list <int>:: iterator it;
 long long int sum=0;
 
 //start prime hunting
 for(int i=3; i<2000000; i++){
     //progress
     if(i % 100000 == 0){
         cout<<i<<" \n";
     }
     
     isPrime=true;
     //first check all the primes we've found so far
     for(it=primes_list.begin(); it!=primes_list.end(); ++it){
         if (i % *it == 0){
             isPrime=false;
             break;
         }
     }
     // if not divisible by any known primes check from biggest known prime to i
     if(isPrime){
         for(int j=primes_list.back();j<i;j++){
             if (i % j == 0){
                 isPrime=false;
                 break;
             }
         }
     }
     if(isPrime){
         primes_list.push_back(i);
         sum+=i;
     }
 }
 
 clock_t end = clock();
 double elapsed = end-begin;
 cout<<"sum of primes: "<<sum<<"\n";
 cout<<"time elapsed: "<<elapsed/CLOCKS_PER_SEC<<" seconds\n";

    
}
