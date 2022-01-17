#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    stack<int> stack1,stack2;
    int n; 
    cin >> n;
    for (int j = 0; j < n; j++){
        int type; 
        cin >> type;
        if (type == 1){
            int x;
            cin >> x;
            if (stack1.empty()){
                stack1.push(x);
            }
            else{
                stack2.push(x);
            }
            
        }
        else if (type == 2){
            stack1.pop();
            if (stack1.empty()){
                while (!stack2.empty()){
                    stack1.push(stack2.top());
                    stack2.pop();
                }
            }
        }
        else{
            cout << stack1.top() << endl;
        }
    }
    return 0;
}
