class Solution {
public:
    vector<int>arrday={0,31,59,90,120,151,181,212,243,273,304,334,365};
    int count(string& s,int i, int j){
        return stoi(s.substr(i,j));
    }

    int calc(int day, int month){
        int total=day+arrday[month-1];
        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
      int arr1month=count(arriveAlice,0,2);
      int arr2month=count(arriveBob,0,2);
      int arr1day=count(arriveAlice,3,5);
      int arr2day=count(arriveBob,3,5);

      int leave1month=count(leaveAlice,0,2);
      int leave2month=count(leaveBob,0,2);
      int leave1day=count(leaveAlice,3,5);
      int leave2day=count(leaveBob,3,5);
      int startcount1=calc(arr1day,arr1month);
      int startcount2=calc(arr2day,arr2month);
      int endcount1=calc(leave1day,leave1month);
      int endcount2=calc(leave2day,leave2month);
      //cout<<startcount1<<" "<<endcount1<<" "<<startcount2<<" "<<endcount2;
      int total=min(endcount1,endcount2)-max(startcount1,startcount2);
      if(total<0)return 0;
      return total+1;

    }
};