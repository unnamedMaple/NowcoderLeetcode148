/***

����·������N������վ��ÿ������վ������gas[i],��ÿ������վ����һվ��������cost[i]
�ʴ��ĸ�����վ�����ܹ��ص���ʼ�㣬����������򷵻�-1��ע��,����Ψһ�ģ�
***/


class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

		int start = gas.size() - 1;
		int end = 0;
		int sum = gas[start] - cost[start];
		while (start >end)
		{
			if (sum >= 0)
			{
				sum += gas[end] - cost[end];
				end++;
			}
			else
			{
				start--;
				sum += gas[start] - cost[start];
			}
		}
		if (sum<0)
		{
			return -1;
		}
		return start;

		// function1
		/***
		int total = 0;
		int res = 0;
		int index = -1;
		for(int i=0;i<gas.size();i++)
		{
		total += gas[i] - cost[i];
		res += gas[i] - cost[i];

		if(res<0)
		{
		res = 0;
		index = i;
		}
		}
		if(total<0)
		{
		return -1;
		}
		return index+1;
		***/
	}
};