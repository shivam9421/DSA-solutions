class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if(numRows==1):
            return s

        ans=''
        increment=(numRows-1)*2
        for i in range(numRows):
            for j in range(i,len(s),increment):
                ans+=s[j]
                middleindex=j+increment-2*i
                if (i>0 and i<numRows-1 and middleindex<len(s)):
                    ans+=s[middleindex]
        return ans




        