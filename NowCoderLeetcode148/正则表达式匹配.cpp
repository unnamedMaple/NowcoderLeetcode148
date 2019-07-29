
/***

Implement regular expression matching with support for'.'and'*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)


***/

/*�ݹ�������*/
class Solution {
public://��pΪ��������������
	bool isMatch(const char *s, const char *p) {
		//int n1 = strlen(s), n2 = strlen(p);
		if (*p == '\0') return *s == '\0';
		if (strlen(p) == 1)return (strlen(s) == 1 && (s[0] == p[0] || p[0] == '.'));
		if (p[1] != '*'){
			if (*s == '\0') return 0;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p + 1);
		}
		//������ p[1] == '*'�����
		while (*s != '\0' && (s[0] == p[0] || p[0] == '.')){//��Ԫ��ƥ������
			if (isMatch(s, p + 2)) return 1;//��ɾȥp��ǰ����Ԫ�ؼ��飨���1��
			s = s + 1; //ɾȥs��Ԫ�ؼ��飨���2��
		}
		//��Ԫ�ز�ƥ�� �� sΪ���ַ��� ����� ����ʱs����Ԫ�ؿ����Ǻ���ģ�
		return isMatch(s, p + 2);
	}
};

/*�ݹ�򻯰�*/
class Solution {
public:
	bool isMatch(const char *s, const char *p) {//����pֻ��һ��Ԫ�صĻ�����������"*"�����Եݹ���Լ�
		if (*p == '\0') return *s == '\0';
		if (strlen(p) > 1 && p[1] == '*')//����s��Ԫ���Ƿ�ƥ�䣬�Ȱ�p��ǰ����Ԫ��ȥ��;֮��ȥ��ƥ���s��Ԫ�أ�����s��Ԫ��ȥ����������
			return isMatch(s, p + 2) || (*s != '\0' && (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p));
		else return *s != '\0' && (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p + 1);
	}
};
/* DP�� */
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
�ݹ����ʱ�ǴӺ���ǰ�գ�DP�Ǵ�ǰ�����ơ�
����һ����ֻ����ʱ���Ų�ͬ��
�ݹ�������ݹ麯��ʱ�ǼӺţ�DP�������ʱ����
*/