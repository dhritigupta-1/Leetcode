class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int top = 0, left = 0, val = 1;
        int right = mat[0].size()-1, bottom = mat.size()-1;
        while(top <= bottom && left <= right){
            for(int i=left; i<= right; i++) mat[top][i] = val++;
            top++;
            for(int i=top; i<=bottom; i++) mat[i][right] = val++;
            right--;
            if(top <= bottom){
                for(int i=right; i>=left; i--) mat[bottom][i] = val++;
                bottom--;
            }
            if(left <= right){
                for(int i=bottom; i>=top; i--) mat[i][left] = val++;
                left++;
            }
        }
        return mat;
    }
};