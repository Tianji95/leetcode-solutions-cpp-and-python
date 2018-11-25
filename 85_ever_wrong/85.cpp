class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int result = 0;
        int n = matrix.size();
        if (n == 0) return result;
        int m = matrix[0].size();
        vector<vector<int>> histogram = vector<vector<int>>(n+1, vector<int>(m, 0));

        for (int i=1; i<=n; ++i) {
            for (int j=0; j<m; ++j) {
                if (matrix[i-1][j] == '1') {
                    histogram[i][j] = 1+histogram[i-1][j];
                }
                // cout << histogram[i][j] << " ";
            }
            // cout << "\n";
        }

        for (int i=0; i<n; ++i) {
            // cout << i << " " << largestRectangleArea(histogram[i+1]) << "\n";
            result = max(result, largestRectangleArea(histogram[i+1]));
        }
        return result;
    }
    
    void getHistogram(vector<vector<bool>>& matrix, vector<vector<int>>& hist, int i, int cols) {
        for (int j=0; j<cols; ++j) {
            if (matrix[i][j]) {
                for (int k=i; k>=0; --k) {
                    if (matrix[k][j]) {
                        ++hist[i][j];
                    } else {
                        break;
                    }
                }
            }
        }
    }
    
    int largestRectangleArea(vector<int> &height) {
        int result = 0;
        int len = height.size();
        if (len == 0)   return result;
        stack<int> sk;          // ascending order, subscript
        int left_sub[len], right_sub[len];
        for (int i=0; i<len; ++i) {
            left_sub[i] = -1;
            right_sub[i] = len;
        }

        for (int i=0; i<len; ++i) {
            while (!sk.empty()) {
                if (height[sk.top()] >= height[i]) {
                    int ref = sk.top();
                    sk.pop();
                    right_sub[ref] = i;
                } else {
                    left_sub[i] = sk.top();
                    break;
                }
            }
            sk.push(i);
        }
        for (int i=0; i<len; ++i) {
            int area = height[i]*(right_sub[i]-left_sub[i]-1);
            result = max(result, area);
        }
        return result;
    }
};