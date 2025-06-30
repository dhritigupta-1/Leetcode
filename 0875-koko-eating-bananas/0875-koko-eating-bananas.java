class Solution {
    boolean Func(int mid, int[] piles, int h)
    {
        int hour = 0;
        for(int i=0; i<piles.length; i++)
        {
            hour += Math.ceil((piles[i]*1.0) / mid);
        }
        if(hour <= h)
            return true;
        return false;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = (int)1e9;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(Func(mid, piles, h))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
}