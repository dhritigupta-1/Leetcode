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
        return{};
        // OR
        /* int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                sum = nums[i] + nums[j];
                if(sum == target)
                    return vector<int> {i,j};
            }
        }
        return vector<int>{}; */
    }
};