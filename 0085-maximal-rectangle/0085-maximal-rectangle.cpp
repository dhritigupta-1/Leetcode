class Solution {
public:
    int largestRectangle(vector<int>& h){
        stack<int> s1;
        int n = h.size();
        int m = 0;
        for(int i=0; i<=n; i++){
            int currentheight = (i == n) ? 0 : h[i];
            while(!s1.empty() && currentheight < h[s1.top()]){
                int h1 = h[s1.top()];
                s1.pop();
                int width = s1.empty() ? i : i - s1.top() -1;
                m = max(m, h1*width);
            }
            s1.push(i);
        }
        return m;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> h(c, 0);
        int maxarea = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            maxarea = max(maxarea, largestRectangle(h));
        }
        return maxarea;
    }
};