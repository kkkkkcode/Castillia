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
	char name[40];	// name 是一个可容纳 40 个字符的数组
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
新特性：
1.用数组array存储字符串string，在该程序中，用户输入的名被存储在数组中，该数组占用内存中40个连续的字节，每个字节存储一个字符值
2.使用%s转换说明来处理字符串的输入输出，注意，在scanf()中，name没有&前缀，而weight有（稍后解释，&weight和name都是地址）
3.用C预处理器把字符常量DENSITY定义为62.4
4.用C函数strlen()获取字符串长度

字符串，如

"我是一个字符串"

其中，双引号不是字符串的一部分，仅仅告诉编译器它括起来的是字符串，正如单引号用于标识单个字符一样

c语言没有专门存储字符串的变量类型，字符串都被存储在char类型的数组中。
数组由连续的存储单元组成，字符串中的字符被存储在相邻的存储单元中，每个单元存储一个字符。
字符'\0'是空字符，c语言用它标记字符串的结束。空字符不是数字0，它是非打印字符，其ASCII码值是（或等价于）0.
C中的字符串一定以空字符结束，这意味着数组容量必须至少比待存储字符串中的字符多1.

*/

int praise1() {

	char name[40];
	printf("What's your name?\n");
	scanf("%s", name);
	printf("Hello, %s.%s\n", name, PRAISE);
	return 0;
}
//scanf在读取字符串时，读取到空格后，就不会再读取后面的内容了
/*
char类型：   'x'
char[]类型： "x"  'x' \0
*/


int praise2() {
	//如果编译器不识别%zd，尝试换成%u或%lu
	char name[40];
	printf("What's your name?\n");
	scanf("%s", name);
	printf("Hello, %s.%s\n", name, PRAISE);
	printf("Your name occupies %zd letter and %zd memory cells.\n", strlen(name), sizeof name);
	printf("The phrase of praise has %zd letters ", strlen(PRAISE));
	printf("and occupies %zd memory cells.\n", sizeof PRAISE);
	return 0;
}

//strlen()会返回字符串中的字符数
//sizeof会返回对象占用内存大小

//strlen()这一类处理字符串的函数原型被声明在<string.h>中，且不会计入字符串末尾的空字符
//但sizeof会计入字符串末尾的空字符
//具体如下输入输出所示：

/*
What's your name?
hhhh
Hello, hhhh.You are an extraordinary being.
Your name occupies 4 letter and 40 memory cells.
The phrase of praise has 31 letters and occupies 32 memory cells.
*/

/*
sizeof name运算符报告 name数组有40个存储单元，但是只有前4个单元用来存储hhhh，所以strlen(name)返回4
name数组的第五个单元储存空字符，所以strlen(name)结果是4
*/

/*
对于PRAISE，strlen(PRAISE)得出的也是字符串中的字符数（包括空格和标点符号）。然而，sizeof PRAISE运算符给出的数更大，
因为sizeof把字符串末尾不可兼得空字符也计算在内
该程序并未明确告诉计算机要给字符串预留多少空间，所以它必须计算双引号内的字符数
*/

/*
对于sizeof和strlen()，转换说明使用%zd
对于sizeof，是否使用圆括号：
运算对象是类型时，圆括号必不可少，但运算对象是特定量时，可有可无
*/

/*
预处理器可以用来定义常量，如：
#define TAXRATE 0.015
编译时，程序中所有TAXRATE都会被替换成0.015，这一过程叫“编译时替换(compile-time substitution)”
这样定义的常量被称为“明示常量(manifest constant)”

通用格式：
#define 符号常量名 符号常量的值
#define NAME value
大写符号表示常量是C语言的传统
活在名称前用c_或k_表示常量
*/

int pizza() {
	// %1.2f表明，结果被四舍五入为两位小数输出。
	float area, circum, radius;
	printf("What is the radius of your pizza?\n");
	scanf("%f", &radius);
	area = radius * radius * PI;
	circum = radius * PI * 2;
	printf("Your basic pizza parameters are as follows:\n");
	printf("circumference = %1.2f, area = %1.2f\n", circum, area);
	return 0;
}

// #define还可以定义字符和字符串常量，前者使用单引号，后者使用双引号
// <limits.h> & <float.h>分别提供了与整数类型和浮点数类型大小限制相关的详细信息
// 没个头文件都定义了一系列供实现使用的明示常量，如，limits.h中包含以下类似的代码：
/*
#define SHRT_MAX +32767
#define SHRT_MIN -32768
*/ 

void printlimits() {
	std::cout << "char类型的位数：\t\t" << CHAR_BIT << std::endl;
	std::cout << "char类型的最大值：\t\t" << CHAR_MAX << std::endl;
	std::cout << "char类型的最小值：\t\t" << CHAR_MIN << std::endl;
	std::cout << "signed char类型的最大值：\t" << SCHAR_MAX << std::endl;
	std::cout << "signed char类型的最小值：\t" << SCHAR_MIN << std::endl;
	std::cout << "unsigned char类型的最大值：\t" << UCHAR_MAX << std::endl;
	std::cout << "short类型的最大值：\t\t" << SHRT_MAX << std::endl;
	std::cout << "short类型的最小值：\t\t" << SHRT_MIN << std::endl;
	std::cout << "unsigned short类型的最大值：\t" << USHRT_MAX << std::endl;
	std::cout << "int类型的最大值：\t\t" << INT_MAX << std::endl;
	std::cout << "int类型的最小值：\t\t" << INT_MIN << std::endl;
	std::cout << "unsigned int类型的最大值：\t" << UINT_MAX << std::endl;
	std::cout << "long类型的最大值：\t\t" << LONG_MAX << std::endl;
	std::cout << "long类型的最小值：\t\t" << LONG_MIN << std::endl;
	std::cout << "unsigned long类型的最大值：\t" << ULONG_MAX << std::endl;
	std::cout << "long long类型的最大值：\t\t" << LLONG_MAX << std::endl;
	std::cout << "long long类型的最小值：\t\t" << LLONG_MIN << std::endl;
	std::cout << "unsigned long long类型的最大值：" << ULLONG_MAX << std::endl;
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
	std::cout << "float类型的尾数位数\t\t\t\t" << FLT_MANT_DIG << std::endl;
	std::cout << "float类型的最少有效数字位数（十进制）\t\t" << FLT_DIG << std::endl;
	std::cout << "带全部有效数字的float类型最小负指数（以10为底）\t" << FLT_MIN_10_EXP << std::endl;
	std::cout << "float类型的最大正指数（以10为底）\t\t" << FLT_MAX_10_EXP << std::endl;
	std::cout << "保留全部精度的float类型最小值\t\t\t" << FLT_MIN << std::endl;
	std::cout << "float类型的最大正数\t\t\t\t" << FLT_MAX << std::endl;
	std::cout << "1.00和比1.00大的最小float类型值之间的差距\t" << FLT_EPSILON << std::endl;
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

//如果想打印百分号%，直接输入两个就可以了，%%

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




