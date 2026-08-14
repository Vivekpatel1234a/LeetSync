class Solution {
public:

   static bool customSort(int a, int b){
       string x=to_string(a);
       string y=to_string(b);
       string ans=x+y;
       string ans2=y+x;
       //cout<<ans<<" "<<ans2<<"     ";
       return ans>ans2;
       /*int i=0;
       int j=0;
       int m=x.size();
       int n=y.size();
       while(i<m && j<n){
        if(x[i]-'0'>y[i]-'0')return true;
        else if(x[i]-'0'<y[i]-'0') return false;
        i++;
        j++;
       }
       if(i==m){
        if(x[i-1]-'0'>y[j]-'0')return true;
        else if(x[i-1]-'0'<=y[j]-'0')return false;
       }
       if(j==n){
        if(x[i]-'0'>y[j-1]-'0')return true;
        else if(x[i]-'0'<=y[j-1]-'0')return false;
       }

       
       return 1;*/
       return 0;
    }

    string largestNumber(vector<int>& nums) {
     sort(nums.begin(),nums.end(),customSort);
     string ans="";
     bool z=0;
     for(auto ele:nums){
        if(ele>0)z=1;
        ans+=to_string(ele);
     }
     if(z==0)return "0";
     return ans; 
    }
};