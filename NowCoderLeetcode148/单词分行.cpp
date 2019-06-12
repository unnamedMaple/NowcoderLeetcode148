/*
words:["This", "is", "an", "example", "of", "text", "justification."]
L:16.

Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]

最后一行有可能有多个单词，此时每个单词之间一个空格，剩余空格向右填充


*/

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string>ret;
		if (words.empty()){
			return ret;
		}

		string line = "";
		vector<string>tmp;
		int curlen = 0;
		int wordcount;
		vector<int> padding;
		for (auto s : words){
			if (curlen + s.length() <= L){
				curlen += s.length() + 1;// at least one space
				tmp.push_back(s);
			}
			else{
				wordcount = tmp.size();

				if (wordcount == 1){
					padding.push_back(L - (curlen - 1));
					line += tmp[tmp.size() - 1];
					while (padding[0]>0){
						line += " ";
						padding[0]--;
					}
					ret.push_back(line);
				}
				else{
					padding = calculatePad(L, curlen, wordcount);
					for (int i = 0; i<tmp.size() - 1; i++){
						string s = tmp[i] + " ";
						int pad = padding[i];
						while (pad>0){
							s += " ";
							pad--;
						}
						line += s;
					}
					line += tmp[tmp.size() - 1];
					ret.push_back(line);
				}



				curlen = s.length() + 1;
				tmp.clear();
				tmp.push_back(s);
				line = "";
				wordcount = 0;
				padding.clear();
			}
		}

		wordcount = tmp.size();

		if (wordcount == 1){
			padding.push_back(L - (curlen - 1));
			line += tmp[tmp.size() - 1];
			while (padding[0]>0){
				line += " ";
				padding[0]--;
			}
			ret.push_back(line);
		}
		else{

			for (int i = 0; i<tmp.size() - 1; i++){
				string s = tmp[i] + " ";


				line += s;
			}
			line += tmp[tmp.size() - 1];
			line += string(L - line.size(), ' ');
			ret.push_back(line);
		}

		return ret;



	}

	vector<int>calculatePad(int L, int curlen, int count){
		vector<int>ret(count - 1, 0);
		if (curlen>L){
			return ret;
		}
		else{
			int pad = L - curlen + 1;
			int i = 0;
			while (pad>0){
				ret[i]++;
				i = (i + 1) % (count - 1);
				pad--;
			}
		}
		return ret;

	}
};