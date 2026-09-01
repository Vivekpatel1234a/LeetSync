class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        vector<pair<double,int>>pr;
        for(int i=0; i<n; i++){
            pr.push_back({boxTypes[i][1],i});
        }
        int ans=0;
        int cap=0;
        sort(pr.rbegin(),pr.rend());
        cout<<endl;
       // for(auto ele:pr)cout<<ele.first<<" "<<ele.second<<"   ";
        for(int i=0; i<n; i++){
            int idx=pr[i].second;
            if(cap+boxTypes[idx][0]<=truckSize){
                cap+=boxTypes[idx][0];
                ans+=boxTypes[idx][0]*boxTypes[idx][1];
            }
            else{
                int remaining=truckSize-cap;
                ans+=boxTypes[idx][1]*remaining;
                break;
            }
        }
        return ans;
    }
};