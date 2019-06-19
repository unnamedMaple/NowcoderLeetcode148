/*
For example,
[1,2,3]have the following permutations:
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], and[3,2,1].
*/

//µÝ¹é A(n) = n*A(n-1)
class Solution {
public:
	vector<vector<int> > permute(vector<int> &nums) {
		vector<vector<int>>ret;
		if (nums.size() == 0){
			vector<int>p;
			ret.push_back(p);
			return ret;
		}
		if (nums.size() == 1){
			vector<int>p;
			p.push_back(nums[0]);

			ret.push_back(p);
			return ret;
		}

		for (int i = 0; i < nums.size(); i++){

			vector<int>sub;
			for (int j = 0; j < nums.size(); j++){
				if (j != i){
					sub.push_back(nums[j]);
				}
			}
			vector<vector<int>> subret = permute(sub);
			for (int k = 0; k < subret.size(); k++){
				vector<int>newv;
				newv.insert(newv.end(), nums[i]);
				newv.insert(newv.end(), subret[k].begin(), subret[k].end());
				ret.push_back(newv);
			}
		}
		return ret;

	}
};

//»ØËÝ·¨
class Solution {
	void permutation(vector<vector<int> >&ans, vector<int>& num, int l)
	{
		if (l == num.size() - 1)
			ans.push_back(num);
		else
		{
			for (int i = l; i<num.size(); i++)
			{
				swap(num[l], num[i]);
				permutation(ans, num, l + 1);
				swap(num[l], num[i]);
			}
		}
	}
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ans;
		permutation(ans, num, 0);
		return ans;
	}
};