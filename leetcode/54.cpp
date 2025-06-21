class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int xMin = 1, yMin = 0;
       int xMax = matrix.size(), yMax = matrix[0].size();

       vector<int> res;
       int x = 0, y = 0;
       int dx = 0, dy = 1;
       int total = xMax * yMax;
       
       for (int i = 0; i < total; ++i) {
            std::cout << " " << x << " " << y << " " <<  dx << " " << dy << std::endl;
            res.push_back(matrix[x][y]);
            if (dy and y + dy >= yMax) {
                yMax--;
                dx = 1;
                dy = 0;
            } else if (dx and x + dx >= xMax) {
                xMax--;
                dx = 0;
                dy = -1;
            } else if (dy and y + dy < yMin) {
                yMin++;
                dy = 0;
                dx = -1;
            } else if (dx and x + dx < xMin) {
                xMin++;
                dx = 0;
                dy = 1;
            }
            x += dx;
            y += dy;
       }
       return res;
    }
};
