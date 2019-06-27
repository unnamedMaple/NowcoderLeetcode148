class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {

		solve(board);


	}

	bool solve(vector<vector<char>>&board){
		int nine = 9;
		for (int i = 0; i<nine; i++){
			for (int j = 0; j<nine; j++){
				if (board[i][j] != '.'){
					continue;
				}

				for (int k = 1; k <= nine; k++){
					board[i][j] = k + '0';
					if (check(board, i, j)){
						if (solve(board)){
							return true;
						}

					}

				}
				board[i][j] = '.';
				return false;


			}
		}
		return true;


	}

	bool check(vector<vector<char> > &board, int row, int col){
		int nine = 9;
		vector<bool>rowflag(nine, false);
		vector<bool>colflag(nine, false);

		vector<bool>subPuzzle(nine, false);
		for (int i = 0; i<nine; i++){
			if (board[row][i] == '.'){
				continue;
			}
			else{
				if (rowflag[board[row][i] - '0' - 1] == true){
					return false;
				}
				else{
					rowflag[board[row][i] - '0' - 1] = true;
				}
			}

		}

		for (int i = 0; i<nine; i++){
			if (board[i][col] == '.'){
				continue;
			}
			else{
				if (colflag[board[i][col] - '0' - 1] == true){
					return false;
				}
				else{
					colflag[board[i][col] - '0' - 1] = true;
				}
			}

		}

		for (int i = 0; i<3; i++){
			for (int j = 0; j<3; j++){
				if (board[row / 3 * 3 + i][col / 3 * 3 + j] == '.'){
					continue;
				}
				else{
					if (subPuzzle[board[row / 3 * 3 + i][col / 3 * 3 + j] - '0' - 1] == true){
						return false;
					}
					else{
						subPuzzle[board[row / 3 * 3 + i][col / 3 * 3 + j] - '0' - 1] = true;
					}
				}

			}
		}

		return true;

	}




};