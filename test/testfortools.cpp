#include <cstdio>
#include <string>
#include "../include/tools.h"
using namespace std;

void test_print() {
    //print("*"); 
    //// 测试printLine
    //printLine();
    //// 测试打印空格
    //print("*"); 
    //printBlankSpace();
    //print("*");
    //// 测试打印int
    //println(-1);
    //// 测试打印unsigned 
    //println((unsigned)-1);
    //// 测试打印 double
    //println(1.22);
    //// 测试打印C字符串
    //println("Hello World");
    //// 测试打印std::string类型的字符串
    //println(string("QWE"));
    //// 测试打印数组
    //{
    //    int A[5] = {-1, -2, -3, -4, -5};
    //    println(A, 5);
    //    unsigned B[5] = {1, 2, 3, 4, 5};
    //    println(B, 5);
    //    const char* C[2] = {"Hello", "duoli"};
    //    println(C, 2);
    //}
    //{
    //    vector<int> A = {-1, -2, -3, -4, -5};
    //    println(A);
    //    vector<unsigned> B = {1, 2, 3, 4, 5};
    //    println(B);
    //    vector<string> C = {"Hello", "duoli"};
    //    println(C);
    //}
    //// 测试打印二维数组
    //{
    //    int A[2][2] = {{1, 2}, {3, 4}};
    //    print(A, 2, 2);
    //    println(A, 2, 2);
    //}
    {
        vector<vector<int>> A = {{1, 2}, {3, 4, 5}};
        //print(A);
        println(A);
    }
}

int main() {
    test_print();
    return 0;
}
