class Solution {
public:
int pallindrome(int i,int j,string &s){
    int len=0;
    while(i>=0 && j<s.size() && s[i]==s[j]){
        len=j-i+1;
        i--;
        j++;
    }
    return len;
}
string longestPalindrome(string s) { 
    int a=0,max1=0;
    for(int i=0;i<s.size();i++){
        int l1=pallindrome(i,i,s);
        int l2=pallindrome(i,i+1,s);
        int l=max(l1,l2);
        if(l>max1){
            max1=l;
            a=i;
        }

    }
    return s.substr(a-(max1-1)/2,max1);
  


    }
};