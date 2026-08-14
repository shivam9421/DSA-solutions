class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        int m_w_size=0;
        unordered_map<char,int> mpp;
        while(j<s.size()){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            j++;
            m_w_size=max(m_w_size,j-i);
        }
        return m_w_size;
        
    }
};