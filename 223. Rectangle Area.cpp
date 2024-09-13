class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int len1 = ax1 - ax2;
        int breadth1 = ay1 - ay2;
        int len2 = bx1 - bx2;
        int breadth2 = by1 - by2;

        int totalAreaWithOrWithoutOverlap = abs(len1 * breadth1) + abs(len2 * breadth2);
        

        int axis_X_overlapStartX = max(ax1, bx1);
        int axis_X_overlapEndX = min(ax2, bx2);
        int axis_Y_overlapStartY = max(ay1, by1);
        int axis_Y_overlapEndY = min(ay2, by2);

        //Extreme points are(axis_X_overlapStartX, axis_Y_overlapStartY) (axis_X_overlapEndX, axis_Y_overlapEndY)
        int overLapArea = 0;

        int len3 =  axis_X_overlapEndX - axis_X_overlapStartX;
        int breadth3 = axis_Y_overlapEndY - axis_Y_overlapStartY;
        cout << len3 << " "<< breadth3;
        
        if(len3 > 0 && breadth3 >0) {
            overLapArea = len3 * breadth3;
        }

        return totalAreaWithOrWithoutOverlap - overLapArea;
        
    }
};