class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto ele:s)mp[ele]++;
        priority_queue<pair<int,char>>pq;
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        string ans="";
        while(!pq.empty() && pq.size()>=2){
            auto it=pq.top();
            char ch1=it.second;
            int freq1=it.first;
            freq1--;
            pq.pop();
            auto it2=pq.top();
            char ch2=it2.second;
            int freq2=it2.first;
            freq2--;
            pq.pop();
            ans=ans+ch1+ch2;
            if(freq1){
                pq.push({freq1,ch1});
            }
            if(freq2){
                pq.push({freq2,ch2});
            }
        }
        int sz;
        if(pq.size()){
             sz=pq.top().first;
            ans=ans+pq.top().second;
        }
        if(sz>1)return "";

           return ans; 
        
    }
};