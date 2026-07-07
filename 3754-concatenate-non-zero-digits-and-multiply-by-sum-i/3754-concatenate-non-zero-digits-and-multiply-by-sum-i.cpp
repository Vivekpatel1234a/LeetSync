class Solution {
public:
    long long sumAndMultiply(int n) {
      int nz=0;
      int sum=0;
      int pow=1;
      while(n!=0){
        int ele=n%10;
        if(ele!=0){
            nz=ele*pow+nz;
            sum+=ele;
            pow=pow*10;
        }
        n/=10;
      }
      
      return  (long long)nz*sum;
    }
};
////BY STRING
// class Solution {
// public:
//     long long sumAndMultiply(int n) {
//       string str=to_string(n);
//       int nz=0;
//       int sum=0;
//       for(auto ele:str){
//         if(ele!='0'){
//             nz=nz*10+(ele-'0');
//             sum+=ele-'0';
//         }
//       }
//       return nz*sum;  
//     }
// };