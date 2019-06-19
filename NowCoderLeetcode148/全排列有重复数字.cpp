
//For example,
//[1, 1, 2]have the following unique permutations :
//[1, 1, 2], [1, 2, 1], and[2, 1, 1].
//µÝ¹é A(n) = n*A(n-1)
class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &nums) {
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

		map<int, int>mymap;
		for (int i = 0; i < nums.size(); i++){

			if (mymap.find(nums[i]) == mymap.end()){
				mymap.insert(pair<int, int>(nums[i], 1));
				vector<int>sub;
				for (int j = 0; j < nums.size(); j++){
					if (j != i){
						sub.push_back(nums[j]);
					}
				}
				vector<vector<int>> subret = permuteUnique(sub);
				for (int k = 0; k < subret.size(); k++){
					vector<int>newv;
					newv.insert(newv.end(), nums[i]);
					newv.insert(newv.end(), subret[k].begin(), subret[k].end());
					ret.push_back(newv);
				}
			}


		}
		return ret;
	}
};

//»ØËÝ·¨
class Solution {
	vector<vector<int>> res;
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());
		solve(num, 0);
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}

	void solve(vector<int>& num, int step){
		if (step == num.size()){
			res.push_back(num);
			return;
		}
		solve(num, step + 1);
		for (int i = step + 1; i<num.size(); ++i){
			if (num[i] == num[step])continue;
			swap(num[step], num[i]);
			solve(num, step + 1);
			swap(num[step], num[i]);
		}
	}
};
