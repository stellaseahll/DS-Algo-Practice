#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    deque<char> dqFront, dqBack;
    for (int j = 0; j < s.size(); j++){
        dqBack.push_back(s[j]);
    }
    while (!dqBack.empty()){
        char curr = dqBack.front();
        dqBack.pop_front();
        if (!dqFront.empty() && dqFront.back() == curr){
            dqFront.pop_back();
        }
        else{
            dqFront.push_back(curr);
        }
    }
    string ans = "";
    while (!dqFront.empty()){
        ans += dqFront.front();
        dqFront.pop_front();
    }
    if (ans.size()==0) {return "Empty String";}
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
