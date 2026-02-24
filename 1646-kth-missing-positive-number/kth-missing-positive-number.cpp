class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low) / 2;
 //we are subtracting mid+1 as the orignally mid+1 should be there but not there so to get total no. of missing value
            int missing = arr[mid]-(mid+1); 
            if(missing<k) low=mid+1;
            else high = mid-1;
        }
        return low+k;
    }
};