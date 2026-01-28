class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> result;
        intervals.push_back(newInterval);
        if(intervals.empty()) return result;
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            vector<int>& last = result.back();
            if(last[1] >= intervals[i][0])
                last[1]=max(intervals[i][1],last[1]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};