class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> s1, s2;
        vector<int> nsei(n), psei(n);
        for(int i=n-1; i>=0; i--){
            while(!s1.empty() && arr[s1.top()] >= arr[i]) s1.pop();
            if(s1.empty()) nsei[i] = arr.size();
            else nsei[i] = s1.top();
            s1.push(i);
        }
        for(int i=0; i<n; i++){
            while(!s2.empty() && arr[s2.top()] >= arr[i]) s2.pop();
            if(s2.empty()) psei[i] = -1;
            else psei[i] = s2.top();
            s2.push(i);
        }
        int maxarea = 0;
        for(int i=0; i<n; i++){
            int l = arr[i];
            int b = nsei[i] - psei[i] - 1;
            int area = l * b;
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};

// formula: next smaller element index - previous smaller element index - 1
// if next smaller element index is -1 replace with arr size
// if previous smaller element index is -1 replace with 0