class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        if(k == 0) return ans;
        for(int i=0; i<n; i++){
            int step = abs(k);
            int idx = i;
            int sum = 0;
            int dir = (k < 0) ? -1 : 1;
            for(int j=0; j<step; j++)
            {
                idx = (idx + dir + n) % n;
                sum += code[idx];
            }
            ans[i] = sum;
        }
        return ans;
    }
};