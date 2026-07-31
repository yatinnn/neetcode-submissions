class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]+carry>9){
                digits[i]=0;
                carry=1;
            }
            else {digits[i]+=carry;
                carry = 0;
            }
            
        }
        if(carry)digits.insert(digits.begin(),1);
        return digits;
    }
};
