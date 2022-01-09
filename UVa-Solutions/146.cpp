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

int main()
{
    string str;
    cin >> str;
    while (str  !=  "#"){
        if (std:: next_permutation(str.begin(), str.end()))
            cout <<str<<endl;
        else
            cout<<"No Successor"<<endl;
        cin>>str;
    }
    return 0;
}