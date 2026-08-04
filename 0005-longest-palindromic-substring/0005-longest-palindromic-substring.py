class Solution(object):
    def  pallindrome(self,left,right,s):
        length=0
        while left>=0 and right<len(s) and s[left]==s[right]:
            length=right-left+1
            left=left-1
            right=right+1
        return length    
    def longestPalindrome(self, s):
        maxi=0
        l=0
        for i in range(len(s)):
            l1=self.pallindrome(i,i,s)
            l2=self.pallindrome(i,i+1,s)
            l=max(l1,l2)
            if l>maxi:
                maxi=max(maxi,l)
                start=i-(l-1)/2
        return    s[start:start+maxi]



        """
        :type s: str
        :rtype: str
        """
        