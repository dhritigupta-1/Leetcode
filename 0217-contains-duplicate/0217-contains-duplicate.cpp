class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto f : nums)
            map[f]++;
        for(auto f : nums){
            if(map[f] > 1)
                return true;
        }
        return false;
    }
};