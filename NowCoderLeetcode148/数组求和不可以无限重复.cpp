/*

All numbers (including target) will be positive integers.
Elements in a combination (a 1, a 2, °≠ , a k) must be in non-descending order. (ie, a 1 °‹ a 2 °‹ °≠ °‹ a k).
The solution set must not contain duplicate combinations.

For example, given candidate set10,1,2,7,6,1,5and target8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]


*/
class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int>>ret;

		vector<int>tmp;

		sort(num.begin(), num.end());
		reCombinationsum(num, target, 0, ret, tmp);
		return ret;
	}

	void reCombinationsum(vector<int> &num, int target, int begin, vector<vector<int>>&ret, vector<int>&tmp){

		if (target == 0){
			ret.push_back(tmp);
			return;
		}

		for (int i = begin; i<num.size(); i++){
			if (i > begin && num[i] == num[i - 1]) continue; // »•÷ÿ

			if (target - num[i]<0){
				return;
			}
			tmp.push_back(num[i]);
			reCombinationsum(num, target - num[i], i + 1, ret, tmp);
			tmp.pop_back();


		}
	}

};