class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            func(nums, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(nums, ans, temp);
        return ans;
    }
};