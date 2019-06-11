class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (word == ""){
			return true;
		}
		int m = board.size();
		int n = board[0].size();

		vector<vector<bool>>visited(m, vector<bool>(n, false));
		int index = 0;
		for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++){
				if (dfs(board, i, j, index, word, visited) == true){
					return true;
				}
			}
		}
		return false;
	}

	bool dfs(vector<vector<char> > &board, int i, int j, int index, string &word, vector<vector<bool>>&visited){
		if (index == word.length()){
			return true;
		}
		if (i >= board.size() || i<0 || j >= board[0].size() || j<0 || visited[i][j] == true || board[i][j] != word[index]){
			return false;
		}

		visited[i][j] = true;
		bool ret = dfs(board, i + 1, j, index + 1, word, visited) || dfs(board, i, j + 1, index + 1, word, visited)
			|| dfs(board, i - 1, j, index + 1, word, visited) || dfs(board, i, j - 1, index + 1, word, visited);
		visited[i][j] = false;

		return ret;
	}
};