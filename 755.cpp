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
    int count;
    int n, c;
    string str;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>c;
        getline(cin,str);
        if (i>0){
            cout<<endl;
        }
        map<string,int> mymap;
        for (int j = 0; j<c; j++){
            getline(cin, str);
            string num="111-1111";
            count=0;
            for(int i=0;i<str.size();i++)
            {
                if(str[i]=='-'||str[i]==' ')
                    continue;
                else if (str[i]=='A'||str[i]=='B'||str[i]=='C'){
                    num[count++]='2';
                }
                else if (str[i]=='D'||str[i]=='E'||str[i]=='F'){
                    num[count++]='3';
                }
                else if (str[i]=='G'||str[i]=='H'||str[i]=='I'){
                    num[count++]='4';
                }
                else if (str[i]=='J'||str[i]=='K'||str[i]=='L'){
                    num[count++]='5';
                }
                else if (str[i]=='M'||str[i]=='N'||str[i]=='O'){
                    num[count++]='6';
                }
                else if (str[i]=='P'||str[i]=='R'||str[i]=='S'){
                    num[count++]='7';
                }
                else if (str[i]=='T'||str[i]=='U'||str[i]=='V'){
                    num[count++]='8';
                }
                else if (str[i]=='W'||str[i]=='X'||str[i]=='Y'){
                    num[count++]='9';
                }
                else{
                    num[count++]=str[i];
                }
                if (count==3) count++;
            }
            map<string,int>::iterator it;
            it = mymap.find(num);
            if (it != mymap.end()){
                it->second = it->second +1;
            }
            else{
                mymap.insert ( std::pair<string,int>(num,1));
            }
        }
        int hasDuplicate=0;
        for (std::map<string,int>::iterator k = mymap.begin(); k != mymap.end(); k++){
            if (k->second > 1){
                cout<<k->first<<" "<<k->second<<endl;
                hasDuplicate=1;
            }
        }
        if (!hasDuplicate){
            cout<<"No duplicates."<<endl;
        }  
    }   
    return 0;
}
