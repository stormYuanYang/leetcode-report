#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

using namespace std;

class Solution {
public:
    // 按斜线比较
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        size_t RLen = matrix.size(), CLen = matrix[0].size();
        // 右上
        for (int i = 0; i < CLen - 1; ++i) {
            for (int r = 0, c = i; r < RLen - 1; ++r) {
                if (matrix[r][c] != matrix[r+1][c+1]) {
                    return false;
                }
            }
        }
        // 左下
        for (int i = 1; i < RLen - 1; ++i) {
            for (int r = i, c = 0; c < CLen - 1; ++c) {
                if (matrix[r][c] != matrix[r+1][c+1]) {
                    return false;
                }
            }
        }
        return true;
    }
    // 顺序遍历比较（代码编写更容易)
    // 每次比较两行组成的子矩阵是否是ToeplitzMatrix
    bool isToeplitzMatrix_new(vector<vector<int>>& matrix) {
        size_t RLen = matrix.size(), CLen = matrix[0].size();
        for (int r = 0; r < RLen - 1; ++r) {
            for (int c = 0; c < CLen - 1; ++c) {
                if (matrix[r][c] != matrix[r+1][c+1]) {
                    return false;
                }
            }
        }
        return true;
    }

    // 进阶 一次只能处理一行矩阵的解决办法
    // 为方便提交leetcode测试，这里仍然传入matrix
    // 在函数内部进行一次只能读取一行的模拟
    bool isToeplitzMatrix_1(vector<vector<int>>& matrix) {
        size_t RLen = matrix.size(), CLen = matrix[0].size();
        vector<int> tmp(CLen);
        // 这个循环相当于 从磁盘读入一行到内存
        // 为模拟此行为，循环内不能直接使用RLen，RLen只能用来遍历矩阵的行
        for (int i = 0; i < RLen; ++i) {
            if (i == 0) {
                for (int j = 0; j < CLen; ++j) {// 模拟从磁盘读入一行数据到内存
                    tmp[j] = matrix[i][j];
                }
            } else {
                // 从磁盘读入新的一行
                for (int j = CLen - 1; j > 0; --j) { 
                    if (matrix[i][j] != tmp[j-1]) {
                        return false;
                    } else {// 更新当前行的内容
                        tmp[j] = matrix[i][j];
                    }
                }
                // 新的第一个元素直接覆盖tmp中的第一个元素即可
                tmp[0] = matrix[i][0];
            } 
        }
        return true;
    }
    // 进阶 一次只能将部分行加载到内存中的解决办法
    // 可用isToeplitzMatrix先判断读入的子矩阵是否是拓普利兹矩阵
    // 然后保留最后一行，继续读入若干行；那么由留下的最后一行和
    // 新读入的若干行就构成了新的子矩阵，继续判断其是否是拓普利兹矩阵；
    // 如此循环，直到矩阵的所有行都读入
    bool isToeplitzMatrix_2(vector<vector<int>>& matrix) {
        // TODO
        return true;
    }
};

#define yy
int main() {
#ifdef yy
    freopen("in", "r", stdin);
#endif
    Solution sol;
    int N, M;
    while (scanf("%d%d", &N, &M) != EOF) {
        assert(N > 0 && M > 0);
        vector<vector<int>> A(N);
        for (int i = 0; i < N; ++i) {
            A[i].resize(M);
            for (int j = 0; j < M; ++j) {
                scanf("%d", &A[i][j]);
            }
        }
        bool ret = sol.isToeplitzMatrix_1(A); 
        println(ret);
    }
    return 0;
}
