class Solution {
public:
    int reverseDegree(string s) {
        int c=0;
int p=0;
int n=s.size();
for(int i=1; i<=n; i++){
    c=c+i*(abs(int(s[p])-123));
    p++;
   
   
}
return c;
    }
};