#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

int findMin(string str){
    int min = 10000;
    for (int i=1; i<str.length(); i++){
        min = (abs(str[i]-str[i-1]) < min) ? abs(str[i]-str[i-1]) : min;
    }
    return min;
}
int main()
{
    string front;
    while (getline (cin, front)){
        vector<pair <int, string > > p;
        string back = front;
        pair <int, string> tmp;
        tmp.second = front;
        tmp.first = -findMin(front);
        p.push_back(tmp);
        for (int i=0; i<10; i++){
            std::next_permutation(front.begin(), front.end());
            std::prev_permutation(back.begin(), back.end());
            tmp.second = front; 
            tmp.first = -findMin(front);
            p.push_back(tmp);
            tmp.second = back; 
            tmp.first = -findMin(back);
            p.push_back(tmp);
        }
        std:: sort(p.begin(), p.end());
        cout << p[0].second << -p[0].first <<endl;
    }
    return 0;
}