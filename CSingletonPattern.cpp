/*
* ��ͼ����֤һ�������һ��ʵ�������ṩһ����������ȫ�ַ��ʵ㡣

��Ҫ�����һ��ȫ��ʹ�õ���Ƶ���ش��������١�

��ʱʹ�ã����������ʵ����Ŀ����ʡϵͳ��Դ��ʱ��

��ν�����ж�ϵͳ�Ƿ��Ѿ������������������򷵻أ����û���򴴽���

�ؼ����룺���캯����˽�еġ�

�ŵ㣺

1�����ڴ���ֻ��һ��ʵ�����������ڴ�Ŀ�����������Ƶ���Ĵ���������ʵ�����������ѧԺ��ҳҳ�滺�棩��
2���������Դ�Ķ���ռ�ã�����д�ļ���������
ȱ�㣺û�нӿڣ����ܼ̳У��뵥һְ��ԭ���ͻ��һ����Ӧ��ֻ�����ڲ��߼�����������������ô����ʵ������

ʹ�ó�����

1��Ҫ������Ψһ���кš�
2��WEB �еļ�����������ÿ��ˢ�¶������ݿ����һ�Σ��õ����Ȼ���������
3��������һ��������Ҫ���ĵ���Դ���࣬���� I/O �����ݿ�����ӵȡ�
*/




#include <iostream>
#include <mutex>

using namespace std;

//����ʽ
//lazy��ʼ��
//���̲߳���ȫ
//���ַ�ʽ lazy loading �����ԣ���Ҫ���̰߳�ȫ���ڶ��̲߳�����������
//�ŵ㣺��һ�ε��òų�ʼ���������ڴ��˷ѡ�
//ȱ�㣺������� ��������Ӱ��Ч�ʡ�
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

//�Ǽ�ʽ/��̬�ڲ���
//lazy��ʼ��
//C++11 ���оֲ��������̰߳�ȫ��
//���ַ�ʽ lazy loading �����ԣ���Ҫ���̰߳�ȫ���ڶ��̲߳�����������

//C++11�Ľ�����һ�������֤���̰߳�ȫ
//����ʼ���׳��쳣����������δ��ʼ��״̬
//�����ڳ�ʼ�����������г�ʼ������߳̽�������
//�����ڳ�ʼ�����̵߳ݹ���ó�ʼ�������Ϊδ����
class CSingleton2
{
private:
	CSingleton2()   //���캯����˽�е�
	{
		cout << "construct CSingleton2" << endl;
	}
public:
	static CSingleton2 & Instance()
	{
		static CSingleton2 instance2;   //�ֲ���̬����
		return instance2;
	}
};

//����ģʽ
//����lazy��ʼ�� �ڳ������֮ǰ����ɵ�������ĳ�ʼ��
//�̰߳�ȫ
//�ŵ㣺û�м�����ִ��Ч�ʻ���ߡ�
//ȱ�㣺�����ʱ�ͳ�ʼ�����˷��ڴ档
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
//�Ƿ� Lazy ��ʼ������
//�Ƿ���̰߳�ȫ����
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