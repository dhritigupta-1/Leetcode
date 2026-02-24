class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        int num = 1, i=0;
        while(ans.size()<=k){
            if(i < arr.size() && arr[i] == num)
                i++;
            else ans.push_back(num);
            num++;
        }
        return ans[k-1];
    }
};