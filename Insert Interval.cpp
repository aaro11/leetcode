/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool func(Interval i1, Interval i2){
    return i1.start < i2.start;
}
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        int len = intervals.size();
        
        for (int i = 0; i != len; i++){
            if (intervals[i].end < newInterval.start || intervals[i].start > newInterval.end)
                result.push_back(intervals[i]);
            else{
                if (intervals[i].start < newInterval.start)
                    newInterval.start = intervals[i].start;
                if (intervals[i].end > newInterval.end)
                    newInterval.end = intervals[i].end;
            }
        }
        result.push_back(newInterval);
        if (result.size() > 1)
            sort(result.begin(), result.end(), func);
        
        return result;
    }
};