/*


//来一个纯模拟手工运算的方法。
//先列出梯形的乘法步骤
//再对应相加，然后进位。
//从高位往低位找第一个不为0个数字，因为临时数组初始化的时候都是0.
//最后将这些数字转化为字符串。
//4ms AC,看来也不慢。

*/
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		vector<int> arr(num1.size() + num2.size(), 0);
		string ans = "";
		char tmp = '0';
		for (int i = num1.size() - 1; i >= 0; --i)
			for (int j = num2.size() - 1; j >= 0; --j) {
				arr[i + j + 1] += (num1[i] - '0')*(num2[j] - '0');
			}
		for (int i = arr.size() - 1; i > 0; --i){
			arr[i - 1] += arr[i] / 10;
			arr[i] = arr[i] % 10;
		}
		int i = 0;
		while (arr[i] == 0) ++i;
		while (i != arr.size()){
			tmp = arr[i] + '0';
			ans += tmp;
			++i;
		}
		return ans;
	}
};