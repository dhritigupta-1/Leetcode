class Solution {
public:
    int length(vector<int>& h){
        int n = h.size();
        stack<int> s;
        int m = 0;
        for(int i=0; i<=n; i++){
            int currentheight = (i == n) ? 0 : h[i];
            while(!s.empty() && currentheight < h[s.top()]){
                int h1 = h[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                m = max(m, h1 * width);
            }
            s.push(i);
        }
        return m;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>h(m, 0);
        int maxarea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            maxarea = max(maxarea, length(h));
        }
        return maxarea;
    }
};