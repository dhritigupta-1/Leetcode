class Solution {
public:
    bool Func(vector<int>& piles, int h, int mid)
    {
        long hour = 0;
        for(int i=0; i<piles.size(); i++)
        {
            hour += ceil((piles[i] * 1.0) / mid);
        }
        if(hour <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1e9;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(Func(piles, h, mid))
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