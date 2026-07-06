class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        map[0] = -1;
        int sum = 0, conti = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) sum += -1;
            else sum += 1;
            if(map.find(sum) != map.end()) conti = max(conti, i-map[sum]);
            else map[sum] = i;
        }
        return conti;
    }
};