#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   stack<string> sequence;
    sequence.push("");
    int n ;
    cin >> n;
    for (int j = 0; j < n; j++){
        int type;
        cin >> type;
        if (type == 1){
            string tmp;
            cin >> tmp;
            sequence.push(sequence.top()+tmp);
        }
        else if (type == 2){
            string tmp = sequence.top();
            int x;
            cin >> x;
            sequence.push(tmp.substr(0,tmp.length()-x));
        }
        else if (type == 3){
            string tmp = sequence.top();
            int x;
            cin >> x;
            cout << tmp[x-1] << endl;
        }
        else{
            sequence.pop();
        }
        
    }
    
    return 0;
}
