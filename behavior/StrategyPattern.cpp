/**************************************************************************
* ����ģʽ
* 
��ͼ���ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬��

��Ҫ�������ν����¼ģʽ�����ڲ��ƻ���װ��ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬�������������Ժ󽫶���ָ���ԭ�ȱ����״̬��

��ʱʹ�ã��ܶ�ʱ������������Ҫ��¼һ��������ڲ�״̬����������Ŀ�ľ���Ϊ�������û�ȡ����ȷ�����ߴ���Ĳ������ܹ��ָ�����ԭ�ȵ�״̬��ʹ������"���ҩ"�ɳԡ�

��ν����ͨ��һ������¼��ר�Ŵ洢����״̬��

�ؼ����룺�ͻ����뱸��¼����ϣ��뱸��¼��������ϡ�

Ӧ��ʵ���� 1�����ҩ�� 2������Ϸʱ�Ĵ浵�� 3��Windows ��� ctri + z�� 4��IE �еĺ��ˡ� 4�����ݿ���������

�ŵ㣺 1�����û��ṩ��һ�ֿ��Իָ�״̬�Ļ��ƣ�����ʹ�û��ܹ��ȽϷ���ػص�ĳ����ʷ��״̬�� 2��ʵ������Ϣ�ķ�װ��ʹ���û�����Ҫ����״̬�ı���ϸ�ڡ�

ȱ�㣺������Դ�������ĳ�Ա�������࣬�Ʊػ�ռ�ñȽϴ����Դ������ÿһ�α��涼������һ�����ڴ档

ʹ�ó����� 1����Ҫ����/�ָ����ݵ����״̬������ 2���ṩһ���ɻع��Ĳ�����

ע����� 1��Ϊ�˷��ϵ�����ԭ�򣬻�Ҫ����һ��������¼���ࡣ 2��Ϊ�˽�Լ�ڴ棬��ʹ��ԭ��ģʽ+����¼ģʽ��
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