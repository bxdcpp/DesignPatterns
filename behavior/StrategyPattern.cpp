/**************************************************************************
* ����ģʽ
* 
��ͼ������һϵ�е��㷨,������һ������װ����, ����ʹ���ǿ��໥�滻��

��Ҫ��������ж����㷨���Ƶ�����£�ʹ�� if...else �������ĸ��Ӻ�����ά����

��ʱʹ�ã�һ��ϵͳ���������࣬���������ǵ�ֻ������ֱ�ӵ���Ϊ��

��ν��������Щ�㷨��װ��һ��һ�����࣬������滻��

�ؼ����룺ʵ��ͬһ���ӿڡ�

Ӧ��ʵ���� 1��������Ľ�����ƣ�ÿһ�����Ҿ���һ�����ԡ� 2�����еĳ��η�ʽ��ѡ�������г�����������ÿһ�����з�ʽ����һ�����ԡ� 3��JAVA AWT �е� LayoutManager��

�ŵ㣺 1���㷨���������л��� 2������ʹ�ö��������жϡ� 3����չ�����á�

ȱ�㣺 1������������ࡣ 2�����в����඼��Ҫ���Ⱪ¶��

ʹ�ó����� 1�������һ��ϵͳ����������࣬����֮���������������ǵ���Ϊ����ôʹ�ò���ģʽ���Զ�̬����һ�������������Ϊ��ѡ��һ����Ϊ�� 2��һ��ϵͳ��Ҫ��̬���ڼ����㷨��ѡ��һ�֡� 3�����һ�������кܶ����Ϊ���������ǡ����ģʽ����Щ��Ϊ��ֻ��ʹ�ö��ص�����ѡ�������ʵ�֡�

ע��������һ��ϵͳ�Ĳ��Զ����ĸ�������Ҫ����ʹ�û��ģʽ��������������͵����⡣
**************************************************************************/

#include <iostream>

class Strategy {
public:
	virtual int doOperation(int num1, int num2) = 0;
	virtual ~Strategy() {};
};

class OperationAdd : public  Strategy
{
public:

	int doOperation(int num1, int num2) override {
		return num1 + num2;
	}
};

class OperationMultiply : public  Strategy
{
public:

	int doOperation(int num1, int num2) override {
		return num1 * num2;
	}
};

class OperationSubtract : public  Strategy
{
public:

	int doOperation(int num1, int num2) override {
		return num1 - num2;
	}
};

class Context {
public:
	Context():m_strategy(nullptr)
	{

	}
	void setStrategy(Strategy* con)
	{
		this->m_strategy = con;
	}
	int executeStrategy(int num1, int num2) {
		return m_strategy->doOperation(num1, num2);
	}
private:
	Strategy* m_strategy;
};


void main()
{
	using std::cout;
	using std::endl;

	Context* context = new Context();
	context->setStrategy(new OperationAdd());
	cout << "10 + 5 = " << context->executeStrategy(10, 5) << endl;

	context->setStrategy(new OperationSubtract());
	cout << "10 - 5 = " << context->executeStrategy(10, 5) << endl;

	context->setStrategy(new OperationMultiply());
	cout << "10 * 5 = " << context->executeStrategy(10, 5) << endl;

}