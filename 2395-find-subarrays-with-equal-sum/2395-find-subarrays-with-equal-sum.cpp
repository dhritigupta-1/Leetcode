class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0; i<nums.size()-1; i++)
        {
            int sum = nums[i] + nums[i+1];
            if(map.count(sum))
                return true;
            map[sum] = 1;
        }
        return false;
    }
};