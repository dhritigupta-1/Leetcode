class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        bool found = false;
        map[0] = -1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(map.find(sum%k) != map.end()){
                if(i - map[sum%k] >= 2)
                    found = true;
            }
            else map[sum%k] = i;
        }
        if(found) return true;
        return false;
    }
};