//子数组连续最大和
class Solution {
public:
	int maxSubArray(int A[], int n) {
		int ret = INT_MIN;
		int max = 0;

		for (int i = 0; i<n; i++){
			max += A[i];
			if (max>ret){
				ret = max;
			}
			if (max<0){
				max = 0;
			}

		}

		return ret;
	}
};