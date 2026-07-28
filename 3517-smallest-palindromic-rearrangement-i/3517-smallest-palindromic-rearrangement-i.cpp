class Solution {
 public:
     //sort half and then copy the same number from the end
     string smallestPalindrome(string s) {
        int n=s.size();
        int mid=n/2;
        sort(s.begin(),s.begin()+mid);
        for(int i=0; i<mid; i++){
            s[n-1-i]=s[i];
        }
        return s;
        }
};

// ////take two part and sort both of them
// class Solution {
// public:
//     string smallestPalindrome(string s) {
//        int n=s.size();
//        int i=0; 
//        int j=n-1;
//        string h1="";
//        string h2="";
//        while(i<j){
//         h1+=s[i++];
//         h2+=s[j--];
//        }
//        sort(h1.begin(),h1.end());
//        sort(h2.rbegin(),h2.rend());
//        string ans=h1;
//        if(i<=j)ans+=s[i];
//        ans+=h2;
//        return ans;
//     }
// };



///////////you can also solve using vector arrray of size 26
/*
class Solution {
public:
    string smallestPalindrome(string s) {
       vector<int>mp(26,0);
        int n=s.size();
        string ans(n,' ');
        int i=0;
        int j=n-1;
        for(auto ele:s)mp[ele-'a']++;
        for(int k=0; k<26; k++){
            char ch=char(k+'a');
            int cnt=mp[k];
                while(cnt>1){
                    if(cnt>1){
                        ans[i++]=ch;
                        cnt--;
                        mp[k]--;
                    }
                    if(cnt){
                        ans[j--]=ch;
                        cnt--;
                        mp[k]--;
                    }
                }
        }
        for(int k=0; k<26; k++){
            char ch=char(k+'a');
            int cnt=mp[k];
            if(cnt==1){
                cout<<ch;
                ans[i++]=ch;
            }
        }
        return ans;
    }
};*/