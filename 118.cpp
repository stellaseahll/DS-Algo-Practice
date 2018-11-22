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

int currX, currY;
int maxX, maxY;
int lost[51][51];
int charToNum(char d){
    if (d == 'N') return 10000;
    if (d == 'E') return 10001;
    if (d == 'S') return 10002;
    if (d == 'W') return 10003;
    return 0;
}

char numToChar(int x){
    while (x < 0) x += 10000;
    if (x%4 == 0) return 'N';
    if (x%4 == 1) return 'E';
    if (x%4 == 2) return 'S';
    if (x%4 == 3) return 'W';
    return 'X';
}

int canMove(int d){
    if (d%4 == 0){
        if (currY == maxY) {
            if (!lost[currX][currY]) return 0;
            return 1;
        }
        currY++;
        return 1;
    }
    if (d%4 == 1){

        if (currX == maxX) {
            if (!lost[currX][currY]) return 0;
            return 1;
        }
        currX++;
        return 1;
    }
    if (d%4 == 2){
        if (currY == 0) {
            if (!lost[currX][currY]) return 0;
            return 1;
        }
        currY--;
        return 1;
    }
    if (d%4 == 3){
        if (currX == 0) {
            if (!lost[currX][currY]) return 0;
            return 1;
        }
        currX--;
        return 1;
    }
    return 1;
}
int main()
{
   
    string str;
    scanf("%d%d\n", &maxX, &maxY);
    memset(lost, 0, sizeof(lost));
    while (getline(cin, str)){
        istringstream iss(str);
        char d;
        int isLost = 0;
        iss >> currX >> currY >> d;
        int dir = charToNum(d);
        getline(cin, str);
        for (int i = 0; i < str.length(); i++){
            if (str[i] == 'R') dir++;
            else if (str[i] == 'L') dir--;
            else if (!canMove(dir)) {
                isLost = 1;
                lost[currX][currY] = 1;
                break; 
            }            
        }
        printf("%d %d %c", currX, currY, numToChar(dir));
        if (isLost) printf(" LOST\n");
        else printf("\n");
    }
    return 0;
}