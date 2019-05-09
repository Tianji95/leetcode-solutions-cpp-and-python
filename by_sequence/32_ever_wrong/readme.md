这个stack用的很巧，保存的是上一个失败时候的index，然后遇到一个)就计算一次长度，这时的长度是和上次失败的长度的差值

还有一个两遍pass，但是空间复杂度是O(1)的算法，不过这里只有java代码：这段代码比较巧妙的是，用了一个left和一个right，如果right》left则全部置为0， 如果right小于left，则按照闭合时候（left==right）来计算长度，这样从左到右算一遍以后，肯定会出现遗漏，例如 （）（（（）），会把右边四个遗漏掉，然后就从右往左pass一遍，只不过这个时候right< left的时候才全部置为0
    
    public class Solution {
        public int longestValidParentheses(String s) {
            int left = 0, right = 0, maxlength = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') {
                    left++;
                } else {
                    right++;
                }
                if (left == right) {
                    maxlength = Math.max(maxlength, 2 * right);
                } else if (right >= left) {
                    left = right = 0;
                }
            }
            left = right = 0;
            for (int i = s.length() - 1; i >= 0; i--) {
                if (s.charAt(i) == '(') {
                    left++;
                } else {
                    right++;
                }
                if (left == right) {
                    maxlength = Math.max(maxlength, 2 * left);
                } else if (left >= right) {
                    left = right = 0;
                }
            }
            return maxlength;
        }
    }