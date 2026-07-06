class Solution {
public:
    bool Vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int l = 0, h = s.length()-1;
        while(l < h){
            while(l<h && !Vowel(s[l])) l++;
            while(l<h && !Vowel(s[h])) h--;
            swap(s[l], s[h]);
            l++;
            h--;
        }
        return s;
    }
};