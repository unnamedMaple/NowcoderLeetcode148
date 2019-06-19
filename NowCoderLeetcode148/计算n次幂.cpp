class Solution {
public:
	double pow(double x, int n) {
		if (n == 0){
			return 1;
		}

		if (n == 1){
			return x;
		}
		if (n == 2){
			return x*x;

		}

		if (n<0){
			x = 1 / x;
			n = -n;
		}

		bool flag = false;
		if (x<0){
			flag = true;
			x = -x;
		}
		double half = 1;
		half = pow(x, n / 2);
		double ret = 1;
		if (n % 2 == 1){

			ret = half*half*x;
		}
		else{
			ret = half*half;
		}

		if (flag && n % 2 == 1){
			ret = -ret;
		}
		return ret;
	}
};