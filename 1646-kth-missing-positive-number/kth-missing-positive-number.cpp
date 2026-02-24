class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i : arr){
            if(i<=k) k++;
            else break;
        }
        return k;
    }
};