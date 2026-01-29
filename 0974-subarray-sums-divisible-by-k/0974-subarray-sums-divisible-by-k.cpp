class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0, count = 0;
        map[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int m = (sum % k + k) % k;
            if(map.find(m) != map.end())
                count += map[m];
            map[m]++;
        }
        return count;
    }
};