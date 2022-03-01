class Solution {
    int totalRow;
    int totalCol;
public:
    
    int lowerBoundCol(vector<vector<int>>& matrix, int target, int sCol, int eCol, int row){
        if (sCol > eCol){return sCol;}
        int mCol = (sCol + eCol)/2;
        if (matrix[row][mCol] >= target){
            return lowerBoundCol(matrix,target,sCol,mCol-1,row);
        }
        return lowerBoundCol(matrix,target,mCol+1,eCol,row);
    }
    
    int lowerBoundRow(vector<vector<int>>& matrix, int target, int sRow, int eRow, int col){
        if (sRow > eRow){return sRow;}
        int mRow = (sRow+eRow)/2;
        if (matrix[mRow][col] >= target){
            return lowerBoundRow(matrix,target,sRow,mRow-1,col);
        }
        return lowerBoundRow(matrix,target,mRow+1,eRow,col);
    }
    bool search(vector<vector<int>>& matrix, int target, int sRow, int eRow, int sCol, int eCol){
        if (sRow > eRow || sCol > eCol){return false;}
        if (target > matrix[eRow][eCol]){return false;}
        if (target < matrix[sRow][sCol]){return false;}
        if (matrix[sRow][sCol] == target){return true;}
        if (matrix[sRow][eCol] == target){return true;}
        if (matrix[eRow][sCol] == target){return true;}
        if (matrix[eRow][eCol] == target){return true;}
        int lastRow = lowerBoundRow(matrix,target,sRow,eRow,sCol);
        int lastCol = lowerBoundCol(matrix,target,sCol,eCol,sRow);
        if (lastRow == eRow+1 && lastCol == eCol+1){
            return search(matrix, target, sRow+1, eRow, sCol+1, eCol);
        }
        if (lastRow == eRow+1){
            if (matrix[sRow][lastCol] == target){return true;}
            return search(matrix, target, sRow, eRow, sCol+1,lastCol-1);
        }
        if (lastCol == eCol+1){
            if (matrix[lastRow][sCol] == target){return true;}
            return search(matrix, target, sRow+1,lastRow, sCol, eCol);
        }
        if (matrix[lastRow][sCol] == target || matrix[sRow][lastCol] == target){return true;}
        return search(matrix, target, sRow, lastRow-1, sCol, lastCol-1);
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        totalRow = matrix.size();
        totalCol = matrix[0].size();
        return search(matrix,target,0,totalRow-1,0,totalCol-1);
    }
};