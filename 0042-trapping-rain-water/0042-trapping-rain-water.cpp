class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> s1;
        int water = 0;
        for(int i=0; i<n; i++){
            while(!s1.empty() && height[i] > height[s1.top()]){
                int mid = s1.top();
                s1.pop();
                if(s1.empty()) break;
                int left = s1.top();
                int width = i - left - 1;
                int boundedheight = min(height[i], height[left]) - height[mid];
                water += width * boundedheight;
            }
            s1.push(i);
        }
        return water;
    }
};