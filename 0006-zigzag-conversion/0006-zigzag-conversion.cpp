class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) {
            return s;
        }
        string ans="";
        int increment=(numRows-1)*2;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<s.size();j=j+increment){
                ans=ans+s[j];
                int diagIndex = j + increment - 2 * i;
                if(i>0&&i<numRows-1&& diagIndex<s.size()){
                    ans=ans+s[diagIndex];
                }
            }
        }
        return ans;
        
    }
};