class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string>mp;
        for(auto &ele:knowledge){
            mp[ele[0]]=ele[1];
        }
        string temp="";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                ans+=temp;
                temp="";
            }
            else if(s[i]==')'){
                if(mp.count(temp)){
                    ans+=mp[temp];
                }
                else ans+='?';
                temp="";
            }
            else temp+=s[i];
        }
        if(temp.size())ans+=temp; 
        return ans;
    }
};