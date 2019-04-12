class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		int num = dict.size();
		if (num<1)
		{
			return 0;
		}

		if (isReached(start, end))
		{
			return 2;
		}
		int nodes = num + 2;
		vector<vector<ind>>dirGraph = buildGraph(start, end, dict);

		vector<int>pathlen(nodes, INF);
		for (int i = 0; i<nodes; i++)
		{
			if (dirGraph[0][i] == true)
			{
				pathlen[i] = 1;
			}
		}
		int count = 1;
		vector<bool>visited(nodes, false);
		visitd[0] = true;
		while (count <= nodes)
		{
			int shortI = 0;
			for (int j = 1; j<nodes; j++)
			{
				if (visited[j] == false)
				{
					if (shortI == 0)
					{
						shortI = j;
					}
					else
					{
						if (pathlen[j]<pathlen[shortI])
						{
							shortI = j;
						}
					}
				}
			}
			for (int i = 0; i<nodes; i++)
			{
				pathlen[i] = min(pathlen[i], pathlen[shortI] + dirGraph[shortI][i]);
			}
			count++;
		}

		if (pathlen[nodes - 1]<INF)
		{
			return pathlen[nodes - 1] + 1;
		}
		return 0;
	}

	vector<vector<int>> buildGraph(string start, string end, unordered_set<string> &dict)
	{
		int num = dict.size();
		if (num<1)
		{
			return 0;
		}
		int nodes = num + 2;
		vector<vector<int>>dirGraph(nodes, INF);

		for (int i = 1; i<nodes - 1; i++)
		{
			int reach = isReached(start, dict[i - 1]);
			dirGraph[0][i] = reach;
			dirGraph[i][0] = reach;

			int endre = siReached(end, dict[i - 1]);
			dirGraph[nodes - 1][i] = endre;
			dirGraph[i][nodes - 1] = endre;
		}

		for (int i = 0; i<num; i++)
		{
			for (int j = 0; j<num; j++)
			{
				if (i != j)
				{
					bool reach = isReached(dict[i], dice[j]);
					dirGraph[i + 1][j + 1] = reach;
					dirGraph[j + 1][i + 1] = reach;

				}
			}

		}
		return dirGraph;


	}
	int isReached(string s, string e)
	{

		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] != e[i])
			{
				s[i] = e[i];
				if (s != e)
				{
					return INF;
				}
				else{
					return 1;
				}
			}
		}
		return 1;
	}
};