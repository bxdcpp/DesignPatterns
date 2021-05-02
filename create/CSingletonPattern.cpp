/*
* 意图：保证一个类仅有一个实例，并提供一个访问它的全局访问点。

主要解决：一个全局使用的类频繁地创建与销毁。

何时使用：当您想控制实例数目，节省系统资源的时候。

如何解决：判断系统是否已经有这个单例，如果有则返回，如果没有则创建。

关键代码：构造函数是私有的。

优点：

1、在内存里只有一个实例，减少了内存的开销，尤其是频繁的创建和销毁实例（比如管理学院首页页面缓存）。
2、避免对资源的多重占用（比如写文件操作）。
缺点：没有接口，不能继承，与单一职责原则冲突，一个类应该只关心内部逻辑，而不关心外面怎么样来实例化。

使用场景：

1、要求生产唯一序列号。
2、WEB 中的计数器，不用每次刷新都在数据库里加一次，用单例先缓存起来。
3、创建的一个对象需要消耗的资源过多，比如 I/O 与数据库的连接等。
*/




#include <iostream>
#include <mutex>

using namespace std;

//懒汉式
//lazy初始化
//多线程不安全
//这种方式 lazy loading 很明显，不要求线程安全，在多线程不能正常工作
//优点：第一次调用才初始化，避免内存浪费。
//缺点：必须加锁 但加锁会影响效率。
class Singleton
{
private:
	static Singleton* instance;
private:
	Singleton() {};
	~Singleton() {};
	Singleton(const Singleton&) =delete;
	Singleton& operator=(const Singleton&) =delete;
public:
	static Singleton* getInstance()
	{
		if (instance == nullptr)
			instance = new Singleton();
		return instance;
	}
};
Singleton* Singleton::instance = nullptr;

//登记式/静态内部类
//lazy初始化
//C++11 这中局部变量是线程安全的
//这种方式 lazy loading 很明显，不要求线程安全，在多线程不能正常工作

//C++11改进了这一情况，保证了线程安全
//若初始化抛出异常将继续保持未初始化状态
//若正在初始化，其它运行初始化语句线程将被阻塞
//若正在初始化的线程递归调用初始化语句行为未定义
class CSingleton2
{
private:
	CSingleton2()   //构造函数是私有的
	{
		cout << "construct CSingleton2" << endl;
	}
public:
	static CSingleton2 & Instance()
	{
		static CSingleton2 instance2;   //局部静态变量
		return instance2;
	}
};

//饿汉模式
//不是lazy初始化 在程序入口之前就完成单例对象的初始化
//线程安全
//优点：没有加锁，执行效率会提高。
//缺点：类加载时就初始化，浪费内存。
class Singleton3
{
private:
	static Singleton3* m_instance3;
private:
	Singleton3() { cout << "construct Singleton3" << endl; };
	~Singleton3() {};
	Singleton3(const Singleton3&) {};
	Singleton3& operator=(const Singleton3&) {};
public:
	static Singleton3* Instance() 
	{
		return m_instance3;
	}
};

// initialize defaultly
Singleton3 *Singleton3::m_instance3 = new Singleton3();

//
//是否 Lazy 初始化：是
//是否多线程安全：是
class Singleton4
{
public:
	static Singleton4* Instance()
	{
		if (m_instance4 == nullptr)
		{
			if (m_mutex.try_lock())
			{
				if (m_instance4 == nullptr)
				{
					m_instance4 = new Singleton4();
				}
				m_mutex.unlock();
			}
		}
		
	}
private:
	Singleton4() {};
	static Singleton4* m_instance4;
	static mutex m_mutex;
};

Singleton4* Singleton4::m_instance4 = nullptr;
mutex Singleton4::m_mutex;



int main()
{
	Singleton3::Instance();
	Singleton3::Instance();
	//CSingleton2::Instance();
	return 0;
}