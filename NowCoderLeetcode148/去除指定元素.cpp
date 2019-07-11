/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*/
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if (n == 0)
		{
			return 0;
		}

		if (n == 1)
		{
			if (A[0] == elem)
			{
				return 0;
			}
			return 1;
		}

		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			while (left<n && A[left] != elem)
			{
				left++;
			}
			while (right >= 0 && A[right] == elem)
			{
				right--;
			}
			if (left<right)
			{
				int tmp = A[left];
				A[left] = A[right];
				A[right] = tmp;
				left++;
				right--;
			}

		}

		return left;
	}
};