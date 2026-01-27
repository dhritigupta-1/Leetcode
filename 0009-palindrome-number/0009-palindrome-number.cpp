class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int t = x;
        long long o = 0;
        while(t != 0){
            int r = t % 10;
            o = (o * 10) + r;
            t = t / 10;
        }
        if(o == x) return true;
        return false;
    }
};