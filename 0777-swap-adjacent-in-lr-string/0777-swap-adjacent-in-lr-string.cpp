class Solution {
public:
    bool canTransform(string start, string result) {
        int i=0;
        int j=0;
        int m=start.size();
        int n=result.size();
        while(i<m || j<n){
            while(start[i]=='X' && i<m)i++;
            while(result[j]=='X' && j<n)j++;
            if(start[i]!=result[j])return false;
            if(result[j]=='L' && i<j)return false;
            if(result[j]=='R' && i>j)return false;
            i++;
            j++;
        }
        if(i==m || j==n){
            return (i==m && j==n);
        }
        return true;
        } 
    
};