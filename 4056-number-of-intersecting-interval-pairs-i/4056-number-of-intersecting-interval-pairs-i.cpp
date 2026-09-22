class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
       int n=intervals.size();
       sort(intervals.begin(),intervals.end());
       int cnt=0;
       for(int i=0; i<n; i++){
        int st=intervals[i][0];
        int end=intervals[i][1];
        for(int j=i+1; j<n; j++){
            int st2=intervals[j][0];
            int end2=intervals[j][1];
            if(i!=j){
                if(st2>=st && end>=st2)cnt++;
               
            }
        }
        
       }
    return cnt;
    }
};