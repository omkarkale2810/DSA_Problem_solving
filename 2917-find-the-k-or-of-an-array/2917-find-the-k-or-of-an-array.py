class Solution(object):
    def findKOr(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        arr=[0]*32
        for i in nums:
            for j in range(0,32):
                if ((1<<j) & i)>=1:
                    print("insideon1")
                    arr[j]+=1
        ans=0
        for i in range(0,32):
            if arr[i]>=k:
                print("inside")
                ans+=(2**i)

        return ans
        # arr = [0] * 32
        # for i in nums:
        #     for j in range(32):
        #         if i & (1 << j):
        #             arr[j] += 1

        # ans = 0
        # for i in range(32):
        #     if arr[i] >= k:
        #         ans += (1 << i)

        # return ans