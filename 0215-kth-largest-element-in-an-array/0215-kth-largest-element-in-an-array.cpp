class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int max = 0;
        for(int i=0; i<nums.size(); i++) pq.push(nums[i]);
        for(int i=0; i<k; i++){
            max = pq.top();
            pq.pop();
        }
        return max;
    }
};