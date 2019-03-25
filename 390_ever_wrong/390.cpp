class Solution {
public:
    int lastRemaining(int n) {
        bool isLeft2Right = true;
        int remainNum = n;
        int step = 1;
        int head = 1;
        
        while(remainNum > 1){
            if(isLeft2Right || remainNum % 2==1){
                head = head + step;
            }
            step *= 2;
            isLeft2Right = !isLeft2Right;
            remainNum /= 2;
        }
    }
};