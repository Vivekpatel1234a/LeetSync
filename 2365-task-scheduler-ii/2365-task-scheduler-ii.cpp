class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long>mp;
        long long point=0;
        for(long long i=0; i<tasks.size(); i++){
            if(!mp.count(tasks[i])){
                mp[tasks[i]]=point;
                point++;
            }
            else{
                if(point-mp[tasks[i]]>space){
                    mp[tasks[i]]=point;
                    point++;
                }
                else{
                    long long prev=mp[tasks[i]];
                    point=prev+space+1;
                    mp[tasks[i]]=point;
                    point++;
                }
            }
            
        }
        return point;
    }
};