
/***



single numer本质就是用一个数记录每个bit出现的次数，当数的某一位出现了指定次数就归0（本题是3次）。
假设当出现2次就归0时，很容易想到可以使用异或的方法。
然而，当出现2次以上时，我们就需要增加记录的数，因为一个数每个bit，只有0，1两种可能，只能记录两种。
此处我们就需要使用两个数分别secondbit,firstbit来进行记录，可以表示4种可能，本题只需要3种00，01，10。

然后，使用卡诺图来得到secondbit,firstbit的表达式,分别简化secondbit,firstbit为符号f,s则有：
f卡诺图：
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