class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        int sign=+1;
       long long atoi=0;
        while(i<n&&s[i]==' ' ){
            i++;
        }
        if(s[i]=='-'){
            i++;
            sign=-1;
        }
        else if(s[i]=='+') { i++; }
        while(i<n &&s[i]=='0' ){
            i++;
        }
        while(i<n && s[i]-'0'>=0 && s[i]-'0'<=9){          // bounds check first
            atoi=atoi*10+(s[i]-'0');
            if(sign*atoi>=INT_MAX) return INT_MAX;           // clamp overflow
            if(sign*atoi<=INT_MIN) return INT_MIN;
            i++;
        }
        return  sign*atoi;
    }
};