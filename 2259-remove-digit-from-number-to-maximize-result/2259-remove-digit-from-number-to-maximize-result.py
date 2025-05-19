class Solution(object):
    def removeDigit(self, number, digit):
        """
        :type number: str
        :type digit: str
        :rtype: str
        """
        occ = []
        for i in range(len(number)):
            if number[i] == digit:
                occ.append(number[:i]+number[i+1:])
        maxnum = -1
        for num in occ:
            if num > maxnum:
                maxnum = num 
        return maxnum
