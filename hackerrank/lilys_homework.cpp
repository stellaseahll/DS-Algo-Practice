#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 void printArr(vector<int> arr){
     for (int j = 0; j < arr.size(); j++){
         cout << arr[j] << " ";
     }
     cout << endl << endl;
 }

int lilysHomework(vector<int> arr) {
    priority_queue<pair<int,int>> pq, pq2;
    vector<int> position(arr.size(),0),position2(arr.size(),0);
    for (int j = 0; j < arr.size(); j++){
        pair<int,int> p(-arr[j],j);
        pq.push(p);
        pair<int,int> p2(arr[j],j);
        pq2.push(p2);
    }
    for (int j = 0; j < arr.size(); j++){
        position[pq.top().second] = j - pq.top().second;
        pq.pop();   
        position2[pq2.top().second] = j - pq2.top().second;
        pq2.pop();        
    }
    int count = 0;
    int k = 0;
    while (k<arr.size()){
        if (position[k] == 0){
            k++;
            continue;
        }
        // printArr(position);
        int tmp = position[k+position[k]] + position[k];
        position[k+position[k]] = 0;
        position[k] = tmp;
        if (position[k] == 0){
            k++;
        }
        count++;
        // printArr(position);
    }
    int count2 = 0;
    k = 0;
    while (k<arr.size()){
        if (position2[k] == 0){
            k++;
            continue;
        }
        // printArr(position);
        int tmp = position2[k+position2[k]] + position2[k];
        position2[k+position2[k]] = 0;
        position2[k] = tmp;
        if (position2[k] == 0){
            k++;
        }
        count2++;
        // printArr(position);
    }

    return (count<count2)?count:count2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int result = lilysHomework(arr);

    fout << result << "\n";

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
