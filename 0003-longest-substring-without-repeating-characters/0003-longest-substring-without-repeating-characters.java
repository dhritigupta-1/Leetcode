class Solution {
    public int lengthOfLongestSubstring(String s) {
       HashMap<Character,Integer> hash=new HashMap<>();
        int start=0;
        int maxLen=0;
        for(int i=0;i<s.length();i++)
        {
            char c=s.charAt(i);
            if (hash.containsKey(c) && hash.get(c) >= start) 
                start = hash.get(c) + 1;
            hash.put(c, i);
            maxLen = Math.max(maxLen, i - start + 1);
        }
        return maxLen;
    }
}