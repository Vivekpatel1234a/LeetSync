class Solution {
public:
    bool checkString(string s) {
        bool flag=false;
        for(auto ele:s){
            if(flag==true && ele=='a')return false;
            if(ele=='b')flag=true;
        }
        return true;
    }
};