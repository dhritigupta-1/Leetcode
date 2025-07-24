class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = prices[0];
        int m = 0;
        for(int i=0; i<n; i++)
        {
            if(prices[i] < min)
                min = prices[i];
            else
                m = max(m, prices[i]-min);
        }
        return m;
    }
};