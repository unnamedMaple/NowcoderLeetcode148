/*


//��һ����ģ���ֹ�����ķ�����
//���г����εĳ˷�����
//�ٶ�Ӧ��ӣ�Ȼ���λ��
//�Ӹ�λ����λ�ҵ�һ����Ϊ0�����֣���Ϊ��ʱ�����ʼ����ʱ����0.
//�����Щ����ת��Ϊ�ַ�����
//4ms AC,����Ҳ������

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