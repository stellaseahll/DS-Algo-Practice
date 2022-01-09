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
#define MAX 1000
using namespace std;

int main()
{
    int G, Q;
    int ss, max, rank;
    int maxScore;
    scanf("%d%d", &G, &Q);
    while (!(G==0&&Q==0)){
        int result[G][Q];
        for (int i=0; i<G; i++){
            for (int j=0; j<Q; j++){
                result[i][j]=0;
            }
        }
        for (int i=0; i<G; i++){
            for (int j=0; j<Q; j++){
                scanf("%d", &result[i][j]);
                result[i][j]--;
            }
        }
        scanf("%d", &ss);
        for (int i=0; i<ss; i++){
            int player[Q];
            for (int i=0; i<Q; i++){
                player[i]=0;
            }
            scanf("%d", &max);
            int score[max];
            for (int j=0; j<max; j++){
                scanf("%d", &score[j]);
            }
            for (int j=0; j<Q; j++){
                for (int k=0; k<G; k++){
                    rank=result[k][j];
                    if (rank<max)
                        player[j]+=score[rank];
                }
            }
            maxScore=player[0];
            int idx=0;
            for (int j=1; j<Q; j++){
                if (maxScore<player[j]){
                    maxScore=player[j];
                    idx=j;
                }
            }
            printf("%d",idx+1);
            for (int j=idx+1; j<Q; j++){
                if (player[j]==maxScore)
                    printf(" %d",j+1);
            }
            printf("\n");
        }
        scanf("%d%d", &G, &Q);
    }

    return 0;
}