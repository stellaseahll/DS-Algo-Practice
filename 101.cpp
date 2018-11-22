#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
vector<stack<int> > out;
map<int, int> mymap;
void moveOnto(int a, int b){
    map<int,int>::iterator itA, itB, itTmp;
    int A,B;
    int c;
    itA = mymap.find(a);
    itB = mymap.find(b);
    A = itA -> second;
    B = itB -> second;
    if (A==B)
        return;
    itA ->second = B;
    while (out[A].top()!=a){
        c=out[A].top();
        itTmp = mymap.find(c);
        itTmp->second = c;
        out[c].push(c);
        out[A].pop();
    }
    while (out[B].top()!=b){
        c=out[B].top();
        itTmp = mymap.find(c);
        itTmp->second = c;
        out[c].push(c);
        out[B].pop();
    }
    out[B].push(a);
    out[A].pop();
    return;
}

void moveOver(int a, int b){
    map<int,int>::iterator itA, itB, itTmp;
    int A,B;
    int c;
    itA = mymap.find(a);
    itB = mymap.find(b);
    A = itA -> second;
    B = itB -> second;
    if (A==B)
        return;
    itA ->second = B;
    out[B].push(a);
    while (out[A].top()!=a){
        c=out[A].top();
        itTmp = mymap.find(c);
        itTmp->second = c;
        out[c].push(c);
        out[A].pop();
    }
    out[A].pop();
    return;
}

void pileOnto(int a, int b){
    map<int,int>::iterator itA, itB, itTmp;
    stack<int> stackA, stackB;
    int A,B, c;
    itA = mymap.find(a);
    itB = mymap.find(b);
    A = itA -> second;
    B = itB -> second;
    if (A==B)
        return;
    itA ->second = B;
    while (out[A].top()!=a){
        stackA.push(out[A].top());
        out[A].pop();
    }
    while (out[B].top()!=b){
        c=out[B].top();
        itTmp = mymap.find(c);
        itTmp->second = c;
        out[c].push(c);
        out[B].pop();
    }
    out[B].push(a);
    out[A].pop();
    while (!stackA.empty()){
        out[B].push(stackA.top());
        itTmp = mymap.find(stackA.top());
        itTmp -> second = B;
        stackA.pop();
    }
    return;
}

void pileOver(int a, int b){
    map<int,int>::iterator itA, itB, itTmp;
    stack<int> stackA;
    int A,B;
    itA = mymap.find(a);
    itB = mymap.find(b);
    A = itA -> second;
    B = itB -> second;
    if (A==B)
        return;
    itA ->second = B;
    while (out[A].top()!=a){
        stackA.push(out[A].top());
        out[A].pop();
    }
    out[B].push(a);
    out[A].pop();
    while (!stackA.empty()){
        out[B].push(stackA.top());
        itTmp = mymap.find(stackA.top());
        itTmp -> second = B;
        stackA.pop();
    }
    return;
}

int main()
{
    int n;
    string str1, str2;
    int a, b;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        stack<int> tmp;
        tmp.push(i);
        out.push_back(tmp);
        mymap.insert (std::pair<int,int>(i,i));
    }
    cin>>str1;
    while (str1!="quit"){
        cin>>a>>str2>>b;
        if (str1=="move" && str2=="onto")
            moveOnto(a,b);
        else if (str1=="move" && str2=="over")
            moveOver(a,b);
        else if (str1=="pile" && str2=="onto")
            pileOnto(a,b);
        else if (str1=="pile" && str2=="over")
            pileOver(a,b);
        cin>>str1;
    }
    for (int i=0; i<n; i++){
        printf("%d:", i);
        stack<int> stackTmp;
        while (!out[i].empty()){
            stackTmp.push(out[i].top());
            out[i].pop();
        }
        while (!stackTmp.empty()){
            printf(" %d", stackTmp.top());
            stackTmp.pop();
        }
        printf("\n");
    }
    return 0;

}
