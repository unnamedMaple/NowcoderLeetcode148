/*
Given a string containing just the characters'('and')', find the length of the longest valid (well-formed) parentheses substring.

For"(()", the longest valid parentheses substring is"()", which has length = 2.

Another example is")()())", where the longest valid parentheses substring is"()()", which has length = 4.



*/

class Solution {
public:
	int longestValidParentheses(string s) {

		if (s.length() == 0)return 0;

		stack<char> chars;

		int max = 0;
		int tempmax = 0;
		vector<int> number(s.length(), 0);
		for (int i = 0; i<s.length(); i++)
		{
			if (s[i] == '(')
			{
				chars.push(s[i]);
				tempmax = 0;
			}
			else
			{
				if (chars.size()>0 && chars.top() == '(')
				{
					tempmax += 2;
					if (number[i - tempmax] != 0)
					{
						tempmax += number[i - tempmax];
					}
					if (tempmax>max)max = tempmax;
					number[i] = tempmax;
					chars.pop();
				}
				else
				{
					tempmax = 0;
				}
			}
		}
		return max;
	}
};