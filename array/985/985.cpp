#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "../../include/tools.h"

using namespace std;
class Solution {
public:
    inline bool isEven(int n) {
        return (n & 1) == 0;
    }
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        size_t ALen = A.size(), QLen = queries.size();
        vector<int> answer(QLen);
        int sumEven = 0;
        for (int i = 0; i < ALen; ++i) {
            if (isEven(A[i])) {
                sumEven += A[i];
            }
        }

        for (int i = 0; i < QLen; ++i) {
            int val   = queries[i][0];
            int index = queries[i][1];
            if (isEven(A[index])) {
                if (isEven(val)) {//偶+偶 偶数的数量并未增加，其总和改变了
                    sumEven += val;
                } else {// 偶+奇 丢失一个偶数
                    sumEven -= A[index];
                }
            } else {
                if (!isEven(val)) {// 奇+奇
                    sumEven += A[index] + val;
                }
                // else{奇+偶时不用处理，不影响偶数的和}
            }
            answer[i] = sumEven;
            A[index] += val;
        }
        return answer;
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
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        vector<vector<int>> queries(M);
        for (int i = 0; i < M; ++i) {
            queries[i].resize(2);
            scanf("%d%d", &queries[i][0], &queries[i][1]);
        }
        vector<int> ret = sol.sumEvenAfterQueries(A, queries); 
        println(ret);
    }
    return 0;
}
