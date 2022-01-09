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
    int N, Q, tH, tM;
    char c, V, q;
    scanf("%d\n", &n);
    for (int k=0; k<n; k++){
        if (k!=0){
            printf("\n");
        }
        int problem[25][7];
        int team = -1;
        vector <vector <int> > data;
        vector< pair< pair <int, int>, int> > result;
        pair<int, int> p;
        p.first=0; 
        p.second=0; 
        pair< pair <int, int>, int> p2;
        p2.first = p;
        for (int i=0; i<25; i++){
            p2.second = i+1;
            result.push_back(p2);
            for (int j=0; j<7; j++){
                problem[i][j]=0;
            }
        }
        //printf("k = %d\n",k);
        //getline(cin, str);
        while (getline(cin, str) && str.length() != 0){
            istringstream iss;
            iss.str(str);
            iss >> N >> q >> tH >> c >> tM >> V;
            Q = q -'A';
            vector <int> vtmp;
            vtmp.push_back(tH*60 + tM);
            vtmp.push_back(N-1);
            vtmp.push_back(Q);
            if (V == 'Y')
                vtmp.push_back(1);
            else
                vtmp.push_back(0);
            team = (team > N) ? team : N;
            data.push_back(vtmp);
        }
        sort(data.begin(), data.end());

        for (int i=0; i<data.size(); i++){
            //cout<<N<<" "<<Q<<" "<<tH<<" "<< c<<" "<< tM<<" "<<V<<endl;
            if (data[i][3] && problem[data[i][1]][data[i][2]] <= 0){
                result[data[i][1]].first.second += data[i][0] - problem[data[i][1]][data[i][2]]*20;
                result[data[i][1]].first.first --;

                //cout<<"check: "<<result[N-1].first.first<<" "<<result[N-1].first.second<<endl;
                problem[data[i][1]][data[i][2]]=1;
            }
            else if (data[i][3] == 0){
                problem[data[i][1]][data[i][2]]--;
            }
        }
        std:: sort(result.begin(), result.end());
        printf("RANK TEAM PRO/SOLVED TIME\n");
        int rank=0;
        int i=0;
        
        while (i<team){
            if (i == 0){
                rank++;
                if (result[i].first.first == 0)
                    printf("%4d %4d\n", rank, result[i].second);
                else
                    printf("%4d %4d %4d %10d\n", rank, result[i].second, -result[i].first.first, result[i].first.second);
            }
            else{
                if (result[i].first.first != result[i-1].first.first || result[i].first.second != result[i-1].first.second){
                    rank=i+1;
                }
                if (result[i].first.first == 0)
                    printf("%4d %4d\n", rank, result[i].second);
                else
                    printf("%4d %4d %4d %10d\n", rank, result[i].second, -result[i].first.first, result[i].first.second);
            }  
            i++;
        }

    }
   
}