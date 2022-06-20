// lianxi.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"//“”是在源文件内查找文件名，<>是在系统目录下查找
//#include "hanshuku.cpp"
using namespace std;

//自编函数库a
//—————————————————————————————————————————————————————————————
/*
extern void abc();											//升序排序
extern void ABC();											//三目运算嵌套(右结合),大小写转换
extern void yunsuanqi();									// + - * /运算器
extern void Max_Min();										//输出最大最小
extern int year(int year, int a);							//判断闰年(a控制是否打印结果)
extern void yunfei(float p, int w, int s);					//运费计算（p运费 w货重 s距离 d折扣 总运费f=p*w*s*(1-d)）
extern void sqrt_x();										//开根号运算(一个数+100和+168后是完全平方数)
extern void num();											//输入年月日判断一年第几天
extern void while_c_num();									//统计输入字符数
extern void san();											//杨辉三角形
extern void QAQ(int i, int n);								//*号金字塔(起始行i个元素，共n行)
extern void Cnxn_4();										//全排列(1-4所能组成的所有四位数)
extern void Cnxn_3();										//全排列(1-4所能组成的所有三位数)
extern void ent_esc();										//按回车统计字数，esc结束循环
extern void Divisibility(int a, int b, int n);				//a~b不能被n整除的数输出
extern void PI(int n, int x);								//求PI,PI/4=1-1/3+1/5-1/7+1/9……(循环次数n,x控制输出过程)
extern void PI2(int n, int x);								//PI2(精度n)
extern void Fibonacci(int n);								//斐波那契数列
extern void prime_number();									//素数
extern void A_B_prime_number(int a, int b);					//打印a~b之间全部素数
extern char *pswd();										//加密
extern void _pswd();										//解密(没学指针未完成)
extern void oooooo();										//起泡排序
extern void ooMAXooooMINoo();								//二维数组找最值及其位置
extern void dichotomia(int n);								//二分法查找数据(n:控制过程输出)
extern void asc_II();										//输出统计输入字符种类于数量
extern void sqrt_momi(double x, int n, int m);				//模拟sqrt()求根(x:求值，n:精度(max:8),m:过程输出控制)
extern long int Factorial(int a);							//求阶乘
extern long int Factorial_D(int a);							//递归阶乘
extern void hanoi(int n, char a, char b, char c);			//汉诺塔

extern float average(int s[6], int n);						//1、调用数组参数求平均值
extern void score()											//2、调用数组参数求平均值

extern void cccccccc();										//输入字符，将原有字符串中相应字符删除(外部函数实现）
--指针----------------------------------------------------------------------------------------------------------------------
extern void Reverse();										//将数组元素反向存储
extern void Max_Min2();										//找输入数据中的最大值和最小值
extern void i_j(int a,int b);								//输入指定行和列数打印二维数组对应的值
extern void process(int x, int y, int(*fun)(int a, int b));	//0、同时调用一个函数实现3个功能

extern int max(int a, int b);								//1、求最大值
extern int min(int a, int b);								//2、求最小值
extern int add(int a, int b);								//3、求和

extern int *a(int n);										//1、输入学生学号后输出学生成绩
extern void prrntf_a(int n);								//2、输出
extern void check_();										//3、判别成绩是否不及格

extern void paixu_2();										//将字符串按字母顺序排序
*/
//—————————————————————————————————————————————————————————————
//自编函数库b
//—————————————————————————————————————————————————————————————
extern void pinter_test1();									//指针测试1
extern void pinter_test2();									//指针测试2
extern void dt_realloc();									//动态分配内存空间（int[]）
//—————————————————————————————————————————————————————————————


//结构体数组
struct votex {
	char name[10];
	int x;
}votex_s[3] = { { "张三",0 } ,{ "李四",0 },{ "王五",0 } };//定义全局结构体数组并初始化
//链表
struct students {
	char id[10];
	char name[10];
	int x;
	struct students *s;
};




//—————————————————————————————————————————————————————————————
//函数体
#if(0)
//投票系统(int n:投票人数)
void votex_(struct votex votes[], int n) {
	char c[10];
	int v;
	printf("请输入候选者编码计数：\n");
	for (int i = 1; i <= n; i++) {
		printf("%d、候选人票：",i);
		scanf_s("%s", c,10);
		for (int j = 0; j < 3; j++) {
			v = 0;
			for (int z = 0; votes[j].name[z] != '\0'; z++) {
				if (votes[j].name[z] == c[z]) {}
				else { v++; }
			}
			if (v==0) {
				votes[j].x++;
			}
		}
	}
	for (int i=0;i<3;i++) {
		printf("%s-候选人共计票数-%d\n", votes[i].name,votes[i].x);
	}
}
//申请动态链表
struct students *To_apply_for() {//动态申请空间
	struct students *st = (struct students *)malloc(sizeof(students));
	st->s = NULL;
	return st;
}
void The_list() {
	char id_[10], name_[10];
	int x_;
	struct students *head;		//定义头指针
	struct students *p;			//目标子帧
	struct students stu;
	head = p = &stu;
	while (1)
	{
		printf("\n%d\n", p);
		printf("请输入学号：\n");
		scanf_s("%s", id_, 10);

		printf("请输入姓名：\n");
		scanf_s("%s", name_, 10);
		printf("请输入成绩：\n");
		scanf_s("%d", &x_);

		strcpy_s(p->id, id_);
		strcpy_s(p->name, name_);
		p->x = x_;
		p->s = To_apply_for();
		p = p->s;
		if (id_[0] == '0') { break; }
	}
	while (head->s != NULL) {
		printf("学号：%s\t姓名：%s\t成绩：%d\n", (*head).id, (*head).name, (*head).x);
		head = head->s;
	}
}
#endif

//删除链表节点
#if(0)
void print_(struct students *p) {//打印链表
	printf("————————————————————\n");
	do {
		printf("学号：%s\t姓名：%s\t成绩：%d\n", p->id, p->name, p->x);
		p = p->s;
	} while (p != NULL);
	printf("————————————————————\n");
}
struct students *contrast_(int n,int cj,char c[], struct students *head) {
	struct students *p0 ,*p;
	int count_;
	p0 = p = head;
	count_ = 0;
	do {
		//printf("head:%d\tp0=%d\tp=%d\n", head, p0, p);
		int l = 0, j = 0;
		if (n == 0) { 
			for (j; p->id[j] != '\0'; j++) {
				if (p->id[j] != c[j]) { l++; break; }
			}
		}
		if (n == 1) {
			for (j; p->name[j] != '\0'; j++) {
				if (p->name[j] != c[j]) { l++; break; }
			}
		}
		if (n == 2) {
			if (p->x != cj) { l++; }
		}
		if (l == 0)
		{
			if (head==p&&p==p0) { 
				head = p0 = p->s;
				p =p->s; 
				count_ += 1;
			}
			else {
				p0->s = p->s;
				count_ += 1;
			}
		}
		if (p0 == p) { p = p->s; }
		else { p0 = p; p = p->s; }
	} while (p != NULL);
	printf("————————————————————\n共删除%d条记录\n", count_);
	return head;
}
void del_stu() {
	struct students s1 = { "11111","赵一", 60,NULL },
					s2 = { "22222","刘二", 91,NULL },
					s3 = { "33333","张三", 86,NULL },
					s4 = { "11111","李四", 77,NULL },
					s5 = { "22222","王五", 30,NULL };
	struct students *head = &s1;
	int n=0;//n=0:学号   n=1:姓名   n=2:成绩
	char c[10] = {0};
	int cj=0; 
	s1.s = &s2;
	s2.s = &s3;
	s3.s = &s4;
	s4.s = &s5;
	print_(head);//打印链表
	xxxxx:printf("请选择查询元素：0、学号\t1、姓名\t2、成绩\n————————————————————\n\t\t");
	scanf_s("%d————————————————————\n", &n);
	switch (n)
	{
	case 0:
		printf("————————————————————\n请输入要删除记录的学号：");
		scanf_s("%s",c,10);
		head=contrast_(n,cj,c,head);
		print_(head);
		break;
	case 1:
		printf("————————————————————\n请输入要删除记录的姓名：");
		scanf_s("%s", c, 10); 
		head = contrast_(n, cj, c, head);
		print_(head);
		break;
	case 2:
		printf("————————————————————\n请输入要删除记录的成绩：");
		scanf_s("%d", &cj);
		head = contrast_(n, cj, c, head);
		print_(head);
		break;
	default:
		printf("指令不正确，请重新选择!\n————————————————————\n");
		goto xxxxx;
		break;
	}
}
#endif
//插入链表节点
//——略

//图片文件合成器
#if(0)
void p_f(char *a,char *b,char *c) {
	FILE *fp1, *fp2, *fp3;
	fp1 = fopen(a, "rb");//图片文件读取
	fp2 = fopen(b, "rb");//压缩文件读取
	fp3 = fopen(c, "wb");//生成文件写入
	//printf("%d\t%d\t%d\n",*fp1, *fp2, *fp3);
	while (!feof(fp1))
	{
		fputc(fgetc(fp1), fp3);
	}
	fclose(fp1);
	while (!feof(fp2)) {
		fputc(fgetc(fp2), fp3);
	}
	fclose(fp2);
	fclose(fp3);
}
void Image_synthesizer(int n) {//n=1时手动输入地址，n！=1时使用默认地址
	char 
		a[50] = "E:\\1.jpg",
		b[50] = "E:\\2.rar",
		c[50] = "E:\\3.jpg";
	if (n == 1) {
		printf("请输入图片地址：");
		scanf_s("%s", a,50);
		printf("请输入文件地址：");
		scanf_s("%s", b, 50);
		printf("请输入目标地址：");
		scanf_s("%s", c, 50);
	}
	p_f(a, b, c);
}
#endif


class String {
public:
	String(const char* str)
	{
		data_ = new char[strlen(str) + 1];
		memset(data_, 0, strlen(str) + 1);
		strcpy(data_, str);
		cout << "深拷贝："<<data_<< endl;
	}
	String(const String& p)
	{
		if (data_ != nullptr)
		{
			delete[] data_;
		}
		data_ = new char[strlen(p.data_) + 1];
		memset(data_, 0, strlen(p.data_) + 1);
		strcpy(data_, p.data_);
		cout << "深拷贝构造：" << data_ << endl;
	}
	String(String&& p)
	{
		data_ = p.data_;
		cout << "浅拷贝构造（右值引用）：" << data_ << endl;
	}
	String& operator=(const String& p)
	{
		if (data_ != nullptr)
		{
			delete[] data_;
		}
		data_ = new char[strlen(p.data_) + 1];
		memset(data_, 0, strlen(p.data_) + 1);
		strcpy(data_, p.data_);
		cout << "深拷贝重赋值运算符：" << data_ << endl;
		return *this;
	}
	String& operator=(String&& p)
	{
		data_ = p.data_;
		cout << "浅拷贝重赋值运算符（右值引用）：" << data_ << endl;
		return *this;
	}
	~String()
	{
		if (data_ != nullptr)
		{
			delete[] data_;
		}
	}
private:
	char* data_;
};

//非递归实现
int binary_search(int a[], size_t len, int data) 
{
	int start = 0;
	int end = len;
	int mid = (end + start) / 2;
	cout << start << "(" << a[start] << ")--->" << mid << "(" << a[mid] << ")" << endl;
	while (1) 
	{
		if (data > a[mid])
		{
			start = mid;
			mid = (end + start) / 2;
			cout << start <<"(" << a[start]<< ")--->" << mid << "(" << a[mid] << ")" << endl;
		}
		else if (data < a[mid])
		{
			end = mid;
			mid = (mid + start) / 2;
			cout << start << "(" << a[start] << ")--->" << mid << "(" << a[mid] << ")" << endl;
		}
		else if(data == a[mid])
		{
			return mid;
		}
		if ((start == mid) && (data != a[mid]))
		{
				cout << "该数组中无data相同值" << endl;
				return -1;

		}
	}
}
//递归实现
int binary_search2(int a[], size_t len, int data)
{
	int mid= len /2;
	static int index= mid;
	static int start = 0;
	cout << "index:" << index << endl;

	if ((len == 1) && (data != a[mid]))
	{
		index = -1;
		cout << "index:" << index << endl;
		return index;
	}
	else 
	{
		if (data < a[mid])
		{
			index =  (index + start) / 2;
			binary_search2(a, mid, data);
			cout << "index:" << index << endl;
			return index;
		}
		else if (data > a[mid])
		{
			start = index;
			index += (len-mid) / 2;
			binary_search2(a + mid, len - mid, data);
			cout << "index:" << index << endl;
			return index;

		}
		else if (data == a[mid])
		{
			cout << "index:" << index << endl;
			return index;
		}
	}
}

//文件存储系统
#include <fstream>
/*


class 系统类
{
	地址设置()：设置/修改文件存储主地址
	创建索引容器()：创建list容器用于存放当前地址下的所有文件名称
	读取显示目录()：将当前地址下的所有文件名称存放到相应list容器中并显示
	创建子目录()：在主目录下创建子目录
	删除子目录()：删除主目录下的子目录
	文件复制()：输入文件地址/或选定当前目录下的文件复制到其他位置
	文件写入()：
	文件读取()：
	文件创建()：输入名称，选择合适格式、地址创建
	文件删除()：选定文件删除
	打开文件()
	关闭文件()
	操作控制()：使用上述功能实现界面操作
}


*/
int main()
{
	//执行区
	int a[] = { 1,2,5,9,11,53,62,86,99 };
	//int b= binary_search(a, sizeof(a)/4, 53);

	int b= binary_search2(a, sizeof(a)/4,62);
	cout << "索引：" << b << endl;



//—————————————————————————————————————————————————————————————
	

//示例区
//—————————————————————————————————————————————————————————————
/*
	abc();
	ABC();
	yunsuanqi();
	Max_Min();
	year(2021, 1);
	yunfei(5.25, 50, 1200);
	sqrt_x();
	num();
	while_c_num();   
	QAQ(1,10);
	Cnxn_4();
	Cnxn_3();
	ent_esc();
	Divisibility(100,200,3);
	PI(100000000,0);
	PI2(8, 0);
	Fibonacci(50);
	prime_number();
	A_B_prime_number(100,2000);
	pswd();
	_pswd();
	oooooo();
	ooMAXooooMINoo();
	dichotomia(0);
	asc_II();
	sqrt_momi(5,3,0);
	hanoi(64,'A', 'B', 'C');
	score();
	cccccccc();
	Reverse();
	Max_Min2();
	i_j(5,3);
	process(31, 20, add);
	check_();
	paixu_2();
	votex_(votex_s,10);
	The_list();
	del_stu();
	Image_synthesizer();



*/
//—————————————————————————————————————————————————————————————
	return 0;
}



//笔记区域
/*
//—————————————————————————————————————————————————————————————
1putchar('A'):字符输出函数
getchar():字符输入函数--有回显
_getch();字符输入函数--无回显--"conio.h"
sqrt():开根号函数--"math.h"
a++*2 == (a*2;a++;)
break：跳出循环（一层），只可用于循环和switch语句中，不对if-else起作用(可对if外层循环起作用)；
continue:结束本次循环
pow(x,y):x的y次方--"math.h"
fabs(x):x的绝对值--"math.h"
scanf():存在返回值，返回值是成功读入数据的个数，读入错误发挥EOF(系统宏定义，一般为-1，视编译器而定);
strcmp(str1,str2)：比较字符串长度函数，str1<str2返回负数，str1>str2返回正数--<string.h>库
 strcat(s1,s2):将s2(字符串)粘贴到s1(字符串)后
 
 *memcpy(*目标,comst *源,size):

while:循环效率高于for;

const int *p：变量常量化，不可被赋值改变（可以被指针改变）；（const int *p:指向常量的指针，指向的常量不可更改，但是指针可以修改）
* const p：可被赋值(实际上也不可以，编译允许，但windows不允许改变)，但不可改变指针（例子：int * const p,其中*p可以被修改，但是p不可修改）
const int * const p:不可被赋值且不可改变指针
//—————————————————————————————————————————————————————————————
存放在内存中：（运算器-->存-->内存-->取-->运算器）
1、auto：默认动态变量类型
2、static：静态变量（只属于当前文件，不可被外部文件引用），相当于全局变量，函数未执行前就赋值，变量不随函数结束而销毁回收
存放在寄存器中：（寄存器在cpu中：不需要在内存中反复调用同一变量，使循环提高执行效率）
1、register：寄存器变量
extern:声明外部变量，扩展函数作用域（引用性声明，可跨文件调用）
//—————————————————————————————————————————————————————————————
c=getchar()！=EOF：用于循环条件，按f6退出循环
EOF：ascII编码结束标志，ctrl+z输入
//—————————————————————————————————————————————————————————————
条件编译：
1、#ifdef	标识符						//如果定义了名为“标识符”的宏，即执行)
			程序段1
	#else	程序段2
	#endif
2、#ifndef（同if !define）				//(if no def)
	例：#ifndef B {#define B 字符串}	//如果未定义宏“B”，则定义B为……
3、#if		常量表达式
			程序段1
   #else
			程序段2
   #endif
   例：#if(n)   函数体    #endif		//n=1时，函数体被编译，n=0时函数不会被编译
//—————————————————————————————————————————————————————————————
*：取值操作符：右结合性
&：取址操作符：右结合性（*&于&*等价）
声明*b字符串，地址位于常量区，不可修改（b的值为字符串的地址）
声明b[]数组可修改:
//—————————————————————————————————————————————————————————————
#:预处理命令(宏命令)—— #define 标识符 字符串（任意）
#:预处理字符—————— #define 标识符 # 任意（将任意内容转换为字符串形式） 
						 例子：定义:	#define s(a) # a
							   函数体:	printf(s(i love %s,%d),s(you),s(520))
							   输出：	i love you,520
##:记号链接运算符————#define 标识符(a,b) a##b(输出ab,若a=1,b=2,则输出12)
例：#define PI 3.14
使用#under PI 终止命令
源程序中“宏”（被当作常量字符串），不会被预处理进行宏代换
可使用宏定义重命名(简单替换)：例：#define INTEGER int
typedef:重新命名
//—————————————————————————————————————————————————————————————
inline：内联函数，函数经过inline标识后，会在mian函数调用时将内联函数在mian函数中直接展开，等同于#define，提高了执行效率
		一般编译器可以自动将一些函数进行内联操作，编译器比程序员更懂得该函数是否适合内联
		内敛操作不可滥用，提高执行效率的同时会增加代码编译时间
//—————————————————————————————————————————————————————————————
结构体声明：struct 结构体名称(student，可省略) { 成员列表……（类型说明符 成员名） };
声明结构体变量：struct student 结构体变量名；
结构体声明和结构体变量可以一起声明，例：struct student { 成员列表…… } student1；
引用：结构体变量名.成员名
声明结构体指针：stuct 结构体名 *结构体指针变量名
				使用：结构体指针变量名=&结构体变量名
					  结构体变量名.x==(*结构体指针变量名).x==结构体指针变量名->x
结构体内存对齐：#pragma pack(2)      宏定义指定对齐模数为2（必须为2的整数倍）
//—————————————————————————————————————————————————————————————
分配内存空间函数：<stdlib.h>
malloc：原型：void *malloc(ungigned int size) ;
		在内存动态存储区分配一个长度为size(无符号数)的连续空间，
		返回空间起始地址指针(类型void)
		函数未能成功执行(例：内存空间不足)返回空指针(NULL)
		不会初始化空间为0
calloc：原型：void *calloc(ungigned n,ungigned size) ;
		分配n个长度为size的连续空间，其余同上
		可以为一维数组开辟动态存储空间，n个元素，元素长度为size
		会初始化空间为0
释放内存空间函数：
free：	原型：void free(void *p)；
		释放p指针(最近一次调用calloc或mallo时返回的值)指向的内存区，无返回值

重新分配内存空间函数：
realloc：原型：void *realloc(void *p,size_t size);
		 将原空间指针p所指向的空间的基础上扩展空间大小为size
		 p指针地址会改变
//—————————————————————————————————————————————————————————————
共用体：使不同变量共占同一段内存的结构（共用体长度=最长元素长度）
--每一次只能存一种数据，以最后一次存入为准（地址相同）
--可以使用共用体指针（不能变量名赋值，不能初始化赋值，不能引用，不能作为函数参数，不能返回）
union 共用体名{成员表列}变量表列;（类似结构体）
//—————————————————————————————————————————————————————————————
枚举类型：常量
enum 枚举结构名 { 枚举元素1，枚举元素2，枚举元素3 } 枚举变量名;(枚举元素默认对应值为的自身位置0、1、2、3……)
使用：例：枚举变量=枚举元素n;
		  printf(枚举变量) ——>  结果为枚举变量=n-1
//—————————————————————————————————————————————————————————————
文件：————<stdio.h>
（技巧：system("pause")--窗口暂停     exit(0)--终止程序）
FILE *fp;										FILE类型结构体（fp：指向FILE类型结构体的指针变量）
fp=fopen(文件名(路径),使用文件方式(读/写))		fopen：文件打开		
	r:只读——该文件必需存在，不存在返回空指针(NULL)
	w:只写——打开文件不存在则新建该名文件,若存在则删除旧文件创建新文件
	a:追加——文件必须存在否则出错
fgetc(fp);										可用ch!=EOF作为结束判断（二进制文件用：!feof(fp)——feof()结束返回1，否则0）
fputc(ch,fp);									每写一次内部指针后移一位，成功写入返回写入值，失败返回EOF(c:-1)
fgets(str,n,fp);								在文件中读出n-1(最后一个是'\0')个字符送入str中,返回str首地址（fp换成stdin--键盘输入文件（遇到输入空格时））
fputs(str,fp);									将字符串str写入文件，成功返回0，失败EOF
fread(buffer,size,count,fp)						buffer--读入或输出数据的地址	
fwrite(buffer,size,count,fp)					size:读写的字节数	count:读写多少次   函数成功写入返回1，错误返回
fprintf(文件指针，格式字符，输出表列)			例：fprintf(fp,"%d,%6.2f",i,t)
fscanf(文件指针，格式字符，输出表列)			例：fscanf(fp,"%d,%f",&i,&t)
	fgetc/fputc——字符读写
	fgets/fputs——字符串读写
	fread/fwrite——数据块读写
	fscanf/fprinf——格式化读写
fseek(文件类型指针,位移量,起始点)				改变文件指针位置一般用于二进制文件
												位移量：起始点后偏移量（long形 例：fseek(fp,100L,0)--起始向后100字节	fseek(fp,100L,1)--当前位置向后100字节	fseek(fp,100L,2)--文件末尾向前100字节）
												起始点：文件开头：SEEK_SET 0	文件当前位置：SEEK_CUR 1	文件末尾：SEEK_END 2

ftell(fp);										得到文件流当前位置，返回偏移量，出错返回-1L
fclose(fp);										fclose文件关闭

错误指示器：
ferror(fp);										出错检测，正常返回0，错误返回非0值，当调用输入（fputc/fputs）输出函数后立即执行检测，否则可能丢失信息，执行fopen函数时ferror函数初始值自动置为0	
												只记录错误状态，无法获取错误内容
												大多数系统会自动记录到errno【#include <errno.h>】中，erron只会返回错误码，可配合strerror(errno)返回错误码对应内容
												可以使用perror("前缀字符串(提示自己，例如：文件打开失败错误原因：)")，返回显示   "前缀字符串+错误原因"
												
位置指示器：
rewind:											rewind（fp）将指针fp指向的文件的读取位置指向文件起始位置
清除指示器：
clearerr(fp)									（两种指示器全部清0）时文件错误标志和文件结束标志置为0（只要出现错误标志，标志就会保留，直到调用clearerr或rewind函数，或任意输入输出）
//—————————————————————————————————————————————————————————————
标准流(指针)：
	标准输入流：stdin
	标准输出流：stdout
	标准错误输出流：stderr
		例子：判断打开文件失败
				if((fp=fopen("文件路径"，"r"))==NULL){
					fputs("打开文件失败",stderr)
					exit(EXIT_FAILURE)//退出当前程序等效于exit(0)
				}

重定向：（linue）
	重定向标准输入：<
	重定向标准输出：>
	重定向标准错误输出：2>
//—————————————————————————————————————————————————————————————
位运算

	&	按位与      ————参与运算是负数则以补码形式参与运算
					清零(位)操作：除操作位全1按位与
					取指定位：除指定为其余全0      
					//大小写转换：if(c&32){c=c&223;}else{c=c|255;}
	
	|	按位或		

	^	按位异或	特定位反转：除指定位全0
					与0运算保持原值
					交换两个值：a=a^b	b=b^a	a=a^b
	
	~	取反

	<<	左移		例:a=<<2左移两位，右侧补0，左侧溢出舍弃（左移一位==*2，适用于无溢出）

	>>	右移		右移一位==/2，适用于无溢出
					若值为负数，符号位移入0/1（取决于计算机），移入0(逻辑右移/简单右移)，移入1(算数右移)
//—————————————————————————————————————————————————————————————
位段（必须指定为unsigned或int，必须存储在同一个存储单元中）
struct packed_data{
	unsigned a:2;//a占两个位
	unsigned b:6;//不够一个字节可用	  unsigned :0;	隔开将0前存在上一个单元，0后存在下一个单元(1/2个字节，视编译系统而定)
	unsigned c:4;
	unsigned d:4;
	int i;
}data;
//—————————————————————————————————————————————————————————————
内存布局：
  低位地址--------------------------------------------------------------------->高位地址
			代码段		数据段			bss段			   堆				栈
			   |		   |			  |					|				 |
			 函数	   全局变量	   未初始化全局变量	  申请的内存空间	执行的函数(cd)参数
			字符串	   静态变量	   未初始化静态变量	  例如realloc		局部变量、常量
		(共享和只读)   全局常量											(系统管理)

程序运行前就存在的:代码区和全局区
程序运行后会出现的：堆区、栈区
堆：需要程序员手动申请并手动释放的内存空间，不同函数体均自由访问（同其余空间一样，从低位地址向高位地址发展）
栈：系统自动规划并自动释放的空间，函数体之间局部变量不能互相访问（与其余空间相反，从高位地址向低位地址发展）

栈区注意事项：不要返回局部变量\常量的地址
			 （局部变量常量在函数执行完会会被系统销毁，返回地址无意义）
			  如果返回局部变量地址，编译器会保留一次数据，之后销毁内存，二次访问乱码
//—————————————————————————————————————————————————————————————
内存池：一种概念，申请指针指向一个该被释放的堆空间，让其不被释放，若有需要不必再次malloc，直接在内存池内使用满足条件的空区域
		倘若内存池内没有满足条件的空区域或空区域已被使用，则再重新使用malloc申请空间
//—————————————————————————————————————————————————————————————

*/





/*																C++
//--------------------------------------------------------------------------------------------------------------------------
	cout << "字符串" << 变量 <<endl					
	rand()%100								0-99随机数
	srand((unsigned int)time(NULL));		根据当前系统时间添加随机数种子#include <ctime>

	string									字符串类型 #include <string>

	堆区开辟内存：new:						例子：	int类型：		int *a = new int(10)
													int数组类型：	int *a = new int[10]
											给数据10在堆区开辟int型内存空间，并返回int类型指针
	堆区释放内存：delete：					例子：	int类型：		delete a
													int数组类型：	delete[] a
											将指针a指向的内存空间释放，再次访问就是非法操作

	引用(起别名)：							语法：	数据类型 &别名 = 原名
											本质：	声明引用：指针常量
													引用赋值操作：解引用赋值
											注意：引用必须初始化，之后不可更改（b作为a的别名不可以再次去引用c）
											引用做函数参数可以代替地址传递 例子：void sss(int &a,int &b)()
											函数的返回值是一个引用，函数调用可以作为左值 
											例子：int *s(...){static int a=10; return a;}   int main(s=100) 
	常量引用：								例子：const int &ref = 10
											等同：int x = 10; const int &ref = x;
											const int %ref 等同于 const int *const ref
											常用于函数参数防止函数内存在修改数据操作

	函数参数可以初始化默认值，调用函数的时候可以省略参数的传入，倘若调用期间传入新数据则会覆盖默认数据
	默认实参必须在形参列表的结尾，默认值后，从左到右都必须有默认值
	如果函数声明存在默认值，则函数实现就不能有默认值(声明和实现只能有一个有默认值)
	
	占位参数：	例：int x(int a,int)
				占位参数可以赋默认值int x(int a , int = 10)

	函数重载：	满足条件：	1、函数名相同 
							2、同一个作用域下 
							3、函数参数的类型个数或顺序不同
				注意事项：	1、返回值可以不同
							2、引用作为重载条件
								例子：	int func(int &b)
										int func(const int &b)
										func(a)调用第一个	int &b=10不合法
										func(10)调用第二个	int &a=a
							3、函数重载时传入默认值，可能会导致二义性，报错(尽量避免)
	




	构造函数/析构函数/拷贝构造函数：	默认为空，必须存在，不写系统会默认添加实现（自写有参系统不提供无参提供拷贝，自写拷贝，其余构造函数都不提供）
	编译器给一个类默认添加的4个函数：	1、构造
										2、析构
										3、拷贝构造
										4、operator=
										5、operator&
										6、coust operator&

	析构函数：							通常将堆区开辟的数据进行释放操作
										例子：if(m_s!=NULL)
										{
											delete m_s;
											m_s == NULL;
										}
										若存在拷贝构造函数时，会引发崩溃，因为是浅拷贝操作，导致重复释放
										解决：浅拷贝问题利用深拷贝解决
										方法：重写拷贝构造函数,为数据new一个新内存空间

	构造函数：		1、普通构造			无参/有参构造（可以重载）
					2、拷贝构造			P( const P &p ){}
					成员函数声明可以在类外，类内声明，类外通过类名实现成员函数
	构造函数调用：	1、括号法(**方便**)
						P p1;			默认构造函数（不要加小括号，编译器会理解为函数的声明）
						P p2(10);		有参构造函数
						P p3(p2);		拷贝构造函数	使用时机：	(初始化复制、实参传形参、当作返回数据类型)
																	1、使用已有对象初始化新对象
																	2、使用值传递的方式给函数参数传值
																		例子：	void xxx(P p){}
																				void aaa(){xxx(p1);}	相当于:P p=p1;
																	3、值方式返回局部变量
																		例子：	P bbb(){P p;return p;}	//并不是将p对象返回到ccc()中，而是拷贝了一份新的P对象返回给了p1 
																				void ccc(){P p1=bbb();}
					2、显示法
						P p1;			无参构造
						P p2 = P(10)	有参构造
						P p3 = p(p2)	拷贝构造
						P(10)		 	单独使用为匿名对象
										执行完会被立刻回收，表现为析构函数立刻执行
										不要用拷贝构造函数去初始化匿名对象
										（编译器认为P(p3)===P p3;p3被重定义）
					3、隐式转换法
						P p4 = 10;		相当于：P p4 = P(10)
						P p5 = p4;		相当于：P p5 = P(p4)

	深浅拷贝(**面试重点**):	
					1、浅拷贝：简单的赋值拷贝操作
					2、深拷贝：在堆区重新申请空间，进行拷贝操作
					问题：见析构函数

	初始化列表：	语法：				构造函数():属性1(值1),属性2(值2)……{}

	对象成员：		B类包含A类，则A为对象成员
					例子：	class A();
							class B()
							{
								A a;
							}
					当其他类的对象作为本类成员，构造时先构造类对象，再构造自身
					析构是先释放本类，再释放类对象

	静态成员:		static
					编译阶段分配内存
					类内声明，类外初始化(必须，否则不能使用)
					例子：	类内：static int m_a;
							类外：int P :: m_a = 100;
					静态成员变量/函数有访问权限（设为私有则在类外可初始化，但是没法访问）
					静态成员函数既可以通过对象访问，也可以通过类名访问（无需创建对象即可访问P::s()）
					静态成员函数只访问静态成员变量（非静态成员变量会使得编译器无法判断变量位置，无法访问）
					

	常函数/常对象：	const
					常函数不可修改成员属性
					成员属性加mutable后可修改，例：mutable int x;
					常对象只能调用常函数(因为普通成员函数是可以修改成员属性的)
					void sss()const{ }【const加在成员函数后】
					this:本质上讲是指针常量，const修饰后变成了指向常量的指针常量，this指向的值也不可以修改了

	空对象占用内存空间为1字节，是为了区分空对象占内存位置，每个空对象也有一个独一无二的内存地址
	静态成员不属于类的对象上，不占用类的内存空间（只有非静态成员变量是属于类的对象上）

	成员变量和成员函数是分开存储的

	this指针：	1、解决名称冲突
				2、返回对象本身用*this（类型为P &,以引用的形式返回）【链式编程思想】
				3、指向被调用的函数所属的成员变量
						例子：	class P{
									public:P(int age){this->age=age;}
									int age;
								}
								int main(){
									P p(18);//this指向p		this->age相当于p.age
								}
	指向对象的空指针可以访问类的成员函数，但涉及成员变量的时候，成员变量未初始化，报错,this指向未初始化的数据
	建议在成员函数中添加if(this==NULL){return;}

	友元： 
	函数访问：在被访问的class中最上边用friend声明函数/类

	运算符重载(也可同时发生函数重载)：
		内置运算规则不可以改变
		不可滥用
		通过operator+（编译器提供的函数名称实现 P.p3=p1+p2）
		例子：	class P
				{
					public:
						//成员函数重载+
						P operator+(P &p)
						{
							P temp;
							temp.m_A=this->m_A+p.m_A;
							temp.m_B=this->m_B+p.m_B;
							return temp;
						}

						int m_A;
						int m_B;
				}
				//全局函数重载+
				P operator+(P &p1,P &p2)
				{
					P temp;
					temp.m_A=p1.m_A+p2.m_A;
					temp.m_B=p1.m_B+p2.m_B;
					return temp;
				}
				//全局函数重载<<实现   cout << p
				ostream & operator<<(ostream &cout,P &p4)
				{
					cout << "m_A="<< p4.m_A <<"m_B="<< p4.m_B
					return cout;
				}
				int main(){
						……
					P p3=p1+p2;	//实现P类对象的对应相加功能
								//成员函数重载+本质调用：P p3=p1.operator+(p2);
								//全局函数重载+本质调用：P p3=operator+(p1,p2);
					cout << p	//全局变量重载<<本质调用：operator<<(cout,P p4)
						……
				}

		前置递增返回引用，后置递增返回值
		class P //递增重载
		{
			public:
				P & operator++()
				{
				m_A+=1;
				return *this
				}
				P operator++(int)
				{
				P temp=*this;
				p.m_A+=1;
				return temp
				}
			private:
				int m_A;
		}

		class S //赋值运算符重载
		{
			public:
				S(int A)
				{
					m_A=new int(A);
				}

				S & operator=(S &s)
				{
					if(m_A!=NULL){
						delete m_A;
						m_A=NULL;
					}
					m_A =new int(*s1.m_A);
					return *this;
				}
			private:
				int *m_A;
		}

		class D//对比运算符重载
		{
			public:
				D(string N,int A):m_N=N,m_A=A{				}

				bool & operator==(D &d)
				{	
					if(this->m_A==d.m_A && this->m_N==d.m_N)
					{
						return turn;
					}
					else
					{
						return false;
					}
				}
			private:
				string m_N;
				int m_A;
		}

		函数调用运算符()重载：仿函数
		class F
		{
			public:
				int &operator()(int a,int b)
				{
					return a+b;
				}
			private:
		}
		调用 
		F f;
		f(100,100);//返回值200	
		可用匿名函数对象调用
		F()(100,100);//返回值200

	继承【***】
	普通继承：	class 子类(派生类): 继承方式 父类(基类){}
	多继承：	class 子类：继承方式 父类1，继承方式 父类2{}
	菱形继承：	class A{}
				class B :public A{}
				class C :public A{}
				class D :public B,public C{}	//菱形继承导致数据有两份，利用虚继承实现
	虚继承：	更改上述类：
				class B : virtual public A{}	//A类成为虚基类
				class C : virtual public A{}
				当存在虚继承后，子类中的同名成员会共享，此时D类中不会出现两份数据
					类模型更变：出现vbptr(虚基类指针)指向vbtable(虚基类表,记录虚函数地址)
								两者之间的偏移量是8（虚继承个数*地址数据长度）


		 
	继承方式：	public——公共继承			不改变父类继承过来的权限
				protected——保护继承		将父类继承过来的权限都以保护权限继承
				private——私有继承			将父类继承过来的权限都以私有权限继承
				注！！！：所有方式都无法访问父类中原有的私有权限内容
				（无法访问原因是编译器隐藏了，而不是没有继承）
						查看：	在vs 2017命令提示符工具下cd跳转到文件所在目录，用dir命令查看类模型
								cl /d1 reoprtSingleClassLayoutSon 03			//Son是类名，是/d1不是DL，03按tab按键自动补齐
				
				继承中，先调用父类构造，再调用子类构造
				销毁时，先调用子类析构，再调用父类析构

				继承中,子类调用同名成员方法：
						子类中直接访问(s.m_A)，继承父类的加作用域访问(s.F::m_A)
				如果子类中出现与父类同名的成员函数，则会隐藏掉父类中的所有的同名成员函数
						例：1、	class A{public:int func(){}}
								class B:public A{}
								A a;B b;
								调用a.func()可调用b.func()——未隐藏
							2、class A{public:int func(){}}
								class B:public A{public:int func(){}}
								A a;B b;
								调用a.func()不可用b.func()，而是b.A:func()——被隐藏
								

	多态【***】	
		作用：				隐藏细节，接口复用
		静态多态：			函数重载、运算符重载
							地址早绑定：编译阶段确认函数地址
		动态多态：			派生类和虚函数实现运行时的多态
							地址晚绑定：运行阶段确定函数地址
							实现条件：	1、存在继承关系
										2、子类要重写父类的虚函数
							使用：		父类指针或引用执行子类对象
		原理：				A类内部结构：
							vfptr->vftable（虚函数表：内部存放：&A::speak）
							B类内部结构：										
							vfprt->vftable（虚函数表：内部存放：&A::speak）
							//当子类重写父类虚函数的时候，子类的虚函数内部会替换成子类的虚函数地址
							（用&B::speak替换&A::speak，父类中的不会改变）

		好处：				组织结构清晰、可读性强、提供可扩展性和可维护性
							满足开闭原则：对扩展进行开发，对修改进行关闭

		纯虚函数：			virtual 返回值类型 函数名 （参数列表）= 0;
							存在纯虚函数（包括纯虚析构）的类被称作抽象类
							抽象类特点：无法实例化，子类必须重写纯虚函数，否则子类也是抽象类

		虚析构：			问题：	父类指针析构的时候不调用子类析构函数，若子类析构中有堆区属性会造成内存泄露
							办法：	将父类中的析构改为虚析构

		纯虚析构:			同上，但必须在类外有具体实现——A::~A(){}

		例子：	class A 
				{
				public:speak(){cout<<"1"<<endl}
				};
				class B:public A					//继承关系
				{
				public:speak(){cout<<"2"<<endl}		//重写父类虚函数
				};

				void dospeak(A &a)					//A &a=b——父类引用执行子类对象
				{
					a.speak();
				}

				int main()
				{
					B b;
					dospeak(b);		//输出结果为1，因为早绑定，无论传入何值，A &a永远指向父类中的函数
									//想要输出2，则现需要将A类中的speak函数转为虚函数
				}

				案例：制作饮料
				class yinpin {
				public:
					void zhushui()
					{
						cout << "煮水" << endl;
					}
					virtual void chongpao() = 0;
					void dao()
					{
					cout << "倒入杯中" << endl;
					}
					virtual void jialiao() = 0;
					void over()
					{
						zhushui();
						chongpao();
						dao();
						jialiao();
					};
				};
				class java :public yinpin {

					void chongpao() {
						cout << "冲泡咖啡" << endl;
					}
					void jialiao()
					{
						cout << "加糖和奶粉" << endl;
					}
				};
				class tea :public yinpin {
					void chongpao() {
						cout << "冲泡茶叶" << endl;
					}
					void jialiao()
					{
						cout << "加柠檬" << endl;
					}
					};
				void shuchu(yinpin *y)
				{
					y->over();
					delete y;
				}
				void t1()
				{
					shuchu(new java);
					shuchu(new tea);
				}

	文件操作：#include <fstream>
		操作文件的三大类：	1、ofstream	写操作
							2、ifstream	读操作
							3、fstream	读写操作
		步骤：	1、包含头文件
					#include <fstream>
				2、创建流对象
					ofstream ofs;	输出流
					ifstream ifs;	输入流
					可以在创建流对象的时候就传入打开方式
					ofstream ofs("文件路径",打开方式
				3、打开文件
					ofs.open("文件路径",打开方式)		.is_open()用来检测是否打开成功，成功返回1
					if(!ofs.is_open()){
						cout<<"打开文件失败"<<endl;
						return;
					}
				4、	1、	写数据						
						ofs <<"写入的数据"
					2、	读数据
						(1)、	char buf(1024)={0};
								while(ifs>>buf)				//ifs读数据遇到空格会结束								{
									cout<<buf<<endl;		//利用ifs>>a && ifs>>b && ifs>>c就可以实现连续的数据读取
								}	
						(2)、	char buf(1024)={0};
								while(ifs.gatline(buf,sizeof(buf)))		//按行读取，.getline(存放地址,最多读取大小)
								{
									cout<<buf<<endl;
								}
						(3)、	string buf;
								while(getline(ifs,buf))		//全局的getline(输入流,字符串)
								{
									cout<<buf<<endl;
								}
						(4)、	char a;
								while((c=ifs.get())!=EOF)	//一个字符一个字符读，读到文件尾跳出
								{							//.eof() 判断是否是文件尾，是返回1
									cout<<buf<<endl;
								}
					3、二进制写数据：
						P p={"张三",18}		//创建一个名叫张三，18岁的人类
						ofs.write((count char *)&p,sizeof(P))		//数据块操作write（(count char *)类型指针,数据长度)
					4、二进制读数据
						P p;
						ifs.read((cahr *)&p,sizeop(P))
						cout<<"姓名："<<p.m_Name<<"年龄："<<p.m_Age<<endl;
				5、关闭文件
					ofs.close();

		文件打开方式：（打开方式可配合使用：例：二进制写文件ios::binary|ios::out）
				1、ios::in		读文件
				2、ios::out		写文件
				3、ios::ate		起始位置：文件尾
				4、ios::app		追加方式写文件
				5、ios::trunc	如果文件存在先删除，再创建新文件
				6、ios::binary	二进制方式

		#pragma once		防止头文件重复包含
		cin >> "键盘上输入"
		system("cls");		清屏




		模板(泛型编程)：	提高复用性
			template<typename T>		//tempname可换成class  
				例子：	template<typename T>		//声明模板，告诉编译器T通用类型不要报错，
						void maSwap(T &a,T &b)						{
							T temp = a;
							a=b;
							b=temp;
						}
						调用：
						int a,b;
						maSwap(a,b)			//自动类型推导
						maSwap<int>(a,b)	//指定类型
			注意：	自动推导必须推导出一致的数据类型
					模板必须确定出T的数据类型才可以使用

			与普通函数区别：利用自动类型推导则不会发生隐式类型转换
							利用显式指定类型可以

			与普通函数调用规则：	
							1、如果函数模板和普通函数都可以调用，则优先调用普通函数
							2、通过空模板参数列表强制调用函数模板
								（m<>(),类似显示指定不写数据类型）
							3、函数模板可以重载
							4、如果函数模板可以更好匹配，则优先调用函数模板
								（编译器优先选择不使用隐式类型转换的匹配）
			局限性：	问题：	自定义类型无法进行操作
						解决：	利用具体化对类操作的版本实现
									class X{};
									template<class T>
									bool 对比函数（T a,T b）{对比操作结果};
									template<> bool 对比函数（X a,X b）{对比操作结果};		//模板的重载版本，T的位置可以直接指定类型
								此时调用函数模板时传入自定义类数据就会走特定版本的模板函数

			类模板：		template<class A,class B = int>			//类型中可以有默认参数（默认类型）
							class S									//声明默认类型调用时就可以以默认类型调用
							{
							public:
								S(A a,B b)
								{
									this->a=a;
									this->b=b;
								}	
								A a;
								B b;
							}
							调用：S<string,int> s("字符串",int整形)			//类模板没有自动类型推导
			创建时机：		普通函数的成员函数一开始就被创建了
							类模板中成员函数在调用的时候才开始创建
							意味着在类模板中的成员函数可以调用不确定的方法而且不报错

			类模板对象做函数参数
							1、指定传入类型(最常用)：
								创建对象：P<string,int> p("佚名",100)
								类模板对象做函数参数：void ssss(P<string,int> &p){};
								调用函数：ssss(p);
							2、参数模板化
								类模板对象做函数参数（模板化）：template<class T1,class T2>
																void ssss(P<T1,T2> &p){};
								(如何查看参数类型及其名称：typeid(T1)   typeid(T1).name() )
							3、整个类模板化
								类模板对象做函数参数（模板化）：template<class T>
																void ssss(T &p){};

			类模板与继承：	子类继承的父类是类模板时，子类在声明时需要指定父类的T的类型
							如若不然，编译器无法给子类分配内存
							想要灵活指定父类T类型，子类也需要变成类模板

			类模板的类外实现：
							template<class T1,class T2>
							P p
							{
							public:
								P(T1 t1,T2 t2);
								void s();
								T1 t1;
								T2 t2;
							}
							
							template<class T1,class T2>
							P<T1,T2>::P(T1 t1,T2 t2)	类名<类模板数据类型指定>::P(){}
							{
								this->t1=t1;
								this->t2=t2;
							}

			类模板分文件编写：
							1、	直接包含源文件（.cpp）而不是头文件（.h）			——很少使用（一般不包含源码）
								原因：创建时机问题导致类模板的成员函数是后生成，导致编译器无法"看见"源文件中的函数实现
							2、	将声明和实现全部写道一个文件中,命名为（.hpp）文件	——常用
			类模板友元：	1、全局函数类内实现：在类模板中成员函数添加friend关键字，变为全局函数
							2、全局函数类外实现：在类模板中用friend关键字声明函数，类外补全实现——（麻烦）
								注意问题：	函数在类模板内声明，声明时需在函数名后添加类模板的参数列表标识<>
											类外的函数实现应放在类模板前，让编译器先看见实现内容
											类外实现的函数因调用类模板，需要在此前再次添加类模板的声明




		【*****************】STL【****************】
		诞生目的：避免重复工作，提高复用性
		STL标准模板库：容器+算法+迭代器			容器和算法通过迭代器无缝链接
		六大组件:
		1、容器：	各种数据结构，存放数据（拥有专属的迭代器）
					1、序列式容器：强调值的排序，元素都有固定位置
					2、关联式容器：二叉树结构，没有严格顺序关系
		2、算法：	常用算法（需要通过迭代器才能访问容器）
					1、质变算法：运算改变区间元素内容，例如拷贝、替换、删除
					2、非质变算法：运算不会改变区间元素内容：例如查找、计算、遍历
		3、迭代器：	容器和算法的胶合剂（类似指针操作）
					1、输入迭代器：		只读访问		支持++、==、!=
					2、输出迭代器：		只写访问		支持++
					3、前向迭代器：		读写操作，并可以向前推进迭代器	支持++、==、！=
					【一般只接触下面两种】
					4、双向迭代器：		读写操作，并可以向前和后操作	支持++
					5、随机访问迭代器：	读写操作，并可以跳跃的方式访问任意数据（最强）	支持++、--、[n]、-n、<、<=、>、>=
		4、仿函数：	运算符重载（），可协助算法完成不同的策略变化
		5、适配器(配接器)：
					修饰算法
		6、空间适配器：
					负责空间配置与管理

		

			容器：vector
			算法：for_each			//#include <algorithm>标准算法头文件
			迭代器：vector<数据类型>::iterator

				存放内置数据类型
					//创建容器
					vector<int> v;
					//容器内插入数据
					v.push_back(10);//.push_back()尾插
					//通过迭代器访问
					vector<int>::iterator 迭代器名称:v.begin();//起始迭代器，指向容器第一个元素
					vector<int>::iterator 迭代器名称:v.end();//结束迭代器，指向容器最后一个元素的下一个位置
					//通过遍历算法遍历容器内的数值
					void 回调函数(int val)	//输出
					{	cout<<val<<endl;		}
					for_each(v.begin(),v.end(),回调函数)
				存放自定义类型
					vector<P> v;
					P p1("111",10);
					v.push_back(&p1);
					//通过for()遍历
					for(vector<P>::iterator it=v.begin();it!=v.end();it++)
					{
						cout<<it->调用1<<(*it).调用2<<endl;
					}
					for(vector<P*>::iterator it=v.begin();it!=v.end();it++)
					{
					cout<<(*it)->调用1<<(*(*it)).调用2<<endl;
					}
				容器嵌套容器
					vector<int> v1			//小容器v1
					v1.push_back(10)
					v1.push_back(20)

					begin					//小容器v2
					v2.push_back(30)
					v2.push_back(40)

					vector<vector<int>> v	//大容器v
					v.push_back(&v1)
					v.push_back(&v2)

					for(vector<vector<int>>::iterator it1=v.begin();it1!=v.end();it1++)
					{
						for(vector<int>::iterator it2=it1->begin();it2!=it1->end();it2++)
						{
							cout<<*it2<<" ";
						}
						cout<<endl;
					}


				容器：string	//类中封装了char*，管理字符串，是char*型容器
					构造：		string():空字符串
								string(const char * s):初始化字符串s
								string(const string &str):拷贝构造，string初始化另一个string
								string(int n,char c):使用n个字符c初始化

					赋值：		string& openator=(const char* s):运算符重载赋值
								string& openator=(const string& s)
								string& openator=(char c)
								string& assign(const char* s):assign()函数重载赋值
								string& assign(const char* s,int n):将前n个字符赋给当前字符串
								string& assign(const string& s)
								string& assign(int n,char c)

					拼接：		string& openator+=(const char* str)
								string& openator+=(const char c)
								string& openator+=(const string& str)
								string& append(const char* s)
								string& append(const char* s,int n)
								string& append(const string& s)
								string& append(const string& s,int pos,int n):将字符串s自pos位置开始的n个字符拼接到字符串结尾

					查找替换：	int find(const string& str,int pos=0)const:查找str第一次出现位置，从pos开始（返回值是位置下标，没有返回-1）
								int find(const char* s,int pos=0)const
								int find(const char* s,int pos,int n)const
								int find(const char c,int pos=0)const
								int rfind(const string& str,int pos=0)const:查找str最后出现位置
								int rfind(const char* s,int pos=0)const
								int rfind(const char* s,int pos,int n)const
								int rfind(const char c,int pos=0)const
								string& replace(int pos,int n,const string& str):替换从pos开始的n个字符为str
								string& replace(int pos,int n,const char* s)

								find是从左往右查找，rfind是从右往左查找

					字符串比较：int compare(const string& s)const;
								int compare(const cahr* s)const;
								按照字符串的ASCII码进行比较
									= return 0;
									> return 1;
									< return -1;
								主要是比较字符串是否相等，判断大小意义不大

					字符存取：	char& openator[](int n):通过下标获取/修改字符
								char& at(int n):通过at方法获取/修改字符

					插入删除：	string& insert(int pos,const char* s):插入
								string& insert(int pos,const string& s):插入
								string& insert(int pos,int n,char c):在pos位置插入n个c
								string& erase(int pos,int n = npos);删除从pos开始n个字符

					获取字串：	string substr(int pos=0,int n=npos)const:返回自pos开始的n个字符组成的字符串

				容器:vector
					单端数组，可动态扩展（不是接续，而是找到更大的空间拷贝进去，释放原空间）
					v,rend()	//容器第一个元素前一个位置
					v.begin()	//容器第一个元素位置
					v.rbegin()	//容器最后一个元素位置
					v.end()		//容器最后一个元素后一个位置
					vector::iterator	随机访问迭代器

					原型：	vector<T> v;				//模板实现，默认构造函数
							vector(v.begin(),v.end());	//将区间内的元素拷贝给本身
							vector(n,elem);				//构造函数将n个elem拷贝给本身
							vector(const vector& v)		//拷贝构造函数

					赋值：	vector& openator=(const vector& vec);	//运算符重载
							assign(beg,end)							//将区间内的数据拷贝赋值给本身		
							assign(n,elem)							//将n个elem拷贝赋值给本身

					容量大小操作：		empty()				//判断是非为空，空为turn 非空false
										capacity():			//获取容量
										size();				//元素个数（容量>=元素个数）
										resize(int num);	//重新指定容量大小（变长以默认值填充，变短超出不部分删除）
										resize(int num,elem)//同上，以elem填充

					插入删除：			push_back(ele);									//尾插
										pop_back();										//尾删
										insert(const_iterator pos,ele);					//迭代器指向pos位置插入元素ele
										insert(const_iterator pos,int count,ele);		//迭代器指向pos位置插入cpount个元素ele
										erase(const_iterator pos);						//删除迭代器指向的元素
										erase(const_iterator start,const_iterator end);	//删除迭代器从start到end之间的元素
										clear();										//清空容器所有元素 

					数据存取：			at(int idx);	//返回索引idx所指向的数据
										openator[]:		//返回索引idx所指向的数据（运算符重载）
										front():		//返回第一个元素
										back();			//返回最后一个元素

					互换：				swap(vec);		//将vec与自身互换
										实际用途：收缩内存空间	
										vector<int>(v).swap(v);
											vector<int>(v):匿名对象
											匿名对象创建后与原容器互换，匿名对象创建完后会立刻执行内存回收
											原容器内元素被转移到匿名对象创建的，和原容器内元素大小一致的空间中
											因原容器内原先的容量>=元素个数，因此相较之前内存使用空间被收缩了

					预留空间：			减少容器动态扩展容量时的扩展次数	
										reserve(int len);		//容器预留len长度空间，预留位置不初始化，内容元素不可访问

				容器：deque
					双端数组，可以对头端进行插入和删除
					与vector区别：	vector头部操作数据量越大，效率越低，
									deque头部操作比vector快
									vector访问元素比deque快
					内部工作原理：	deque内部存在中控器，维护缓冲区内容，缓冲区内存放真实数据元素
									中控器存放的是缓冲区地址，使容器逻辑上是连成一片的内存空间

					使用过程中const	deque<int>&d是不被允许的，想要限制容器无法修改需要使用const_iterator只读迭代器

					函数原型：		deque<T> deq;
									deque(beg,end);			//拷贝
									deque(n,elem);			//n个elem拷贝
									deque(const deque& deq)	//拷贝构造函数

					插入删除：		push_front(elem)							//头插
									push_back(elem)								//尾插
									pop_front()								//头删
									pop_back()								//尾删

									insert(pos,elem)						//指定位置插入数据，返回新数据位置
									insert(pos,n,elem)						//pos位置插入n个elem,无返回值
									insert(pos,beg,end)						//插入另一个deque容器区间的数据，无返回值
									clear()									//清空
									erase(beg,end)							//删除区间内数据，返回下一个数据位置
									erase(pos)								//删除指定位置数据，返回同上

					赋值操作：		deque& operator=(const deque& deq)		//等号运算符重载
									assign(beg,end);
									assign(n,elem);

					大小操作：		.empty()				//判空
									.size()					//个数
									.resize(num)			//重新指定容器长度
									.resize(num,elem)

					存取：			at(int idx)	
									openator[]
									front()
									back() 

					排序【算法】：	sort(iterator beg,iterator end)		//对区间内元素排序（默认升序）
									支持随机访问迭代器的容器都可以使用sort排序


				容器：stack
					先进后出数据结构（栈）
					栈不允许遍历行为（只能看见栈底元素）

					判空：empty()
					元素个数：size()

					构造函数：		stack() stk;
									stack(const stack& stk);
					赋值：			运算符重载=
					存取：			top()		栈底元素	
									push(elem)	入栈
									pop()		出栈
					大小：			empty()		判空
									size()		元素个数


				容器：queue
					先进先出（队列）
					队列不允许遍历行为（只能看见队头和队尾）

					构造函数：		//默认
									//拷贝
					赋值：			运算符重载=
					存取：			push(elem)
									oop()
									front()		队头
									back()		队尾
					大小：			//
									//

				容器：list【*********】
					双向循环链表
						优点：内存动态分配，不会造成内存浪费和溢出，快速插入删除操作灵活
						缺点：遍历速度低于数组、占用内存空间大
					迭代器是双向迭代器，只支持前移和后移

					构造函数：		//默认
									//拷贝
									list(beg,end)			//区间拷贝
									list(n,elem)
					赋值：			assign(beg,end)
									assign(n,elem)
									//=
									swap(list)				//容器交换
					大小：			size()
									empty()
									resize(num)				//重新指定大小
									resize(n,elem)
					插入删除：		push_back(elem)			//尾插
									push_front(elem)		//头插
									pop_back()				//尾删
									pop_front()				//头删
									insert(pos,elem)		//插入elem,返回新数据位置
									insert(pos,n,elem)		//无返回值
									insert(pos,beg,end)		//无返回值
									clear()					//清空
									erase(beg,end)			//删除
									erase(pos)
									remove(elem)			//移除与elem值的相同元素
					存取：			front();
									back();
					反转/排序：		reverse();				//反转
									sort();					//排序（成员函数，不是算法的）
									排序默认升序，若要降序操作
									bool m(int a,int b)【排序规则:元素降序】
									{
										return a>b;
									}
									调用：l.sort(m)

									bool m(P &p1,P &p2)【多条件高级排序:先年龄排序，相同年龄按身高排序】
									{
										if(p1.m_Age==p2.m_Age)
										{
											return p1.m_Height>p2.m_Height;
										}else{
											return p1.m_Age>p2.m_Age;
										}
										
									}

				容器:set/multiset
					集合结构
					关联式容器
					所有元素插入时自动排序（结构二叉树）
					不允许重复元素（multiset允许）
					验证：插入数据后，set返回类型是对组(有重复检测)，multiset返回迭代器(无重复检测)

					构造：			//默认
									//拷贝
					插入删除：		insert(elem)
									clear()
									erase(pos);
									erase(beg,end);
									erase(elem);			//类似remove
					大小：			size()
									empty()
									swap(st)				//互换
					查找统计：		find(key)				//查找key是否存在，存在返回迭代器，不存在返回set.end()
									count(key)				//统计key个数
					容器排序规则:	仿函数
									创建容器时完成
									class M
									{
									public:
										bool operator()(int a,int b)
										{
											return a>b;
										}
									}
									set<int,M> s;
									class M2
									{
									public:
										bool operator()(const P& p1,const P& p2)
										{
											return p1.m_Age>p2.m_Age;
										}
									}
				对组：pair
					成对出现的数据，利用对组可以返回两个数据
					第一个值为key（键值），第二个值为value（实值）

					创建方式：		pair<type,type> p (value1,value2);
									pair<type,type> p = make_pair(value1,value2);
					获取数据：		.first	//第一个数据
									.second	//第二个数据

				容器：map/multimap		
					字典结果
					关联式容器
					底层二叉树
					高性能，高效率
					每个元素都是pair，根据元素键值自动排序
					map不允许重复键值，multimap允许重复键值

					构造：				map<T1,T2> mp/默认
										//拷贝
					插入/删除：			insert(pair<type,type>(key,value))
										insert(make_pair(key,value))
										insert(map<type,type>::value_type(key,value))
										mp[key]=value			//不建议，查询使用时，若不存在则会创建一个value=0的对组插入
										clear()
										erase(pos)
										erase(beg,end)
										erase(key)
					大小：				size()
										empty()
										swap(st)		//互换
					查找/统计：			find(key)		//查找
										count(key)		//统计
					排序:				同上
										class M;
										调用：map<int,int,M> mp

				函数对象：仿函数
					重载()，本质是一个类
					特点：	1、可以像普通函数那样调用，可以有参数，也可以有返回值
							2、超出普通函数概念，可以有自己的状态（成员属性）
							3、可以作为参数传递

					谓词：
						返回bool类型的仿函数
						如果重载()接受1个参数，就叫做一元谓词
						如果重载()接受2个参数，就叫做二元谓词
						find_if(beg,end,谓词(查询条件))			//区间内根据查询条件查询，返回迭代器

				内建函数对象：#include <functional>
					算数仿函数：	1、template<class T> T plus<T>				+
									2、template<class T> T minus<T>				-
									3、template<class T> T multiplies<T>		*
									4、template<class T> T divdes<T>			/
									5、template<class T> T modelus<T>			%
									6、template<class T> T negate<T>			取反
									使用例：代码：	negate<int> n
													n(50)
											打印值：-50
					关系仿函数：	1、template<class T> T equal_to<T>			=
									2、template<class T> T not_equal_to<T>		!=
									3、template<class T> T greater<T>			>
									4、template<class T> T greater_equal<T>		>=
									5、template<class T> T less<T>				<
									6、template<class T> T less_equal<T>		<=
					逻辑运算符：	1、template<class T> T logical_and<T>		&&
									2、template<class T> T logical_or<T>		||
									3、template<class T> T logical_not<T>		！

			常用算法：
				#include <algorithm>	标准算法头文件	最大
				#include <numeric>		体积小，只包含在序列上进行简单数学运算的模板函数
				#include <functional>	定义了一些模板类，用以声明函数对象

				遍历
				for_each(v.begin(),v.end,回调函数)			//函数/仿函数负责输出

				搬运(A容器—>B容器)
				transform(beg1,end1,beg2,回调函数)			//回调函数可以对A容器内元素进行处理后传入B元素
					注意：B容器必须事先开辟空间

				查找
				find(beg,end,value)					//返回迭代器，找不到返回.end()
													//自定义类型比较需要在类中重载==

				条件查找
				find_if(beg,end,谓词)				//返回迭代器

				查找相邻重复元素
				adjacent_find(beg,end)				//相邻元素返回前一个的迭代器

				二分查找法
				binary_search(beg,end,value)		//返回bool
					注意：在无序序列中不可用，必须有序

				统计元素个数
				count(beg,end,value)				//自定义类型比较需要在类中重载==

				条件统计
				count_if(beg,end,谓词)							

			常用排序算法：
				元素内容排序
				sort(beg,end,谓词);

				洗牌(随机调整)
				random_shuffle(beg,end);			//随机种子srand((unsigned int)time(NULL))	#include <ctime>

				合并(存储到其他容器)
				merge(beg1,end1,beg2,end2,目标容器迭代器)
					注意：必须有序且同序，合并后依旧有序

				反转(首尾对调)
				reverse(beg,end);				

			常用拷贝替换算法：
				范围拷贝
				copy(beg,end,beg2)
					注意：目标容器需要提前开辟空间

				指定范围替换
				replace(beg,end,旧值,新值)

				指定范围条件替换
				replace_if(beg,end,谓词,新值)

				互换容器内容
				swap(容器1,容器2)

			常用算术生成算法：	#include <numeric>
				累加
				accumulate(beg,end,value)				//value:初始值,返回值int

				向容器内添加元素
				fill(beg,end,value);

			常用集合算法：
				求两容器交集
				set_intersection(beg1,end1,beg2,end2,目标容器迭代器)		//返回最后结束位置
					注意：最特殊情况是大容器完全包含小容器内容，开辟空间取小容器内容即可
							v.resize(min(v1.size,v2.size))		//min在标准算法库内

				求两容器并集
				set_union(容器1,容器2)										//返回最后结束位置
					注意：最特殊情况是两个容器无并集，开辟空间大小取两者大小之和
							v.resize(v1.size+v2.size)

				求两容器差集
				set_difference(容器1,容器2)									//返回最后结束位置
					注意：容器顺序有异，差集为第一个容器排除于第二个容器内元素相同的元素
							最特殊情况是两者无交集，开辟空间大小为第一个容器的大小

*/										

