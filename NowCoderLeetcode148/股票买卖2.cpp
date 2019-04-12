class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int sum = 0;
		int profit = 0;
		int min = INT_MAX;
		for (int i = 0; i<prices.size(); i++)
		{
			if (prices[i]<min)
			{
				if (profit>0)
				{
					sum += profit;
					min = prices[i];
					profit = 0;
				}
				min = prices[i];
			}
			else
			{
				if (prices[i] - min>profit)
				{
					profit = prices[i] - min;
				}
				else
				{
					sum += profit;
					min = prices[i];
					profit = 0;
				}
			}
		}

		if (profit>0)
		{
			sum += profit;
		}
		return sum;
	}
};