class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s1;
        for(int i=n-1; i>=0; i--){
            while(!s1.empty() && s1.top()<0 && asteroids[i]>0){
                if(-s1.top() < asteroids[i]) {
                    s1.pop();
                }
                else if(-s1.top() == asteroids[i]) {
                    s1.pop();
                    asteroids[i] = 0;
                    break;
                }
                else{
                    asteroids[i] = 0;
                    break;
                }
            }
            if(asteroids[i] != 0) s1.push(asteroids[i]);
        }
        vector<int> ans;
        while(!s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        return ans;
    }
};