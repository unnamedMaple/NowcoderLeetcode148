class Solution {
public:
	static bool cmp(vector<int>&a, vector<int>&b){
		if (a.size() == b.size()){
			return a[0]<b[0];
		}
		return a.size()<b.size();
	}

	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int>>ret;
		vector<int>empty;
		ret.push_back(empty);

		sort(S.begin(), S.end());

		for (int i = 0; i<S.size(); i++){
			int len = ret.size();
			for (int j = 0; j<len; j++){
				vector<int>tmp = ret[j];
				tmp.push_back(S[i]);
				ret.push_back(tmp);
			}

		}

		sort(ret.begin(), ret.end(), cmp);
		return ret;

	}
};