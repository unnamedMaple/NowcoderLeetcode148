class Solution {
public:
	bool isPalindrome(string s) {

		bool ret = true;
		int left = 0;
		int right = s.size() - 1;
		while (left<right)
		{
			while (left<right &&!isAlpha(s[left]))
			{
				left++;
			}

			while (left<right && !isAlpha(s[right]))
			{
				right--;
			}
			if (left<right && !eq(s[left], s[right]))
			{
				ret = false;
				break;
			}
			else
			{
				left++;
				right--;
			}
		}
		return ret;

	}

	bool isAlpha(char a)
	{
		if (a <= 'z'&&a >= 'a' || a <= 'Z'&&a >= 'A' || a <= '9'&&a >= '0')
		{
			return true;
		}
		return false;

	}
	bool eq(char A, char B)
	{
		char tmp = '0';
		if (B <= 'z'&&B >= 'a')
		{
			tmp = 'A' + B - 'a';
		}
		else
		{
			tmp = 'a' + B - 'A';
		}

		if (A == B || A == tmp)
		{
			return true;
		}
		return false;
	}
};