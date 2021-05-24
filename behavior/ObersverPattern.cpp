/**************************************************************************
* �۲���ģʽ
* 
��ͼ�����������һ��һ�Զ��������ϵ����һ�������״̬�����ı�ʱ���������������Ķ��󶼵õ�֪ͨ�����Զ����¡�

��Ҫ�����һ������״̬�ı����������֪ͨ�����⣬����Ҫ���ǵ����ú͵���ϣ���֤�߶ȵ�Э����

��ʱʹ�ã�һ������Ŀ����󣩵�״̬�����ı䣬���е��������󣨹۲��߶��󣩶����õ�֪ͨ�����й㲥֪ͨ��

��ν����ʹ����������������Խ�����������ϵ������

�ؼ����룺�ڳ���������һ�� ArrayList ��Ź۲����ǡ�

Ӧ��ʵ���� 1��������ʱ������ʦ�۲���߱�ۣ�Ȼ��֪ͨ�����������߾��ۡ� 2�����μ���������������������캢������������һ��ˮ����һ�����ڹ꣬����ڹ���ǹ۲��ߣ����۲�������ˮ���������

�ŵ㣺 1���۲��ߺͱ��۲����ǳ�����ϵġ� 2������һ�״������ơ�

ȱ�㣺 1�����һ�����۲��߶����кܶ��ֱ�Ӻͼ�ӵĹ۲��ߵĻ��������еĹ۲��߶�֪ͨ���Ứ�Ѻܶ�ʱ�䡣 2������ڹ۲��ߺ͹۲�Ŀ��֮����ѭ�������Ļ����۲�Ŀ��ᴥ������֮�����ѭ�����ã����ܵ���ϵͳ������ 3���۲���ģʽû����Ӧ�Ļ����ù۲���֪�����۲��Ŀ���������ô�����仯�ģ�������ֻ��֪���۲�Ŀ�귢���˱仯��

ʹ�ó�����

һ������ģ�����������棬����һ��������������һ�����档����Щ�����װ�ڶ����Ķ�����ʹ���ǿ��Ը��Զ����ظı�͸��á�
һ������ĸı佫��������һ����������Ҳ�����ı䣬����֪�������ж��ٶ��󽫷����ı䣬���Խ��Ͷ���֮�����϶ȡ�
һ���������֪ͨ�������󣬶�����֪����Щ������˭��
��Ҫ��ϵͳ�д���һ����������A�������Ϊ��Ӱ��B����B�������Ϊ��Ӱ��C���󡭡�������ʹ�ù۲���ģʽ����һ����ʽ�������ơ�
ע����� 1��JAVA ���Ѿ����˶Թ۲���ģʽ��֧���ࡣ 2������ѭ�����á� 3�����˳��ִ�У�ĳһ�۲��ߴ���ᵼ��ϵͳ���ǣ�һ������첽��ʽ��
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