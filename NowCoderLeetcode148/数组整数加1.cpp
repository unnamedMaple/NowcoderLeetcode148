class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int>ret;
		if (digits.empty()){
			ret.push_back(1);
			return ret;
		}

		int add = 0;
		int index = digits.size() - 1;
		add = digits[index] + 1 >= 10 ? 1 : 0;
		ret.insert(ret.begin(), (digits[index] + 1) % 10);
		index--;
		int cur;
		while (index >= 0){
			cur = (digits[index] + add) % 10;
			add = digits[index] + add >= 10 ? 1 : 0;
			ret.insert(ret.begin(), cur);
			index--;
		}
		if (add == 1){
			ret.insert(ret.begin(), 1);

		}
		return ret;
	}
};



//���ý�λ�İ취
//1.����Ҫflag! ��������,����9�ͱ�0,��9�ͼ�1,Ȼ��break;
//2.digits[0]�������0,˵������������1,���½�����,��λΪ1,����λΪ0;
public int[] plusOne(int[] digits) {
	for (int i = digits.length - 1; i >= 0; i--) {
		if (digits[i] == 9)digits[i] = 0;
		else {
			digits[i] = digits[i] + 1;
			break;
		}
	}
	if (digits[0] == 0){
		int[] arr = new int[digits.length + 1];
		arr[0] = 1;
		for (int i = 1; i < arr.length; i++) arr[i] = 0;
		return arr;
	}
	return digits;
}