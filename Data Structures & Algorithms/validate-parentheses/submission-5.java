class Solution {
    public boolean isValid(String s) {
        int n=s.length();
        if(n==1||n==0)return false;
        Stack<Character>st=new Stack<>();
        for(Character c:s.toCharArray()){
            if(c=='('||c=='{'||c=='[')st.add(c);
            else {
                if(st.empty())return false;
                if(c==')'&& st.peek()!='(' || c==']' && st.peek()!='[' || c=='}' && st.peek()!='{')return false;
             st.pop();
            }
        }
        return st.empty();
    }
}
