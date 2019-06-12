//牛顿迭代法开根，平方收敛速度

class Solution {
public:
	int sqrt(int x) {
		if (x<0){
			return -1;
		}
		long ret = x;
		while (ret*ret >x){
			ret = (ret*ret + x) / (2 * ret);
		}
		return int(ret);

	}
};