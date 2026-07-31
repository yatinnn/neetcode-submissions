class Solution {
public:
    bool isHappy(int n) {
        set<int>st;
        st.insert(n);

        while(n!=1){
            // cout<<n<<endl;
            n=f(n);
            if(st.find(n)!=st.end())return false;
            st.insert(n);
        }
        return true;
    }
    int f(int n){
        int ans=0;
        while(n>0){
            int digit=n%10;
            digit=digit*digit;
            ans+=digit;
            n=n/10;
        }
        return ans;
    }
};
