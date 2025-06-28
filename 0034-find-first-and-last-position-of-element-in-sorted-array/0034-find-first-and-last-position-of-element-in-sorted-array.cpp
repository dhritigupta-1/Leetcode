class Solution {
public:
    int firstoccurence(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                ans =  mid;
                high = mid - 1;
            }
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }

    int lastoccurence(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                ans = mid;
                low = mid + 1;
            }
            else if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(firstoccurence(nums, target));
        res.push_back(lastoccurence(nums, target));
        return res;
    }
};