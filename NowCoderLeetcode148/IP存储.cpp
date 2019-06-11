
/*

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given"25525511135",

return["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>ret;
		if (s.size()>12 || s.size()<4)
		{
			return ret;
		}

		ret = restoreIpAddressesByRe(s, 3);
		return ret;
	}

	vector<string>restoreIpAddressesByRe(string s, int cut)
	{
		vector<string>ret;

		if (s == "")
		{
			return ret;
		}




		if (cut == 0)
		{
			if (s.size()>1 && s[0] == '0')
			{
				return ret;
			}
			if (atoi(s.c_str()) <= 255 && atoi(s.c_str()) >= 0)
			{
				ret.push_back(s);
				return ret;
			}
		}


		for (int i = 0; i<s.size(); i++)
		{
			string head = s.substr(0, i + 1);
			if (head[0] == '0'&&head.size()>1)
			{
				continue;
			}
			if (atoi(head.c_str()) <= 255 && atoi(head.c_str()) >= 0)
			{
				vector<string>tmp = restoreIpAddressesByRe(s.substr(i + 1), cut - 1);

				for (int j = 0; j<tmp.size(); j++)
				{
					tmp[j] = head + "." + tmp[j];
					ret.push_back(tmp[j]);
				}


			}


		}
		return ret;

	}
};