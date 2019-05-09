class Solution {
public
    int trap(vectorint& height) {
        stackint value;
        stackint index;
        
        int len = height.size();
        
        int out = 0;
        
        for(int i = 0; i  len; i++){
            if(height[i]!=0){
                if(value.size()==0){
                    value.push(height[i]);
                    index.push(i);
                }
                else{
                    int prevTop = 0;
                    int top = value.top();
                    int idx = index.top();
                    while(value.size()!=0 && top = height[i]){
                        out += (top-prevTop)  (i - idx - 1);
                        value.pop();
                        index.pop();
                        prevTop = top;
                        if(value.size()!=0){
                            top = value.top();
                            idx = index.top();
                        }
                    }
                    if(topheight[i]){
                        out += (height[i] - prevTop)(i-idx-1);
                    }
                    value.push(height[i]);
                    index.push(i);
                }
            }
        }
        
        
        return out;
    }
};