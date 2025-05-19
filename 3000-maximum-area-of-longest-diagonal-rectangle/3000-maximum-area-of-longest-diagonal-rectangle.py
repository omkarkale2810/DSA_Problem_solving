import math
class Solution(object):
    def areaOfMaxDiagonal(self, dimensions):
        """
        :type dimensions: List[List[int]]
        :rtype: int
        """
        maxdiag = -1
        maxarea = -1
        for i in dimensions:
            leng = i[0]
            wid = i[1]
            diag = math.sqrt((leng*leng) + (wid*wid))
            if diag >= maxdiag:
                maxdiag = diag
                maxarea = leng*wid
        return maxarea