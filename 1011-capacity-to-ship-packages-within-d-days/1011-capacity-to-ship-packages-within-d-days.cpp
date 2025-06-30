class Solution {
public:
    bool Func(vector<int>& weights, int days, int mid)
    {
        int cap = 0;
        int d = 1;
        for(int i=0; i<weights.size(); i++)
        {
            if(cap+weights[i] <= mid)
                cap += weights[i];
            else
            {
                cap = weights[i];
                d++;
            }
        }
        if(d <= days)
                return true;
         return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int l = 0;
        for(int i=0; i<weights.size(); i++)
        {
            sum += weights[i];
            if(weights[i] > l)
                l = weights[i];
        }
        int low = l;
        int high = sum;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(Func(weights, days, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};