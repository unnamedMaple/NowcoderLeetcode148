class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0){
			return 0;
		}

		if (s.size() == 1){
			return 1;
		}

		int arr[2] = { 0 };

		s_len = s.size();


		int cur = 0
			if (s[s_len - 1] != '0'){
				arr[0] = 1;
			}
		for (i = 2; i<s.size(); i++){
			index = s_len - i;
			switch (s[index]){
			case '1':
				cur = arr[1] + arr[0];

				break;
			case '2':
				if (s[index + 1] <= '6'&&s[index + 1] >= '0'){
					cur = arr[1] + arr[0];

				}
				else{
					cur = arr[0];

				}
				break;
			default:
				cur = arr[0];
			}
			arr[1] = arr[0];
			arr[0] = cur;



		}
		return arr[0];

	}
};