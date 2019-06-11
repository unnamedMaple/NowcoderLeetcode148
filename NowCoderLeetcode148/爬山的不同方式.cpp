//You are climbing a stair case. It takes n steps to reach to the top.

//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
class Solution {
public:
	int climbStairs(int n) {
		if (n == 0){
			return 0;
		}
		if (n == 1){
			return 1;
		}
		if (n == 2){
			return 2;
		}

		int base[2] = { 1, 2 };
		int cur;



		for (int i = 3; i <= n; i++){
			cur = base[1] + base[0];

			base[0] = base[1];
			base[1] = cur;


		}
		return cur;
	}
};