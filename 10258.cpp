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
using namespace std;

int main()
{
    string str;
    int n;
    int N, Q, T;
    char R;
    scanf("%d\n\n", &n);
    for (int k=0; k<n; k++){
        if (k!=0){
            printf("\n");
        }
        int problem[100][9];
        int time_taken[100];
        int problem_solved[100];
        for (int i = 0; i < 100; i++){
            time_taken[i] = -1;
            problem_solved[i] = 0;
            for (int j = 0; j < 9; j++){
                problem[i][j]=0;
            }
        }
        vector <vector <int> > data;
         while (getline(cin, str) && str.length() != 0){
            istringstream iss;
            iss.str(str);
            iss >> N >> Q >> T >> R;
            N--; 
            Q--;
            vector <int> vtmp;
            vtmp.push_back(T);
            vtmp.push_back(N);
            vtmp.push_back(Q);
            if (R == 'C')
                vtmp.push_back(1);
            else if (R == 'I')
                vtmp.push_back(0);
            else
                vtmp.push_back(-1);
            data.push_back(vtmp);
        }
        sort(data.begin(), data.end());
        for (int i=0; i<data.size(); i++){
            if (time_taken[data[i][1]] == -1)
                time_taken[data[i][1]] = 0;
            if (data[i][3] == -1)
                continue;
            if (data[i][3] == 1 && problem[data[i][1]][data[i][2]] >= 0){
                problem_solved[data[i][1]]--;
                time_taken[data[i][1]] += data[i][0] + problem[data[i][1]][data[i][2]]*20;
                problem[data[i][1]][data[i][2]] = -1000;
            }
            else if (data[i][3] == 0){
                problem[data[i][1]][data[i][2]]++;
            }
        }
        vector< pair< pair <int, int>, int> > result;
        pair<pair <int, int>, int> p;
        for (int i=0; i<100; i++){
            if (time_taken[i] == -1)
                continue;
            p.first.first = problem_solved[i];
            p.first.second = time_taken[i];
            p.second = i+1;
            result.push_back(p);
        }
        std:: sort(result.begin(), result.end());
        for (int i=0; i<result.size(); i++){
            printf("%d %d %d\n", result[i].second, -result[i].first.first, result[i].first.second);
        }
    }
   
}