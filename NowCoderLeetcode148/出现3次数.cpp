
/***



single numer���ʾ�����һ������¼ÿ��bit���ֵĴ�����������ĳһλ������ָ�������͹�0��������3�Σ���
���赱����2�ξ͹�0ʱ���������뵽����ʹ�����ķ�����
Ȼ����������2������ʱ�����Ǿ���Ҫ���Ӽ�¼��������Ϊһ����ÿ��bit��ֻ��0��1���ֿ��ܣ�ֻ�ܼ�¼���֡�
�˴����Ǿ���Ҫʹ���������ֱ�secondbit,firstbit�����м�¼�����Ա�ʾ4�ֿ��ܣ�����ֻ��Ҫ3��00��01��10��

Ȼ��ʹ�ÿ�ŵͼ���õ�secondbit,firstbit�ı��ʽ,�ֱ��secondbit,firstbitΪ����f,s���У�
f��ŵͼ��
***/

class Solution {
public:
	int singleNumber(int A[], int n) {
		int firstbit = 0, secondbit = 0;
		int one = 0;
		for (int i = 0; i < n; i++){
			one = firstbit;
			firstbit = (~secondbit&~firstbit&A[i]) | (~secondbit&firstbit&~A[i]);
			secondbit = (~secondbit&one&A[i]) | (secondbit&~one&~A[i]);
		}
		return firstbit | secondbit;
	}

};