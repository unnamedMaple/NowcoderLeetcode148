/*


Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3→1,3,2
3,2,1→1,2,3
1,1,5→1,5,1


从后往前先找到不满足递增排序的点，swap这个点与后面大于此的数，然后对后面升序排列

*/
class Solution {
public:

	void nextPermutation(vector<int> &num) {
		if (num.size() <= 1) return;
		int i = num.size() - 1;
		while (i>0 && num[i] <= num[i - 1]) --i;
		if (i == 0) {                           //5,4,3,2,1
			reverse(num.begin(), num.end());
		}
		else{
			int j = num.size() - 1;
			while (num[j] <= num[i - 1]) --j;
			swap(num[j], num[i - 1]);
			reverse(num.begin() + i, num.end());
		}
	}
};