#ifndef tools_h
#define tools_h

#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector> 
#include <string>
using namespace std; 

/*
 * 注意 tools.h不使用cout对参数进行打印（虽然使用cout更加方便)。
 * 这只是一个玩具类型的方法库，方便做题时调试，所以所有工具
 * 方法都放在同一个头文件，并不进行分类和拆分。
 * 所有函数均实现在头文件中，不单独放在c文件。
 * 
 * 打印函数：主要利用C++提供的函数重载功能，分别对不同C类型的数据进行打印。
 */

/* 打印函数均命名为print或者println 
 * 然后对print和println进行重载
 * print只打印指定的元素不换行
 * println会换行
 */

// print
inline void printLine() {
    putchar('\n');
}

inline void printBlankSpace() {
    putchar(' ');
}

inline void print(int a) {
    printf("%d", a);
}

inline void print(unsigned int a) {
    printf("%u", a);
}

inline void print(double a) {
    printf("%f", a);
}

inline void print(const char* str) {
    assert(str);
    printf("%s", str);
}

inline void print(const string& str) {
    const char* cstr = str.c_str();
    assert(cstr);
    print(cstr);
}

// 打印数组
void print(const auto A, size_t size) {
    assert(A);
    for (size_t i = 0; i < size; ++i) {
        print(A[i]);
        printBlankSpace();
    }
}

void print(const vector<auto>& A) {
    for (size_t i = 0; i < A.size(); ++i) {
        print(A[i]);
        printBlankSpace();
    }
}

// 打印二维数组

// 注意这个函数不支持子数组长度不一致的数组
// 比如，int* A[5]; A[0] = malloc(sizeof(int)*3);A[1] = malloc(sizeof(int)*5);
// 数组A[0]的长度为3，数组A[1]的长度为5;这种二维数组暂时不支持
// 一般而言，int A[5][2]；这样的数组会被支持
void print(const auto A, size_t size1, size_t size2) {
    assert(A);
    for (size_t i = 0; i < size1; ++i) {
        print(A[i], size2);
        printLine();
    }
}


// println
inline void println(int a) {
    print(a);
    printLine();
}

inline void println(unsigned int a) {
    print(a);
    printLine();
}

inline void println(double a) {
    print(a);
    printLine();
}

inline void println(const char* str) {
    print(str);
    printLine();
}

inline void println(const string& str) {
    print(str);
    printLine();
}

inline void println(const auto A, size_t size) {
    print(A, size);
    printLine();
}

inline void println(const vector<auto>& A) {
    print(A);
    printLine();
}

void println(const auto A, size_t size1, size_t size2) {
    print(A, size1, size2);
}

void println(const vector<const vector<auto>>& A) {
    print(A);
} 
#endif // tools_h
