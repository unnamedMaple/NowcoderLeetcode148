
class Solution {
	//ʹ�õ�һ�к͵�һ������¼�к��е���0���
	//��Ҫ��¼�����Լ��Ƿ�Ҫ��0��ֻ��Ҫ����������һ���ǵ�һ�У�һ���ǵ�һ�У��Ϳ����ˡ�
	//Ȼ����ǵ�һ�к͵�һ�У����Ҫ��0���Ͱ�����ֵ����0������������Ҳ����0�����۵�һ�л��ߵ�һ����û��0����������ԭֵ��
	//Ȼ����ݵ�һ�к͵�һ�еļ�¼������Ԫ�ؽ�����0��
	//����ٸ���ǰ������������ȷ���ǲ���Ҫ�ѵ�һ�к͵�һ����0�Ϳ����ˡ�
	//����������ֻ��Ҫ����������������Կռ临�Ӷ���O(1)��
	//ʱ������Ҫ��������ɨ�裬һ��ȷ��������0�����һ�ζԾ������ʵ�ʵ���0�����������ܵ�ʱ�临�Ӷ���O(m*n)
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