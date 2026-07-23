class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int j = 0, sum = 0;
        double maxAvg = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(i-j+1 == k){
                double avg = (double)sum/k;
                maxAvg = max(maxAvg, avg);
                sum -= nums[j]; j++; 
            }
        }
        return maxAvg;
    }
};