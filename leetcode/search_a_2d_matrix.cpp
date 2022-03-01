class Solution {
public:
    int searchMatrixRow(vector<vector<int>>& matrix, int totalCol, int target, int startRow, int endRow) {
        if (target > matrix[endRow][totalCol-1]){return endRow+1;}
        if (target <= matrix[startRow][totalCol-1]) {return startRow;}
        int midRow = (startRow + endRow)/2;
        if (target <= matrix[midRow][totalCol-1]){
            return searchMatrixRow(matrix, totalCol, target, startRow+1, midRow);
        }
        return searchMatrixRow(matrix, totalCol, target, midRow+1, endRow);
    } 
    bool searchCol(const vector<int>& arr, int left, int right, int target){
        if (right < left){return false;}
        if (arr[left] == target || arr[right] == target){return true;}
        if (right - left <= 1) {return false;}
        int mid = (left + right)/2;
        if (arr[mid] == target){return true;}
        if (arr[mid] < target){
            return searchCol(arr,mid+1,right,target);
        }
        return searchCol(arr,left,mid-1,target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalRow = matrix.size();
        int totalCol = matrix[0].size();
        int row = searchMatrixRow(matrix, totalCol, target, 0, totalRow-1);
        if (row == totalRow){return false;}
        return searchCol(matrix[row],0,totalCol-1,target);
    }
};