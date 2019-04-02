/***
给定一个string s，打印出它的所有可能的回文子串
***/

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>>ret;
		vector<string>tmp;
		if (s.size() == 0)
		{
			return ret;
		}
		if (s.size() == 1)
		{
			tmp.push_back(s);
			ret.push_back(tmp);
			return ret;
		}

		for (int i = 1; i <= s.length(); i++)
		{
			string sub = s.substr(0, i);

			if (sub == string(sub.rbegin(), sub.rend()))
			{
				vector<vector<string>>tmpret = partition(s.substr(i, s.length() - i));
				for (int j = 0; j<tmpret.size(); j++)
				{
					vector<string>t = tmpret[j];
					t.insert(t.begin(), sub);

					ret.push_back(t);
				}
			}
		}

		if (s == string(s.rbegin(), s.rend()))
		{
			vector<string>t(1, s);
			ret.push_back(t);
		}


		return ret;


	}
};