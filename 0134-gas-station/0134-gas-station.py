class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if sum(gas)<sum(cost):
            return -1
        n=len(gas)
        istravel=0
        startindex=0
        for i in range(len(gas)):
            istravel+=(gas[i]-cost[i])
            if istravel<0:
                startindex=i+1
                istravel=0
        return startindex
                
    





        