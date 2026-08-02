class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int i=0;
        int n=piles.size();
        int j=n-1;
        int sumA=0;
        int sumB=0;
        while(i<j){
            if(piles[i]<piles[j]){
                sumA+=piles[j];
                sumB+=piles[i];
            }
            else{
                sumA+=piles[i];
                sumB+=piles[j];
            }
            i++;
            j--;
        }
        return sumA>=sumB;
    }
};