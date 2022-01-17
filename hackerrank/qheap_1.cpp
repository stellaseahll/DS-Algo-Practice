#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    vector<int> heap;
    int number;
    cin >> number;
    for (int j = 0; j<number; j++){
        int type;
        cin >> type;
        if (type == 1){
            int value; 
            cin >> value;
            if (heap.size()==0){
                heap.push_back(value);
            }
            else{
                int idx=heap.size();
    
                for (int k=0; k<heap.size(); k++){
                    if (value < heap[k]){
                        idx = k;
                        break;
                    }
                }
                heap.insert(heap.begin()+idx,value);
            }
        }
        else if (type == 2){
            int value;
            cin >> value;
            int idx;
            for (int k=0; k<heap.size(); k++){
                if (value == heap[k]){
                    idx = k;
                    break;
                }
            }
            heap.erase(heap.begin()+idx);
        }
        else if (type == 3){
            cout << heap[0] << endl;
        }
    
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


// int main() {
//     priority_queue<int> heap;
//     int number;
//     cin >> number;
//     for (int j = 0; j<number; j++){
//         int type;
//         cin >> type;
//         if (type == 1){
//             int value; 
//             cin >> value;
//             heap.push(-value);
//         }
//         else if (type == 2){
//             int value;
//             cin >> value;
//             priority_queue<int> tmp;
//             while (!heap.empty()){
//                 if (heap.top()==-value){
//                     heap.pop();
//                     continue;
//                 }
//                 tmp.push(heap.top());
//                 heap.pop();
//             }
//             heap = tmp;
//         }
//         else if (type == 3){
//             cout << -heap.top() << endl;
//         }
//     }
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     return 0;
// }
