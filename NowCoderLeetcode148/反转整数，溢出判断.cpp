class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x != 0){
			//���һλ
			int tail = x % 10;
			int newRes = res * 10 + tail;
			//���newRes-tail)/10!=res˵�����������
			if ((newRes - tail) / 10 != res)
				return 0;
			res = newRes;
			x = x / 10;
		}
		return res;
	}
};