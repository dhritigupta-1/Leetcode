class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> map;
        int start = 0, maxLen = 0;
        for(int i=0; i<fruits.size(); i++){
            map[fruits[i]]++;
            while(map.size() > 2){
                map[fruits[start]]--;
                if(map[fruits[start]] == 0) map.erase(fruits[start]);
                start++;
            }
            maxLen = max(maxLen, i-start+1);
        }
        return maxLen;
    }
};