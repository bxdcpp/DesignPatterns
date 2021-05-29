/**************************************************************************
* �н���ģʽ
* 
��ͼ����һ���н��������װһϵ�еĶ��󽻻����н���ʹ��������Ҫ��ʽ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ظı�����֮��Ľ�����

��Ҫ��������������֮����ڴ����Ĺ�����ϵ�������Ʊػᵼ��ϵͳ�Ľṹ��úܸ��ӣ�ͬʱ��һ���������ı䣬����Ҳ��Ҫ������֮������Ķ���ͬʱ������Ӧ�Ĵ���

��ʱʹ�ã�������໥��ϣ��γ�����״�ṹ��

��ν������������״�ṹ����Ϊ���ͽṹ��

�ؼ����룺���� Colleague ֮���ͨ�ŷ�װ��һ�����е�������

Ӧ��ʵ���� 1���й����� WTO ֮ǰ�Ǹ��������໥ó�ף��ṹ���ӣ������Ǹ�������ͨ�� WTO ������ó�ס� 2����������ϵͳ�� 3��MVC ��ܣ�����C�������������� M��ģ�ͣ��� V����ͼ�����н��ߡ�

�ŵ㣺 1����������ĸ��Ӷȣ���һ�Զ�ת������һ��һ�� 2��������֮��Ľ�� 3�����ϵ�����ԭ��

ȱ�㣺�н��߻��Ӵ󣬱�ø�������ά����

ʹ�ó����� 1��ϵͳ�ж���֮����ڱȽϸ��ӵ����ù�ϵ����������֮���������ϵ�ṹ���Ҷ������Ը��øö��� 2����ͨ��һ���м�������װ������е���Ϊ�����ֲ�������̫������ࡣ

ע�������Ӧ����ְ����ҵ�ʱ��ʹ�á�
**************************************************************************/

#include <iostream>
#include <vector>

using namespace std;



class Colleague;
//�����н���
class Mediator 
{
public:
    virtual void Register(Colleague* colleague) = 0;
    virtual void Relay(Colleague* cl) = 0;
};

class Colleague {
public:
	void setMedium(Mediator* mediator)
	{
		this->mediator = mediator;
	}
	virtual void Receive() = 0;
	virtual void Send() = 0;
protected:
	Mediator* mediator = nullptr;
};

//�����н���
class ConcreteMediator :public  Mediator {
public:

	void Register(Colleague* colleague) override {
		auto res = std::find(colleagues.begin(), colleagues.end(), colleague);

		if (res == colleagues.end())
		{
			colleagues.push_back(colleague);
			colleague->setMedium(this);
		}
	}
	void Relay(Colleague* cl) override {
		for (auto ob : colleagues) {
			if (ob == cl) {
				ob->Receive();
			}
		}
	}
private:
	vector<Colleague*> colleagues;
};




//����ͬ����
class ConcreteColleague1 :public Colleague {
public:
	 void Receive() {
		cout << ("����ͬ����1�յ�����\n");
	}
	 void Send() {
		cout << ("����ͬ����1��������\n");
		mediator->Relay(this); //���н���ת��
	}
};
//����ͬ����
class ConcreteColleague2 : public Colleague {
public:
	 void Receive() {
		cout << ("����ͬ����2�յ�����\n");
	}
      void Send() {
		cout << ("����ͬ����2��������\n");
		mediator->Relay(this); //���н���ת��
	}
};



int main() {
	Mediator* md = new ConcreteMediator();
	Colleague* c1, *c2;
	c1 = new ConcreteColleague1();
	c2 = new ConcreteColleague2();
	md->Register(c1);
	md->Register(c2);
	c1->Send();
	cout<<("-------------\n");
	c2->Send();
    return 0;
}