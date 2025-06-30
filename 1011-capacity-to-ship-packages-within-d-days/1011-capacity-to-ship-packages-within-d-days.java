class Solution {
    boolean Func(int [] weights, int days, int mid)
    {
        int sum = 0;
        int d = 1;
        for(int i=0; i<weights.length; i++)
        {
            if(sum+weights[i] <= mid)
            {
                sum += weights[i];
            }
            else
            {
                sum = weights[i];
                d++;
            }
        }
        if(d <= days)
            return true;
        return false;
    }
    public int shipWithinDays(int[] weights, int days) {
        int sum = 0;
        int largest = 0;
        for(int i=0; i<weights.length; i++)
        {
            sum += weights[i];
            if(weights[i] > largest)
                largest = weights[i];
        }
        int low = largest;
        int high = sum;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(Func(weights, days, mid))
            {
                ans = mid;
                high = mid - 1 ;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
}