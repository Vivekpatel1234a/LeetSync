class Solution {
public:
    string smallestPalindrome(string s) {
       int n=s.size();
       int i=0; 
       int j=n-1;
       string h1="";
       string h2="";
       while(i<j){
        h1+=s[i++];
        h2+=s[j--];
       }
       sort(h1.begin(),h1.end());
       sort(h2.rbegin(),h2.rend());
       string ans=h1;
       if(i<=j)ans+=s[i];
       ans+=h2;
       return ans;
    }
};