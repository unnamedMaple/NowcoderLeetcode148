链接：https://www.nowcoder.com/questionTerminal/1025ffc2939547e39e8a38a955de1dd3
来源：牛客网

/**
* 动态规划：回文的最小切割数
* 题意： 给定一个字符串s，返回把s全部切成回文子串的最小分割数。
*        例如"ABA"，不需要切割，返回0；"ABCBAE"，需要切割1次，成"ABCBA"和"E"，返回1。
*        "ABCDE"，需要切割4次，变成"A"、"B"、"C"、"D"、"E"，返回4。
*
* 解：
* dp[i]表示s.substring(0, i + 1)子串的回文最小切割数，
* (Java子字符串函数满足左闭右开特点，i+1表示包含第i个字符)
* 显然最终结果为dp[s.length - 1]。
*
* 确认初始状态：
*    dp[0] = 0,1个字符不用切割
*    当子串是回文串时，dp[i] = 0，
*    否则dp[i]初值等于i（最坏的情况），
*    即整个子串不存在回文子字符串，需要切割i次成单个字符
* 确认状态转移方程：
*    当s.substring(j, i + 1) (1 <= j <= i)是回文时，
*    dp[i] = min(dp[i], dp[j - 1] + 1)。
*    即用变量j遍历i之前的每个子串，注意判断是否回文，是则重新给dp[i]赋值
*
* （小白一枚，借鉴了网友的思路，自己总结了一下）
**/


class Solution {
public:
	int minCut(string s) {

		int len = s.length();
		if (len <= 1)
		{
			return 0;
		}
		vector<int>minCut(len, 0);

		for (int i = 1; i<len; i++)
		{


			string sub = s.substr(0, i + 1);
			if (sub == string(sub.rbegin(), sub.rend()))
			{
				minCut[i] = 0;
			}
			else
			{
				minCut[i] = i;

				for (int j = i; j>0; j--)
				{
					string tmp = s.substr(j, i - j + 1);
					if (tmp == string(tmp.rbegin(), tmp.rend()))
					{
						minCut[i] = min(minCut[i], minCut[j - 1] + 1);
					}



				}
			}


		}
		return minCut[len - 1];
	}
};