/*
Divide two integers without using multiplication, division and mod operator.
//�Ľ��������ѭ��������ԭÿ�μ�������Ч�ʲ��ߣ��׳�ʱ����ÿ�μ��������������㷨Ч���ܹ��õ������Ż�
*/
class Solution {
public:


	int divide(int dividend, int divisor) {

		if (divisor == 0)
			return INT_MAX;
		int flag = (dividend<0) ^ (divisor<0);
		long long a = labs(dividend), b = labs(divisor);
		int res = 0;
		while (a >= b)
		{
			long long tp = b, k = 1;
			while ((tp << 1) <= a)
			{
				tp <<= 1;
				k <<= 1;
			}
			a -= tp;
			res += k;

		}
		return flag ? ~res + 1 : res;
	}


};