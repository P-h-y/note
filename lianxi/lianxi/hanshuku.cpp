#include "stdafx.h"
#include "math.h"
#include "conio.h"
//#define NULL ((void *)0) ：空指针（当指针定义时初始化使用）

//练习A
#if(0)
//升序排序
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
//三目运算嵌套(右结合),大小写转换
void ABC() {
	char c;
	//c = getchar();
	scanf_s("%c", &c);//scanf:无效报错
	c >= 97 && c <= 122 ? printf("%c转化为大写=%c\n", c, c - 32) :
		c >= 65 && c <= 90 ? printf("%c转化为小写=%c\n", c, c + 32) : printf("%c不是大小写字母\n", c);
}
// + - * /运算器
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
		if (a == 0) { printf("不是有效运算"); }
		else { result = a / b; }
		break;
	}
	default:printf("不是有效运算"); break;
	}
	printf("=%.2f\n", result);
}
//输出最大最小
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
//判断闰年(a控制是否打印结果)
int year(int year, int a) {
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			if (a == 1) { printf("%d是闰年\n", year); }
			return 1;
		}
		else {
			if (a == 1) { printf("%d不是闰年\n", year); }
			return 0;
		}
	}
	else {
		if (year % 4 == 0) {
			if (a == 1) { printf("%d是闰年\n", year); }
			return 1;
		}
		else {
			if (a == 1) { printf("%d不是闰年\n", year); }
			return 0;
		}
	}
}
//运费计算（p运费 w货重 s距离 d折扣 总运费f=p*w*s*(1-d)）
void yunfei(float p, int w, int s) {
	float d, f;
	if (s < 250)d = 0.00;
	if (s < 500)d = 0.02;
	if (s < 1000)d = 0.05;
	if (s < 2000)d = 0.80;
	if (s < 3000)d = 0.10;
	else d = 0.15;
	f = p * w*s*(1 - d);
	printf("基本运费：\t%.2f\n货重：\t%d\n运输距离：\t%d\n折扣：\t%.2f\n总运费:\t%.2f\n", p, w, s, d, f);
}
//开根号运算(一个数+100和+168后是完全平方数)
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
//输入年月日判断一年第几天
void num() {
	int y, m, d, day = 0;
	int num1[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int num2[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	printf("输入年月日:\n");
	scanf_s("%d %d %d", &y, &m, &d);
	if (m > 12 || d > 31) { printf("月份或日数输入错误！"); }
	else
	{
		if (year(y, 0) == 0 && m == 2 && d>28) { printf("非闰年2月份只有28天！！！"); }
		else if (year(y, 0) == 1 && m == 2 && d>29) { printf("闰年2月份只有29天！！！"); }
		else
		{
			if (year(y, 0) == 1) {
				for (int i = 0; i < m - 1; i++) { day += num2[i]; }
			}
			else {
				for (int i = 0; i < m - 1; i++) { day += num1[i]; }
			}
			day += d;
			printf("共 %d 天\n", day);
		}
	}
}
//统计输入字符数
void while_c_num() {
	int n = 0;
	while (getchar() != '\n') {
		n++;
	}
	printf("共输入%d个字符\n", n);
}
//*号金字塔(起始行i个元素，共n行)
void QAQ(int i, int n) {
	for (i; i < n; i++) {
		for (int j = i; j >0; j--) {
			printf("*");
		}
		printf("\n");
	}
}
//杨辉三角形
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
//全排列(1-4所能组成的所有四位数)
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
	printf("共计：%d\n", sum_n);
}
//全排列(1-4所能组成的所有三位数)
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
	printf("共计：%d\n", sum_n);
}
//按回车统计字数，esc结束循环
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
		if (c == 27) { printf("\r退出\n"); break; }
		printf("\n当前共输入 %d 个字符\n", i);
	}
}
//a~b不能被n整除的数输出
void Divisibility(int a, int b, int n) {
	int i = 0;
	for (a; a <= b; a++) {
		if (a%n == 0) { continue; }
		printf("%d\t", a);
		i++;
		if (i % 8 == 0) { printf("\n"); }
	}
	printf("\n共%d个数！\n", i);
}
//求PI,PI/4=1-1/3+1/5-1/7+1/9……(循环次数n,x控制输出过程)
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
//PI2(精度n)
void PI2(int n, int x) {
	long double pi = 4.0;
	double nx = pow(10, n);//10的n次方
	for (int i = 1; ((1 + 2 * i) / 4.0)<nx; i++) {
		i % 2 == 0 ? pi += 4.0 / (1 + 2 * i) : pi -= 4.0 / (1 + 2 * i);
		if (x == 1) {
			printf("PI(%d)=%.10f\t", i, pi);
			if (i % 5 == 0) { printf("\n"); }
		}
	}
	printf("\nPI=%.50f\n", pi);
}
//斐波那契数列
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
//素数
void prime_number() {
	int x = 0, prime = 0;
	printf("请输入数字：");
	scanf_s("%d", &x);
	printf("%d该数", x);
	if ((int)sqrt(x) / sqrt(x) == 1) {//优化
		x = sqrt(x);
		printf("不");
	}
	else {
		for (int i = 2; i<x / 2; i++) {
			if (x%i == 0) { printf("不"); break; }
		}
	}
	printf("是素数\n");
}
//打印a~b之间全部素数
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
	printf("共%d个素数\n", x);
}
//加密
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
		else { printf("\n数据不正确，无法加密\n"); break; }
	}
	c[i + 1] = '\0';
	for (int j = 0; j != i + 1; j++)
	{
		printf("%c", c[j]);
	}
	return c;
}
//解密(没学指针未完成)
void _pswd() {}
//起泡排序
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
//二维数组找最值及其位置
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
		printf("\n——————————————————————\n");
	}
	printf("第%d行%d列为最大值：%d\n第%d行%d列为最小值：%d\n\n\n", a1, a2, max, b1, b2, min);
}
//二分法查找数据(n:控制过程输出)
void dichotomia(int n) {
	int x[20] = { -999,-102,-86,-15,-12,0,12,21,34,48,51,61,75,88,91,120,155,992,1016,1865 };
	int a, b, c, y;
	a = 0;
	c = sizeof(x) / 4 - 1;
	printf("请输入比较值：");
	scanf_s("%d", &y);
	//printf("%d", sizeof(x));
	if (y<x[a] || y>x[c]) { printf("\n该值不在数列范围!!!\n\n"); }
	else {
		while (1) {
			b = (a + c) / 2;
			if (n) { printf("———————————\na=%d\tb=%d\tc=%d\n———————————\n", a, b, c); }
			if (x[b] == y) { printf("\n该值存在于数列的第%d号位置!!!\n\n", b); break; }
			if (a >= c) {
				if (a > b) { int i = a; a = b; b = i; }
				printf("\n该值于数列内不存在!!!\n\n");
				break;
			}
			if (x[b] > y) { c = b - 1; }
			if (x[b] < y) { a = b + 1; }
			if (n) { printf("a=%d\tb=%d\tc=%d\n", a, b, c); }
		}
	}
}
//输出统计输入字符种类于数量
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
	printf("\n\n\n  共%d种字符\n", g);
	for (int k = 0; k <= g; k++) {
		printf("%5.d\t|%5.d\n", c[k][0], c[k][1]);
	}
}
//模拟sqrt()求根(x:求值，n:精度(max:8),m:过程输出控制)
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
	printf("\n\n\n——————————————————————\n\t%.5f的算数平方根是为：%.8f\n——————————————————————\n", x, i);
}
//求阶乘
long int Factorial(int a) {
	long int f = 1;
	for (int i = 1; i <= a; i++) {
		f *= i;
	}
	return f;
}
//递归阶乘
long int Factorial_D(int a) {
	long int x;
	if (a < 0) { printf("a<0,错误！！！\n"); return 0; }
	else {
		if (a == 0 || a == 1) { x = 1; }
		else { x = Factorial_D(a - 1)*a; }
		return x;
	}
}
//汉诺塔
void hanoi(int n, char a, char b, char c) {
	if (n == 1) { printf("%c-->%c ", a, c); }
	else {
		hanoi(n - 1, a, c, b);
		printf("%c-->%c ", a, c);
		hanoi(n - 1, b, a, c);
	}
}
//调用数组参数求平均值
float average(int s[6], int n) {//平均值
	float sum = 0.0, age;
	for (int j = 0; j <n; j++) {
		sum += s[j];
	}
	age = sum / n;
	return age;
}
void score() {//输入输出
	int s[6] = { 0 };
	int n = sizeof(s) / 4;
	for (int i = 0; i<n - 1; i++) {
		scanf_s("%d ", &s[i]);
	}
	printf("上述平均值为：%.2f\n", average(s, n));
}
//输入字符，将原有字符串中相应字符删除(外部函数实现）
void cccccccc() {
	int x = 0;
	char c[] = "qwertyu1676205bykuki351iopasdsdagh178963214586245klzxcvbnm", d;
	printf("原字符串为：%s\n请输入一个要删除的字符：", c);
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
	printf("现字符串为：%s\n共删除字符：%d\n", c, x);
}

//--指针-------------------------------------------------------

//将数组元素反向存储
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
//找输入数据中的最大值和最小值
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
//输入指定行和列数打印二维数组对应的值
void i_j(int a,int b) {
	char c[5][5] ={	1,2,3,4,5,
					6,7,8,9,10,
					11,12,13,14,15,
					16,17,18,19,20,
					21,22,23,24,25};
	char (*p)[5] = c;
	printf("%d\n",*(*(p+a-1)+b-1));
}
//同时调用一个函数实现3个功能
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
//输入学生学号后输出学生成绩
int  *a(int n) {
	static int a[][4] = {{ 1,95,64,30 },
					{ 2,85,120,68 },
					{ 3,89,101,64 },
					{ 4,75,65,46 },
					{ 5,12,30,9 } };//！！！！！！！静态
	return a[n-1];
}
void prrntf_a(int n) {
	int *pp,i;
	pp= a(n-1);
	for (i = 1; i < 4; i++) {
		printf("%d\t", *(pp + i));
	}
}
void check_() {//判别成绩是否不及格
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j < 4; j++) {
			if (*(a(i) + j) < 60) { 
				printf("学号:%d",i);
				if (j == 1) { printf("语文"); }
				if (j == 2) { printf("数学"); }
				if (j == 3) { printf("英语"); }
				printf("不及格！\n");
			}
		}
	}
}
//将字符串按字母顺序排序
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

//练习B
#if(1)
//指针测试1
void pinter_test1() {
	//结论：int *为定义指针   p为地址   *p为p地址取值   
	//		&(*p)为p地址取值后数值的地址，&(*p)=p
	int a=1,b=2,c=3;
	int *p = &a;
	printf("a的地址为：%p\na=%d\n",p,*p);
	a = b;
	printf("a=b后,a的地址为：%p\na=%d\n", p, *p);
	p = &c;
	printf("p=&c后,a的地址为：%p\na=%d\n", p, *p);
	printf("&(*p)=%p\n",&(*p));
}
//指针测试2
void pinter_test2() {
	//结论：数组指针中，    p=*p    p+i= *(p+i)    p+i是自身地址，而(*p)[i]指向数组每个元素所在地址
	//即：	数组指针是对数组的直观映射  

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
//动态分配内存空间（int[]）
void dt_realloc() {
	int nub = 0;
	int *p = NULL;
	for (int i=0;;i++) {
		printf("当前p指针空间大小为：%d 请输入第%d个元素：", (i + 1) *sizeof(int), i+1);
		scanf_s("%d", &nub);
		if (nub == -1) {//输入-1退出遍历int[]
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





