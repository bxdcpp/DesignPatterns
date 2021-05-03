/*
* 工厂模式
意图：定义一个创建对象的接口，让其子类自己决定实例化哪一个工厂类，工厂模式使其创建过程延迟到子类进行。

主要解决：主要解决接口选择的问题,解耦

何时使用：我们明确地计划不同条件下创建不同实例时。

如何解决：让其子类实现工厂接口，返回的也是一个抽象的产品。

关键代码：创建过程在其子类执行。
优点： 1、一个调用者想创建一个对象，只要知道其名称就可以了。 
	2、扩展性高，如果想增加一个产品，只要扩展一个工厂类就可以。 
	3、屏蔽产品的具体实现，调用者只关心产品的接口。

缺点：每次增加一个产品时，都需要增加一个具体类和对象实现工厂，使得系统中类的个数成倍增加，
	在一定程度上增加了系统的复杂度，同时也增加了系统具体类的依赖。这并不是什么好事。
*/




#include <iostream>
#include <algorithm>

using namespace std;

void log(string str)
{
	cout << str << endl;
}

class Shape
{
public:
	virtual void draw() {};
};

class  Rectangle : public Shape
{
public:
	Rectangle() = default;
	~Rectangle() = default;
	void draw() override
	{
		log("Inside Square::draw() method.");
	}

private:

};

class Square : public Shape
{
public:
	void draw() override
	{
		log("Inside Square::draw() method.");
	}
};

class Circle : public Shape
{
public:
	void draw() override
	{
		log("Inside Circle::draw() method.");
	}
};

class ShapeFactory
{
public:
	//使用 GetShape 方法获取形状类型的对象
	Shape* GetShape(string shapeType)
	{
		if (shapeType.empty())
		{
			return nullptr;
		}
		if (shapeType._Equal("CIRCLE")) 
		{
			return new Circle();
		}
		else if (shapeType._Equal("RECTANGLE"))
		{
			return new Rectangle();
		}
		else if (shapeType._Equal("SQUARE"))
		{
			return new Square();
		}
		return nullptr;
	}
};


int main()
{

	ShapeFactory* shapeFactory = new ShapeFactory();

	//获取 Circle 的对象，并调用它的 draw 方法
	Shape* shape1 = shapeFactory->GetShape("CIRCLE");

	//调用 Circle 的 draw 方法
	shape1->draw();

	//获取 Rectangle 的对象，并调用它的 draw 方法
	Shape* shape2 = shapeFactory->GetShape("RECTANGLE");

	//调用 Rectangle 的 draw 方法
	shape2->draw();

	//获取 Square 的对象，并调用它的 draw 方法
	Shape* shape3 = shapeFactory->GetShape("SQUARE");

	//调用 Square 的 draw 方法
	shape3->draw();
	return 0;
}