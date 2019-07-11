/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S:"barfoothefoobarman"
L:["foo", "bar"]

You should return the indices:[0,9].
(order does not matter).
*/
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		map<string, int>Lmap;
		vector<int>ret;
		int wordnum = L.size();
		if (wordnum <= 0)
		{
			return ret;
		}
		int wordlen = L[0].length();
		if (wordlen <= 0)
		{
			return ret;
		}
		if (S.length()<wordlen*wordnum)
		{
			return ret;
		}
		for (int i = 0; i<L.size(); i++)
		{
			if (Lmap.find(L[i]) == Lmap.end())
			{
				Lmap[L[i]] = 1;
			}
			else
			{
				Lmap[L[i]]++;
			}

		}



		int count = 0;
		for (int i = 0; i <= S.length() - wordlen*wordnum; i++)
		{
			map<string, int>tempMap;
			count = 0;
			for (int j = 0; j<wordnum; j++)
			{
				string word = S.substr(i + j*wordlen, wordlen);
				if (Lmap.find(word) == Lmap.end())
				{
					break;
				}

				if (tempMap.find(word) == tempMap.end())
				{
					tempMap[word] = 1;

				}
				else
				{
					tempMap[word]++;
				}

				if (tempMap[word] >Lmap[word]){
					break;
				}
				else{
					count++;
				}


			}
			if (count == wordnum)
			{
				ret.push_back(i);
			}
		}
		return ret;

	}
};