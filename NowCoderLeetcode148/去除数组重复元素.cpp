//我的版本

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 2){
			return n;
		}

		vector<int>tmp(n, 0);
		int remove = A[0] - 1;

		int count = 1;
		int cur = A[0];
		int index = 1;
		tmp[0] = A[0];
		for (int i = 1; i<n; i++){
			if (cur == A[i]){
				if (count<2){
					count++;
					tmp[index] = A[i];
					index++;

				}

			}
			else{
				cur = A[i];
				count = 1;
				tmp[index] = A[i];
				index++;
			}
		}

		for (int i = 0; i<index; i++){
			A[i] = tmp[i];
		}

		return index;

	}
};


//高效版本

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 2) return n;
		int index = 2;//允许重复两次，可以修改为三次
		for (int i = 2; i<n; i++)
		{
			if (A[i] != A[index - 2])//允许重复两次，可以修改为三次
				A[index++] = A[i];
		}

		return index;
	}
};