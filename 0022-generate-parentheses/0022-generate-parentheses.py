class Solution(object):
    def backtrack(self,n,open,close,ans,possiblestring):
        if open==n and close ==n:
            ans.append(possiblestring)
            return
        if(open<n):
            self.backtrack(n,open+1,close,ans,possiblestring+'(')
        if(close<open) :
            self.backtrack(n,open,close+1,ans,possiblestring+')')   


    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans=[]
        self.backtrack(n,0,0,ans,"")
        return ans
        