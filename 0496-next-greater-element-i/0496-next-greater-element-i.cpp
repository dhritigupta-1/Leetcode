class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans(n2, -1);
        stack<int> s;
        for(int i=n2-1; i>=0; i--){
            while(!s.empty() && nums2[i] >= nums2[s.top()]) s.pop();
            if(s.empty()) ans[i] = -1;
            else ans[i] = nums2[s.top()];
            s.push(i);
        }
        vector<int> res(n1, -1);
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(nums1[i] == nums2[j]){
                    res[i] = ans[j];
                    break;
                }
                    
            }
        }
        return res;
    }
};