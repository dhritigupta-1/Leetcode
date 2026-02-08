class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;
        for(int i=0; i<height.size(); i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int mid = st.top();
                st.pop();
                if(st.empty()) break;
                int left = st.top();
                int width = i - left - 1;
                int boundedheight = min(height[i], height[left]) - height[mid];
                water += width * boundedheight;
            }
            st.push(i);
        }
        return water;
    }
};