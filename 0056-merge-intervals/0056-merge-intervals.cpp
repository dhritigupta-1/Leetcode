class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            vector<int>& last = res.back();
            if(last[1] >= intervals[i][0])
                last[1] = max(intervals[i][1], last[1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};