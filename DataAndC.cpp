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
��ʮ������ʾ���֣�ʹ��%d���԰˽�����ʾ���֣�ʹ��%o����ʮ��������ʾ���֣�ʹ��%x��
��ʾ�˽������ֵ�ǰ׺0��ʹ��%#x����ʾʮ���������ֵ�ǰ׺0x��0X���ֱ�ʹ��%#x��%#X��
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
	*���������
	 2147483647 -2147483648 -2147483647
     4294967295 0 1
	 ע�⣺����unsigned int���ͣ�ռλ����%u 
	 ����long���ͣ�ռλ����%ld��������o��xǰ�����l��ʹ��lǰ׺��ʾlong������ʾ��ӡ�˽��Ƹ�ʽ��long����ʮ�����Ƶ�long
	 ת��˵����ֻ��ʹ��Сд������׺
	 ͬ������short���ͣ�����%hd��%ho��%hx
	 h��l�����Ժ�uһ��ʹ��%lu��%hu
	*/
	return 0;
}

/*
* ��ʹ�� printf() ����ʱ����ͬ�ĸ�ʽ����ʶ������ %hd��%d��%ld��%lld����ָʾ�����������ض������ͺʹ�С��������Ӧ�Ĳ�����
��Щ��ʶ����Ӧ�����ͺ������ڶ�������ռ�õ�λ��ͨ�����£�
%hd�������ʽ����ʶ������ short int ���͡�short int ͨ���� 16 λ��2 �ֽڣ����������ȡ�����ض���ƽ̨�ͱ�������
%d���˱�ʶ������ int ���͡���׼�� int ��Сͨ���� 32 λ��4 �ֽڣ�������ͬ������������ƽ̨�ͱ�������
%ld������ long int ���͡��ڴ�����ִ�ƽ̨�ϣ�long int �� 32 λ��4 �ֽڣ��� 64 λ��8 �ֽڣ���
����ȡ���ڲ���ϵͳ�ͱ�������32 λϵͳ��ͨ���� 32 λ��64 λϵͳ�Ͽ����� 64 λ����
%lld�������ʽ����ʶ������ long long int ���͡�long long int �����������ִ�ƽ̨�϶��� 64 λ��8 �ֽڣ���
��Ҫע����ǣ���Щλ���Ǵ����ƽ̨�ͱ�������ͨ�ù��򣬵����ǿ��ܻ���ݲ�ͬ��ϵͳ�ܹ��ͱ�����������ͬ��
Ϊ�˻�ȡ�ض������и����͵�ȷ�д�С������ʹ�� sizeof ����������磬sizeof(int) ��������ȷ�� int �������ض�ƽ̨��ռ�õ��ֽ�����
*/

int print2() {
	//ʹ�ô����ת����õ����벻���Ľ��
	unsigned int un = 3000000000;
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;

	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and %d\n", end, end);//���������ݲ���ʱ���������Զ���shortת��Ϊint
	printf("big = %ld and %d and not %hd\n", big, big, big);//ʹ��h���η�������ʾ�ϴ��������ضϳ�short���͵������
	//65537�Ķ�������0000 0000 0000 0001 0000 0000 0000 0001��ʹ��%hd��printf()ֻ��鿴��16λ��������ʾֵ��1
	printf("verybig = %lld and not %ld and not %d\n", verybig, verybig, verybig);
	//32λ����ϵͳ�� int��long int����鿴��32λ ��long long int��鿴��64λ
	/*
    * ���������
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
* broiled = 'T';//Ϊ�丳ֵ����ȷ
* broiled = T;//���󣡴�ʱT��һ������
* broiled = "T";//���󣡴�ʱ"T"��һ���ַ���
*
* 
* char grade = 65; //65��A��ACSII��ֵ
* �����A����65
* C���Խ��ַ�������Ϊint���Ͷ���char����
*/

/*
���з���\n
�س�����\r
ˮƽ�Ʊ����\t
��ֱ�Ʊ����\v
�˸����\b
��ҳ����\f
��б������\\
�����ţ�\'
˫���ţ�\"
�ʺţ�\?
���ַ���null����\0
�����ַ���\a
�˽���ֵ��\0oo
ʮ������ֵ��\xhh

���ʹ��ת�����ж������Ƕ�Ӧ��ASCII��
*/

int charcode() {
	//���ʹ��char����С����������ʹ��signed char��unsigned char����Χ�ֱ���-128~127��0~255
	//���Աܿ���ͬ����������char��ȡֵ��ͬ������
	char ch;
	printf("Please enter a character\n");
	scanf("%c",&ch);
	printf("The code for %c is %d.\n", ch, ch);
	return 0;
}

//_Bool���ͱ�ʾ����ֵ��true��ֵ1��ʾ��false��ֵ0

//����ֲ���ͣ�stdint.h��inttype.h
/* 
    stdint.h��
    int32_t:�����32λ����������

	��С������ͣ�
	int_least8_t:������8λ�з�������ֵ�������п����С�����͵ı���
	
	�����С������ͣ�
	int_fast8_t:ϵͳ�ж�8λ����ֵ��������������������

	����з����������ͣ�intmax_t �κ���Ч���з�������ֵ
	����޷����������ͣ�uintmax_t �κ���Ч���з�������ֵ

	���ڿ���ֲ���͵�ռλ����ʹ��inttype.h�еĺ궨������ӡ
	��PRId32�ַ����꣬�����ӡ32λ�з���ֵ�ĺ���ת��˵������d��l��

*/

int altnames() {
	int32_t me32;
	me32 = 45933945;
	printf("First,assume int32_t is int: \n");
	printf("me32 = %d\n", me32);
	printf("Next,let's not manke any assumptions.\n");
	//��������ת������ \" ����ʾ�ַ����е�˫����
	printf("Instead,use a \"macro\"from inttypes.h:\n");
	printf("me32 = %" PRId32 "\n", me32);
	/*
	�൱��printf("me32 = %" "d" "\n", me32);
	��C�����У����԰Ѷ���ַ�������һ���������൱�ڣ�printf("me32 = %d\n", me32);
	*/
	return 0;
}

//��������ʹ��ָ������������ѧ�������ڼ�����еı�����ʽ������1.6e-19 
//float���ͱ��������ܱ�ʾ6λ��Ч���� ��ȡֵ��Χ������10e-37��10e+37
//6λ��Ч���֣���33.333333����һ�����ڷ����ʾ����̫������2.0e30ǧ��,���ӵ����1.6e-19���أ�����ծ������֡�
//ϵͳ���渡����ͨ��Ҫ32λ������8λ��ʾָ����ֵ�ͷ��ţ�����24λ������ʾ��ָ�����֣�β������Ч�����������

/*
double�����������ܱ�ʾ10λ��Ч���� 
doubleռ��64λ����32λ 
һЩϵͳ���������32λȫ��������ʾ��ָ�����֣��������������˾���
��һЩϵͳ��һЩλ�����ָ��������˷�Χ
�������ַ�����double���͵�ֵ������13λ��Ч���֣������˱�׼�����λ���涨
���߾���Ҫ��long double
*/

/*
����ʡ������
����û��С�����ָ������ ������ͬʱû������
ͨ������£�������Ĭ�ϸ����ͳ�����double����
�ڸ�������f��F���Խ�doubleת��Ϊfloat��9.11E+9F
ʹ��l��L����ת��Ϊlong double���Ƽ�ʹ��L

ʮ�����Ʊ�ʾ������ʮ��������ǰ�����0x��0X����p��P����e��E��2���ݴ���10���ݣ�p�����������磺0xa.1fp10 aΪ10��fΪ15
0xa.1fp10 = (10 + 1/16 + 15/256) * pow(2,10) = 10364.0
*/

/*
��������ӡ��
float,double %f
float,double��ָ�������� %e
ʮ�����Ƹ���������a��A����e��E
long doubleҪʹ��%Lf %Le %La
δ��ʾ˵���ĸ�������C���������Զ���floatת��double
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
	//�����inf ����������overflow
	float toosmall = 3.4e-38f / 100.0f;
	printf("%e\n", toosmall);
}
//����underflow��������߾��ȱ�ʾ����С������10����ʧĩβ������
//NaN:Not a Number δ������Ϊ�����Ľ�������asin()�������1����
int floaterr() {
	float a, b;
	b = 2.0e+20 + 1.0;
	a = b - 2.0e+20;
	printf("%f\n", a);
	//�����4008175468544.000000����Ϊ�����ȱ���㹻��С��λ����������
	return 0;
}

int typesize() {
	/* C99 Ϊ���ʹ�С�ṩ %zd ת��˵�� */
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
	printf("%d\n", n, m); //����̫��
	printf("%d %d %d\n", n);//����̫��
	printf("%d %d\n", f, g);//ֵ�����Ͳ�ƥ��
	return 0;
}

//�������������������ַ�����Ҫ����ʱ��printf()������ݷ��͵��նˣ���һ��Ϊ����Ϊˢ�»�����

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
	printf("������һ��ASCII��ֵ\n");
	scanf("%d", &ch);
	printf("���ASCII��ֵ��Ӧ���ַ���%c\n", ch);
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
	printf("������ˮ�Ŀ�����:");
	scanf("%f", &water);
	printf("\n���к���%e��ˮ\n", water * 950 / 3.0e-23);
}

void chap3_question7() {
	float bodyheight;
	printf("������������:");
	scanf("%f", &bodyheight);
	printf("\n��������׺���%2.2f\n", bodyheight * 2.54);
}

void chap3_question8() {
	float cup;
	printf("�����뱭����");
	scanf("%f", &cup);
	float pint = cup / 2;
	printf("\n�����Ʒ�Ѻ���%.1f\n", pint);
	float ounce = cup * 8;
	printf("����ɰ�˾����%.1f\n", ounce);
	float bigsoupspoon = ounce * 2;
	printf("����ɴ����׺���%.1f\n", bigsoupspoon);
	float teaspoon = bigsoupspoon * 3;
	printf("����ɲ��׺���%.1f\n", teaspoon);
}

