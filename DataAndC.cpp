#include "DataAndC.h"


void chap2_question1() {
	printf("Gustav Mahler\n");
	printf("Gustav\nMahler\n");
	printf("Gustav ");
	printf("Mahler\n");
}

void chap2_question2() {
	const char* name = "Gustav Mahler";
	printf("My name is %s\n",name);
	printf("My address is Nuaa,Nanjing,China\n");
}

void chap2_question3(int age) {
	int day = age * 365;
	printf("%d %d\n",age,day);
}

void jolly() {
	printf("For he's a jolly good fellow!\n");
}

void deny() {
	printf("Which nobody can deny!\n");
}

void chap2_question4() {
	for (int i = 0; i < 3; i++) {
		jolly();
	}
	deny();
}

void br() {
	printf("Brazil, Russia ");
}

void ic() {
	printf("India, China ");
}

void chap2_question5() {
	br(); ic(); printf("\n");
	ic(); printf("\n");
	br(); printf("\n");
}

void chap2_question6(int toes) {
	printf("%d %d %f\n", toes, 2 * toes, pow(toes, 2));
}

void chap2_question7() {
	for (int i = 3; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			printf("Smile!");
		}
		std::cout << std::endl;
	}
}
void two() {
	printf("two\n");
}

void one_three() {
	printf("one\n");
	two();
	printf("three\n");
}

void chap2_question8() {
	printf("starting now:\n");
	one_three();
	printf("done!\n");
}

int platinum() {
	float weight;
	float value;
	printf("Please enter your weight in pounds.\n");
	scanf("%f", &weight);
	value = 1700.0 * weight * 14.5833;
	printf("Your weight in platinum is worth %.2f.\n",value);
	//getchar();
	return 0;
}

int print1() {
	int ten = 10;
	int two = 2;

	printf("Doing it right:");
	printf("%d minus %d is %d\n", ten, two, ten - two);
	printf("Doing it wrong:");
	printf("%d minus %d is %d\n", 0X10, 0XA, 0X10 - 0XA);
	return 0;
}

/*
以十进制显示数字，使用%d，以八进制显示数字，使用%o，以十六进制显示数字，使用%x，
显示八进制数字的前缀0，使用%#x，显示十六进制数字的前缀0x，0X，分别使用%#x，%#X。
*/

int bases() {
	int x = 100;
	printf("dec = %d; octal = %o; hex = %x;\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x;\n", x, x, x);
	return 0;
}

int toobig() {
	int i = 2147483647;
	unsigned int j = 4294967295;

	printf("%d %d %d\n", i, i + 1, i + 2);
	printf("%u %u %u\n", j, j + 1, j + 2);
	/*
	*程序输出：
	 2147483647 -2147483648 -2147483647
     4294967295 0 1
	 注意：对于unsigned int类型，占位符是%u 
	 对于long类型，占位符是%ld，可以在o和x前面加上l（使用l前缀表示long），表示打印八进制格式的long或者十六进制的long
	 转换说明中只能使用小写常量后缀
	 同理，对于short类型，则是%hd，%ho，%hx
	 h和l都可以和u一起使用%lu，%hu
	*/
	return 0;
}

/*
* 在使用 printf() 函数时，不同的格式化标识符（如 %hd，%d，%ld，%lld）会指示编译器按照特定的类型和大小来解释相应的参数。
这些标识符对应的类型和它们在二进制中占用的位数通常如下：
%hd：这个格式化标识符用于 short int 类型。short int 通常是 16 位（2 字节），但这可能取决于特定的平台和编译器。
%d：此标识符用于 int 类型。标准的 int 大小通常是 32 位（4 字节），但这同样可能依赖于平台和编译器。
%ld：用于 long int 类型。在大多数现代平台上，long int 是 32 位（4 字节）或 64 位（8 字节），
具体取决于操作系统和编译器（32 位系统上通常是 32 位，64 位系统上可能是 64 位）。
%lld：这个格式化标识符用于 long long int 类型。long long int 几乎在所有现代平台上都是 64 位（8 字节）。
需要注意的是，这些位数是大多数平台和编译器的通用规则，但它们可能会根据不同的系统架构和编译器有所不同。
为了获取特定环境中各类型的确切大小，可以使用 sizeof 运算符。例如，sizeof(int) 可以用来确定 int 类型在特定平台上占用的字节数。
*/

int print2() {
	//使用错误的转换会得到意想不到的结果
	unsigned int un = 3000000000;
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;

	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and %d\n", end, end);//给函数传递参数时，编译器自动将short转换为int
	printf("big = %ld and %d and not %hd\n", big, big, big);//使用h修饰符可以显示较大整数被截断成short类型的情况。
	//65537的二进制是0000 0000 0000 0001 0000 0000 0000 0001，使用%hd，printf()只会查看后16位，所以显示值是1
	printf("verybig = %lld and not %ld and not %d\n", verybig, verybig, verybig);
	//32位操作系统中 int和long int都会查看后32位 而long long int会查看后64位
	/*
    * 程序输出：
     un = 3000000000 and not -1294967296
     end = 200 and 200
     big = 65537 and 65537 and not 1
     verybig = 12345678908642 and not 1942899938 and not 1942899938
    */
	return 0;
}

/*
* char grade = 'A';
* 
* 
* char broiled;
* broiled = 'T';//为其赋值，正确
* broiled = T;//错误！此时T是一个变量
* broiled = "T";//错误！此时"T"是一个字符串
*
* 
* char grade = 65; //65是A的ACSII码值
* 最好用A代替65
* C语言将字符常量视为int类型而非char类型
*/

/*
换行符：\n
回车符：\r
水平制表符：\t
垂直制表符：\v
退格符：\b
换页符：\f
反斜杠自身：\\
单引号：\'
双引号：\"
问号：\?
空字符（null）：\0
警报字符：\a
八进制值：\0oo
十六进制值：\xhh

最好使用转义序列而非它们对应的ASCII码
*/

int charcode() {
	//如果使用char处理小整数：建议使用signed char和unsigned char，范围分别是-128~127和0~255
	//可以避开不同编译器对于char的取值不同的问题
	char ch;
	printf("Please enter a character\n");
	scanf("%c",&ch);
	printf("The code for %c is %d.\n", ch, ch);
	return 0;
}

//_Bool类型表示布尔值，true用值1表示，false是值0

//可移植类型：stdint.h和inttype.h
/* 
    stdint.h中
    int32_t:宽度是32位的整数类型

	最小宽度类型：
	int_least8_t:可容纳8位有符号整数值的类型中宽度最小的类型的别名
	
	最快最小宽度类型：
	int_fast8_t:系统中对8位符号值而言运算最快的整数类型

	最大有符号整数类型：intmax_t 任何有效的有符号整数值
	最大无符号整数类型：uintmax_t 任何有效的有符号整数值

	对于可移植类型的占位符：使用inttype.h中的宏定义来打印
	如PRId32字符串宏，代表打印32位有符号值的合适转换说明（如d或l）

*/

int altnames() {
	int32_t me32;
	me32 = 45933945;
	printf("First,assume int32_t is int: \n");
	printf("me32 = %d\n", me32);
	printf("Next,let's not manke any assumptions.\n");
	//这里用了转义序列 \" 来表示字符串中的双引号
	printf("Instead,use a \"macro\"from inttypes.h:\n");
	printf("me32 = %" PRId32 "\n", me32);
	/*
	相当于printf("me32 = %" "d" "\n", me32);
	在C语言中，可以把多个字符串合在一起，所以又相当于：printf("me32 = %d\n", me32);
	*/
	return 0;
}

//浮点数：使用指数计数法（科学计数法在计算机中的表现形式），如1.6e-19 
//float类型必须至少能表示6位有效数字 且取值范围至少是10e-37到10e+37
//6位有效数字：如33.333333，后一项用于方便表示诸如太阳质量2.0e30千克,质子电荷量1.6e-19库仑，国家债务等数字。
//系统储存浮点数通常要32位，其中8位表示指数的值和符号，其余24位用来表示非指数部分（尾数和有效数）及其符号

/*
double类型则至少能表示10位有效数字 
double占用64位而非32位 
一些系统将多出来的32位全部用来表示非指数部分，这样做大大提高了精度
另一些系统将一些位分配给指数，提高了范围
无论哪种方法，double类型的值至少有13位有效数字，超过了标准的最低位数规定
更高精度要求：long double
*/

/*
可以省略正号
可以没有小数点或指数部分 但不能同时没有两者
通常情况下，编译器默认浮点型常量是double类型
在浮点后面加f或F可以将double转换为float如9.11E+9F
使用l或L可以转换为long double，推荐使用L

十六进制表示法：在十六进制数前面加上0x或0X，用p和P代替e和E用2的幂代替10的幂（p计数法），如：0xa.1fp10 a为10，f为15
0xa.1fp10 = (10 + 1/16 + 15/256) * pow(2,10) = 10364.0
*/

/*
浮点数打印：
float,double %f
float,double的指数计数法 %e
十六进制浮点数：用a和A代替e和E
long double要使用%Lf %Le %La
未显示说明的浮点数，C编译器会自动将float转成double
*/

int showf_pt() {
	float aboat = 32000.0;
	double abet = 2.14e+9;
	long double dip = 5.32e-5;

	printf("%f can be written %e\n", aboat, aboat);
	printf("And it's %a in hexadecimal, powers of 2 notation\n", aboat);
	printf("%f can be written %e\n", abet, abet);
	printf("%Lf can be written %Le\n", dip, dip);
	/*
	32000.000000 can be written 3.200000e+04
    And it's 0x1.f400000000000p+14 in hexadecimal, powers of 2 notation
    2140000000.000000 can be written 2.140000e+09
    0.000053 can be written 5.320000e-05
	*/
	return 0;
}

void toobigdemo() {
	float toobig = 3.4e+38 * 100.0f;
	printf("%e\n", toobig);
	//输出：inf 发生了上溢overflow
	float toosmall = 3.4e-38f / 100.0f;
	printf("%e\n", toosmall);
}
//下溢underflow：把用最高精度表示的最小数除以10，损失末尾数精度
//NaN:Not a Number 未定义行为产生的结果，如给asin()传入大于1的数
int floaterr() {
	float a, b;
	b = 2.0e+20 + 1.0;
	a = b - 2.0e+20;
	printf("%f\n", a);
	//输出：4008175468544.000000，因为计算机缺少足够的小数位来进行运算
	return 0;
}

int typesize() {
	/* C99 为类型大小提供 %zd 转换说明 */
	printf("Type int has a size of %zd bytes.\n", sizeof(int));
	printf("Type char has a size of %zd bytes.\n", sizeof(char));
	printf("Type long has a size of %zd bytes.\n", sizeof(long));
	printf("Type long long has a size of %zd bytes.\n",
		sizeof(long long));
	printf("Type double has a size of %zd bytes.\n",
		sizeof(double));
	printf("Type long double has a size of %zd bytes.\n",
		sizeof(long double));
	/*
	Type int has a size of 4 bytes.
    Type char has a size of 1 bytes.
    Type long has a size of 4 bytes.
    Type long long has a size of 8 bytes.
    Type double has a size of 8 bytes.
    Type long double has a size of 8 bytes.
	*/
	return 0;
}

int badcount() {
	int n = 4;
	int m = 5;
	float f = 7.0f;
	float g = 8.0f;
	printf("%d\n", n, m); //参数太多
	printf("%d %d %d\n", n);//参数太少
	printf("%d %d\n", f, g);//值的类型不匹配
	return 0;
}

//缓冲区满，遇到换行字符或需要输入时，printf()会把数据发送到终端，这一行为被称为刷新缓冲区

int escape() {
	float salary;

	printf("\aEnter your desired monthly salary:");
	printf("$_______\b\b\b\b\b\b\b");
	scanf("%f", &salary);
	printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12);
	printf("\rGee!\n");

	return 0;
}

void chap3_question2() {
	char ch;
	printf("请输入一个ASCII码值\n");
	scanf("%d", &ch);
	printf("这个ASCII码值对应的字符是%c\n", ch);
}

void chap3_question3() {
	printf("\aStartled by the sudden sound,Sally shouted,\n\"By the Great Pumpkin, what was that!\"");
}

void chap3_question4() {
	float fl;
	printf("Enter a floating-point value:");
	scanf("%f", &fl);
	printf("\nfixed-point notation:%f\n", fl);
	printf("exponential notation:%e\n", fl);
	printf("p notation:%a\n", fl);
}

void chap3_question5() {
	int age;
	printf("Enter your age:");
	scanf("%d", &age);
	printf("\nYour age in second is %lf", age * 3.156e7);
}

void chap3_question6() {
	float water;
	printf("请输入水的夸脱数:");
	scanf("%f", &water);
	printf("\n其中含有%e滴水\n", water * 950 / 3.0e-23);
}

void chap3_question7() {
	float bodyheight;
	printf("请输入你的身高:");
	scanf("%f", &bodyheight);
	printf("\n换算成厘米后是%2.2f\n", bodyheight * 2.54);
}

void chap3_question8() {
	float cup;
	printf("请输入杯数：");
	scanf("%f", &cup);
	float pint = cup / 2;
	printf("\n换算成品脱后是%.1f\n", pint);
	float ounce = cup * 8;
	printf("换算成盎司后是%.1f\n", ounce);
	float bigsoupspoon = ounce * 2;
	printf("换算成大汤勺后是%.1f\n", bigsoupspoon);
	float teaspoon = bigsoupspoon * 3;
	printf("换算成茶勺后是%.1f\n", teaspoon);
}

