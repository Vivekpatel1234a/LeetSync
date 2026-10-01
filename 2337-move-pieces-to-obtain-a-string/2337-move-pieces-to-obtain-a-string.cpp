class Solution {
    public:
     bool canChange(string start, string target) {
        int i=0;
        int j=0;
        int m=start.size();
        int n=target.size();
        while(i<m || j<n){
            while(start[i]=='_' && i<m)i++;
            while(target[j]=='_' && j<n)j++;
            if(start[i]!=target[j])return false;
            if(target[j]=='L' && i<j)return false;
            if(target[j]=='R' && i>j)return false;
            i++;
            j++;
        }
        if(i==m || j==n){
            return (i==m && j==n);
        }
        return true;
        }
};
///////////////////MLE////////////////////
// class Solution {
// public:

//     int solve(string start, string target, unordered_map<string,int>mp){
      
//         int n=start.size();
//         if(mp.count(start))return mp[start];
//           if(start==target)return 1;
//         for(int i=0; i<n; i++){
//             if(start[i]=='_')continue;
//             else if(start[i]=='L'){
//                 if(i-1>=0 && start[i-1]=='_'){
//                     swap(start[i-1],start[i]);
//                     if(solve(start,target,mp)==true)return true;
//                     swap(start[i-1],start[i]);
//                 }
//             }
//             else if(start[i]=='R'){
//                 if(i+1<n && start[i+1]=='_'){
//                     swap(start[i],start[i+1]);
//                     if(solve(start,target,mp))return true;
//                     swap(start[i],start[i+1]);
//                 }
//             }

//         }
//         return mp[start]=false;
//     }

//     bool canChange(string start, string target) {
//      int m=start.size();
//      int n=target.size();
//      unordered_map<string,int>mp;
//      return solve(start,target,mp);  
//     }
// };