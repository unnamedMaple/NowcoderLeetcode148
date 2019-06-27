/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return[-1, -1].

For example,
Given[5, 7, 7, 8, 8, 10]and target value 8,
return[3, 4].

*/
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int>res(2, -1);

		int left = 0;
		int right = n - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = left + (right - left) / 2;

			if (A[mid] == target)
			{
				int i = mid;
				while (i - 1 >= 0 && A[i - 1] == target)
				{
					i--;
				}
				res[0] = i;
				i = mid;
				while (i + 1 <= n - 1 && A[i + 1] == target)
				{
					i++;
				}
				res[1] = i;
				break;

			}
			else if (A[mid]>target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;

			}

		}

		return res;
	}
};