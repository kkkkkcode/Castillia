#include "PtrLearning.h"


int rain(float precipitation[YEARS][MONTHS]) {
	//����ÿ����ܽ�ˮ������ƽ����ˮ����ÿ�µ�ƽ����ˮ��
	//�����ά����ʱ��������������Ҫ֪���ڶ���ά�ȵ������С�������Դ���float array[][],������float array[][x]
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
	printf("���ܽ�ˮ����\n");
	printArr(YEARS, totalByYear);
	printf("��ƽ����ˮ����\n");
	printArr(YEARS, averByYear);
	printf("��ƽ����ˮ����\n");
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
	//��������������Ԫ�صĵ�ַ arr == &arr[0];
	pti = dates; //��Ч��pti = &dates[0];
	ptf = bills; //��Ч��ptf = &bills[0];
	printf("%23s %15s\n", "short", "double");
	for (index = 0; index < SIZE; index++) {
		//%p��ʮ�����Ʊ�ʾָ���ֵ
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	}
	printf("%p %p\n", dates + 2, &dates[2]);
	printf("%d\n", dates + 2 == &dates[2]);
	printf("%d %d\n", *(dates + 2), dates[2]);
	printf("%d\n", *(dates + 2) == dates[2]);
	return 0;
}

/*
���������
				  short          double
pointers + 0: 000000E66DBBF728 000000E66DBBF788
pointers + 1: 000000E66DBBF72A 000000E66DBBF790
pointers + 2: 000000E66DBBF72C 000000E66DBBF798
pointers + 3: 000000E66DBBF72E 000000E66DBBF7A0
��ַ��ʮ�����Ƶģ�short���͵�ָ��+1���ַ��ԭ����2��double���͵�ָ��+1���ַ��ԭ����8
��ַ�����ֽڱ�ַ��shortռ��2�ֽڣ���doubleռ��8�ֽ�
��C�����У�ָ��+1ָ��������һ���洢��Ԫ
��������ԣ�����ζ�ż�1��ĵ�ַ����һ��Ԫ�صĵ�ַ����������һ���ֽڵĵ�ַ
����Ϊʲô��������ָ����ָ��������͵�ԭ��֮һ��ֻ֪����ַ��������Ϊ�����Ҫ֪�����������Ҫ�����ֽ�
dates + 2 == &date[2] //��ͬ�ĵ�ַ
*(dates + 2) == dates[2] //��ͬ��ֵ

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
	printf("����֮���� %ld\n", answer);
	printf("�����С�� %zd\n", sizeof marbles);
	return 0;
}

int sump(int* start, int* end) {
	int total = 0;
	while (start < end) {
		//һԪ�����*���Ը�ָ������ã���ȡָ����ָ����ڴ��ַ�д洢��ֵ����++�����ȼ���ͬ��
		//��˳���Ǵ�����������������startָ���������һ��Ԫ�أ�֮����ʹ��*��������
		total += *start++;
		//printf("%p\n",start);//start����ָ�룬�����ǵ�ַ
		//printf(" % d\n", *start);//*start����ָ��ָ���ֵ����������ֵ������һ���У�������int����
	}
	return total;
}

int sum_arr2() {
	int marbles[SIZE1] = { 20,10,5,39,4,16,19,26,31,20 };
	//C��֤�ڸ��������ռ�ʱ��ָ����������һ��λ�õ�ָ��������Ч��ָ��
	long answer = sump(marbles, marbles + SIZE1);
	printf("����֮���� %ld\n", answer);
	printf("�����С�� %zd\n", sizeof marbles);
	return 0;
}













