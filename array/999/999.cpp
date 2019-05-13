#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int RRow, RCol;
        for (int i = 0; i < board.size(); ++i)  {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'R') {
                    RRow = i;
                    RCol = j;
                    break;
                }
            }
        }
        int sum = 0;
        // 左
        for (int j = RCol - 1; j >= 0; --j) {
            if (board[RRow][j] == 'B') {
                break;
            } else if (board[RRow][j] == 'p') {
                ++sum;
                break;
            }
        }
        // 右
        for (int j = RCol + 1; j < board[RRow].size(); ++j) {
            if (board[RRow][j] == 'B') {
                break;
            } else if (board[RRow][j] == 'p') {
                ++sum;
                break;
            }
        }
        // 上
        for (int i = RRow - 1; i >= 0; --i) {
            if (board[i][RCol] == 'B') {
                break;
            } else if (board[i][RCol] == 'p') {
                ++sum;
                break;
            }
        }
        // 下
        for (int i = RRow + 1; i < board.size(); ++i) {
            if (board[i][RCol] == 'B') {
                break;
            } else if (board[i][RCol] == 'p') {
                ++sum;
                break;
            }
        }
        return sum;
    }
};

#define yy
int main() {
#ifdef yy
    freopen("in", "r", stdin);
#endif
    Solution sol;
    int N;
    while (scanf("%d", &N) != EOF) {
        assert(N > 0);
        vector<vector<char>> A(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        println(sol.numRookCaptures(A));
    }
    return 0;
}
