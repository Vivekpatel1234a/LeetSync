class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
      int ax=rec1[0];
      int ay=rec1[1];
      int cx=rec1[2];
      int cy=rec1[3];

      int ex=rec2[0];
      int ey=rec2[1];
      int gx=rec2[2];
      int gy=rec2[3]; 
      int bx=cx;
      int fx=gx;
      int dy=cy;
      int hy=gy;
      if(ex>=bx || fx<=ax || ey>=dy || ay>=hy)return 0;
      return 1;    
    }
};