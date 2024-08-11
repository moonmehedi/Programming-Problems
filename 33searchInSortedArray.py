class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        start=0
        stop=len(nums)-1

        while(start<=stop) :
            mid=int((start+stop)/2)
            if(target==nums[mid]):
                return mid

            elif(nums[start]<=nums[mid]):
                if(nums[start]<=target<=nums[mid]):
                    stop=mid-1
                else:
                    start=mid+1
            else:
                if(nums[mid]<=target<=nums[stop]):
                    start=mid+1
                else:
                    stop=mid-1
        return -1
s=Solution()
print(s.search([3,4,6,8,9],3))


