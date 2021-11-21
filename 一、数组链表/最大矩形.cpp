class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> left(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;     //对每个位置求其左侧有几个1的方块（包括自己）
                }
            }
        }
        left.push_back(vector<int>(col, 0));        //加上一行0，用于单调栈的计算，行数也增加
        row++;
        int ans = 0;
        for (int j = 0; j < col; j++) {             //竖着将每一列看作求柱状图中最大矩形
            stack<Rect> stk;
            for (int i = 0; i < row; i++) {
                int widthSum = 0;
                while (!stk.empty() && left[i][j] < stk.top().height) { //处理每个大于当前高度的栈顶元素
                    widthSum += stk.top().width;                        //长度累计
                    ans = max(ans, widthSum * stk.top().height);        //计算最大面积
                    stk.pop();                                          //弹出
                }
                stk.push(Rect{1 + widthSum, left[i][j]});               //压入新矩形
            }
        }
        return ans;
    }
private:
    struct Rect {
        int width;
        int height;
    };
};