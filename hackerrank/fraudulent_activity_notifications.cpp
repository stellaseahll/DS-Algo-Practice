#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */
typedef pair<int,int> ii;
int getMedian(const set<ii>& left, const set<ii>& right, int d){
    ii rightP = *(right.begin());
    if (d%2==0){
        ii leftP = *(--left.end());
        return (leftP.first+rightP.first);
    }
    return rightP.first*2;
}
int activityNotifications(vector<int> expenditure, int d) {
    
    int notice = 0;
    set<ii> left, right;
    vector<ii> tmp;
    for (int j = 0; j < d; j++){
        tmp.push_back(ii(expenditure[j],j));
    }
    sort(tmp.begin(),tmp.end());
    for (int j = 0; j < d/2; j++){
        left.insert(tmp[j]);
    }
    for (int j = d/2; j < d; j++){
        right.insert(tmp[j]);
    }
    int count = 0;
    
    for (int j = d; j < expenditure.size(); j++){
        int currMedian = getMedian(left, right, d);
        if (expenditure[j]>=currMedian){count++;}
        ii last(expenditure[j-d],j-d);
        set<ii>::iterator itL=left.find(last),itR=right.find(last);
        // cout << (*(itL)).first << " " << (*(itL)).second << endl;
        bool isDeleteLeft = true;
        if (left.count(last) != 0){
            left.erase(left.find(last));
        }
        else{
            isDeleteLeft = false;
            right.erase(right.find(last));
        }
        ii largestLeft, smallestRight;
        if (!left.empty()){
            largestLeft = *(--left.end());
        }
        else{
            largestLeft = ii(-10000,0);
        }
        if (!right.empty()){
            smallestRight = *(right.begin());
        }
        else{
            smallestRight = ii(1000000,0);
        }
        if (expenditure[j] <= largestLeft.first && isDeleteLeft){
            left.insert(ii(expenditure[j],j));
        }
        else if (expenditure[j] >= smallestRight.first && !isDeleteLeft){
            right.insert(ii(expenditure[j],j));
        }
        else if (expenditure[j] <= largestLeft.first && !isDeleteLeft){
            right.insert(*(--left.end()));
            left.erase(--left.end());
            left.insert(ii(expenditure[j],j));
        }
        else{
            left.insert(*(right.begin()));
            right.erase(right.begin());
            right.insert(ii(expenditure[j],j));
        }
     
    }
        
    return count;
}
// int activityNotifications(vector<int> expenditure, int d) {
//     priority_queue<pair<int,int>> pq;
//     if (d == expenditure.size()){return 0;}
//     for (int j = 0; j < d; j++){
//         pq.push(pair<int,int>(expenditure[j],j));
//     }
//     int numToPop = (d%2==0) ? (d-2)/2 : (d-1)/2;
//     int numToSum = (d%2==0) ? 2 : 1;
//     int currIdx = d;
//     int notice = 0;
//     while (currIdx < expenditure.size()){
//         int count = 0;
//         priority_queue<pair<int,int>> tmpPQ;
//         while (count < numToPop){
//             pair<int,int> p;
//             p = pq.top();
//             pq.pop();
//             if (p.second < currIdx-d){
//                 continue;
//             }
//             else{
//                 count++;
//                 tmpPQ.push(p);
//             }
//         }
//         count = 0;
//         int median = 0;
//         while (count < numToSum){
//             pair<int,int> p;
//             p = pq.top();
//             pq.pop();
//             if (p.second < currIdx-d){
//                 continue;
//             }
//             else{
//                 count++;
//                 median += p.first;
//                 tmpPQ.push(p);
//             }
//         }
//         if (numToSum == 1) {median = median*2;}
//         if (expenditure[currIdx] >= median){
//             notice++;
//         }
//         pq.push(pair<int,int>(expenditure[currIdx],currIdx));
//         currIdx++;
//         while (!tmpPQ.empty()){
//             pq.push(tmpPQ.top());
//             tmpPQ.pop();
//         }
//     }
        
//     return notice;
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
