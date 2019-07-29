
/***

Implement regular expression matching with support for'.'and'*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)


***/

/*递归清晰版*/
class Solution {
public://以p为主对象分情况讨论
	bool isMatch(const char *s, const char *p) {
		//int n1 = strlen(s), n2 = strlen(p);
		if (*p == '\0') return *s == '\0';
		if (strlen(p) == 1)return (strlen(s) == 1 && (s[0] == p[0] || p[0] == '.'));
		if (p[1] != '*'){
			if (*s == '\0') return 0;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p + 1);
		}
		//以下是 p[1] == '*'的情况
		while (*s != '\0' && (s[0] == p[0] || p[0] == '.')){//首元素匹配的情况
			if (isMatch(s, p + 2)) return 1;//先删去p的前两个元素检验（情况1）
			s = s + 1; //删去s首元素检验（情况2）
		}
		//首元素不匹配 和 s为空字符串 的情况 （此时s的首元素可能是后面的）
		return isMatch(s, p + 2);
	}
};

/*递归简化版*/
class Solution {
public:
	bool isMatch(const char *s, const char *p) {//由于p只有一个元素的话，不可能是"*"，所以递归可以简化
		if (*p == '\0') return *s == '\0';
		if (strlen(p) > 1 && p[1] == '*')//无论s首元素是否匹配，先把p的前两个元素去掉;之后去掉匹配的s首元素；即是s首元素去掉与否的讨论
			return isMatch(s, p + 2) || (*s != '\0' && (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p));
		else return *s != '\0' && (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p + 1);
	}
};
/* DP版 */
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		int m = strlen(s), n = strlen(p);
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++){
				if (j > 1 && p[j - 1] == '*')
					dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
				else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		return dp[m][n];
	}
};



/*
递归回溯时是从后往前收，DP是从前往后推。
本质一样，只是推时符号不同；
递归往后调递归函数时是加号，DP往后递推时减号
*/