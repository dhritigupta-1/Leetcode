class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<n && nums[i]!=i){
                int correct = nums[i];
                swap(nums[i], nums[correct]);
            }
            else i++;
        }
        for(int j=0; j<n; j++){
            if(nums[j] != j)
                return j;
        }
        return n;
    }
};