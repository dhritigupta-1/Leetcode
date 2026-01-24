class Solution {
public:
    bool Rotate(vector<vector<int>>& mat, int n, vector<vector<int>>& target){
        for(int k=0; k<n; k++){
            for(int i=0; i<mat.size(); i++){
                for(int j=i+1; j<mat.size(); j++){
                    swap(mat[i][j], mat[j][i]);
                }
            }            
            for(int i=0; i<mat.size(); i++){
                reverse(mat[i].begin(), mat[i].end());
            }
            bool same = true;
            for(int i=0; i<mat.size(); i++){
                    for(int j=0; j<mat.size(); j++){
                        if(mat[i][j] != target[i][j]){
                            same = false;
                            break;
                        }
                    }
                if(!same) break;
            }
            if(same) return true;
        }
        return false;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int k = 4;
        return Rotate(mat, k, target);
    }
};