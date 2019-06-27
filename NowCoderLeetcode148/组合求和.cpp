/*
All numbers (including target) will be positive integers.
Elements in a combination (a 1, a 2, … , a k) must be in non-descending order. (ie, a 1 ≤ a 2 ≤ … ≤ a k).
The solution set must not contain duplicate combinations.

For example, given candidate set2,3,6,7and target7,
A solution set is:
[7]
[2, 2, 3]



*/

class Solution{
public:
	void backTracking(vector<int> &candidates, vector<vector<int>> &res, vector<int> &combine, int target, int begin)
	{
		if (target == 0)
		{
			res.push_back(combine);
			return;
		}
		for (int i = begin; i<candidates.size(); i++)
		{
			if (target - candidates[i]<0) return;
			combine.push_back(candidates[i]);
			backTracking(candidates, res, combine, target - candidates[i], i);
			combine.pop_back();
		}
	}
	/// 使用所给的整数能够组成和为target的组合有多少种，元素可以重复使用无限次
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		vector<vector<int>> res;
		vector<int> combine;
		int len = candidates.size();
		if (len == 0) return res;
		sort(candidates.begin(), candidates.end());
		backTracking(candidates, res, combine, target, 0);
		return res;
	}
};