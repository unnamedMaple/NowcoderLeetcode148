class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		/// 先排序再双指针进行夹逼
		int len = num.size();
		vector<vector<int>> res;
		if (len == 0) return res;
		sort(num.begin(), num.end());
		for (int i = 0; i<len; i++)
		{
			int sum = -num[i];
			int j = i + 1, k = len - 1;
			while (j<k)
			{
				int cur = num[j] + num[k];
				if (cur == sum)
				{
					vector<int> temp;
					temp.push_back(num[i]);
					temp.push_back(num[j]);
					temp.push_back(num[k]);
					res.push_back(temp);
					/// skip same num[j],num[k]
					while (j<k && num[j] == temp[1])
						j++;
					while (j<k && num[k] == temp[2])
						k--;
				}
				else if (cur<sum)
					++j;
				else
					--k;
			}
			/// skip same num[i]
			while (i<len - 1 && num[i] == num[i + 1])
				i++;
		}
		return res;

	}
};