class Solution {
public:
    vector<int> c;
    int solve(int i, vector<int>& cost){
        if(i >= cost.size()) return 0;
        if(c[i] != -1) return c[i];
        c[i] = cost[i] + min(solve(i+1, cost), solve(i+2, cost));
        return c[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        c.resize(cost.size(), -1);
        return min(solve(0, cost), solve(1, cost));
    }
};