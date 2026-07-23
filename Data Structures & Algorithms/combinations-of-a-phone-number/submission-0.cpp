class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string nums[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.size()==0)return ans;
        f(0,"",digits,nums,ans);
        return ans;
    }

    void f(int i,string s,string& digits,string nums[],vector<string>&ans){
        if(i==digits.size())return ans.push_back(s);
            string val=nums[digits[i]-'0'];
        for(int j=0;j<val.size();j++){
            f(i+1,s+val[j],digits,nums,ans);
        }
    }
};
