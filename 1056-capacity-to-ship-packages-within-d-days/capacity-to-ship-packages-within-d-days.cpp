class Solution {
public:
    bool Func(vector<int>& weights, int days, int mid){
        int cap = 0;
        int d = 1;
        for(int i=0; i<weights.size(); i++){
            if(cap+weights[i] <= mid) cap += weights[i];
            else{
                cap = weights[i];
                d++;
            }
        }
        if(d <= days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // int sum = 0;
        // for(int i=0; i<weights.size(); i++) sum+=weights[i];
        int low = *max_element(weights.begin(), weights.end());
        //int high = sum;
        int high = accumulate(weights.begin(), weights.end(), 0); // to sum an array
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(Func(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};