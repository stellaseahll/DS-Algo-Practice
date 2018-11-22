#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <map>
#include <string.h>
#include <utility>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str)){
        char prev;
        for(int i=0;i<str.size();i++)
        {
            if (i==0)
                prev='0';
            else
                prev=str[i-1];
            if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='H'||str[i]=='W'||str[i]=='Y')
                continue;
            else if (str[i]=='B'||str[i]=='F'||str[i]=='P'||str[i]=='V'){
                if (prev=='B'||prev=='F'||prev=='P'||prev=='V')
                    continue;
                else
                    printf("1");
            }
            else if (str[i]=='C'||str[i]=='G'||str[i]=='J'||str[i]=='K'||str[i]=='Q'||str[i]=='S'||str[i]=='X'||str[i]=='Z'){
                if (prev=='C'||prev=='G'||prev=='J'||prev=='K'||prev=='Q'||prev=='S'||prev=='X'||prev=='Z')
                    continue;
                else
                    printf("2");
            }
            else if (str[i]=='D'||str[i]=='T'){
                if (prev=='D'||prev=='T')
                    continue;
                else
                    printf("3");
            }
            else if (str[i]=='L'){
                if (prev=='L')
                    continue;
                else
                    printf("4");
            }
            else if (str[i]=='M'||str[i]=='N'){
                if (prev=='M'||prev=='N')
                    continue;
                else
                    printf("5");
            }
            else if (str[i]=='R'){
                if (prev=='R')
                    continue;
                else
                    printf("6");
            }
        }
        printf("\n");
    }
   
    return 0;
}
