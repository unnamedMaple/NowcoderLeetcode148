/*

Given array A =[2,3,1,1,4]

The minimum number of jumps to reach the last index is2. 
(Jump1step from index 0 to 1, then3steps to the last index.)

*/

//动态规划//O(n)的额外空间
class Solution {
public:
	int jump(int A[], int n) {

		int cur = 0;
		int i = 0;
		vector<int>minsteps(n, INT_MAX);
		minsteps[0] = 0;

		while (i <= cur&&i <= n - 1){
			if (i + A[i]>cur){
				cur = A[i] + i;
			}

			for (int j = i + 1; j <= cur&&j <= n - 1; j++){
				minsteps[j] = min(minsteps[i] + 1, minsteps[j]);
			}

			i++;
		}

		return minsteps[n - 1];
	}
};
//O(1)空间
class Solution {
public:
	// 当前能够到达的最远距离还没有到n，必须再走下一步
	int jump(int A[], int n)
	{
		int curReach = 0, maxReach = 0, steps = 0;
		for (int i = 0; i<n && i <= maxReach; i++)
		{
			if (i>curReach)    //steps-1步能够到达的距离,必须再走一步了
			{
				++steps;
				curReach = maxReach;
			}
			maxReach = max(maxReach, i + A[i]); // step步最远距离
		}
		if (maxReach<n - 1)
			return -1;
		else
			return steps;
	}
};
