#include "StrLearning.h"

#define PRAISE "You are an extraordinary being."
#define DENSITY 62.4
#define PI 3.14159
#define PAGES 959

int calculate(int bottom, int top) {
	if (top > bottom) {
		auto even = [](auto e) {return e % 2 == 0; };
		auto evens = std::views::iota(bottom, top + 1) | std::views::filter(even);
		return std::accumulate(evens.begin(), evens.end(), 0);
	}
	else {
		return 0;
	}
}

int talkback() {
	float weight, volume;
	int size, letters;
	char name[40];	// name ��һ�������� 40 ���ַ�������
	printf("Hi! What's your first name?\n");
	scanf("%s", name);
	printf("%s, what's your weight in pounds?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
	printf("Also, your first name has %d letters,\n", letters);
	printf("and we have %d bytes to store it.\n", size);
	return 0;
}

/*
�����ԣ�
1.������array�洢�ַ���string���ڸó����У��û�����������洢�������У�������ռ���ڴ���40���������ֽڣ�ÿ���ֽڴ洢һ���ַ�ֵ
2.ʹ��%sת��˵���������ַ��������������ע�⣬��scanf()�У�nameû��&ǰ׺����weight�У��Ժ���ͣ�&weight��name���ǵ�ַ��
3.��CԤ���������ַ�����DENSITY����Ϊ62.4
4.��C����strlen()��ȡ�ַ�������

�ַ�������

"����һ���ַ���"

���У�˫���Ų����ַ�����һ���֣��������߱������������������ַ��������絥�������ڱ�ʶ�����ַ�һ��

c����û��ר�Ŵ洢�ַ����ı������ͣ��ַ��������洢��char���͵������С�
�����������Ĵ洢��Ԫ��ɣ��ַ����е��ַ����洢�����ڵĴ洢��Ԫ�У�ÿ����Ԫ�洢һ���ַ���
�ַ�'\0'�ǿ��ַ���c������������ַ����Ľ��������ַ���������0�����ǷǴ�ӡ�ַ�����ASCII��ֵ�ǣ���ȼ��ڣ�0.
C�е��ַ���һ���Կ��ַ�����������ζ�����������������ٱȴ��洢�ַ����е��ַ���1.

*/

int praise1() {

	char name[40];
	printf("What's your name?\n");
	scanf("%s", name);
	printf("Hello, %s.%s\n", name, PRAISE);
	return 0;
}
//scanf�ڶ�ȡ�ַ���ʱ����ȡ���ո�󣬾Ͳ����ٶ�ȡ�����������
/*
char���ͣ�   'x'
char[]���ͣ� "x"  'x' \0
*/


int praise2() {
	//�����������ʶ��%zd�����Ի���%u��%lu
	char name[40];
	printf("What's your name?\n");
	scanf("%s", name);
	printf("Hello, %s.%s\n", name, PRAISE);
	printf("Your name occupies %zd letter and %zd memory cells.\n", strlen(name), sizeof name);
	printf("The phrase of praise has %zd letters ", strlen(PRAISE));
	printf("and occupies %zd memory cells.\n", sizeof PRAISE);
	return 0;
}

//strlen()�᷵���ַ����е��ַ���
//sizeof�᷵�ض���ռ���ڴ��С

//strlen()��һ�ദ���ַ����ĺ���ԭ�ͱ�������<string.h>�У��Ҳ�������ַ���ĩβ�Ŀ��ַ�
//��sizeof������ַ���ĩβ�Ŀ��ַ�
//�����������������ʾ��

/*
What's your name?
hhhh
Hello, hhhh.You are an extraordinary being.
Your name occupies 4 letter and 40 memory cells.
The phrase of praise has 31 letters and occupies 32 memory cells.
*/

/*
sizeof name��������� name������40���洢��Ԫ������ֻ��ǰ4����Ԫ�����洢hhhh������strlen(name)����4
name����ĵ������Ԫ������ַ�������strlen(name)�����4
*/

/*
����PRAISE��strlen(PRAISE)�ó���Ҳ���ַ����е��ַ����������ո�ͱ����ţ���Ȼ����sizeof PRAISE�����������������
��Ϊsizeof���ַ���ĩβ���ɼ�ÿ��ַ�Ҳ��������
�ó���δ��ȷ���߼����Ҫ���ַ���Ԥ�����ٿռ䣬�������������˫�����ڵ��ַ���
*/

/*
����sizeof��strlen()��ת��˵��ʹ��%zd
����sizeof���Ƿ�ʹ��Բ���ţ�
�������������ʱ��Բ���űز����٣�������������ض���ʱ�����п���
*/

/*
Ԥ�����������������峣�����磺
#define TAXRATE 0.015
����ʱ������������TAXRATE���ᱻ�滻��0.015����һ���̽С�����ʱ�滻(compile-time substitution)��
��������ĳ�������Ϊ����ʾ����(manifest constant)��

ͨ�ø�ʽ��
#define ���ų����� ���ų�����ֵ
#define NAME value
��д���ű�ʾ������C���ԵĴ�ͳ
��������ǰ��c_��k_��ʾ����
*/

int pizza() {
	// %1.2f�������������������Ϊ��λС�������
	float area, circum, radius;
	printf("What is the radius of your pizza?\n");
	scanf("%f", &radius);
	area = radius * radius * PI;
	circum = radius * PI * 2;
	printf("Your basic pizza parameters are as follows:\n");
	printf("circumference = %1.2f, area = %1.2f\n", circum, area);
	return 0;
}

// #define�����Զ����ַ����ַ���������ǰ��ʹ�õ����ţ�����ʹ��˫����
// <limits.h> & <float.h>�ֱ��ṩ�����������ͺ͸��������ʹ�С������ص���ϸ��Ϣ
// û��ͷ�ļ���������һϵ�й�ʵ��ʹ�õ���ʾ�������磬limits.h�а����������ƵĴ��룺
/*
#define SHRT_MAX +32767
#define SHRT_MIN -32768
*/ 

void printlimits() {
	std::cout << "char���͵�λ����\t\t" << CHAR_BIT << std::endl;
	std::cout << "char���͵����ֵ��\t\t" << CHAR_MAX << std::endl;
	std::cout << "char���͵���Сֵ��\t\t" << CHAR_MIN << std::endl;
	std::cout << "signed char���͵����ֵ��\t" << SCHAR_MAX << std::endl;
	std::cout << "signed char���͵���Сֵ��\t" << SCHAR_MIN << std::endl;
	std::cout << "unsigned char���͵����ֵ��\t" << UCHAR_MAX << std::endl;
	std::cout << "short���͵����ֵ��\t\t" << SHRT_MAX << std::endl;
	std::cout << "short���͵���Сֵ��\t\t" << SHRT_MIN << std::endl;
	std::cout << "unsigned short���͵����ֵ��\t" << USHRT_MAX << std::endl;
	std::cout << "int���͵����ֵ��\t\t" << INT_MAX << std::endl;
	std::cout << "int���͵���Сֵ��\t\t" << INT_MIN << std::endl;
	std::cout << "unsigned int���͵����ֵ��\t" << UINT_MAX << std::endl;
	std::cout << "long���͵����ֵ��\t\t" << LONG_MAX << std::endl;
	std::cout << "long���͵���Сֵ��\t\t" << LONG_MIN << std::endl;
	std::cout << "unsigned long���͵����ֵ��\t" << ULONG_MAX << std::endl;
	std::cout << "long long���͵����ֵ��\t\t" << LLONG_MAX << std::endl;
	std::cout << "long long���͵���Сֵ��\t\t" << LLONG_MIN << std::endl;
	std::cout << "unsigned long long���͵����ֵ��" << ULLONG_MAX << std::endl;
}

int pivotIndex(int* nums, int numsSize) {
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	int leftsum = 0;
	int rightsum = sum;
	for (int i = 0; i < numsSize; i++) {
		leftsum += nums[i];
		rightsum += -nums[i];
		if (leftsum - nums[i] == rightsum) {
			return i;
		}
	}
	return -1;
}

int searchInsert(int* nums, int numsSize, int target) {
	if (target < nums[0]) {
		return 0;
	}
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == target) {
			return i;
		} else if(target > nums[i] && i != numsSize - 1 && target < nums[i + 1]) {
			return i + 1;
		}
	}
	return numsSize;
}

void printfloats() {
	std::cout << "float���͵�β��λ��\t\t\t\t" << FLT_MANT_DIG << std::endl;
	std::cout << "float���͵�������Ч����λ����ʮ���ƣ�\t\t" << FLT_DIG << std::endl;
	std::cout << "��ȫ����Ч���ֵ�float������С��ָ������10Ϊ�ף�\t" << FLT_MIN_10_EXP << std::endl;
	std::cout << "float���͵������ָ������10Ϊ�ף�\t\t" << FLT_MAX_10_EXP << std::endl;
	std::cout << "����ȫ�����ȵ�float������Сֵ\t\t\t" << FLT_MIN << std::endl;
	std::cout << "float���͵��������\t\t\t\t" << FLT_MAX << std::endl;
	std::cout << "1.00�ͱ�1.00�����Сfloat����ֵ֮��Ĳ��\t" << FLT_EPSILON << std::endl;
}

int defines() {
	printf("Some number limits for this system:\n");
	printf("Biggest int: %d\n", INT_MAX);
	printf("Smallest long long: %lld\n", LLONG_MIN);
	printf("One byte = %d bits on this system.\n", CHAR_BIT);
	printf("Largest double: %e\n", DBL_MAX);
	printf("Smallest normal float: %e\n", FLT_MIN);
	printf("float precision = %d digits\n", FLT_DIG);
	printf("float epsilon = %e\n", FLT_EPSILON);
	return 0;
}

int printout()
{
	int number = 7;
	float pies = 12.75;
	int cost = 7800;
	printf("The %d contestants ate %2.2f berry pies.\n", number, pies);
	printf("The value of pi is %f.\n", PI);
	printf("Farewell! thou art too dear for my possessing,\n");
	printf("%c%d\n", '$', 2 * cost);
	return 0;
}

//������ӡ�ٷֺ�%��ֱ�����������Ϳ����ˣ�%%

int width() {
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);
	return 0;
}

int floatwidth() {
	const double RENT = 3852.99;
	printf("*%f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%4.2e*\n", RENT);
	return 0;
}




