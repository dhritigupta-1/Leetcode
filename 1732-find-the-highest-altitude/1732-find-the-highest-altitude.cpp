class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int g = 0, mg = 0;
        for(int i=0; i<gain.size(); i++){
            g += gain[i];
            mg = max(mg, g);
        }
        return mg;
    }
};