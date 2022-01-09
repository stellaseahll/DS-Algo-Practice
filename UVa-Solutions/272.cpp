#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

int main()
{
    char str[200000];
    long count;
    while(gets(s))
    {
    	count=0;
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='"')
            {
                count++;
                if(p%2)
                	printf("``");
                else
                	printf("''");
            }
            else
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
