class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        f(0,s,ans,temp);
        return ans;
    }

    bool isPalindrome(string& local,int start,int end){
        while(start<end){
            if(local[start++]!=local[end--])return false;
        }
        return true;
    }

    void f(int i,string& s,vector<vector<string>>&ans ,vector<string>&temp){
        if(i==s.size())return ans.push_back(temp);
        for(int j=i;j<s.size();j++){
            if(isPalindrome(s,i,j)){
                string t=s.substr(i,j-i+1);
                temp.push_back(t);
                f(j+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
};
