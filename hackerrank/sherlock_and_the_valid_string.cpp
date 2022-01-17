#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    // 97
    int freqTable[26];
    map<int,int> m;
    memset(freqTable,0,sizeof(freqTable));
    for (int j = 0; j < s.length(); j++){
        freqTable[s[j]-97]++;
    }
    for (int j = 0; j < 26; j++){
        int c = freqTable[j];
        if (c==0){
            continue;
        }
        if (m.count(c)==0){
            m[c] = 1;
        }
        else{
            m[c]++;
        }
    }
    map<int,int>::iterator it;
    if (m.size()==1){
        return "YES";
    }
    if (m.size()>2){
        return "NO";
    }
    int j = 0;
    int freqKey[2], number[2];
    int first,second,countFirst,countSecond;
    for (it=m.begin(); it!=m.end(); it++){
        freqKey[j] = it->first;
        number[j] = it->second;
        j++;
    }  
    if (freqKey[0]<freqKey[1]){
        first = freqKey[0];
        second = freqKey[1];
        countFirst = number[0];
        countSecond = number[1];
    }
    else{
        first = freqKey[1];
        second = freqKey[0];
        countFirst = number[1];
        countSecond = number[0];
    }
    if (first == 1 && countFirst == 1){//aaaabbbbcccc... x
        return "YES";
    }
    if (second-first>1){
        return "NO";
    }

    if (second != first+1){
        return "NO";
    }
    if (countSecond != 1){
        return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
