class Solution(object):
    def findMatrix(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        array_dict = {}

        for n in nums:
            if n in array_dict:
                array_dict[n] += 1
            else:
                array_dict[n] = 1

        ans = []
        lst = []

        while array_dict:
            keys = list(array_dict.keys())
            for num in keys:
                if array_dict[num] > 0:
                    lst.append(num)
                    array_dict[num] -= 1
                if array_dict[num] == 0:
                    del array_dict[num]

            ans.append(lst)
            lst = []

        return ans


s = Solution()
s.findMatrix([1, 2, 3, 4, 1, 2, 2, 45, 10, 12, 1, 33, 32])
