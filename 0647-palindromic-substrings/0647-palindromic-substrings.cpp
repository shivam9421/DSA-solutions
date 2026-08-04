class Solution {
public:
    int  pallindrome(int left,int right,string &s){
        int count=0;
        while (left>=0 and right<s.size() and s[left]==s[right]){
            count++;
            left--;
            right++;
            }
        return count;  }
    int countSubstrings(string s) {
        int total_palindrome=0;
        for(int i=0;i<s.size();i++){
           int   c1=pallindrome(i,i,s);
           int  c2=pallindrome(i,i+1,s);
            total_palindrome+=c1+c2;
        }
        return total_palindrome;
    }
};