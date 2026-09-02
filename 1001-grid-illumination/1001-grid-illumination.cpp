class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        unordered_map<int,int>diag;
        unordered_map<int,int>anti;
        set<pair<int,int>>active;
        for(auto ele:lamps){
            int i=ele[0];
            int j=ele[1];
            if(active.count({i,j}))continue;
            row[i]++;
            col[j]++;
            diag[i-j]++;
            anti[i+j]++;
            active.insert({i,j});
        }
        vector<int>ans;
        for(auto ele:queries){
            int i=ele[0];
            int j=ele[1];
            if(row.count(i) || col.count(j) || diag.count(i-j) || anti.count(i+j)){
                ans.push_back(1);

                for(int r=i-1; r<=i+1; r++){
                    if(r<0 || r>=n)continue;
                    for(int c=j-1; c<=j+1; c++){
                        if(c<0 || c>=n)continue;
                        if(active.count({r,c})){
                        active.erase({r,c});
                        row[r]--;
                        if(row[r]==0)row.erase(r);
                        col[c]--;
                         if(col[c]==0)col.erase(c);
                        diag[r-c]--;
                         if(diag[r-c]==0)diag.erase(r-c);
                        anti[r+c]--;
                         if(anti[r+c]==0)anti.erase(r+c);
                        }
                    }
                }
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};