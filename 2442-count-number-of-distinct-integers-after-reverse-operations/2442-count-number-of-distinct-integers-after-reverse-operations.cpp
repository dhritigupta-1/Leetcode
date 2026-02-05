class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int rev = 0;
            while(arr[i] != 0){
                int ld = arr[i] % 10;
                rev = rev * 10 + ld;
                arr[i] = arr[i] / 10;
            }
            nums.push_back(rev);
        }
        int count = 0;
        unordered_set<int> set;
        for(int i=0; i<nums.size(); i++){
            if(set.find(nums[i]) == set.end()){
                set.insert(nums[i]);
                count++;
            }
        }
        return count;
    }
};