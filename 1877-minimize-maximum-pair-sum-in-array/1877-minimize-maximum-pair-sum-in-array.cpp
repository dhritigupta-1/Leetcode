class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int right = nums.size() - 1;
        int left = 0;
        int count = 0;
        while(left < right){
            int sum = nums[right] + nums[left];
            count = max(sum, count);
            right--;
            left++;
        }
        return count;
    }
};