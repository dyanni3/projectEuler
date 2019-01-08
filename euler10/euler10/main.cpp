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
#include <set>
#include <string>
#include <map>

using namespace std;

list <int> collatz(int n){
    list <int> returns;
    returns.push_back(n);
    do{
        if(n % 2 ==0){
            n=n/2;
        }
        else{
            n=3*n+1;
        }
        returns.push_back(n);
    }
    while(n!=1);
    return(returns);
}


void prnt_list(list <int> my_list){
    list <int>:: iterator it;
    for(it=my_list.begin(); it!=my_list.end(); ++it){
        cout<<*it<<"\n";
    }
}

void collatz_main(){
    clock_t start = clock();
    long long int colsize = 0;
    list <int> col13;
    for(int i=3;i<1000000;i++){
        //progress
        if(i % 100000 == 0){
            cout<<i<<" \n";
        }
        col13 = collatz(i);
        if(col13.size()>colsize){
            colsize=col13.size();
        }
    }
    cout<<colsize<<"\n";
    clock_t end = clock();
    cout<<(end-start)/CLOCKS_PER_SEC;
}
 
int euler10(){
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
    return(1);
}

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

// sum of divisors from prime factors
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

void e21_main() {
    clock_t start = clock();
    long int sum_of_amicables = 0;
    
    // hash all the sum of divisors
    map <int,int> sods;
    for(int i=1; i<10000; i++){
        sods.insert(pair<int,int>(i,sum_of_divisors(i)));
    }
    
    // go through hash map and check for amicable pairs
    for(int j=1;j<10000;j++){
        if(sods[sods[j]]==j && j!=sods[j]){
            sum_of_amicables+=j;
        }
    }
    
    clock_t end = clock();
    cout<<"Sum of amicables < 10000 : "<<sum_of_amicables<<"\n";
    cout<<"Time elapsed: "<<double(end-start)/CLOCKS_PER_SEC<<" seconds \n";
}


int main(){
    //collatz_main();
    e21_main();
}
