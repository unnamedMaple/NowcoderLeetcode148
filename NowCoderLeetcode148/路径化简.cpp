/*这道题让简化给定的路径，光根据题目中给的那一个例子还真不太好总结出规律，
应该再加上两个例子 path = "/a/./b/../c/", => "/a/c"和path = "/a/./b/c/", => "/a/b/c"，
这样我们就可以知道中间是"."的情况直接去掉，是".."时删掉它上面挨着的一个路径，
而下面的边界条件给的一些情况中可以得知，如果是空的话返回"/"，如果有多个"/"只保留一个。
那么我们可以把路径看做是由一个或多个"/"分割开的众多子字符串，把它们分别提取出来一一处理即可
*/
string simplifyPath(string path)
{
	vector<string> res;
	stringstream ss(path);
	string sub;
	while (getline(ss, sub, '/'))
	{
		if (sub == "." || sub == "")
			continue;
		else if (sub == ".." && res.size())
			res.pop_back();
		else if (sub != "..")
			res.push_back(sub);
	}
	string result;
	for (string temp : res)
		result += '/' + temp;
	return res.empty() ? "/" : result;
}