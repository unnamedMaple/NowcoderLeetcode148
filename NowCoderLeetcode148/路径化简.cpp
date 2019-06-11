/*������ü򻯸�����·�����������Ŀ�и�����һ�����ӻ��治̫���ܽ�����ɣ�
Ӧ���ټ����������� path = "/a/./b/../c/", => "/a/c"��path = "/a/./b/c/", => "/a/b/c"��
�������ǾͿ���֪���м���"."�����ֱ��ȥ������".."ʱɾ�������氤�ŵ�һ��·����
������ı߽���������һЩ����п��Ե�֪������ǿյĻ�����"/"������ж��"/"ֻ����һ����
��ô���ǿ��԰�·����������һ������"/"�ָ���ڶ����ַ����������Ƿֱ���ȡ����һһ������
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