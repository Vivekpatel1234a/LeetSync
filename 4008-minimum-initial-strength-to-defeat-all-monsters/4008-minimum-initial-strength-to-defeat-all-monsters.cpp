class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
     int n=monsters.size();
     vector<long long>ps(n+1,0);//prestrength
     for(auto ele:boosts){
        int st=ele[0];
        int end=ele[1];
        int bonus=ele[2];
        ps[st]+=bonus;
        ps[end+1]-=bonus;
    }
    long long sum=0;
    for(int i=0; i<n; i++){
        sum+=ps[i];
        ps[i]=sum;
    }
    long long low=0;
    long long high=LLONG_MAX;
    long long mid;
    long long ans=0;
    while(low<=high){
        mid=low+(high-low)/2;
        long long is=mid;//initial strength
        bool flag=false;
        for(int i=0; i<n; i++){
            if(is>=monsters[i]-ps[i]){
                is=max(0LL,is-monsters[i]);
            }
            else{
                flag=true;
                break;
            }
        }
        if(flag){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }

     return ans;
    }
};