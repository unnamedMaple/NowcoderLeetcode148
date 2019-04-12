
/*


Given a 2D board containing'X'and'O', capture all regions surrounded by'X'.

A region is captured by flipping all'O's into'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
class Solution {
public:
	void solve(vector<vector<char>> &board) {

		int m = board.size();
		if (m <= 1){
			return;
		}
		int n = board[0].size();
		if (n <= 1){
			return;
		}

		for (int i = 0; i<m; i++){
			dfs(board, i, 0);
			dfs(board, i, n - 1);
		}

		for (int j = 0; j<n; j++){
			dfs(board, 0, j);
			dfs(board, m - 1, j);
		}

		for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++){
				if (board[i][j] == 'F'){
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O'){
					board[i][j] = 'X';
				}
			}
		}
		return;
	}
	void dfs(vector<vector<char>> &board, int i, int j){
		int m = board.size();
		int n = board[0].size();
		if (i<0 || i>m - 1 || j<0 || j>n - 1){
			return;
		}

		if (board[i][j] == 'X'){
			return;
		}

		if (board[i][j] == 'O'){
			board[i][j] = 'F';
			dfs(board, i - 1, j);
			dfs(board, i + 1, j);
			dfs(board, i, j - 1);
			dfs(board, i, j + 1);
		}

	}
};