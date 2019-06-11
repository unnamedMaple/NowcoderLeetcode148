class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int c[26] = { 0 };
		for (int i = 0; i<s1.size(); i++)
		{
			c[s1[i] - 'a']++;
			c[s2[i] - 'a']--;
		}
		for (int j = 0; j<26; j++)
		{
			if (c[j] != 0)
				return false;
		}
		for (int k = 1; k<s1.size(); k++)
		{
			if (isScramble(s1.substr(0, k), s2.substr(0, k)) && isScramble(s1.substr(k), s2.substr(k)))
				return true;
			if (isScramble(s1.substr(0, k), s2.substr(s2.size() - k)) && isScramble(s1.substr(k), s2.substr(0, s2.size() - k)))
				return true;
		}
		return false;
	}
};