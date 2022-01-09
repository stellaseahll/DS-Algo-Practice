#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
#include <cstdlib> // for atoi
#include <sstream>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str)){
        std::list<char> s;
        std::list<char>::iterator it;
        it = s.begin();
        for (int i=0; i<str.length(); i++){
            if (str[i]=='['){
                it = s.begin();
            }
            else if (str[i]==']'){
                it = s.end();
            }
               
            else{
                s.insert(it, str[i]);
            }
            
        }
        for (it = s.begin(); it != s.end(); it++){
            cout<<*it;
        }
        printf("\n");
    }
   
}