/*
Validate if a given string is numeric.

Some examples:
"0"=>true
" 0.1 "=>true
"abc"=>false
"1 a"=>false
"2e10"=>true

Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.



*/



class Solution 

{
public:
	bool isNumber(const char *s) {
		int n = strlen(s);
		if (s == NULL)
			return false;
		if (n == 1 && s[0] == ' ')//情形为“ ”
			return false;
		if (n == 1 && s[0] == '.')//情形为“.”
			return false;
		if (n == 1 && (s[0] == 'e' || s[0] == 'E'))//情形为“e”
			return false;
		bool ee = false;//是否出现过‘e’
		bool point = false;//是否出现过.
		bool nums = false;//是否出现过数字
		bool mark = false;//在e前出现的正负号
		bool mark1 = false;//在e后出现的正负号
		int i = 0;
		while (s[i] != '\0'){
			if (s[i] == '-' || s[i] == '+' || s[i] == 'e' || s[i] == 'E' || s[i] == '.' || (s[i] >= '0'&&s[i] <= '9') || s[i] == ' '){
				if (s[i] == '-' || s[i] == '+'){
					if (ee == true){//如果实在e后出现的正负号
						if (mark1 == false){
							mark1 = true;
							int j = i + 1;
							if (j >= n || !(s[j] >= '0'&&s[j] <= '9'))//e+/e-
								return false;
						}
						else
							return false;//e后正负号多次出现
					}
					else{//e前出现的正负号

						if (nums == true || point == true)//8+/.+
							return false;
						else{
							if (mark == true)//如果e前正负号出现多次
								return false;
							else
								mark = true;
						}
					}

				}
				if (s[i] == ' '){
					if (nums == false && ee == false && point == false && mark == false);
					else{//如果在中间位置出现‘ ’
						int j = i + 1;
						while (j<n){
							if (s[j] != ' ')
								return false;
							j++;
						}
					}

				}
				if (s[i] == '.'){
					if (ee == false){
						if (point == false){


							point = true;
						}
						else//e前出现多个小数点
							return false;
					}
					else//e后出现多个小数点
						return false;
				}
				if (s[i] == 'E' || s[i] == 'e'){
					if (ee == false){
						if (i == n - 1 || (nums == false && point == false) || (nums == false && point == true))
							return false;//e后出现小数点/e前没有任何信息
						else
							ee = true;
					}
					else
						return false;

					int j = i + 1;
					while (j<n){
						if (s[j] == ' ')
							j++;
						else
							break;
					}
					if (j >= n)//e后没有数字
						return false;
				}
				if (s[i] >= '0'&&s[i] <= '9')
					nums = true;
				i++;
			}
			else
				return false;
		}
		if (nums == false && point == true)//如果没有数字只有小数点
			return false;
		return true;
	}
};