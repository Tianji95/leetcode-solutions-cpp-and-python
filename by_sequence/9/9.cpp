class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        int back = 0;
        int tmpX = x;
        int revertX = 0;
        while(tmpX){
            back = tmpX % 10;
            revertX = revertX * 10 + back;
            tmpX = tmpX / 10;
        }
        if(revertX == x){
            return true;
        }
        return false;
    }
};