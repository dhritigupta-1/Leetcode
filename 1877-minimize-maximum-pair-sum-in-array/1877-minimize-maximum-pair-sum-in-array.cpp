class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int right = nums.size() - 1;
        int left = 0;
        int count = 0;
        while(left < right){
            count = max(count, nums[right] + nums[left]);
            right--;
            left++;
        }
        return count;
    }
};