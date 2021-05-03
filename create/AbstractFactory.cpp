/*
抽象工厂模式（Abstract Factory Pattern）是围绕一个超级工厂创建其他工厂。
该超级工厂又称为其他工厂的工厂。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。
在抽象工厂模式中，接口是负责创建一个相关对象的工厂，不需要显式指定它们的类。
每个生成的工厂都能按照工厂模式提供对象。

意图：提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。

主要解决：主要解决接口选择的问题。

何时使用：系统的产品有多于一个的产品族，而系统只消费其中某一族的产品。

如何解决：在一个产品族里面，定义多个产品。

关键代码：在一个工厂里聚合多个同类产品。

优点：当一个产品族中的多个对象被设计成一起工作时，它能保证客户端始终只使用同一个产品族中的对象。

缺点：产品族扩展非常困难，要增加一个系列的某一产品，既要在抽象的 Creator 里加代码，又要在具体的里面加代码。

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
	virtual void draw() =0;
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


class Color
{
public:
	virtual void fill() = 0;
};


class Red : public  Color {
public:

	void fill()override
	{
		log("Inside Red::fill() method.");
	}
};



class Green : public Color
{
public:
	void fill()override
	{
		log("Inside Green::fill() method.");
	}
};

class Blue : public Color {

public:
	void fill() override
	{
		log("Inside Blue::fill() method.");
	}
};


class AbstractFactory
{
public:
	virtual Color* GetColor(string color) = 0;
	virtual Shape* GetShape(string shape) = 0;
};

 class ShapeFactory : public AbstractFactory
 {
 public:
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

	 Color* GetColor(string color) override {
		 return nullptr;
	 }
 };


 class ColorFactory : public AbstractFactory {

 public:
	 Shape* GetShape(string shapeType) override
	 {
		 return nullptr;
	 }

	 Color* GetColor(string color) override
	 {
		 if (color.empty())
		 {
			 return nullptr;
		 }
		 if (color._Equal("RED")) {
			 return new Red();
		 }
		 else if (color._Equal("GREEN")) {
			 return new Green();
		 }
		 else if (color._Equal("BLUE")) {
			 return new Blue();
		 }
		 return nullptr;
	 }
 };


 class FactoryProducer 
 {
 public:
	 static AbstractFactory* GetFactory(string choice) 
	 {
		 if (choice._Equal("SHAPE")) 
		 {
			 return new ShapeFactory();
		 }
		 else if (choice._Equal("COLOR"))
		 {
			 return new ColorFactory();
		 }
		 return nullptr;
	 }
 };


int main()
{
	//获取形状工厂
	AbstractFactory* shapeFactory = FactoryProducer::GetFactory("SHAPE");

	//获取形状为 Circle 的对象
	Shape* shape1 = shapeFactory->GetShape("CIRCLE");

	//调用 Circle 的 draw 方法
	shape1->draw();

	//获取形状为 Rectangle 的对象
	Shape* shape2 = shapeFactory->GetShape("RECTANGLE");

	//调用 Rectangle 的 draw 方法
	shape2->draw();

	//获取形状为 Square 的对象
	Shape* shape3 = shapeFactory->GetShape("SQUARE");

	//调用 Square 的 draw 方法
	shape3->draw();

	//获取颜色工厂
	AbstractFactory* colorFactory = FactoryProducer::GetFactory("COLOR");

	//获取颜色为 Red 的对象
	Color* color1 = colorFactory->GetColor("RED");

	//调用 Red 的 fill 方法
	color1->fill();

	//获取颜色为 Green 的对象
	Color* color2 = colorFactory->GetColor("GREEN");

	//调用 Green 的 fill 方法
	color2->fill();

	//获取颜色为 Blue 的对象
	Color* color3 = colorFactory->GetColor("BLUE");

	//调用 Blue 的 fill 方法
	color3->fill();
	return 0;
}