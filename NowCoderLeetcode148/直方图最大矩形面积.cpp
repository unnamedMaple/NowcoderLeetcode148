class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		if (height.size() == 0){
			return 0;
		}


		stack<int>mys;
		mys.push(height[0]);
		int area = 0;
		int count = 0;
		for (int i = 1; i<height.size(); i++)
		{
			if (height[i] >= mys.top()){
				mys.push(height[i]);
			}
			else{
				count = 0;
				while (!mys.empty() && mys.top()>height[i]){
					int tmp = mys.top();
					mys.pop();
					count++;
					area = max(area, tmp*count);
				}

				while (count>0){
					mys.push(height[i]);
					count--;
				}
				mys.push(height[i]);
			}
		}
		count = 0;
		while (!mys.empty()){
			int tmp = mys.top();
			mys.pop();
			count++;
			area = max(area, tmp*count);
		}
		return area;
	}
};