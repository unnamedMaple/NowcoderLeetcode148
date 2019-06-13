/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A =[2,3,1,1,4], returntrue.

A =[3,2,1,0,4], returnfalse.

*/
class Solution {
public:
	bool canJump(int A[], int n) {
		int cur = 0;
		int i = 0;
		while (i <= cur){
			if (i + A[i]>cur){
				cur = A[i] + i;
			}
			if (cur >= n - 1){
				return true;
			}
			i++;
		}
		return false;
	}
};