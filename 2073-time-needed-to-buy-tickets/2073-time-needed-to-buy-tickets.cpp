class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0; i<tickets.size(); i++){
            if(i==k)q.push({tickets[i],i});
            else q.push({tickets[i],-1});
        }
        int cnt=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int val=it.first;
            int idx=it.second;
            cout<<val<<" "<<idx<<" "<<cnt<<"   ";
            if(idx!=-1 && val==1)return cnt+1;//////////
            else{
               cnt++;
               if(val!=1)q.push({val-1,idx});
            }
        }
        return cnt;
    }
};