/**************************************************************************
在代理模式（Proxy Pattern）
一个类代表另一个类的功能。这种类型的设计模式属于结构型模式。
在代理模式中，我们创建具有现有对象的对象，以便向外界提供功能接口

意图：为其他对象提供一种代理以控制对这个对象的访问。

主要解决：在直接访问对象时带来的问题，比如说：要访问的对象在远程的机器上。
		在面向对象系统中，有些对象由于某些原因（比如对象创建开销很大，或者某些操作需要安全控制，或者需要进程外的访问），
		直接访问会给使用者或者系统结构带来很多麻烦，我们可以在访问此对象时加上一个对此对象的访问层。

何时使用：想在访问一个类时做一些控制。

如何解决：增加中间层。

关键代码：实现与被代理类组合

优点： 1、职责清晰。 2、高扩展性。 3、智能化。

缺点： 1、由于在客户端和真实主题之间增加了代理对象，因此有些类型的代理模式可能会造成请求的处理速度变慢。
		2、实现代理模式需要额外的工作，有些代理模式的实现非常复杂。

**************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Image {
public:
	virtual void display() = 0;
};

class RealImage : public Image {

public:
	RealImage(string fileName) {
		this->fileName = fileName;
		loadFromDisk(fileName);
	}

		void display() override {
		std::cout<<("Displaying " + fileName)<<endl;
	}
private:
	void loadFromDisk(string fileName) {
		std::cout << ("Loading " + fileName)<<endl;
	}
	string fileName;
};
class ProxyImage : public Image {


public:

 ProxyImage(string fileName) {
		this->fileName = fileName;
	}

	void display() override {
		if (realImage == nullptr) {
			realImage = new RealImage(fileName);
		}
		realImage->display();
	}
private:
	RealImage* realImage = nullptr;
	string fileName;
};


int main()
{
	Image* image = new ProxyImage("test_10mb.jpg");

	// 第一次图像将从磁盘加载
	image->display();
	cout <<("");
	// 图像不需要从磁盘加载
	image->display();
	return 0;
}