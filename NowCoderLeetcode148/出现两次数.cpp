class Solution {
public:
	int singleNumber(int A[], int n) {
		if (n<1)
		{
			return -1;
		}
		int result = A[0];
		for (int i = 1; i<n; i++)
		{
			result ^= A[i];
		}
		return result;
	}
};