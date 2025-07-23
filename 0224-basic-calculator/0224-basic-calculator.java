class Solution {
    public int calculate(String s) {
        int ans=0, num=0, sign=1;
        Stack<Integer> st = new Stack<>();
        st.push(sign);
        for(char c : s.toCharArray())
        {
            if(Character.isDigit(c))
                num = num * 10 + (c - '0');
            else if(c == '(')
                st.push(sign);
            else if(c == ')')
                st.pop();
            else if(c == '+' || c == '-')
            {
                ans += sign * num;
                sign = (c == '+' ? 1 : -1) * st.peek();
                num = 0;
            }
        } 
        return ans + sign * num;
    }
}