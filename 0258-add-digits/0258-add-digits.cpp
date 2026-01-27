class Solution {
public:
    int addDigits(int num) {
        int r = 0, sum;
        while(num >= 10){
            sum = 0;
            while(num != 0){
                r = num % 10;
                sum = sum + r;
                num = num / 10;
            }
            num = sum;
        }
    return num;
    }
};