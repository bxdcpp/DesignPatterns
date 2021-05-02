/**************************************************************************
* װ����ģʽ
װ����ģʽ��Decorator Pattern��������һ�����еĶ�������µĹ��ܣ�ͬʱ�ֲ��ı���ṹ���������͵����ģʽ���ڽṹ��ģʽ��������Ϊ���е����һ����װ��

����ģʽ������һ��װ���࣬������װԭ�е��࣬���ڱ����෽��ǩ�������Ե�ǰ���£��ṩ�˶���Ĺ��ܡ�

����ͨ�������ʵ������ʾװ����ģʽ���÷������У����ǽ���һ����״װ���ϲ�ͬ����ɫ��ͬʱ�ֲ��ı���״�ࡣ
* 
��ͼ����̬�ظ�һ���������һЩ�����ְ�𡣾����ӹ�����˵��װ����ģʽ������������Ϊ��

��Ҫ�����һ��ģ�����Ϊ����չһ���ྭ��ʹ�ü̳з�ʽʵ�֣����ڼ̳�Ϊ�����뾲̬����������������չ���ܵ����࣬���������͡�

��ʱʹ�ã��ڲ������Ӻܶ�������������չ�ࡣ

��ν���������幦��ְ�𻮷֣�ͬʱ�̳�װ����ģʽ��

�ؼ����룺 1��Component ��䵱�����ɫ����Ӧ�þ���ʵ�֡� 2�����������úͼ̳� Component �࣬������չ����д���෽����

Ӧ��ʵ���� 1��������� 72 �䣬�������"����"�����ĸ�������һֻ���ӣ�����������������Ĺ��ܡ� 2������һ������û�л��򶼿��Թ���ǽ�ϣ�����ͨ�������л���ģ�����ʵ�����ǻ��򱻹���ǽ�ϡ��ڹ���ǽ��֮ǰ�������Ա����ϲ�����װ���������ʱ���������ͻ����γ���һ�����塣

�ŵ㣺װ����ͱ�װ������Զ�����չ�������໥��ϣ�װ��ģʽ�Ǽ̳е�һ�����ģʽ��װ��ģʽ���Զ�̬��չһ��ʵ����Ĺ��ܡ�

ȱ�㣺���װ�αȽϸ��ӡ�

ʹ�ó����� 1����չһ����Ĺ��ܡ� 2����̬���ӹ��ܣ���̬������

ע������ɴ���̳С�
**************************************************************************/

#include <iostream>

class Shape
{
public:
	Shape() = default;
	~Shape() = default;

	virtual void draw() {};
private:

};

class Rectangle : public Shape
{
public:
	void draw() override
	{
		std::cout << ("Shape: Rectangle")<<std::endl;
	}
};

class Circle : public Shape
{
public:

	void draw() override
	{
		std::cout << ("Shape: Rectangle") << std::endl;
	}
};

class ShapeDecorator : public Shape
{

public:
	ShapeDecorator(Shape* decoratedShape)
		:decoratedShape(decoratedShape)
	{
	}

	void draw()
	{
		decoratedShape->draw();
	}
protected:
	Shape* decoratedShape = nullptr;
};

class RedShapeDecorator : public ShapeDecorator
{
public:
	RedShapeDecorator(Shape* decoratedShape)
		:ShapeDecorator(decoratedShape)
	{
	}
	void draw() override
	{
		decoratedShape->draw();
		setRedBorder(decoratedShape);
	}

private:
	void setRedBorder(Shape* decoratedShape)
	{
		std::cout << ("Border Color: Red") << std::endl;
	}
};




void main()
{
	Shape* circle = new Circle();
	ShapeDecorator* redCircle = new RedShapeDecorator(new Circle());
	ShapeDecorator* redRectangle = new RedShapeDecorator(new Rectangle());
	//Shape redCircle = new RedShapeDecorator(new Circle());
	//Shape redRectangle = new RedShapeDecorator(new Rectangle());
	std::cout <<("Circle with normal border\n");
	circle->draw();

	std::cout <<("\nCircle of red border");
	redCircle->draw();

	std::cout <<("\nRectangle of red border");
	redRectangle->draw();
}