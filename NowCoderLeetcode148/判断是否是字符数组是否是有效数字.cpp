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
		if (n == 1 && s[0] == ' ')//����Ϊ�� ��
			return false;
		if (n == 1 && s[0] == '.')//����Ϊ��.��
			return false;
		if (n == 1 && (s[0] == 'e' || s[0] == 'E'))//����Ϊ��e��
			return false;
		bool ee = false;//�Ƿ���ֹ���e��
		bool point = false;//�Ƿ���ֹ�.
		bool nums = false;//�Ƿ���ֹ�����
		bool mark = false;//��eǰ���ֵ�������
		bool mark1 = false;//��e����ֵ�������
		int i = 0;
		while (s[i] != '\0'){
			if (s[i] == '-' || s[i] == '+' || s[i] == 'e' || s[i] == 'E' || s[i] == '.' || (s[i] >= '0'&&s[i] <= '9') || s[i] == ' '){
				if (s[i] == '-' || s[i] == '+'){
					if (ee == true){//���ʵ��e����ֵ�������
						if (mark1 == false){
							mark1 = true;
							int j = i + 1;
							if (j >= n || !(s[j] >= '0'&&s[j] <= '9'))//e+/e-
								return false;
						}
						else
							return false;//e�������Ŷ�γ���
					}
					else{//eǰ���ֵ�������

						if (nums == true || point == true)//8+/.+
							return false;
						else{
							if (mark == true)//���eǰ�����ų��ֶ��
								return false;
							else
								mark = true;
						}
					}

				}
				if (s[i] == ' '){
					if (nums == false && ee == false && point == false && mark == false);
					else{//������м�λ�ó��֡� ��
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
						else//eǰ���ֶ��С����
							return false;
					}
					else//e����ֶ��С����
						return false;
				}
				if (s[i] == 'E' || s[i] == 'e'){
					if (ee == false){
						if (i == n - 1 || (nums == false && point == false) || (nums == false && point == true))
							return false;//e�����С����/eǰû���κ���Ϣ
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
					if (j >= n)//e��û������
						return false;
				}
				if (s[i] >= '0'&&s[i] <= '9')
					nums = true;
				i++;
			}
			else
				return false;
		}
		if (nums == false && point == true)//���û������ֻ��С����
			return false;
		return true;
	}
};