#ifndef PtrLearning
#define PtrLearning

#include <stdio.h>  // ������׼��������⣬��Ϊ����ʹ�� printf

#define MONTHS 12  // �·ݵ�����
#define YEARS 5  // ��ݵ�����
#define SIZE 4   // SIZE �Ķ���
#define SIZE1 10

// ����ԭ������
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