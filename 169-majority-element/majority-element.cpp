class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int lead = 0;
        for(auto i : nums) map[i]++;
        for(auto i : map){
            if(i.second > nums.size()/2) lead = i.first;
        }
        return lead;
    }
};