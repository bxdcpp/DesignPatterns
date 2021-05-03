/*
���󹤳�ģʽ��Abstract Factory Pattern����Χ��һ������������������������
�ó��������ֳ�Ϊ���������Ĺ������������͵����ģʽ���ڴ�����ģʽ�����ṩ��һ�ִ����������ѷ�ʽ��
�ڳ��󹤳�ģʽ�У��ӿ��Ǹ��𴴽�һ����ض���Ĺ���������Ҫ��ʽָ�����ǵ��ࡣ
ÿ�����ɵĹ������ܰ��չ���ģʽ�ṩ����

��ͼ���ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ�����ࡣ

��Ҫ�������Ҫ����ӿ�ѡ������⡣

��ʱʹ�ã�ϵͳ�Ĳ�Ʒ�ж���һ���Ĳ�Ʒ�壬��ϵͳֻ��������ĳһ��Ĳ�Ʒ��

��ν������һ����Ʒ�����棬��������Ʒ��

�ؼ����룺��һ��������ۺ϶��ͬ���Ʒ��

�ŵ㣺��һ����Ʒ���еĶ��������Ƴ�һ����ʱ�����ܱ�֤�ͻ���ʼ��ֻʹ��ͬһ����Ʒ���еĶ���

ȱ�㣺��Ʒ����չ�ǳ����ѣ�Ҫ����һ��ϵ�е�ĳһ��Ʒ����Ҫ�ڳ���� Creator ��Ӵ��룬��Ҫ�ھ��������Ӵ��롣

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
	//��ȡ��״����
	AbstractFactory* shapeFactory = FactoryProducer::GetFactory("SHAPE");

	//��ȡ��״Ϊ Circle �Ķ���
	Shape* shape1 = shapeFactory->GetShape("CIRCLE");

	//���� Circle �� draw ����
	shape1->draw();

	//��ȡ��״Ϊ Rectangle �Ķ���
	Shape* shape2 = shapeFactory->GetShape("RECTANGLE");

	//���� Rectangle �� draw ����
	shape2->draw();

	//��ȡ��״Ϊ Square �Ķ���
	Shape* shape3 = shapeFactory->GetShape("SQUARE");

	//���� Square �� draw ����
	shape3->draw();

	//��ȡ��ɫ����
	AbstractFactory* colorFactory = FactoryProducer::GetFactory("COLOR");

	//��ȡ��ɫΪ Red �Ķ���
	Color* color1 = colorFactory->GetColor("RED");

	//���� Red �� fill ����
	color1->fill();

	//��ȡ��ɫΪ Green �Ķ���
	Color* color2 = colorFactory->GetColor("GREEN");

	//���� Green �� fill ����
	color2->fill();

	//��ȡ��ɫΪ Blue �Ķ���
	Color* color3 = colorFactory->GetColor("BLUE");

	//���� Blue �� fill ����
	color3->fill();
	return 0;
}