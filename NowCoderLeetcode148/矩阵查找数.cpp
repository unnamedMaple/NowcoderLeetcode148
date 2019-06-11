//常规思路：二分法查找
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		if (m == 0){
			return false;
		}
		int n = matrix[0].size();
		int low = 0;
		int high = m*n - 1;
		int mid;
		while (low <= high){
			mid = low + (high - low) / 2;

			if (matrix[mid / n][mid%n] == target){
				return true;

			}
			else if (matrix[mid / n][mid%n]>target){

				high = mid - 1;
			}
			else{
				low = mid + 1;
			}



		}
		return false;
	}
};





//从右上角开始，目标大去掉行，目标小去掉列
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		if (i == 0)
		{
			return false;

		}
		int n = matrix[0].size();

		int row = 0;
		int col = n - 1;
		while (row < m&&col >= 0){
			if (target == matrix[row][col]){
				return true;
			}
			else if (target > matrix[row][col]){
				row++;

			}
			else{
				col--;
			}


		}
		return false;
	}
};