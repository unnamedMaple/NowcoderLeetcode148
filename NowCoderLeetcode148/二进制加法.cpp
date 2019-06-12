class Solution {
public:
	string addBinary(string a, string b) {

		if (a.empty()){
			return b;

		}

		if (b.empty()){
			return a;

		}

		string ret = "";

		bool sign = false;

		int aptr = a.length() - 1;
		int bptr = b.length() - 1;

		bool aone = false;
		bool bone = false;
		while (aptr >= 0 && bptr >= 0){
			if (a[aptr] == '1'){
				aone = true;
			}
			else{
				aone = false;
			}

			if (b[bptr] == '1'){
				bone = true;
			}
			else{
				bone = false;

			}

			if ((!aone&!bone&sign) | (!aone&bone&!sign) | (aone&bone&sign) | (aone&!bone&!sign)){
				ret = "1" + ret;
			}
			else{
				ret = "0" + ret;
			}

			if ((aone&bone) | (!aone&bone&sign) | (aone&!bone&sign)){
				sign = true;
			}
			else{
				sign = false;
			}


			aptr--;
			bptr--;
		}
		while (aptr >= 0){
			if (a[aptr] == '1'){
				aone = true;
			}
			else{
				aone = false;
			}
			if (sign^aone){
				ret = "1" + ret;
			}
			else{
				ret = "0" + ret;
			}

			if (sign&aone){
				sign = true;
			}
			else{
				sign = false;
			}
			aptr--;

		}

		while (bptr >= 0){
			if (b[bptr] == '1'){
				bone = true;
			}
			else{
				bone = false;
			}
			if (sign^bone){
				ret = "1" + ret;
			}
			else{
				ret = "0" + ret;
			}

			if (sign&bone){
				sign = true;
			}
			else{
				sign = false;
			}
			bptr--;

		}
		if (sign){
			ret = "1" + ret;
		}
		return ret;
	}

};