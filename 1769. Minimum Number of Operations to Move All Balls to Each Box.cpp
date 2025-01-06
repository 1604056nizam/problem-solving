class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> distance(boxes.size(), 0), ballBox;
        int leftElementsWhichIsOne = 0, rightShift = 0, rightElementsWhichIsOne = 0, leftShift = 0;
        for(int i = 0; i < boxes.size(); i++) {
            rightShift += leftElementsWhichIsOne;
            distance[i] = rightShift;
            leftElementsWhichIsOne += (boxes[i] - '0');
        }

        for(int i = boxes.size() - 1; i > -1; i--) {
            leftShift += rightElementsWhichIsOne;
            distance[i] += leftShift ;
            rightElementsWhichIsOne += (boxes[i] - '0');
        }

        return distance;
    }
};