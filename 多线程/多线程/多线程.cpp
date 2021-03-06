// 多线程.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <thread>
#include <list>
#include <mutex>
#include <future>
using namespace std;
/*
	工作线程和界面线程区别：
		界面线程有消息循环

//#include <pthread.h>
static int a = 0;
//线程函数格式：
//线程函数是一个全局函数
//若想要把类的成员函数作为线程函数，需要把成员函数声明成静态
DWORD WINAPI T1(LPVOID lpParameter)
{
	void(*p)(int);
	p=(void (*)(int))lpParameter;
	p(10);
	return 0;
}

void xxx(int a) {
	for (int i = 0; i < a; i++) 
	{
		cout << "xxxxxxxxxxxx" << endl;
	}
}

//创建线程
int xiancheng1() 
{
	//线程id：
	DWORD dw = 0;
	//接收句柄
	//(安全指针(安全级别默认：NULL),堆栈大小,自定线程函数,线程函数传参(指针),挂起状态,线程id)
	HANDLE h=CreateThread(NULL,0, T1,(LPVOID)123,0,&dw);
	cout <<"线程号："<<dw<<"\t句柄："<< h << endl;
	//关闭句柄
	CloseHandle(h);
	return 0;
}
int xiancheng2() 
{	
	DWORD dw = 0;
	void (*x)(int);
	x = xxx;
	HANDLE h = CreateThread(NULL, 0, T1, (LPVOID)x, 0, &dw);
	return 0;
}
*/


/*
	一、并发：
			多个独立的任务同时执行

			1、上下文切换：
					并发的假，分时复用，划分时间片执行任务切换
					不同线程切换时将自己的状态进度等信息保存(以及复原)在寄存器中，是有时间开销的
					线程并非越多越好

			2、多核cpu实现真正的并发

			3、进程：
					运行的独立的可执行程序
					每个进程都有一个唯一的主线程
					产生进程后，主线程就一起启动了
					
			4、线程：
					主线程寿命跟随进程
					线程是系统资源调度的最小单位
					线程独享线程栈和寄存器

			5、实现并发：多进程||多线程
				5.1、多进程并发：进程之间通信
								（同一个电脑：管道、共享内存、消息队列、文件）
								（不同的电脑：socket通信）
				5.2、多线程并发：同一个进程中的线程共享地址空间（共享内存）
								 即全局变量、指针引用可以在线程中传递，比多进程开销小
								 共享带来问题：数据一致性的技术难点
				5.3、总结：
						线程优点：	启动速度快，更轻量级
									系统资源开销少，执行速度快(共享内存)
						线程缺点：	有难度，需要小心处理数据一致性问题

	二、c++11新标准线程库：
			以往的多线程代码不能跨平台
			新标准增加语言本身提供多线程支持，意味着可移植性（跨平台）
*/

/*
	lambda表达式：
		//[]捕获表达式：捕获匿名函数之外的变量
		[](参数列表){函数实现}(传递参数)		//可赋值给auto类型对象

		例子：auto xxx=[](int x){cout<<x<<endl;};
			调用xxx(9);		//输出结果为9
		或：	xxx=[](int x){cout<<x<<endl;}(9);
		自动类型推导：
			auot xxxx=[](int x){return x;};
			可知：xxx(9)==9;
*/		

/*
	一般情况下，主线程执行完毕后，进程被终止，意味着若存在未执行完的子线程也会被强行终止
	例外：detach()

	1、#include <thread>
	2、创建初始函数
	3、thread创建子线程并执行
	4、.join()阻塞主线程等待子线程执行完毕

	1、thread 子线程名（线程函数/类）：创建子线程并执行
	2、.join()：阻塞主线程，使主线程等待子线程汇合
	3、.detach()：传统主线程需要等待子线程，现在分离主线程与子线程，主线程先行结束不会影响子线程的执行
				使用后子线程会和主线程失去联系（变成守护线程：驻留后台运行，被c++运行时库接管）

				当调用引用对象后，主线程结束后守护线程内对象还在，因为这个对象实际上是被复制到线程中去的(执行深拷贝操作)
				传递引用在线程函数中实质是值传递（对应地址内值复制到了新的内存空间），因此依旧安全
				传递指针是不可行的，主线程执行完毕后指针指向的内存空间会被释放，从而影响分离的守护线程内的数据

				建议：detach()推荐值传递，避免隐式类型转换
						char str[]=="xxxxxxx";
						void 子线程名(const string &str){}
						thread 子线程名（线程函数名，str）
					事实存在在主线程执行完成后才开始传参隐式构造的情况，存在隐式的危险
					子线程来不及构造类对象，类对象就被回收了
					应改成
						thread 子线程名（线程函数名，string(str)）		//构造临时对象
					通过临时对象将类对象提前构造出，然后通过值传递传递给子线程

				//不能再次join()
	4、joinable()：判断是否可以成功使用join()或detach(),ture/false

	用函数创建线程：
		void 线程函数(){}
		thread 子线程名（线程函数名，传入参数1，传入参数2）
	用类对象创建线程：
		class 线程类{仿函数}
		thread 子线程名（类名）
	用lambda表达式创建线程：
		auto 表达式名=[]{函数体}
		thread 子线程名（lambda表达式名）

	线程id：每个线程都有(索引)
		创建线程后：线程名.get_id()
		线程函数中：this_thread::get_id()
*/

void time(int a, const char *c)//循环输出测试
{
	for (int i = 0; i < a; i++) {
		Sleep(1000);
		cout << c << ":第" << i + 1 << "秒" << endl;
	}
}

class ThC //线程初始类
{
	int &m_i;
public:
	ThC(int &i) :m_i(i)
	{

	}
	void operator()()
	{
		cout << "执行子线程(类): " << this << endl;
		cout << "类对象内输出myT2线程id:" << this_thread::get_id() << endl;
		time(m_i, "子线程(类)");
		cout << "退出子线程" << endl;
	}
};

int Th() //线程初始函数
{
	cout << "执行子线程" << endl;
	cout << "函数内输出myT1线程id:" << this_thread::get_id() << endl;
	time(8, "子线程");
	cout << "退出子线程" << endl;
	return 0;
}

int call_T() //调用线程
{

	thread myT1(Th);//1、thread类创建线程myT,入口是Th();2、Th()开始执行
	int i = 10;//问题！！！若此时分离类线程，当主线程执行完成后会销毁i，分离后的线程中失去引用会出问题
	ThC thc(i);
	thread myT2(thc);
	cout << "myT1线程id:" << myT1.get_id() << endl;
	cout << "myT2线程id:" << myT2.get_id() << endl;
	time(5, "主线程");
	if (myT1.joinable() && myT2.joinable()) //判断是否可以阻塞或分离
	{
		cout << "阻塞主线程" << endl;
		myT1.join();//阻塞主线程，主线程与子线程汇合
		myT2.join();//阻塞主线程，主线程与子线程汇合
	}
	return 0;
}



/*
	线程传类对象参数：
		默认情况传递，线程对象默认是重新构造新类对象，通过拷贝构造传入数据
		解决方法（传入时使用）：red(函数)
		会使当前传参为引用传递，不会出现拷贝构造

	传递智能指针：
		一个独占式智能指针传入另一个独占式智能指针：move(智能指针名)
		必须join()
		
	数据共享：
		只读：安全稳定
		读写：简单的不崩溃处理（读写不同时进行，添加互斥量）

		思想：将读写命令添加到一个链表中，通过队列操作完成读写命令(头读取并删除，尾插入)
		保护措施：同一时间只能一个线程操作，其他线程等待

		互斥量：#include <mutex>
				类，多个线程用:lock()成员函数加锁、unlock加锁
				只有一个线程可以锁成功，成功标志是lock()函数返回
				没锁成功线程就会阻塞，直至成功
				步骤：
				mutex 互斥锁名
				互斥锁名.lock() 共享数据操作 互斥锁名.unlock()
				必须成对使用，否则容易死锁

				lock_guard():自动unlock(),使用后不可再用lock和unlock（类似独占式智能指针）
				使用：lock_guard<mutex> 名称(互斥锁名)
				原理：是一个类模板，构造函数内执行了lock,析构执行unlock

				unique_lock():  取代lock_guard(),更灵活，但效率低，内存占用大
								缺省状态下功能相同，更能按第二参数区分
								所有权：一个互斥量只对应一个unique_lock()
										unique_lock()对象可以转让互斥量所有权：
										1、		mutex x;
												unique_lock<mutex> s1(x);
												unique_lock<mutex> s2(move(s1));
										2、		unique_lock<mutex> s3()
												{
													unique_lock<mutex> linshi(x);
													return linshi;
												}
												unique_lock<mutex> s4=s3;
								第二参数：	1、adopt_lock——去除lock功能(前提：必须先lock)
											2、try_to_lock——尝试加锁(前提：不可以lock)
															  没拿到锁会返回数据不会卡住
															  加锁判别：unique_lock名称.owns_lock()，拿到1，没拿到0
											3、defer_lock——初始化一个未加锁的互斥量(前提：不可以lock)
															 之后必须加锁
								成员函数：	lock();
											unlock();
											owns_lock()——判别是否加锁1/0
											try_lock()——尝试加锁,加锁返回true，未加锁返回false
											release()——返回mutex的所有权，unique_lock不在和互斥量有关系
														 使用：
															mutex sss;
															unique_lock<mutex> s(sss);
															mutex *p=s.release();
															之后需要自己unlock();
															p.unlock();									

		死锁：	AB两把锁，环境1：先锁A再锁B，然后都解锁
						环境2：先锁B再锁A，然后都解锁
				发生死锁原理：环境1中A锁锁住，环境2中B锁锁住，然后环境1中的B锁无法锁住，环境2中同理
							两个环境中两把锁互相等待造成死锁

				解决方法：	1、	不同环境下上锁顺序相同
							2、	lock(互斥量1,互斥量2,……)函数模板
								存在多个互斥量时使用，要么全锁住，要么全不锁
								当一个锁住另一个没锁住时，会将所有互斥量都解锁
								
								使用lock()模板函数时，可以配合lock_guard<mutex,adopt_lock>//不使用lock



		*/



class A 
{
public:
	void I()//插入命令
	{
		for (int i = 0; i < 1000; i++) 
		{
			cout<<i << ":输入消息对列-I"<< endl;
			m_Mutex.lock();
			//lock_guard<mutex> s1(m_Mutex);
			List.push_back(i);//尾插
			m_Mutex.unlock();
		}
	}

	bool o(int &mingling)
	{
		//lock_guard<mutex> s2(m_Mutex);
		m_Mutex.lock();

		chrono::milliseconds duta(2000);//时常2s
		this_thread::sleep_for(duta);//线程休眠（时常）


		if (!List.empty()) //消息队列不为空
		{
			mingling = List.front();//取
			List.pop_front();			//移除
			m_Mutex.unlock();
			cout << mingling << ":输出消息队列-O" << endl;
			return true;
		}
		m_Mutex.unlock();
		return false;
	}

	void O()//输出命令
	{
		for (int i = 0; i < 1000; i++) 
		{
			if (o(i)) {}
			else 
			{
				cout<<i<<":当前消息队列为空************************"<<endl;
			}   
		}
	}

private:
	list<int> List;//消息队列
	mutex m_Mutex;//互斥锁

};

int call_T2() 
{
	A a;
	thread ThAI(&A::I, &a);
	thread ThAO(&A::O, &a);

	ThAI.join();
	ThAO.join();
	return 0;
}


/*


	设计模式：	代码的规定类型写法
				划分模块总结整理成的设计模式
				特点：程序灵活，维护方便(可能)，但别人接管阅读痛苦，代码晦涩难明
				活学活用，不要深陷其中

	单例设计模式：	整个项目中，有某个特殊类属于该类的对象（那么就只能创建一次）
					例子：设计一个操作配置文件的类，只允许创建一个该类的对象，不允许创建多个对象去反复操作配置文件

					创建问题：在线程执行之前于主线程中初始化或装载单例类，并创建单例类对象，后续只进行只读操作

					存在需要在创建线程中创建单例类，且不止一个的问题！
					单例类对象的创建类成员函数存在一个线程中正在创建单例类，期间上下文切换带另一个线程中再次创建单例类
					然后再跳转回来再次完成之前操作，规避了if的作用，导致出错
					解决：	1、添加单层if互斥锁：效率低，因互斥锁只在第一次创建有意义，其余的时候的无意义的加锁解锁操作
								例子：		unigue_lock	加锁
											if(){}
							2、双层查锁(锁定)：解决上述问题
								例子：		if()
											{
												unigue_lock	加锁
												if(){}
											}
							3、使用call_once(标记名，函数名)：	c++11新增，保证多个线程中，该函数只能被调用一次，具备互斥量能力
																据说比互斥量更高效
																需要与once_flag标记结合使用
																调用后会把标记设为已标记状态，则函数a()就不会被执行了(置位)


*/

static once_flag f_MyCAS;

class MyCAS//单例类
{
	static void get_Instance() 
	{
		if (m_Instance==NULL)
		{
			m_Instance = new MyCAS();
			static Delete_Instance cl;
		}
	}
private://私有化构造
	MyCAS() {}
	static MyCAS *m_Instance;//静态成员变量，构造函数指针
public:

	class Delete_Instance //类嵌套，回收单例类对象（可有可无）
	{
	public:
		~Delete_Instance() 
		{
			if (MyCAS::m_Instance) 
			{
				delete MyCAS::m_Instance;
				MyCAS::m_Instance = NULL;
			}
		}
	};

	static MyCAS *Get_Instance()
	{
		
		if (m_Instance == NULL)
		{
			call_once(f_MyCAS, get_Instance);
		}
		return m_Instance;
	}


};
MyCAS *MyCAS::m_Instance = NULL;//初始化静态成员函数

MyCAS *p = MyCAS::Get_Instance();//创建对象返回创建对象的指针
//通过此种方式创建的对象都是唯一的，无论创建多少指针都是指向同一个对象


/*
	coudition_variable:	条件变量类
						需要与互斥量配合使用
						使用场景：	线程A：等待B中条件满足
									线程B：向消息队列输入数据
						使用方式：	coudition_variable 条件变量对象名;
									条件变量对象名.wait(互斥量名，lambda表达式)		//不一定非要是lambda表达式
									//表达式内容示例：	[this]
														{
															if( )
															{	
																return true;
															}
															return false;
														}
									若返回值为false解锁互斥量并阻塞本行,直至线程调用notify_one()成员函数解锁
										然后wait()会不断尝试加锁，加锁成功继续执行
										当该线程已被唤醒时，notify_one()可能会失效，即不可以以此作为计数器做统计使用
									若返回ture则wait()直接返回不堵塞
									若wait()没有第二个参数，则与返回false相同

									notify_one只能唤醒一个线程，而notify_all可以唤醒多个线程


*/



/*
	创建后台任务并返回值：
		#希望线程返回结果
		#include <future>
		async：函数模板，启动异步任务，返回future对象(类模板)，调用get()函数获取线程返回结果
				异步任务：创建一个线程并执行线程入口函数
				launch::deferred——（做async第一个参数，其余参数顺延）表示线程入口函数调用被延迟到wait()或get函数调用时才执行
									延迟调用不会创建线程，会直接在主线程中执行
				launch::async——(同上)，在调用async函数时线程就被创建，创建子线程
				使用：	future<线程返回值类型> 对象名 = async(线程函数名) ;	//绑定关系
						对象名.get()										//获取返回值，若获取不到会阻塞,只能调用一次，移动语义
						
						类成员函数做线程函数：
						A a;
						future<线程返回值类型> 对象名 = async(&匿名成员函数，&类对象，传参)	//必须引用，才能保证是同一个对象（共享内存），否则会重新创建

						launch::async | launch::deferred（不带参数时默认缺省状态，主要看编译器）
						同时使用时，两种选择交由系统抉择
						当系统资源充足时选择async创建线程执行，当系统资源匮乏时选择deferred直接在主线程中执行

				优点：	相较于thread方式创建线程，可以预防创建线程（一般100-200）太多系统资源耗尽崩溃
						更方便获取线程函数返回值

				焦点：	采用缺省方式让系统抉择时，不确定是否真正创建出线程，是否推迟执行，会导致程序出错
						使用wait_for(chrono::seconds(0))延迟等待0秒判断，支持wait_for(10s)写法，以及s\min\
						

		future对象.get()：获取线程函数返回值
		future_status：枚举类型，获取当前线程运行状态
			例子：
				future_status s=future对象.wait_for(chrono::seconds(1))//等待一秒
				if(s==future_status::timeout)	{	//超时状态：若当前线程运行时常超过1秒没执行完触发	}
				if(s==future_status::ready)		{	//成功返回：线程在给定时间内成功完成并返回	}
				if(s==future_status::deferred)	{	//延迟状态：当async第一个参数设置为deferred，即可激活此状态	}  
				 
		shared_future：解决future的get()方法因移动语义缘故只可调用一次问题
					shared_future的get()方法是复制数据
					（future对象.valid():布尔类型返回值，判断是否存在有效值）
					使用方法：	1、shared_future<参数类型> 对象名(  move(future对象)  ) 
								2、shared_future<参数类型> 对象名(  future对象.share()  )

*/

class B 
{
public:
	int XC_C(int x) 
	{
		cout << "类对象线程函数启动值：" << x << endl;
		cout << "类对象线程函数关闭"<< endl;
		return 0;
	}
};

int XC_M()
{
	cout << "线程函数启动,id:" <<this_thread::get_id()<< endl;
	chrono::milliseconds dura(5000);
	this_thread::sleep_for(dura);
	cout << "线程函数关闭,id:" << this_thread::get_id() << endl;
	return 5;
}

int call_T3() 
{
	future<int> xc_c_int = async(XC_M) ;
	int x = xc_c_int.get();
	cout << "线程函数返回值:" << x << endl;//get()不拿到值就堵塞

	B b;
	future<int> xc_c_class = async(&B::XC_C,&b, x);
	cout << "类对象线程函数返回值" << xc_c_class.get() << endl;
	return 0;
}

/*
	packaged_task:	任务打包，类模板
					模板参数是可调用对象，把各种可调用对象包装起来方便用作线程入口
					使用方法：	packaged_task<返回值类型(传参类型)> 打包名称(可调用对象【线程入口函数/类…】);
								创建线程执行打包任务
								.join()
								……
								future<int> 对象名=打包名称.get_future();		//将打包数据的返回值返回给对象
								对象名.get()									//通过get()获取

								还可以直接调用，即不执行线程操作（相当于函数直接调用）
								打包名称(传入值)
								使用future拿值
*/

int XC_int(int x) 
{
	cout<<"线程入口函数——传值："<<x<<endl;
	chrono::milliseconds dura(5000);
	this_thread::sleep_for(dura);
	return x;
}

int call_T4() 
{
	packaged_task<int(int)> mypt(XC_int);
	thread s1(ref(mypt),1);	//纯引用传入打包数据，传参1
	s1.join();

	future<int> re = mypt.get_future();//将打包数据的返回值返回给re
	cout << "线程函数返回值：" << re.get() << endl;//通过get()获取
	return 0;
}

/*
	参考：包入容器操作
*/

vector<packaged_task<int(int)>> v;//创建容器
int call_T5() 
{
	packaged_task<int(int)> mypt(XC_int);
	packaged_task<int(int)> mypt2(XC_int);

	v.push_back(move(mypt));//移入容器1，包现已为空
	auto iter=v.begin();//使用中间变量接收容器内包的数据
	mypt2 = move(*iter);//将中间变量移入容器2
	v.erase(iter);//删除迭代器，所以后续代码不可以再次使用iter
	mypt2(50);
	future<int> f = mypt2.get_future();
	cout << "包2数据："<< f.get() <<endl;;
	
	return 0;
}

/*
	promise：	类模板
				作用：在一个线程中赋值set_value()，在另一个线程中取出数据get_future()
*/

void XC_r(promise<int> &pr, int c) //线程函数1
{
	cout << "线程函数1启动:将"<<c<<"传入包中" << endl;
	pr.set_value(c);
}

void XC_R(promise<int> &pr, int c) //线程函数2
{
	future<int> f = pr.get_future();
	cout << "线程函数2启动：将包内数据" << f.get() << "拿出" << endl;
}

void call_T6() 
{
	promise<int> pr;
	thread s1(XC_r, ref(pr),10);
	thread s2(XC_R,ref(pr), 10);
	s1.join();
	s2.join();

}
/*
	原子操作：atomic
		概念引入：	当两个线程分别对一个共享数据进行读写操作时
					哪怕此时的读写操作不会相互干扰，也无法保证读操作读出数据的准确性
					因为读操作和写操作在两个线程可能存在时间上重叠在一起
					写操作过程中的底层汇编代码在未完全执行结束就可能会被读操作取走中间数据
					加锁后同一时刻只能一个线程操作，多线程优势无法体现且加减锁消耗资源
		原子操作：	无锁多线程并发操作，在多线程中不会被打断的程序执行片段，不可分割
					比互斥量效率高
					互斥量使用场景：	代码段
					原子操作使用场景：	单个变量
		使用方法：	atomic<参数类型> 参数名称 = 赋值;
		使用心得：	常用于计数或统计、记录状态

		运算方式：	++、--、+=、-=、&=、|=、*=等
					不支持x=x+1等类型运算
		特点：		atomic之间没有拷贝构造方法以及赋值操作

		方法：		load()：以原子方式读atomic对象的值
						atomic<int> s1=0;
						atomic<int> s2(s1.load(s1));
					store():以原子方式将值写入atomic对象
						s2.store(12);

*/

/*原子操作范例1*/

int x = 0;
atomic<int> y = 0;//封装int型原子对象，当作变量操作即可

void ch()
{	
	for (int i = 0; i < 1000000; i++) 
	{
		++x;//普通操作
		++y;//原子操作
	}
}


void call_T7()
{
	thread s1(ch);
	thread s2(ch);
	s1.join();
	s2.join();
	cout << "无操作值x:" << x << endl;
	cout << "原子操作y:" << y << endl;//原子操作不会被打断
}

/*原子操作范例2*/
atomic<bool> tf = false;//线程退出标记
void ch2() 
{
	chrono::milliseconds ms(500);
	while (!tf)//原子操作保证判断条件不会被打断
	{	
		cout<<this_thread::get_id()<<":线程任务执行中"<<endl;
		this_thread::sleep_for(ms);
	}
	cout << this_thread::get_id() << ":线程任务执行结束" << endl;
}
void call_T8()
{
	thread s1(ch2);
	thread s2(ch2);
	chrono::milliseconds ms(5000);
	this_thread::sleep_for(ms);
	tf = true;//线程结束
	s1.join();
	s2.join();
}


/*
	windows临界区：		类似互斥量，需要初始化
	多次进入临界区：	在同一线程中，相同临界区变量代表的临界区可以多次进入，但必须相同次数离开(互斥量不可以)
	自动析构技术：		容器、自动指针都属于RAII类
	class x				//调用该类可以类似lock_guard()自动加锁释放锁
	{
		x(CRITICAL_SECTION *p)
		{
			m_p=p;
			EnterCriticalSection(m_p);
		}
		`x()
		{
			LeaveCriticalSection(m_p);
		}
		public:
		CRITICAL_SECTION *p;
	}

	recursive_mutex:		递归的独占互斥量
							独占：自己lock时候，别人无法lock
							递归的独占互斥量：允许同一个线程同一个互斥量多次lock
							特点：与mutex相比效率低，消耗大
							使用前提：考虑代码是否有可以继续优化的空间
							递归次数：据说有限制，次数太多会跳异常，不常用

	timed_mutex:			带超时的独占互斥量
							超时等待
							新方法：	try_lock_for():	参数是等待一段时间，若拿到了锁，或未拿到锁超时，则线程就可以走下去
														拿到锁返回1,未拿到返回0
														使用方法：
														chronn::milliseconds timeout(100);
														my_mutex.try_lock_for(timeout);
										try_lock_until():参数是未来的一个时间点，时间点内拿到了锁或时间点后未拿到锁，线程可以继续向下走
														使用方法：
														my_mutex.try_lock_until(chronn::steady_clock::now()+timeout);			//当前时间+100ms

	recursive_timed_mutex：	带超时的递归独占互斥量




	虚假唤醒:	数据队列没数据，操作线程被唤醒

	线程池技术：
		应用场景问题:	1、多端访问，不可能为每一个链接都创建一个线程
						2、在资源匮乏的情况下存在线程创建失败的情况，程序稳定性差
		线程池：		事先创建多个线程统一管理，使用线程的时候在线程池中调用，任务结束后线程不会释放，继续回归到线程池中循环利用

	线程创建数量：
		极限：一般为2000左右
		创建建议：	1、	采用某些技术时：根据api接口提供商建议来创建，例如cpu个数、cpu*2，cpu*2+2等
						(因api会可能涉及到cpu绑定等提高效率的手段，因此建议按照提供商的建议来创建，确保程序高效)
					2、	按照完成业务：一个线程等于一条执行通路，按照最大通路堵塞需求来创建
						(例如设计最大充值业务通道为100，即100个线程同时执行充值请求，则创建100+个线程，多出线程可以继续为用户提供其他服务)
					3、	线程不是越多越好，线程在cpu时间片中执行时需要进行数据的备份和恢复工作，线程操作时在达到一定数量后工作效率会下降
					4、	尽量不超过500，尽量控制在200以内
					5、	实际创建数量应自己去测试

	c++11多线程跨平台优势
*/

int main()
{	
	//xiancheng1();//创建线程
	//xiancheng2();
	cout << "执行主线程" << endl;
	cout << "主线程id:" << this_thread::get_id() << endl;

	 
	//call_T();
	//call_T2();
	//call_T3();
	//call_T4();
	//call_T5();	//包入容器操作
	//call_T6();
	//call_T7();	//原子操作范例1
	//call_T8();	//原子操作范例2

	cout << "退出主线程" << endl;
    return 0;
}




