class Solution {
public:
    bool make(vector<int>& arr, int m, int k, int mid){
        int b = 0, f = 0;
        for(int d : arr){
            if(d <= mid){
                f++;
                if(f == k){
                    b++;
                    f=0;
                }
            }
            else f = 0;
        }
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       long long total = 1LL * m * k;
       if(total > bloomDay.size()) return -1;
       int ans = -1, count = 0, i=0;
       int low = *min_element(bloomDay.begin(), bloomDay.end());
       int high = *max_element(bloomDay.begin(), bloomDay.end());
       while(low <= high){
        int mid = low + (high - low) / 2;
        if(make(bloomDay, m, k, mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
       }
       return ans;
    }
};