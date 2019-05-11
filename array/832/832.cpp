/*
 *  这个题目很简单；最直观的办法就是遍历两次矩阵：一次翻转，一次反转。
 *  但实际上只需要遍历一次矩阵。
 */
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> result = A;
        for (int i = 0; i < result.size(); ++i) {
            int len = result.size();
            int mid = (len+1)>>1;
            for (int j = 0; j < mid; ++j) {
                int rj = len-1-j;
                if (result[i][j] == result[i][rj]) {
                    result[i][j] ^= 1;
                    if (j != rj) {
                        result[i][rj] ^= 1;
                    }
                }
            }
        }
        return result;
    }
};

#define yy
int main() {
#ifdef yy
    freopen("in", "r", stdin);
#endif
    Solution sol;
    int row, col;
    while (scanf("%d %d", &row, &col) != EOF) {
        vector<vector<int>> A(row);
        for (int i = 0; i < row; ++i) {
            A[i] = vector<int>(col);
            for (int j = 0; j < col; ++j) {
                scanf("%d", &A[i][j]);
            }
        }
        vector<vector<int>> result = sol.flipAndInvertImage(A);
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result[i].size(); ++j) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
