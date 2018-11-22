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

using namespace std;
bool compareString (string i, string j){
    if (i.length() == j.length())
        return (i > j);
    string ij, ji;
    ij = i+j;
    ji = j+i;
    return (ij > ji);

}
int main()
{
    int n; 
    scanf("%d", &n);
    string str;
    while (n != 0){
        vector<string> p;
        for (int i = 0; i < n; i++){
            cin>>str;
            p.push_back(str);
        }
        std:: sort(p.begin(), p.end(), compareString);
        for (int i=0; i<p.size(); i++){
            cout<<p[i];
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}