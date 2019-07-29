class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string res = "";
		if (strs.size() == 0)
		{
			return res;

		}

		res = strs[0];
		int i = 0;
		int j = 0;
		for (i = 1; i<strs.size(); i++)
		{
			for (j = 0; j<strs[i].size() && res[j] != '\0'; j++)
			{
				if (strs[i][j] != res[j]){
					break;
				}
			}
			res = res.substr(0, j);
			if (res.size() == 0)
			{
				return res;
			}
		}
		return res;
	}
};