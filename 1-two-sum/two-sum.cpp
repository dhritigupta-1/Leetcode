class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum = target - nums[i];
            if(map.find(sum) != map.end()){
                return {map[sum], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

