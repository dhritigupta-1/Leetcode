class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = 4;
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
};