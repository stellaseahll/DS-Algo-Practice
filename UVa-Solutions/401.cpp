#include <vector>
#include <iostream>
#include <istream>
#include <queue>
#include <sstream>
#include <set>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h>
#define INF 1000000
using namespace std;
typedef pair<int,int> ii;

bool isPalindrome(string s){
    for (int j = 0; j < s.length()/2; j++){
        if (s[j] != s[s.length()-1-j]){return false;}
    }
    return true;
}

bool isMirrorString(string s){
    char mirrorChar[] = {'A','E','H','I','L','J','M','O','S','T','U','V','W','X','Y','Z','0','1','2','3','5','8'};
    set<char> mirrorSet(mirrorChar,mirrorChar+22);
    for (int j = 0; j < s.length()/2; j++){
        if (mirrorSet.count(s[j]) == 0){
            return false;
        }
        if (s[j] != 'E' && s[j] != '3' && s[j] != 'J' && s[j] != 'L' && s[j] != 'S' && s[j] != '2' && s[j] != '5' && s[j] != 'Z' && s[j] != s[s.length()-1-j]){
            return false;
        }
        if ((s[j] == 'E' && s[s.length()-1-j] != '3' ) || ( s[j] == '3' && s[s.length()-1-j] != 'E')){
            return false;
        }
        if ((s[j] == 'J' && s[s.length()-1-j] != 'L' ) || ( s[j] == 'L' && s[s.length()-1-j] != 'J')){
            return false;
        }
        if ((s[j] == 'S' && s[s.length()-1-j] != '2') || (s[j] == '2' && s[s.length()-1-j] != 'S')){
            return false;
        }
        else if ((s[j] == 'Z' && s[s.length()-1-j] != '5') || (s[j] == '5' && s[s.length()-1-j] != 'Z')){
            return false;
        }
    }
    if (s.length()%2 == 1) {
        if (mirrorSet.count(s[s.length()/2]) == 0) {return false;}
        if (s[s.length()/2] == 'E' || s[s.length()/2] == '3' || s[s.length()/2] == 'L' || s[s.length()/2] == 'J' || s[s.length()/2] == '2' || s[s.length()/2] == 'S' || s[s.length()/2] == '5' || s[s.length()/2] == 'Z'){
            return false;
        }
    }
    return true;
}

string mirror(string s){
    for (int j = 0; j < s.length()/2; j++){
        if (s[j] == '3'){
            s[j] = 'E';
        }
        else if (s[j] == '2'){
            s[j] = 'S';
        }
        else if (s[j] == '5'){
            s[j] = 'Z';
        }
        else if (s[j] == 'L'){
            s[j] = 'J';
        }
        else if (s[j] == 'J'){
            s[j] = 'L';
        }
        else if (s[j] == 'Z'){
            s[j] = '5';
        }
        else if (s[j] == 'S'){
            s[j] = '2';
        }
        else if (s[j] == 'E'){
            s[j] = '3';
        }
    }
    return s;
}

bool isAllMirror(string s){
    char mirrorChar[] = {'A','E','H','I','L','J','M','O','S','T','U','V','W','X','Y','Z','0','1','2','3','5','8'};
    set<char> mirrorSet(mirrorChar,mirrorChar+22);
    for (int j = 0; j < s.length(); j++){
        if (mirrorSet.count(s[j]) == 0){
            return false;
        }
    } 
    return true;
}

int main(){
    string s;
    while (getline(cin,s)){
        string mirrorStr = mirror(s);       
        if (isMirrorString(s)){
            if (isPalindrome(s)){
                cout << s << " -- is a mirrored palindrome.\n" << endl;
            }
            else{
                cout << s << " -- is a mirrored string.\n" << endl;
            }
            continue;
        }
        if (isPalindrome(s)){
            cout << s << " -- is a regular palindrome.\n" << endl;
        }
        else{
            cout << s << " -- is not a palindrome.\n" << endl;
        }
    }
    return 0;
}