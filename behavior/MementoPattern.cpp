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
#include <vector>

using namespace std;

class Memento {
public:
	Memento(string state)
	{
		this->state = state;
	}
	string getState() {
		return state;
	}
private:
	string state;
};

class Originator
{
public:
	void setState(string state)
	{
		this->state = state;
	}
	string getState() {
		return state;
	}
	Memento* saveStateToMemento() {
		return new Memento(state);
	}
	void getStateFromMemento(Memento* memento) {
		state = memento->getState();
	}
private:
	string state;
};

class CareTaker
{
public:
	void add(Memento* state)
	{
		mementoList.push_back(state);
	}
	Memento* get(int index) {
		return mementoList[index];
	}
private:
	vector<Memento*> mementoList;

};




void main()
{
	using std::cout;
	using std::endl;

	Originator* originator = new Originator();
	CareTaker* careTaker = new CareTaker();
	originator->setState("State #1");
	originator->setState("State #2");
	careTaker->add(originator->saveStateToMemento());
	originator->setState("State #3");
	careTaker->add(originator->saveStateToMemento());
	originator->setState("State #4");

	cout << "Current State: " << originator->getState() << endl;
	originator->getStateFromMemento(careTaker->get(0));
	cout << "First saved State: " << originator->getState()<<endl;
	originator->getStateFromMemento ( careTaker->get(1));
	cout << "Second saved State: " << (originator->getState());


}