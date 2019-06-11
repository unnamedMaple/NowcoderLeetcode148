//C(n,k) = C(n-1,k-1)+C(n-1,k)
class Solution {
public:
	vector<vector<int> > combine(int n, int k) {

		vector<vector<int>>ret;

		if (k == 1){
			for (int i = 1; i <= n; i++){
				vector<int>tmp(1, i);
				ret.push_back(tmp);
			}
			return ret;
		}

		if (n == k){

			vector<int>tmp(n, 0);
			for (int i = 1; i <= n; i++){
				tmp[i - 1] = i;
			}
			ret.push_back(tmp);
			return ret;
		}

		vector<vector<int>>hasN = combine(n - 1, k - 1);


		for (int i = 0; i<hasN.size(); i++){
			hasN[i].push_back(n);
			ret.push_back(hasN[i]);
		}

		vector<vector<int>>nothasN = combine(n - 1, k);

		for (int i = 0; i<nothasN.size(); i++){

			ret.push_back(nothasN[i]);
		}
		return ret;

	}
};