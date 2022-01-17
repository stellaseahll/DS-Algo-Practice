#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */

void printDeque(deque<pair<int,int>> q){
    cout << "queue : ";
    while (!q.empty()){
        cout << q.front().first << " ";
        q.pop_front();
    }
    cout << endl;
}
void printArr(vector<int> arr){
    for (int j = 0 ; j < arr.size();  j++){
        cout << arr[j] << " ";
    }
    cout << endl;
    return;
}
vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> answer;

    for (int j = 0; j < queries.size(); j++){
        int currSize = queries[j];
        pair<int,int> p;
        deque<pair<int,int>> q;
        vector<int> allMax;
        for (int k = 0; k < currSize; k++){
            pair<int,int> p(arr[k],k);
            while(!q.empty() && q.back().first <= arr[k]){
                q.pop_back();
            }
            q.push_back(p);
        }
        allMax.push_back(q.front().first);
        for (int k = currSize; k < arr.size(); k++){
            while (!q.empty() && q.front().second <= k-currSize){
                q.pop_front();
            }
            while (!q.empty() && q.back().first <= arr[k]){
                q.pop_back();
            }
            pair<int,int> p2(arr[k],k);
            q.push_back(p2);
            allMax.push_back(q.front().first);
            
        }
        int currMin = allMax[0];
        for (int k = 1; k < allMax.size(); k++){
            if (allMax[k] < currMin){
                currMin = allMax[k];
            }
        }
        answer.push_back(currMin);
    }    
    return answer;

}
// vector<int> solve(vector<int> arr, vector<int> queries) {
//     vector<int> answer;
//     for (int j = 0; j < queries.size(); j++){
//         int size = queries[j];
//         priority_queue<pair<int,int>> pq;
//         for (int k = 0; k<size; k++){
//             pair<int,int> p(arr[k],k);
//             pq.push(p);
//         }
//         vector<int> allMax;
//         for (int k = size; k<arr.size(); k++){
//             allMax.push_back(pq.top().first);
//             pair<int,int> p(arr[k],k);
//             pq.push(p);
//             while ((pq.top().second)<= k-size){
//                 pq.pop();
//             }
//         }
//         allMax.push_back(pq.top().first);
//         // printArr(allMax);
//         sort(allMax.begin(),allMax.end());
//         answer.push_back(allMax[0]);
//     }
//     return answer;
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
