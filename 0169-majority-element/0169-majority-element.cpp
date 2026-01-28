class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int lead = 0;
        for(auto f : nums){
            if(++map[f] > nums.size()/2) lead = f;
        }
        return lead;
    }
};