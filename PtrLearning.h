#ifndef PtrLearning
#define PtrLearning

#include <stdio.h>  // 包含标准输入输出库，因为函数使用 printf

#define MONTHS 12  // 月份的数量
#define YEARS 5  // 年份的数量
#define SIZE 4   // SIZE 的定义
#define SIZE1 10

// 函数原型声明
void printArr(int rows, float* array);
void testRain();
int rain(float precipitation[5][12]);
int timesChart();
int pnt_add();
int day_mon3();
int sum(int ar[], int len);
int sum_arr1();
int sump(int* start, int* end);
int sum_arr2();

#endif