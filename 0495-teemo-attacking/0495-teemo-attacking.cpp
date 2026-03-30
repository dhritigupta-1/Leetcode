class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int t = 0;
        for(int i=0; i<timeSeries.size(); i++){
            if(i == timeSeries.size()-1) t += duration;
            else{
                int gap = timeSeries[i+1] - timeSeries[i];
                t += min(gap, duration);
            }
        }
        return t;
    }
};