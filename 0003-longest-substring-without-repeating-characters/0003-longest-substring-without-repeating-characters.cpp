class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int j = 0; 
        int i = 0; 
        int count = 0;
        unordered_map<char, int> mpp;
        int maxlength = 0;
            
        while(j < n){
            if(mpp.find(s[j]) != mpp.end()){
                if(mpp[s[j]] >= i){
                    i = mpp[s[j]] + 1;
                }
            }
            count = j - i + 1;  // +1 fix
            maxlength = max(count, maxlength);
            mpp[s[j]] = j;
            j++;    
        }
        
        return maxlength;
    }
};