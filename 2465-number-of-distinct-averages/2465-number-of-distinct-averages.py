class Solution(object):
    def distinctAverages(self, nums):
        st = set()
        nums.sort()
        i = 0
        j = len(nums)-1
        while j >= i:
            avg = float((nums[i]+nums[j])/2)
            st.add(avg)
            i+=1
            j-=1
        return len(st)

        