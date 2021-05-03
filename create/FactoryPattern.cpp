/*
* ����ģʽ
��ͼ������һ����������Ľӿڣ����������Լ�����ʵ������һ�������࣬����ģʽʹ�䴴�������ӳٵ�������С�

��Ҫ�������Ҫ����ӿ�ѡ�������,����

��ʱʹ�ã�������ȷ�ؼƻ���ͬ�����´�����ͬʵ��ʱ��

��ν������������ʵ�ֹ����ӿڣ����ص�Ҳ��һ������Ĳ�Ʒ��

�ؼ����룺����������������ִ�С�
�ŵ㣺 1��һ���������봴��һ������ֻҪ֪�������ƾͿ����ˡ� 
	2����չ�Ըߣ����������һ����Ʒ��ֻҪ��չһ��������Ϳ��ԡ� 
	3�����β�Ʒ�ľ���ʵ�֣�������ֻ���Ĳ�Ʒ�Ľӿڡ�

ȱ�㣺ÿ������һ����Ʒʱ������Ҫ����һ��������Ͷ���ʵ�ֹ�����ʹ��ϵͳ����ĸ����ɱ����ӣ�
	��һ���̶���������ϵͳ�ĸ��Ӷȣ�ͬʱҲ������ϵͳ��������������Ⲣ����ʲô���¡�
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
	//ʹ�� GetShape ������ȡ��״���͵Ķ���
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

	//��ȡ Circle �Ķ��󣬲��������� draw ����
	Shape* shape1 = shapeFactory->GetShape("CIRCLE");

	//���� Circle �� draw ����
	shape1->draw();

	//��ȡ Rectangle �Ķ��󣬲��������� draw ����
	Shape* shape2 = shapeFactory->GetShape("RECTANGLE");

	//���� Rectangle �� draw ����
	shape2->draw();

	//��ȡ Square �Ķ��󣬲��������� draw ����
	Shape* shape3 = shapeFactory->GetShape("SQUARE");

	//���� Square �� draw ����
	shape3->draw();
	return 0;
}