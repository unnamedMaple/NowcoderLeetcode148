/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };

Given a collection of intervals, merge all overlapping intervals.

For example,
Given[1,3],[2,6],[8,10],[15,18],
return[1,6],[8,10],[15,18].

*/
class Solution {
public:
	bool static cmp(Interval &a, Interval &b){
		return a.start<b.start;
	}
	vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.size() <= 1){
			return intervals;
		}
		sort(intervals.begin(), intervals.end(), cmp);
		Interval cur = intervals[0];


		vector<Interval>ret;

		for (int i = 1; i<intervals.size() - 1; i++){
			if (cur.end<intervals[i].start){
				ret.push_back(cur);
				cur = intervals[i];


			}
			else if (intervals[i].end<cur.start){
				ret.push_back(intervals[i]);

			}
			else{
				cur.start = min(cur.start, intervals[i].start);
				cur.end = max(cur.end, intervals[i].end);

			}

		}


		if (cur.end<intervals[intervals.size() - 1].start){
			ret.push_back(cur);
			ret.push_back(intervals[intervals.size() - 1]);


		}
		else if (intervals[intervals.size() - 1].end<cur.start){
			ret.push_back(intervals[intervals.size() - 1]);
			ret.push_back(cur);
		}
		else{
			cur.start = min(cur.start, intervals[intervals.size() - 1].start);
			cur.end = max(cur.end, intervals[intervals.size() - 1].end);
			ret.push_back(cur);
		}
		return ret;

	}
};