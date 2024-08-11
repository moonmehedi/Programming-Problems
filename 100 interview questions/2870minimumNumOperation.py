class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        frq = {}

        for i in nums:
            if i in frq:
                frq[i] += 1
            else:
                frq[i] = 1

        count = 0

        for i in frq:
            if frq[i] == 1:
                count = - 1
                break
            elif frq[i] % 3 == 0:
                count += frq[i]/3
            else:
                count += int(frq[i]/3)+1

        return count


s = Solution()
print(s.minOperations([2, 3, 3, 2, 2, 4, 2, 3, 4]))
