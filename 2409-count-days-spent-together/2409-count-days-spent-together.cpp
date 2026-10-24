class Solution {
public:
    vector<int>arrday={0,31,59,90,120,151,181,212,243,273,304,334,365};
    int count(string& s,int i, int j){
        return stoi(s.substr(i,j));
    }
    int calc(string& a1,string& a2, string& l1, string& l2){
        int arr1count=arrday[count(a1,0,2)-1]+count(a1,3,5);
        int arr2count=arrday[count(a2,0,2)-1]+count(a2,3,5);
        int end1count=arrday[count(l1,0,2)-1]+count(l1,3,5);
        int end2count=arrday[count(l2,0,2)-1]+count(l2,3,5);
        return min(end1count,end2count)-max(arr1count,arr2count)+1;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    int ans=calc(arriveAlice,arriveBob,leaveAlice,leaveBob);
     return ans<=0?0:ans;

    }
};