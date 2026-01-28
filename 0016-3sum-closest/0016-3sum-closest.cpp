class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, best = 0;
        sort(nums.begin(), nums.end());
        best = nums[0] + nums[1] + nums[2];
        for(int i=0; i<n-2; i++){
            int low = i+1, high = n - 1;
            while(low < high){
                sum = nums[i] + nums[low] + nums[high];
                if(abs(sum - target) < abs(best - target)) best = sum;
                else if(sum < target) low++;
                else high--;
            }
        }
        return best;
    }
};