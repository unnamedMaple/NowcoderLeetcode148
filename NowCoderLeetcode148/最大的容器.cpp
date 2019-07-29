class Solution {
public:
	int maxArea(vector<int> &height) {
		int res = 0;
		if (height.size() <= 1)
		{
			return res;
		}

		int left = 0;
		int right = height.size() - 1;
		res = (right - left)*min(height[left], height[right]);
		while (left<right)
		{
			if (height[left]<height[right])
			{
				left++;
			}
			else
			{
				right--;
			}


			if ((right - left)*min(height[left], height[right])>res)
			{
				res = (right - left)*min(height[left], height[right]);
			}



		}
		return res;
	}
};