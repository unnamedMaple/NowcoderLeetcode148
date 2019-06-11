class Solution {
public:
	void sortColors(int A[], int n) {

		if (n == 0){
			return;
		}
		int left = 0;
		int right = n - 1;

		for (int i = 0; i <= right; i++){
			if (A[i] == 0){
				A[i] = A[left];
				A[left] = 0;
				left++;

			}
			else if (A[i] == 2){
				A[i] = A[right];
				A[right] = 2;
				right--;
				i--;
			}



		}
		return;

	}
};