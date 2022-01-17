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


int main(){
    int N; 
    cin >> N;
    int arr[N][N];
    memset(arr, 0, sizeof(arr));
    for (int j = 0; j < N ; j++){
        for (int k = 0; k < N; k++){
            scanf("%d",&arr[j][k]);
            if (j>0) {arr[j][k] += arr[j-1][k];} // cumulative sum of row
            if (k>0) {arr[j][k] += arr[j][k-1];} // cumulative sum of col
            if (j>0 && k>0) {arr[j][k] -= arr[j-1][k-1];} // subtract off double count }
        }
    }
    int maxSum = -1000000000;
    for (int j = 0; j < N; j++){ // j and k are start coordinates
        for (int k = 0; k < N; k++){
            for (int m = j; m < N; m++){ // m and n are end coordinates
                for (int n = k; n <N; n++){
                    int subRect = arr[m][n];
                    if (j > 0) {subRect -= arr[j-1][n];}
                    if (k > 0) {subRect -= arr[m][k-1];}
                    if (j > 0 && k > 0) {subRect += arr[j-1][k-1];}
                    maxSum = (subRect > maxSum) ? subRect : maxSum;
                }
            }
        }
    }
    cout << maxSum << endl;

    return 0;
}