//
//  counting_sundays.cpp
//  euler
//
//  Created by David Yanni on 1/8/19.
//  Copyright © 2019 David Yanni. All rights reserved.
//

/*
 You are given the following information, but you may prefer to do some research for yourself.
 
 1 Jan 1900 was a Monday.
 Thirty days has September,
 April, June and November.
 All the rest have thirty-one,
 Saving February alone,
 Which has twenty-eight, rain or shine.
 And on leap years, twenty-nine.
 A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <list>
#include <map>
#include <string>
using namespace std;

int count_sundays() {
    int num_sundays = 0;
    
    // days in month hash
    map<string,int> days_in_month;
    days_in_month.insert(pair<string,int>("JAN",31));
    days_in_month.insert(pair<string,int>("FEB",28));
    days_in_month.insert(pair<string,int>("MAR",31));
    days_in_month.insert(pair<string,int>("APR",30));
    days_in_month.insert(pair<string,int>("MAY",31));
    days_in_month.insert(pair<string,int>("JUN",30));
    days_in_month.insert(pair<string,int>("JUL",31));
    days_in_month.insert(pair<string,int>("AUG",31));
    days_in_month.insert(pair<string,int>("SEP",30));
    days_in_month.insert(pair<string,int>("OCT",31));
    days_in_month.insert(pair<string,int>("NOV",30));
    days_in_month.insert(pair<string,int>("DEC",31));
    
    // start at day 1 == JAN 1st 1900
    // advance by number of days in month to next first of month
    //and see if day is a sunday
    int today = 1;
    int year = 1900;
    map <string, int>::iterator it;
    while(year<2001){
        for(it=days_in_month.begin();it!=days_in_month.end();++it){
            if(it->first=="FEB" && year%4==0 && year!=2000){
                today+=1;
                today+=it->second;
            }
            else{
                today+=it->second;
            }
            if(today%7==0 && year>1900){
                num_sundays++;
            }
        }
        year++;
    }
    
    return(num_sundays);
}

