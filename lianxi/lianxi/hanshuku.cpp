#include "stdafx.h"
#include "math.h"
#include "conio.h"
//#define NULL ((void *)0) ����ָ�루��ָ�붨��ʱ��ʼ��ʹ�ã�

//��ϰA
#if(0)
//��������
void abc() {
	int a = 1, b = 9, c = 1543, d;
	if (a > b) {
		d = a;
		a = b;
		b = d;
	}
	if (b > c) {
		d = b;
		b = c;
		c = d;
	}
	if (a > b) {
		d = a;
		a = b;
		b = d;
	}
	printf("a=%d\nb=%d\nc=%d\n", a, b, c);
}
//��Ŀ����Ƕ��(�ҽ��),��Сдת��
void ABC() {
	char c;
	//c = getchar();
	scanf_s("%c", &c);//scanf:��Ч����
	c >= 97 && c <= 122 ? printf("%cת��Ϊ��д=%c\n", c, c - 32) :
		c >= 65 && c <= 90 ? printf("%cת��ΪСд=%c\n", c, c + 32) : printf("%c���Ǵ�Сд��ĸ\n", c);
}
// + - * /������
void yunsuanqi() {
	int a, b;
	float result = 0;
	char Operator;
	scanf_s("%d%c", &a, &Operator);
	scanf_s("%d", &b);
	switch (Operator)
	{
	case '+':result = a + b; break;
	case '-':result = a - b; break;
	case '*':result = a * b; break;
	case '/':
	{
		if (a == 0) { printf("������Ч����"); }
		else { result = a / b; }
		break;
	}
	default:printf("������Ч����"); break;
	}
	printf("=%.2f\n", result);
}
//��������С
void Max_Min() {
	int a[5], max, min;
	for (int j = 0; j < 5; j++) {
		scanf_s("%d", &a[j]);
	}
	max = min = a[0];
	for (int i = 0; i < 5; i++) {
		printf("%d  ", a[i]);
		(max > a[i]) ? 0 : max = a[i];
		(min < a[i]) ? 0 : min = a[i];
	}
	printf("\nMax=%d Min=%d", max, min);
}
//�ж�����(a�����Ƿ��ӡ���)
int year(int year, int a) {
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			if (a == 1) { printf("%d������\n", year); }
			return 1;
		}
		else {
			if (a == 1) { printf("%d��������\n", year); }
			return 0;
		}
	}
	else {
		if (year % 4 == 0) {
			if (a == 1) { printf("%d������\n", year); }
			return 1;
		}
		else {
			if (a == 1) { printf("%d��������\n", year); }
			return 0;
		}
	}
}
//�˷Ѽ��㣨p�˷� w���� s���� d�ۿ� ���˷�f=p*w*s*(1-d)��
void yunfei(float p, int w, int s) {
	float d, f;
	if (s < 250)d = 0.00;
	if (s < 500)d = 0.02;
	if (s < 1000)d = 0.05;
	if (s < 2000)d = 0.80;
	if (s < 3000)d = 0.10;
	else d = 0.15;
	f = p * w*s*(1 - d);
	printf("�����˷ѣ�\t%.2f\n���أ�\t%d\n������룺\t%d\n�ۿۣ�\t%.2f\n���˷�:\t%.2f\n", p, w, s, d, f);
}
//����������(һ����+100��+168������ȫƽ����)
void sqrt_x() {
	int x, y;
	for (int i = 0; i < 100000; i++) {
		x = i + 100;
		y = i + 168;
		if ((int)sqrt(x) / sqrt(x) == 1 && (int)sqrt(y) / sqrt(y) == 1)
		{
			printf("%d\t", i);
		}
	}
}
//�����������ж�һ��ڼ���
void num() {
	int y, m, d, day = 0;
	int num1[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int num2[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	printf("����������:\n");
	scanf_s("%d %d %d", &y, &m, &d);
	if (m > 12 || d > 31) { printf("�·ݻ������������"); }
	else
	{
		if (year(y, 0) == 0 && m == 2 && d>28) { printf("������2�·�ֻ��28�죡����"); }
		else if (year(y, 0) == 1 && m == 2 && d>29) { printf("����2�·�ֻ��29�죡����"); }
		else
		{
			if (year(y, 0) == 1) {
				for (int i = 0; i < m - 1; i++) { day += num2[i]; }
			}
			else {
				for (int i = 0; i < m - 1; i++) { day += num1[i]; }
			}
			day += d;
			printf("�� %d ��\n", day);
		}
	}
}
//ͳ�������ַ���
void while_c_num() {
	int n = 0;
	while (getchar() != '\n') {
		n++;
	}
	printf("������%d���ַ�\n", n);
}
//*�Ž�����(��ʼ��i��Ԫ�أ���n��)
void QAQ(int i, int n) {
	for (i; i < n; i++) {
		for (int j = i; j >0; j--) {
			printf("*");
		}
		printf("\n");
	}
}
//���������
void san() {
	int r, c, a[15];
	a[0] = 1;
	printf("%5d\n", a[0]);
	for (r = 1; r<sizeof(a) / 4; r++) {
		a[r] = 1;
		for (c = r - 1; c >= 1; c--) {
			a[c] = a[c] + a[c - 1];
		}
		for (c = 0; c <= r; c++) {
			printf("%5d\t", a[c]);
		}
		printf("\n");
	}
}
//ȫ����(1-4������ɵ�������λ��)
void Cnxn_4() {
	int sum_n = 0;
	for (int a = 1; a < 5; a++) {
		for (int b = 1; b < 5; b++) {
			if (b != a) {
				for (int c = 1; c < 5; c++) {
					if (c != a && c != b) {
						for (int d = 1; d < 5; d++) {
							if (d != a && d != b && d != c) {
								printf("%d%d%d%d\t", a, b, c, d);
								sum_n++;
							}
						}
					}
				}
			}
		}
		printf("\n");
	}
	printf("���ƣ�%d\n", sum_n);
}
//ȫ����(1-4������ɵ�������λ��)
void Cnxn_3() {
	int sum_n = 0;
	for (int a = 1; a < 5; a++) {
		for (int b = 1; b < 5; b++) {
			if (b != a) {
				for (int c = 1; c < 5; c++) {
					if (c != a && c != b) {
						printf("%d%d%d\t", a, b, c);
						sum_n++;
					}
				}
			}
		}
		printf("\n");
	}
	printf("���ƣ�%d\n", sum_n);
}
//���س�ͳ��������esc����ѭ��
void ent_esc() {
	int i = 0;
	char c;
	while (1)
	{
		c = 0;
		while (c != 13 && c != 27)
		{
			c = _getch();
			printf("%c", c);
			i++;
		}
		if (c == 27) { printf("\r�˳�\n"); break; }
		printf("\n��ǰ������ %d ���ַ�\n", i);
	}
}
//a~b���ܱ�n�����������
void Divisibility(int a, int b, int n) {
	int i = 0;
	for (a; a <= b; a++) {
		if (a%n == 0) { continue; }
		printf("%d\t", a);
		i++;
		if (i % 8 == 0) { printf("\n"); }
	}
	printf("\n��%d������\n", i);
}
//��PI,PI/4=1-1/3+1/5-1/7+1/9����(ѭ������n,x�����������)
void PI(int n, int x) {
	long double pi = 4.0;
	for (int i = 1; i <= n; i++) {
		i % 2 == 0 ? pi += 4.0 / (1 + 2 * i) : pi -= 4.0 / (1 + 2 * i);
		if (x == 1) {
			printf("PI(%d)=%.10f\t", i, pi);
			if (i % 5 == 0) { printf("\n"); }
		}
	}
	printf("PI(%d)=%.50f\n", n, pi);
}
//PI2(����n)
void PI2(int n, int x) {
	long double pi = 4.0;
	double nx = pow(10, n);//10��n�η�
	for (int i = 1; ((1 + 2 * i) / 4.0)<nx; i++) {
		i % 2 == 0 ? pi += 4.0 / (1 + 2 * i) : pi -= 4.0 / (1 + 2 * i);
		if (x == 1) {
			printf("PI(%d)=%.10f\t", i, pi);
			if (i % 5 == 0) { printf("\n"); }
		}
	}
	printf("\nPI=%.50f\n", pi);
}
//쳲���������
void Fibonacci(int n) {
	long int Fi[60];
	Fi[0] = 0;
	Fi[1] = Fi[2] = 1;
	for (int c = 3; c <= n; c++)
	{
		Fi[c] = Fi[c - 1] + Fi[c - 2];
	}
	for (int x = 1; x <= n; x++) {
		printf("%12.d\t", Fi[x]);
		if (x % 5 == 0) { printf("\n"); }
	}
}
//����
void prime_number() {
	int x = 0, prime = 0;
	printf("���������֣�");
	scanf_s("%d", &x);
	printf("%d����", x);
	if ((int)sqrt(x) / sqrt(x) == 1) {//�Ż�
		x = sqrt(x);
		printf("��");
	}
	else {
		for (int i = 2; i<x / 2; i++) {
			if (x%i == 0) { printf("��"); break; }
		}
	}
	printf("������\n");
}
//��ӡa~b֮��ȫ������
void A_B_prime_number(int a, int b) {
	int x = 0;
	for (a; a <= b; a++) {
		if ((int)sqrt(a) / sqrt(a) == 1) { continue; }
		for (int j = 2; j <= (int)(a / 2); j++) {
			if (a%j == 0) { break; }
			if (j != (int)(a / 2)) { continue; }
			printf("%d\n", a); x++;
		}
	}
	printf("��%d������\n", x);
}
//����
char *pswd() {
	char c[100], y;
	int i = 0;
	while (1) {
		y = getchar();
		if (y == 10) { break; }
		if ((y > 64 && y < 91) || (y > 96 && y < 123)) {
			if (y + 4 > 122 || (y + 4<97) && (y + 4 > 91)) { y -= 26; }
			c[i] = y + 4;
			i++;
		}
		else { printf("\n���ݲ���ȷ���޷�����\n"); break; }
	}
	c[i + 1] = '\0';
	for (int j = 0; j != i + 1; j++)
	{
		printf("%c", c[j]);
	}
	return c;
}
//����(ûѧָ��δ���)
void _pswd() {}
//��������
void oooooo() {
	int x[10] = { 10,52,14,21,75,42,12,1,354,125 }, y;
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9 - i; j++) {
			if (x[j] < x[j + 1]) {
				y = x[j];
				x[j] = x[j + 1];
				x[j + 1] = y;
			}
		}
	}
	for (int a = 0; a < 10; a++) { printf("%10.d", x[a]); }
}
//��ά��������ֵ����λ��
void ooMAXooooMINoo() {
	int max, min, a1, a2, b1, b2;
	int x[4][4] = { { 11,8,6,16 } ,{ 5,1,51,351 } ,{ 28,46,8,15 },{ 51,51,58,8 } };
	max = min = x[0][0];
	a1 = a2 = b1 = b2 = 1;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			printf("%10.d|", x[i][j]);
			if (x[i][j] > max) {
				max = x[i][j];
				a1 = i + 1, a2 = j + 1;
			}
			if (x[i][j] < min) {
				min = x[i][j];
				b1 = i + 1, b2 = j + 2;
			}
		}
		printf("\n��������������������������������������������\n");
	}
	printf("��%d��%d��Ϊ���ֵ��%d\n��%d��%d��Ϊ��Сֵ��%d\n\n\n", a1, a2, max, b1, b2, min);
}
//���ַ���������(n:���ƹ������)
void dichotomia(int n) {
	int x[20] = { -999,-102,-86,-15,-12,0,12,21,34,48,51,61,75,88,91,120,155,992,1016,1865 };
	int a, b, c, y;
	a = 0;
	c = sizeof(x) / 4 - 1;
	printf("������Ƚ�ֵ��");
	scanf_s("%d", &y);
	//printf("%d", sizeof(x));
	if (y<x[a] || y>x[c]) { printf("\n��ֵ�������з�Χ!!!\n\n"); }
	else {
		while (1) {
			b = (a + c) / 2;
			if (n) { printf("����������������������\na=%d\tb=%d\tc=%d\n����������������������\n", a, b, c); }
			if (x[b] == y) { printf("\n��ֵ���������еĵ�%d��λ��!!!\n\n", b); break; }
			if (a >= c) {
				if (a > b) { int i = a; a = b; b = i; }
				printf("\n��ֵ�������ڲ�����!!!\n\n");
				break;
			}
			if (x[b] > y) { c = b - 1; }
			if (x[b] < y) { a = b + 1; }
			if (n) { printf("a=%d\tb=%d\tc=%d\n", a, b, c); }
		}
	}
}
//���ͳ�������ַ�����������
void asc_II() {
	char c[128][2] = { { 0,0 } }, x[100], y;
	int g = 0;
	for (int i = 0; i<100; i++) {
		y = _getch();
		printf("%c", y);
		x[i] = y;
		if (y == 27) { break; }
		int j = 0;
		for (j; j <= g; j++) {
			if (j == g) {
				if (c[j][1] == 0) {
					c[j][0] = y;
					++c[j][1];
					g++;
				}
				else { g++; }
				break;
			}
			if (y == c[j][0]) { c[j][1] += 1; break; }
		}
	}
	printf("\n\n\n  ��%d���ַ�\n", g);
	for (int k = 0; k <= g; k++) {
		printf("%5.d\t|%5.d\n", c[k][0], c[k][1]);
	}
}
//ģ��sqrt()���(x:��ֵ��n:����(max:8),m:�����������)
void sqrt_momi(double x, int n, int m) {
	double i = 0, z = 0, k = 0;
	int y = 0, kongzhi = 0;
	if (x<1) { k = 1; }
	else if (x >= 1 && x<4) { k = x; }
	else { k = x / 2; }
	for (i; i<k&&i*i <= x; i += pow(10, -n)) {
		if (m) {
			printf("->%.8f  ", i);
			y++;
			if (y % 10 == 0) { printf("\n"); }
		}
		if (x == i * i) { kongzhi = 1; break; }
		if (i*i<x && (i + pow(10, -n))*(i + pow(10, -n)) >= x) { z = i; }
	}
	if (kongzhi == 0) { i = z; }
	if (n % 2 != 0) { i += pow(10, -n); }
	printf("\n\n\n��������������������������������������������\n\t%.5f������ƽ������Ϊ��%.8f\n��������������������������������������������\n", x, i);
}
//��׳�
long int Factorial(int a) {
	long int f = 1;
	for (int i = 1; i <= a; i++) {
		f *= i;
	}
	return f;
}
//�ݹ�׳�
long int Factorial_D(int a) {
	long int x;
	if (a < 0) { printf("a<0,���󣡣���\n"); return 0; }
	else {
		if (a == 0 || a == 1) { x = 1; }
		else { x = Factorial_D(a - 1)*a; }
		return x;
	}
}
//��ŵ��
void hanoi(int n, char a, char b, char c) {
	if (n == 1) { printf("%c-->%c ", a, c); }
	else {
		hanoi(n - 1, a, c, b);
		printf("%c-->%c ", a, c);
		hanoi(n - 1, b, a, c);
	}
}
//�������������ƽ��ֵ
float average(int s[6], int n) {//ƽ��ֵ
	float sum = 0.0, age;
	for (int j = 0; j <n; j++) {
		sum += s[j];
	}
	age = sum / n;
	return age;
}
void score() {//�������
	int s[6] = { 0 };
	int n = sizeof(s) / 4;
	for (int i = 0; i<n - 1; i++) {
		scanf_s("%d ", &s[i]);
	}
	printf("����ƽ��ֵΪ��%.2f\n", average(s, n));
}
//�����ַ�����ԭ���ַ�������Ӧ�ַ�ɾ��(�ⲿ����ʵ�֣�
void cccccccc() {
	int x = 0;
	char c[] = "qwertyu1676205bykuki351iopasdsdagh178963214586245klzxcvbnm", d;
	printf("ԭ�ַ���Ϊ��%s\n������һ��Ҫɾ�����ַ���", c);
	scanf_s("%c", &d);
	for (int i = 0; i<sizeof(c); i++) {
		if (c[i] != d) { continue; }
		else
		{
			for (int j = i; j < sizeof(c) - 1; j++) {
				c[j] = c[j + 1];
				if (j + 1 == sizeof(c)) { c[j + 1] = '\0'; }
			}
			x++;
		}
	}
	printf("���ַ���Ϊ��%s\n��ɾ���ַ���%d\n", c, x);
}

//--ָ��-------------------------------------------------------

//������Ԫ�ط���洢
void Reverse() {
	char c[] = {'1','2','c','4','5','6','7','8','9','0','t'};
	char *i = c,
		*v = c + sizeof(c) / 2,
		*b = c + sizeof(c)-1,
		m;
	for (i;i<v;i++,b--) {
		m = *i;
		*i = *b;
		*b = m;
	}
	for (char *j = c; j <c+sizeof(c); j++) {
		printf("%c\t", *j);
	}
}
//�����������е����ֵ����Сֵ
void Max_Min2() {
	int x[10],max,min;
	for (int *i = x; i < x+sizeof(x)/4; i++)
	{
		scanf_s("%d",i);
	}
	max = *x, min = *x;
	for (int *j = x; j<x+sizeof(x)/4; j++) {
		//printf("%d\t",*j);
		if (*j < min) { min = *j; }
		if (*j > max) { max = *j; }
		
	}
	printf("MAX=%d\tMIN=%d\n", max, min);
} 
//����ָ���к�������ӡ��ά�����Ӧ��ֵ
void i_j(int a,int b) {
	char c[5][5] ={	1,2,3,4,5,
					6,7,8,9,10,
					11,12,13,14,15,
					16,17,18,19,20,
					21,22,23,24,25};
	char (*p)[5] = c;
	printf("%d\n",*(*(p+a-1)+b-1));
}
//ͬʱ����һ������ʵ��3������
void process(int x,int y,int (*fun)(int a,int b)) {
	printf("%d\n",(*fun)(x,y));
}
int max(int a, int b) { 
	if (a > b) { return a; }
	else { return b; }
}
int min(int a, int b) {
	if (a < b) { return a; }
	else { return b; }
}
int add(int a, int b) {
	return a+b;
}
//����ѧ��ѧ�ź����ѧ���ɼ�
int  *a(int n) {
	static int a[][4] = {{ 1,95,64,30 },
					{ 2,85,120,68 },
					{ 3,89,101,64 },
					{ 4,75,65,46 },
					{ 5,12,30,9 } };//����������������̬
	return a[n-1];
}
void prrntf_a(int n) {
	int *pp,i;
	pp= a(n-1);
	for (i = 1; i < 4; i++) {
		printf("%d\t", *(pp + i));
	}
}
void check_() {//�б�ɼ��Ƿ񲻼���
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j < 4; j++) {
			if (*(a(i) + j) < 60) { 
				printf("ѧ��:%d",i);
				if (j == 1) { printf("����"); }
				if (j == 2) { printf("��ѧ"); }
				if (j == 3) { printf("Ӣ��"); }
				printf("������\n");
			}
		}
	}
}
//���ַ�������ĸ˳������
void paixu_2() {
	static char c[][20] = { "Fishc.com1","www.fishc.com","home.fishc.com","fuck you","thank you" };
	char *name[5], *p;
	for (int i = 0; i < 5; i++) {
		name[i] = c[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (strlen(c[i]) <= strlen(c[j])) {
				p = name[i];
				name[i] = name[j];
				name[j] = p;
				//printf("%s\n", name[j]);
			}
		}
	}

	for (int z = 0;z<5; z++) {
		printf("%s\n", name[z]);
	}
}
#endif

//��ϰB
#if(1)
//ָ�����1
void pinter_test1() {
	//���ۣ�int *Ϊ����ָ��   pΪ��ַ   *pΪp��ַȡֵ   
	//		&(*p)Ϊp��ַȡֵ����ֵ�ĵ�ַ��&(*p)=p
	int a=1,b=2,c=3;
	int *p = &a;
	printf("a�ĵ�ַΪ��%p\na=%d\n",p,*p);
	a = b;
	printf("a=b��,a�ĵ�ַΪ��%p\na=%d\n", p, *p);
	p = &c;
	printf("p=&c��,a�ĵ�ַΪ��%p\na=%d\n", p, *p);
	printf("&(*p)=%p\n",&(*p));
}
//ָ�����2
void pinter_test2() {
	//���ۣ�����ָ���У�    p=*p    p+i= *(p+i)    p+i�������ַ����(*p)[i]ָ������ÿ��Ԫ�����ڵ�ַ
	//����	����ָ���Ƕ������ֱ��ӳ��  

	int a[] = { 1,2,3 };
	int(*p)[3] = &a;
	printf("a=%p\n", a);
	for (int i = 0; i < sizeof(a) / 4; i++) {
		printf("&a[i]=%p\n",&a[i]);
	}

	for (int i = 0; i < sizeof(a)/4; i++) {
		printf("(*p)[i]=%d\t", (*p)[i]);
		printf("*(*p+i)=%d\t", *(*p + i));
		printf("*(p+i)=%p\t", *(p+i));
		printf("*p+i=%p\t", *p + i);
		printf("&(*p)[i]=%p\n", &(*p)[i]);
	}
}
//��̬�����ڴ�ռ䣨int[]��
void dt_realloc() {
	int nub = 0;
	int *p = NULL;
	for (int i=0;;i++) {
		printf("��ǰpָ��ռ��СΪ��%d �������%d��Ԫ�أ�", (i + 1) *sizeof(int), i+1);
		scanf_s("%d", &nub);
		if (nub == -1) {//����-1�˳�����int[]
			for (int j = 0; j < i; j++) {
				printf("%d ",p[j-1]);
			}
			break;
		}
		p = (int *)realloc(p, (i + 1)*sizeof(int));
		p[i - 1] = nub;
	}
}
#endif





