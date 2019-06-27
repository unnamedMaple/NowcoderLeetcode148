/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1is read off as"one 1"or11.
11is read off as"two 1s"or21.
21is read off as"one 2, thenone 1"or1211.

Given an integer n, generate the n th sequence.

Note: The sequence of integers will be represented as a string.

....5..1.,
.4.3.....,
.....3..1,
8......2.,
..2.7....,
.15......,
.....2...,
.2.9.....,
..4......

*/
class Solution {
public:
	string countAndSay(int n) {
		string start = "1";

		if (n == 1){
			return start;
		}
		string cur = "";
		int count = 0;
		char ch;
		for (int i = 1; i<n; i++){
			count = 1;
			ch = start[0];

			for (int j = 1; j<start.length(); j++){
				if (start[j] == ch){
					count++;
				}
				else{
					cur = cur + to_string(count) + string(1, ch);
					count = 1;
					ch = start[j];
				}
			}
			cur = cur + to_string(count) + string(1, ch);
			start = cur;
			cur = "";


		}
		return start;
	}
};