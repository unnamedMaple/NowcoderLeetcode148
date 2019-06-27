/*
ompute how much water it is able to trap after raining.

For example,
Given[0,1,0,2,1,0,1,3,2,1,2,1], return6.
*/
class Solution {
public:
	int trap(int A[], int n) {

		if (n <= 2) return 0;
		int lefttop = A[0], righttop = A[n - 1];
		int i = 1, j = n - 2;
		int sums = 0;
		while (i <= j) {
			if (lefttop > righttop) {
				sums += max(0, righttop - A[j]);
				righttop = max(righttop, A[j]);
				--j;
			}
			else {
				sums += max(0, lefttop - A[i]);
				lefttop = max(lefttop, A[i]);
				++i;
			}
		}
		return sums;
	}
};