typedef pair<int,int> ii;
class Solution {
public:
    void rotateBorder(vector<vector<int>>& matrix, int left, int right){
        ii tl(left,left), tr(left,right), bl(right,left), br(right,right);
        for (int j = left; j <right;j++){
            int tmp = matrix[tl.first][tl.second];
            matrix[tl.first][tl.second] = matrix[bl.first][bl.second];
            matrix[bl.first][bl.second] = matrix[br.first][br.second];
            matrix[br.first][br.second] = matrix[tr.first][tr.second];
            matrix[tr.first][tr.second] = tmp;
            tl.second++;
            tr.first++;
            br.second--;
            bl.first--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int L = 0, R = n-1;
        while (L<R){
            rotateBorder(matrix, L++, R--);
        }
        return;
        
    }
};