/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool myFunc(Interval i1, Interval i2){
    return i1.start < i2.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), myFunc);
        vector<Interval> result;
        
        Interval tmp(-1, -1);
        
        for (int i = 0; i != intervals.size(); i++){
            if(tmp.start == -1 && tmp.end == -1){
                tmp = intervals[i];
            }
            else if (tmp.end >= intervals[i].start){
                tmp.end = max(tmp.end, intervals[i].end);
            }else{
                result.push_back(tmp);
                tmp = intervals[i];
            }
        }
        if (tmp.start!= -1 || tmp.end != -1)
            result.push_back(tmp);
            
        return result;
    }
};
