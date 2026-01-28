class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0, far=0, stop=0;
        if(nums.size() <=1) return jump;
        for(int i=0; i<nums.size()-1; i++){
            far = max(far, nums[i]+i);
            if(i == stop){
                jump++;
                stop = far;
            }
        }
        return jump;
    }
};