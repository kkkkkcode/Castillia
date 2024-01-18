#include "PtrLearning.h"


int rain(float precipitation[YEARS][MONTHS]) {
	//计算每年的总降水量，年平均降水量和每月的平均降水量
	//传入二维数组时，编译器至少需要知道第二个维度的数组大小，不可以传入float array[][],至少是float array[][x]
	float totalByYear[YEARS] = { 0 };
	float averByYear[YEARS] = { 0 };
	float averByMonth[MONTHS] = { 0 };
	for (int i = 0; i < YEARS; i++) {
		for (int j = 0; j < MONTHS; j++) {
			totalByYear[i] += precipitation[i][j];
		}  
		averByYear[i] = totalByYear[i] / MONTHS;
	}
	for (int j = 0; j < MONTHS; j++) {
		for (int i = 0; i < YEARS; i++) {
			averByMonth[j] += precipitation[i][j];
		}
		averByMonth[j] /= YEARS;
	}
	printf("年总降水量：\n");
	printArr(YEARS, totalByYear);
	printf("年平均降水量：\n");
	printArr(YEARS, averByYear);
	printf("月平均降水量：\n");
	printArr(MONTHS, averByMonth);
	return 0;
}

void printArr(int rows, float* array) {
	for (int i = 0; i < rows; i++) {
		printf("%f ", array[i]);
	}
	printf("\n");
}

void testRain() {
	float precipitation[5][12] = {
		{8.85, 81.73, 51.97, 65.82, 29.10, 53.65, 91.47, 97.26, 79.33, 7.35, 94.33, 52.21},
		{83.67, 88.72, 18.90, 86.69, 74.18, 63.53, 9.88, 57.71, 2.61, 9.85, 4.92, 53.89},
		{0.12, 22.02, 27.22, 2.70, 64.90, 47.93, 49.13, 20.90, 85.77, 89.09, 80.09, 20.31},
		{86.93, 76.04, 16.06, 99.97, 78.59, 79.59, 70.35, 85.53, 65.40, 18.92, 44.75, 34.16},
		{62.16, 77.13, 76.42, 41.80, 30.46, 26.06, 58.31, 54.18, 97.02, 8.38, 98.17, 99.64}
	};
	rain(precipitation);
}

int timesChart() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d * %d = %d ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}

int pnt_add() {
	short dates[SIZE];
	short* pti;
	short index;
	double bills[SIZE];
	double* ptf;
	//数组名是数组首元素的地址 arr == &arr[0];
	pti = dates; //等效于pti = &dates[0];
	ptf = bills; //等效于ptf = &bills[0];
	printf("%23s %15s\n", "short", "double");
	for (index = 0; index < SIZE; index++) {
		//%p以十六进制表示指针的值
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	}
	printf("%p %p\n", dates + 2, &dates[2]);
	printf("%d\n", dates + 2 == &dates[2]);
	printf("%d %d\n", *(dates + 2), dates[2]);
	printf("%d\n", *(dates + 2) == dates[2]);
	return 0;
}

/*
结果分析：
				  short          double
pointers + 0: 000000E66DBBF728 000000E66DBBF788
pointers + 1: 000000E66DBBF72A 000000E66DBBF790
pointers + 2: 000000E66DBBF72C 000000E66DBBF798
pointers + 3: 000000E66DBBF72E 000000E66DBBF7A0
地址是十六进制的，short类型的指针+1后地址比原来大2，double类型的指针+1后地址比原来大8
地址按照字节编址，short占用2字节，而double占用8字节
在C语言中，指针+1指的是增加一个存储单元
对数组而言，这意味着加1后的地址是下一个元素的地址，而不是下一个字节的地址
这是为什么必须声明指针所指向对象类型的原因之一。只知道地址不够，因为计算机要知道储存对象需要多少字节
dates + 2 == &date[2] //相同的地址
*(dates + 2) == dates[2] //相同的值

*/

int day_mon3() {
	int days[MONTHS] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int index;
	for (index = 0; index < MONTHS; index++) {
		printf("Months %2d has %d days.\n", index + 1, *(days + index));
	}
	return 0;
}

int sum(int ar[], int len) {
	int total = 0;
	for (int i = 0; i < len; i++) {
		total += *(ar + i);
	}
	//printf("The size of ar is %zd bytes\n", sizeof ar);
	return total;
}

int sum_arr1() {
	int marbles[SIZE1] = { 20,10,5,39,4,16,19,26,31,20 };
	long answer = sum(marbles, SIZE1);
	printf("数组之和是 %ld\n", answer);
	printf("数组大小是 %zd\n", sizeof marbles);
	return 0;
}

int sump(int* start, int* end) {
	int total = 0;
	while (start < end) {
		//一元运算符*（对该指针解引用，获取指针所指向的内存地址中存储的值）和++的优先级相同，
		//但顺序是从右往左，先自增，令start指向数组的下一个元素，之后再使用*来解引用
		total += *start++;
		//printf("%p\n",start);//start代表：指针，内容是地址
		//printf(" % d\n", *start);//*start代表：指针指向的值，内容是数值，在这一例中，内容是int整数
	}
	return total;
}

int sum_arr2() {
	int marbles[SIZE1] = { 20,10,5,39,4,16,19,26,31,20 };
	//C保证在给数组分配空间时，指向数组后面第一个位置的指针仍是有效的指针
	long answer = sump(marbles, marbles + SIZE1);
	printf("数组之和是 %ld\n", answer);
	printf("数组大小是 %zd\n", sizeof marbles);
	return 0;
}













