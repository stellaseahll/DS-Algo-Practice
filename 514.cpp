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
#include <stack>
using namespace std;

int main()
{
    stack<int> A;
    stack<int> middle, t;
    stack<int> B;
    int n, tmp;
    scanf("%d", &n);
    while (n!=0){
        scanf("%d", &tmp);
        while (tmp != 0){
            for (int i=n; i>0; i--){
                A.push(i);
            }
            t.push(tmp);
            for (int i=1; i<n; i++){
                scanf("%d", &tmp);
                t.push(tmp);
            }
            for (int i=0; i<n; i++){
                B.push(t.top());
                t.pop();
            }
            while (!A.empty()){
                if (A.top() == B.top()){
                    A.pop();
                    B.pop();
                }
                else{
                    middle.push(A.top());
                    A.pop();
                }
            
            }

        }

    }
}