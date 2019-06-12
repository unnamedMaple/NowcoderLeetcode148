/*


The set[1,2,3,бн,n]contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
*/

class Solution {
public:
	int getNum(vector<bool>&sign, int offset){

		for (int i = 0; i<sign.size(); i++){
			if (sign[i] == false && offset == 0){
				sign[i] = true;
				return i + 1;
			}

			if (sign[i] == false){
				offset--;
			}
		}
		return -1;

	}
	string getPermutation(int n, int k) {
		vector<bool>sign(n, false);
		int mulsum = 1;
		for (int i = 2; i <= n - 1; i++){
			mulsum *= i;
		}

		int count = k - 1;
		int offset = 0;
		int num = 0;
		string ret = "";
		for (int j = 1; j<n; j++){
			offset = count / mulsum;
			num = getNum(sign, offset);
			count = count%mulsum;
			mulsum /= n - j;
			ret += to_string(num);
		}

		num = getNum(sign, 0);
		ret += to_string(num);
		return ret;

	}
};