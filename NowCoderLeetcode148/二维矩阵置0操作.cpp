
class Solution {
	//使用第一行和第一列来记录行和列的置0情况
	//想要记录它们自己是否要置0，只需要两个变量（一个是第一行，一个是第一列）就可以了。
	//然后就是第一行和第一列，如果要置0，就把它的值赋成0（反正它最终也该是0，无论第一行或者第一列有没有0），否则保留原值。
	//然后根据第一行和第一列的记录对其他元素进行置0。
	//最后再根据前面的两个标记来确定是不是要把第一行和第一列置0就可以了。
	//这样的做法只需要两个额外变量，所以空间复杂度是O(1)。
	//时间上需要进行两次扫描，一次确定行列置0情况，一次对矩阵进行实际的置0操作，所以总的时间复杂度是O(m*n)
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int rows = matrix.size();
		if (rows == 0) return;
		int cols = matrix[0].size();
		bool r0 = 0;
		for (int i = 0; i < rows; i++)
			if (matrix[i][0] == 0)
			{
				r0 = 1;
				break;
			}
		bool c0 = 0;
		for (int i = 0; i < cols; i++)
			if (matrix[0][i] == 0)
			{
				c0 = 1;
				break;
			}

		for (int i = 1; i < rows; i++)
		{
			for (int j = 1; j < cols; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < rows; i++)
		{
			for (int j = 1; j < cols; j++)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
		}
		if (r0 == 1)
			for (int i = 0; i < rows; i++)
				matrix[i][0] = 0;
		if (c0 == 1)
			for (int i = 0; i < cols; i++)
				matrix[0][i] = 0;
	}
};