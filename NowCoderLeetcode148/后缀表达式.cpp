/***
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are+,-,*,/. Each operand may be an integer or another expression.

Some examples:

["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
***/
class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int>mystack;
		int ret = 0;
		for (int i = 0; i<tokens.size(); i++)
		{
			if ((tokens[i][0] <= '9' &&tokens[i][0] >= '0') || (tokens[i].size()>1 && (tokens[i][0] == '+' || tokens[i][0] == '-')))
			{
				int tmp = strToInt(tokens[i]);
				mystack.push(tmp);
			}
			else
			{
				int a = mystack.top();
				mystack.pop();
				int b = mystack.top();
				mystack.pop();
				int result = 0;

				if (tokens[i] == "+")
				{
					result = b + a;
				}
				else if (tokens[i] == "-")
				{
					result = b - a;
				}
				else if (tokens[i] == "*")
				{
					result = b * a;
				}
				else if (tokens[i] == "/")
				{
					result = b / a;
				}


				mystack.push(result);

			}

		}

		ret = mystack.top();
		return ret;
	}


	int strToInt(string &str)
	{
		int ret = 0;
		bool sign = false;
		int i = 0;
		if (str[0] == '-')
		{
			sign = true;
			i = 1;
		}

		if (str[0] == '+')
		{
			i = 1;
		}
		for (; i<str.size(); i++)
		{
			ret = ret * 10 + str[i] - '0';
		}

		if (sign == true)
		{
			ret = -ret;
		}
		return ret;
	}
};