/*
Given a string s consists of upper/lower-case alphabets and empty space characters' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s ="Hello World",
return5.



*/

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		bool space = false;
		int len = strlen(s);

		if (len == 0){
			return 0;
		}
		len--;
		int ret = 0;
		while (len >= 0){
			if (s[len] == ' '){
				len--;
			}
			else{
				break;
			}
		}

		while (len >= 0){
			if (s[len] != ' '){
				ret++;
			}
			else{
				break;
			}
			len--;


		}

		return ret;

	}
};