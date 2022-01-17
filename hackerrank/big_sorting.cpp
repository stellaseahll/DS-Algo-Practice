#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */
bool isFirstSmaller(string s1, string s2){
    if (s1.length()<s2.length()){
        return true;
    }
    else if (s1.length()>s2.length()){
        return false;
    }
    if (s1 == s2){return true;}
    for (int j = 0; j < s1.length(); j++){
        if (s1[j]>s2[j]){
            return false;
        }
        else if (s1[j]<s2[j]){
            return true;
        }
    }
    return true; // if equal
}
void merge(int left, int mid, int right, vector<string>& arr){
    int leftSize = mid-left+1;
    int rightSize = right-mid;
    vector<string> leftArray, rightArray;
    leftArray.insert(leftArray.end(), arr.begin()+left,arr.begin()+mid+1);
    rightArray.insert(rightArray.end(), arr.begin()+mid+1,arr.begin()+right+1);
    int leftIdx = 0; 
    int rightIdx = 0;
    int currIdx = left;
    vector<string> tmp;
    while (leftIdx < leftSize && rightIdx < rightSize){
        if (isFirstSmaller(leftArray[leftIdx],rightArray[rightIdx])){
            arr[currIdx++] = leftArray[leftIdx++];
        }
        else{
            arr[currIdx++] = rightArray[rightIdx++];
        }
    }
    while (leftIdx < leftSize){
        arr[currIdx++] = leftArray[leftIdx++];
    }
    while (rightIdx < rightSize){
        arr[currIdx++] = rightArray[rightIdx++];
    }
    return;
}

void mergeSort(int left, int right, vector<string>& arr){
    if (left >= right){
        return;
    }
    int mid = (left+right)/2;
    mergeSort(left,mid,arr);
    mergeSort(mid+1,right,arr);
    merge(left,mid,right,arr);
}


vector<string> bigSorting(vector<string> unsorted) {
    mergeSort(0,unsorted.size()-1,unsorted);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

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
