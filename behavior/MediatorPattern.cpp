/**************************************************************************
* 中介者模式
* 
意图：用一个中介对象来封装一系列的对象交互，中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。

主要解决：对象与对象之间存在大量的关联关系，这样势必会导致系统的结构变得很复杂，同时若一个对象发生改变，我们也需要跟踪与之相关联的对象，同时做出相应的处理。

何时使用：多个类相互耦合，形成了网状结构。

如何解决：将上述网状结构分离为星型结构。

关键代码：对象 Colleague 之间的通信封装到一个类中单独处理。

应用实例： 1、中国加入 WTO 之前是各个国家相互贸易，结构复杂，现在是各个国家通过 WTO 来互相贸易。 2、机场调度系统。 3、MVC 框架，其中C（控制器）就是 M（模型）和 V（视图）的中介者。

优点： 1、降低了类的复杂度，将一对多转化成了一对一。 2、各个类之间的解耦。 3、符合迪米特原则。

缺点：中介者会庞大，变得复杂难以维护。

使用场景： 1、系统中对象之间存在比较复杂的引用关系，导致它们之间的依赖关系结构混乱而且难以复用该对象。 2、想通过一个中间类来封装多个类中的行为，而又不想生成太多的子类。

注意事项：不应当在职责混乱的时候使用。
**************************************************************************/

#include <iostream>
#include <vector>

using namespace std;



class Colleague;
//抽象中介者
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

//具体中介者
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




//具体同事类
class ConcreteColleague1 :public Colleague {
public:
	 void Receive() {
		cout << ("具体同事类1收到请求。\n");
	}
	 void Send() {
		cout << ("具体同事类1发出请求。\n");
		mediator->Relay(this); //请中介者转发
	}
};
//具体同事类
class ConcreteColleague2 : public Colleague {
public:
	 void Receive() {
		cout << ("具体同事类2收到请求。\n");
	}
      void Send() {
		cout << ("具体同事类2发出请求。\n");
		mediator->Relay(this); //请中介者转发
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