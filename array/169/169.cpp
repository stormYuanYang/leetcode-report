#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include "../../include/tools.h"

using namespace std;

class Solution {
public:
    // 最直接的办法就是用hash表，找到统计数量大于一半的元素
    // 此方法空间复杂度O(n)，时间复杂度O(n)
    int majorityElement(vector<int>& nums) {
        size_t len = nums.size();
        size_t halfLen = len >> 1;
        unordered_map<int, int> ht; 
        for (int i = 0; i < len; ++i) {
            int val = nums[i];
            if (ht.count(val) == 0) {
                ht[val] = 1;
            } else {
                ++ht[val];
            }
            if (ht[val] > halfLen) {
                return val;
            }
        }
        // 数据正确逻辑不会走到这里
        return -1;
    }
    
    // 对区间内的元素按大小进行一次划分，并返回一个下标
    // 这个下标满足：A[begin ~ j-1] <= A[j] <= A[j+1 ~ end]
    int partition(vector<int>& A, int begin, int end) {
        assert(begin <= end);
        if (begin == end) {
            return begin;
        }
        // 随机选择下标，尽量避免一些坏的划分
        int randomIndex = rand() % (end - begin + 1) + begin;
        if (randomIndex != end) {
            swap(A[randomIndex], A[end]);
        }
        int j = begin;
        for (int i = begin; i < end; ++i) {
            if (A[i] <= A[end]) {
                if (j != i) {
                    swap(A[j], A[i]);
                }
                ++j;
            }
        }
        swap(A[j], A[end]);
        return j;
    }

    // 直接用划分的思想 复杂度O(n)，空间复杂度O(1)
    // 比起采用hash表，会多次遍历数组，执行时间会更多
    // 数组中的元素按大小进行划分（并不是排序）
    // 找到第n/2大的那个数，就是众数
    // 因为题目保证众数出现次数大于2/n，
    // 那么按大小划分，直到A[0]～A[n/2 - 1]都小于等于A[n/2]，
    // 此时A[n/2]就是众数（注意，A[0]~A[n/2 - 1]之间并不一定是有序的
    // 只是保证A[0]~A[n/2 - 1]都小于等于A[n/2]）
    //
    // 可以这样验证此方法的正确性：
    // 如果数组已经是按大小排好序(非降序)了，那么众数会出现在什么位置呢？
    // 如果众数就是数组中最小的那个数，则众数的下标一定在[0, 数组size内，
    // 并且左端一定是从0开始,右端至少到达A[n/2]
    // 如果众数就是数组中最小的那个数，则众数的下标一定在(0, 数组size-1],
    // 并且右端一定是从数组size-1开始,左端至少到达A[n/2]
    // 那么A[n/2]一定是众数。
    //
    // 再说划分为什么能求得众数：求众数不要求数组有序，A[n/2]左端的数字都小于等于
    // A[n/2]，那么A[n/2]一定是众数。
    int majorityElement_1(vector<int>& nums) {
        size_t begin = 0, end = nums.size() - 1, halfSize = nums.size() >> 1;
        int index = partition(nums, begin, end); 
        while (index != halfSize) {
            if (index < halfSize) {
                begin = index + 1;
                index = partition(nums, begin, end);
            } else {
                end = index - 1;
                index = partition(nums, begin, end);
            }
        }
        return nums[halfSize];
    }

    int majorityElement_2(vector<int>& nums) {
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
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        println(sol.majorityElement_1(A));
    }
    return 0;
}
