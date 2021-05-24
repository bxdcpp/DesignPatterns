/**************************************************************************
* 观察者模式
* 
意图：定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。

主要解决：一个对象状态改变给其他对象通知的问题，而且要考虑到易用和低耦合，保证高度的协作。

何时使用：一个对象（目标对象）的状态发生改变，所有的依赖对象（观察者对象）都将得到通知，进行广播通知。

如何解决：使用面向对象技术，可以将这种依赖关系弱化。

关键代码：在抽象类里有一个 ArrayList 存放观察者们。

应用实例： 1、拍卖的时候，拍卖师观察最高标价，然后通知给其他竞价者竞价。 2、西游记里面悟空请求菩萨降服红孩儿，菩萨洒了一地水招来一个老乌龟，这个乌龟就是观察者，他观察菩萨洒水这个动作。

优点： 1、观察者和被观察者是抽象耦合的。 2、建立一套触发机制。

缺点： 1、如果一个被观察者对象有很多的直接和间接的观察者的话，将所有的观察者都通知到会花费很多时间。 2、如果在观察者和观察目标之间有循环依赖的话，观察目标会触发它们之间进行循环调用，可能导致系统崩溃。 3、观察者模式没有相应的机制让观察者知道所观察的目标对象是怎么发生变化的，而仅仅只是知道观察目标发生了变化。

使用场景：

一个抽象模型有两个方面，其中一个方面依赖于另一个方面。将这些方面封装在独立的对象中使它们可以各自独立地改变和复用。
一个对象的改变将导致其他一个或多个对象也发生改变，而不知道具体有多少对象将发生改变，可以降低对象之间的耦合度。
一个对象必须通知其他对象，而并不知道这些对象是谁。
需要在系统中创建一个触发链，A对象的行为将影响B对象，B对象的行为将影响C对象……，可以使用观察者模式创建一种链式触发机制。
注意事项： 1、JAVA 中已经有了对观察者模式的支持类。 2、避免循环引用。 3、如果顺序执行，某一观察者错误会导致系统卡壳，一般采用异步方式。
**************************************************************************/

#include <iostream>

/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the mySubject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

#include <iostream>
#include <list>
#include <string>


























int static_number_ = 0;

class myIObserver {
public:
    virtual ~myIObserver() {};
    virtual void Update(const std::string& message_from_subject) = 0;
    virtual void SetID(int id) {};
    virtual int GetID() { return 0; };

};

class myISubject {
public:
    virtual ~myISubject() {};
    virtual void AddObserver(myIObserver* observer) = 0;
    virtual void RemoveObserver(myIObserver* observer) = 0;
    virtual void Notify() = 0;
};

class mySubject : public myISubject {
public:
    virtual ~mySubject() {
        std::cout << "Goodbye, I was the mySubject.\n";
    }

    /**
     * The subscription management methods.
     */
    void AddObserver(myIObserver* observer) override {
        list_observer_.push_back(observer);
        observer->SetID(static_number_++);
        std::cout << "Hi, I'm the Observer \"" << static_number_ << "\".\n";
    }
    void RemoveObserver(myIObserver* observer) override {
        std::cout << "Observer \"" << observer->GetID() << "\" removed from the list.\n";
        list_observer_.remove(observer);

    }
    void Notify() override {
        std::list<myIObserver*>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void CreateMessage(std::string message = "Empty") {
        this->message_ = message;
        Notify();
    }
    void HowManyObserver() {
        std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
    }

    /**
     * Usually, the subscription logic is only a fraction of what a mySubject can
     * really do. Subjects commonly hold some important business logic, that
     * triggers a notification method whenever something important is about to
     * happen (or after it).
     */
    void SomeBusinessLogic() {
        this->message_ = "change message message";
        Notify();
        std::cout << "I'm about to do some thing important\n";
    }

private:
    std::list<myIObserver*> list_observer_;
    std::string message_;
};


class myObserver : public myIObserver {
public:

    myObserver() {
    }
    virtual ~myObserver() {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Update(const std::string& message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void PrintInfo() {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    }
    void SetID(int id) override{
        std::cout << "Hi, I'm the Observer \"" << id<< "\".\n";
        this->number_ = id;
    }
    int GetID() override
    {
        return this->number_;
    }

private:
    std::string message_from_subject_;
    int number_;
};


void ClientCode() {
#if 0
    mySubject* subject = new mySubject;
    Observer* observer1 = new Observer(*subject);
    Observer* observer2 = new Observer(*subject);
    Observer* observer3 = new Observer(*subject);
    Observer* observer4;
    Observer* observer5;

    subject->CreateMessage("Hello World! :D");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new Observer(*subject);

    observer2->RemoveMeFromTheList();
    observer5 = new Observer(*subject);

    subject->CreateMessage("My new car is great! ;)");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;
#endif


    mySubject* subject = new mySubject;
    myObserver* observer1 = new myObserver();
    subject->AddObserver(observer1);

    myObserver* observer2 = new myObserver();
    subject->AddObserver(observer2);
    myObserver* observer3 = new myObserver();
    subject->AddObserver(observer3);
    myObserver* observer4;
    myObserver* observer5;

    subject->CreateMessage("Hello World! :D");
    subject->RemoveObserver(observer3);

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new myObserver();
    subject->AddObserver(observer4);

    subject->RemoveObserver(observer2);
    observer5 = new myObserver();
    subject->AddObserver(observer5);

    subject->CreateMessage("My new car is great! ;)");
    subject->RemoveObserver(observer5);

    subject->RemoveObserver(observer4);
    subject->RemoveObserver(observer1);


    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

}

int main() {
    ClientCode();
    return 0;
}