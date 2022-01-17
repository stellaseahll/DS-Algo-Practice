#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxSubarray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> maxSubarray(vector<int> arr) {
    vector<int> c(2,0);
    int largestNegative = -1000000;
    bool isPositive = true;
    vector<int> possibleSum;
    int currIdx = 0;
    int currSum = 0;
    stack<int> possible;
    
    for (int j = 0; j < arr.size(); j++){
        if (arr[j]<=0){
            if (arr[j]>largestNegative){
                largestNegative = arr[j];
            }
        }
        else{
            c[1]+=arr[j];
        }
    }
    if (c[1]<=0){ 
        c[1] = largestNegative; 
        c[0] = largestNegative;
        return c;
    }
    
    for (int j = 0; j < arr.size(); j++){ // find first positive
        if (arr[j]>0){
            currIdx = j; 
            break;
        }
    }
    for (int j = currIdx; j < arr.size(); j++){
        if ((isPositive && arr[j]<0) || (!isPositive && arr[j]>0)){
            isPositive = !isPositive;
            if (arr[j]<0){
                possible.push(currSum);
            }
            else if (arr[j]>0){
                if (currSum<0){
                    currSum = 0;
                }
            }
        }
        currSum += arr[j];
    }
    if (arr[arr.size()-1]>=0){
        possible.push(currSum);
    }
    int maximum = -1000000;
    while (!possible.empty()){
        if (possible.top()>maximum){
            maximum = possible.top();            
        }
        possible.pop();
    }
    c[0] = maximum;
    
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = maxSubarray(arr);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
