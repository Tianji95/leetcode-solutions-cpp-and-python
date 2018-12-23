class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left, right, top, bottom;
        
        left = std::max(A, E);
        right = std::min(C, G);
        top = std::min(D, H);
        bottom = std::max(B, F);
        int common;
        if(left > right || bottom > top)
            common = 0;
        else
            common = (right-left) * (top-bottom);
        
        
        return (C-A)*(D-B)+(G-E)*(H-F)-common;
        
    }
};