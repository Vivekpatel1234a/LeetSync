class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0])
        return a[1] > b[1];   
    return a[0] < b[0];      
}
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt=1;
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        int st,end;
        st=intervals[0][0];
        end=intervals[0][1];
        int i=1;
        while(i<n){
            int st2=intervals[i][0];
            int end2=intervals[i][1];
            i++;
            if(st<=st2 && end>=end2)continue;
            else{
                st=st2;
                end=end2;
                cnt++;
            }
        }
        return cnt;
    }
};