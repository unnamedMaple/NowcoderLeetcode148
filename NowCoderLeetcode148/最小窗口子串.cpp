class Solution {
public:
	string minWindow(string S, string T) {

		map<char, int>mymap;
		for (int i = 0; i<T.length(); i++){
			mymap[i] = 0;
		}

		int left = 0;
		int end;
		string ret = "";
		int count = 0;
		int minlen = S.length() + 1;
		for (end = 0; end<S.length(); end++){
			if (mymap.find(S[end]) != mymap.end()){
				if (mymap[S[end]] == 0){
					mymap[S[end]]++;
					count++;
				}
				else{
					mymap[S[end]]++;
				}
			}

			while (count == T.length()){
				if (mymap.find(S[left]) != mymap.end()){

					if (minlen>end - left + 1){
						minlen = end - left + 1;
						ret = S.substr(left, minlen);
					}


					if (mymap[S[left]] == 1){
						mymap[S[left]]--;
						count--;
					}
					else{
						mymap[S[left]]--;
					}
				}
				left++;
			}



		}

		return ret;
	}
};