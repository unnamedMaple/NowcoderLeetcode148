/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals[1,3],[6,9], insert and merge[2,5]in as[1,5],[6,9].

Example 2:
Given[1,2],[3,5],[6,7],[8,10],[12,16], insert and merge[4,9]in as[1,2],[3,10],[12,16].

This is because the new interval[4,9]overlaps with[3,5],[6,7],[8,10].


*/
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		int len = intervals.size();
		vector<Interval>ret;

		int i = 0;

		bool addnew = false;

		for (i = 0; i<len; i++){
			if (intervals[i].end<newInterval.start){
				ret.push_back(intervals[i]);
			}
			else{


				if (newInterval.end<intervals[i].start){
					ret.push_back(newInterval);
					addnew = true;
					break;

				}
				newInterval.start = intervals[i].start<newInterval.start ? intervals[i].start : newInterval.start;
				if (newInterval.end<intervals[i].end){
					newInterval.end = intervals[i].end;
					ret.push_back(newInterval);
					i++;
					addnew = true;
					break;
				}
			}

		}

		for (; i<len; i++){
			ret.push_back(intervals[i]);
		}

		if (addnew == false){
			ret.push_back(newInterval);
		}
		return ret;
	}
};



//¸ü¼ò½àµÄÐ´·¨
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> res;
		int i = 0;
		for (; i<intervals.size(); i++){
			if (newInterval.end<intervals[i].start)
				break;
			else if (newInterval.start>intervals[i].end)
				res.push_back(intervals[i]);
			else{
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
			}

		}

		res.push_back(newInterval);
		for (; i<intervals.size(); i++)
			res.push_back(intervals[i]);
		return res;
	}
};