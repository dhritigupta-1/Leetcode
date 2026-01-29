class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int last = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int sum = 0;
            for(int j=i; j<nums.size(); j++)
            {
                sum += nums[j];
                if(sum == k)
                    last++;
            }
        }
        return last;
        /*
         unordered_map<int,int> map;
        int sum=0, count=0;
        map[0] = 1;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(map.find(sum-k) != map.end())
                count += map[sum - k];
            map[sum]++;
        }
        return count;
        */
    }
};