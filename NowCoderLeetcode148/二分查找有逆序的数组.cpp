
/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e.,0 1 2 4 5 6 7might become4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.


*/
class Solution {
public:
	int search(int A[], int n, int target) {
		int res = -1;

		int left = 0;
		int right = n - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (A[mid] == target)
			{
				res = mid;
				break;
			}
			else if (target<A[left])
			{
				if (A[mid]>A[left])
				{
					left = mid + 1;
				}
				else
				{
					left++;
				}
			}
			else if (target>A[right])
			{
				if (A[mid]>A[left])
				{
					right--;
				}
				else
				{
					right = mid - 1;
				}
			}
			else
			{
				if (A[mid]>target)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}




		}
		return res;


	}
};


链接：https://www.nowcoder.com/questionTerminal/7cd13986c79d4d3a8d928d490db5d707
来源：牛客网

class Solution {
public:
	// 不要被“旋转”而迷惑，“有序”并不是二分查找的核心
	// 二分查找的核心是"通过界桩快速决定查找方向，大幅缩短查找空间"
	// 只要能快速确定界桩，就能使用二分查找
	// 充分利用有序数组能够快速获取边界值的特性
	// 利用这一特性可以快速确定目标值应处的区间
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		int lo = 0, hi = nums.size() - 1;

		while (lo <= hi) {
			int mi = lo + ((hi - lo) >> 1);
			if (nums[mi] == target)
				return mi;

			// 只要在普通的二分查找判断语句中加一层 && 来确定目标值所在的区间，即可以同样O(logn)的复杂度查找
			if (nums[lo] <= nums[mi] && (nums[lo] <= target && target < nums[mi]))
				hi = mi - 1;
			else if (nums[mi] <= nums[hi] && !(nums[mi] < target && target <= nums[hi]))
				hi = mi - 1;
			else
				lo = mi + 1;
		}
		return -1;
	}
};