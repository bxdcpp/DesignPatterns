#include <iostream>

using namespace std;

//懒汉式
//class CSingleton
//{
//private:
//	CSingleton()   //构造函数是私有的
//	{
//		cout << "construct CSingleton" << endl;
//	}
//	static CSingleton *m_pInstance;
//public:
//	static CSingleton * Instance()
//	{
//		if (m_pInstance == nullptr)  //判断是否第一次调用
//			m_pInstance = new CSingleton();
//		return m_pInstance;
//	}
//};
// init static member

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


class Singleton3
{
private:
	static Singleton3 instance3;
private:
	Singleton3() { cout << "construct Singleton3" << endl; };
	~Singleton3() {};
	Singleton3(const Singleton3&) {};
	Singleton3& operator=(const Singleton3&) {};
public:
	static Singleton3& Instance() 
	{
		return instance3;
	}
};

// initialize defaultly
Singleton3 Singleton3::instance3;





int main()
{
	Singleton3::Instance();
	Singleton3::Instance();
	//CSingleton2::Instance();
	return 0;
}