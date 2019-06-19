/*

回文构词法有一个特点：单词里的字母的种类和数目没有改变，只是改变了字母的排列顺序。

For example:

Input:  ["tea","and","ate","eat","den"]

Output:   ["tea","ate","eat"]
*/

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		int l = strs.size();
		vector<string>ret;
		if (l <= 0){
			return ret;
		}

		map<string, int>mymap;
		for (int i = 0; i<l; i++){
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			if (mymap.find(tmp) == mymap.end()){
				mymap[tmp] = i;

			}
			else{
				if (mymap[tmp] >= 0){
					ret.push_back(strs[mymap[tmp]]);
					mymap[tmp] = -1;
				}
				ret.push_back(strs[i]);
			}


		}
		return ret;

	}
};