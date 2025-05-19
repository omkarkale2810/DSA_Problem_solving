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
        occ.sort()
        return occ[-1]
