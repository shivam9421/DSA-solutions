class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        count=1
        matrix = [[0] * n for _ in range(n)]
        for layer in range((n + 1) // 2):
            for left in range(layer,n-layer):
                matrix[layer][left]=count
                count+=1
            for top in range(layer+1,n-layer):
                matrix[top][n-layer-1]=count
                count=count+1   
            for right in range(n-layer-2,layer-1,-1):
                matrix[n-layer-1][right]=count
                count=count+1
            for bottom in range(n-layer-2,layer,-1):
                matrix[bottom][layer]=count
                count=count+1   

        return matrix            
       

        