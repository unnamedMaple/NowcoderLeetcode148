/*
Divide two integers without using multiplication, division and mod operator.
//改进最基本的循环方法，原每次减除数，效率不高，易超时，将每次减数翻倍，这样算法效率能够得到极大优化
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