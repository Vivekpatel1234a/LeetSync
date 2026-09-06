class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        deque<int>q1;
        deque<int>q2;
        long long sum1=0;
        for(int i=0; i<n/2; i++){
            q1.push_back(nums[i]);
            sum1+=nums[i];
        }
        long long sum2=0;
        for(int i=n/2; i<n; i++){
            q2.push_back(nums[i]);
            sum2+=nums[i];
        }
        int cnt=0;
        for(int i=0; i<n; i++){
              if(sum1>sum2)cnt++;
              q1.push_back(q2.front());
              q2.pop_front();
              q2.push_back(q1.front());
              q1.pop_front();
              sum1-=q2.back();
              sum1+=q1.back();
              sum2-=q1.back();
              sum2+=q2.back();
        }
        return cnt;
    }
};