���ӣ�https://www.nowcoder.com/questionTerminal/1025ffc2939547e39e8a38a955de1dd3
��Դ��ţ����

/**
* ��̬�滮�����ĵ���С�и���
* ���⣺ ����һ���ַ���s�����ذ�sȫ���гɻ����Ӵ�����С�ָ�����
*        ����"ABA"������Ҫ�и����0��"ABCBAE"����Ҫ�и�1�Σ���"ABCBA"��"E"������1��
*        "ABCDE"����Ҫ�и�4�Σ����"A"��"B"��"C"��"D"��"E"������4��
*
* �⣺
* dp[i]��ʾs.substring(0, i + 1)�Ӵ��Ļ�����С�и�����
* (Java���ַ���������������ҿ��ص㣬i+1��ʾ������i���ַ�)
* ��Ȼ���ս��Ϊdp[s.length - 1]��
*
* ȷ�ϳ�ʼ״̬��
*    dp[0] = 0,1���ַ������и�
*    ���Ӵ��ǻ��Ĵ�ʱ��dp[i] = 0��
*    ����dp[i]��ֵ����i������������
*    �������Ӵ������ڻ������ַ�������Ҫ�и�i�γɵ����ַ�
* ȷ��״̬ת�Ʒ��̣�
*    ��s.substring(j, i + 1) (1 <= j <= i)�ǻ���ʱ��
*    dp[i] = min(dp[i], dp[j - 1] + 1)��
*    ���ñ���j����i֮ǰ��ÿ���Ӵ���ע���ж��Ƿ���ģ��������¸�dp[i]��ֵ
*
* ��С��һö����������ѵ�˼·���Լ��ܽ���һ�£�
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