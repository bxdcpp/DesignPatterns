/**************************************************************************
* * ���ģʽ
����
��ͼ��Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һ�µĽ��棬���ģʽ������һ���߲�ӿڣ�����ӿ�ʹ����һ��ϵͳ��������ʹ�á�

��Ҫ��������ͷ��ʸ���ϵͳ���ڲ���ϵͳʱ�ĸ��Ӷȣ��򻯿ͻ�����֮�Ľӿڡ�

��ʱʹ�ã� 1���ͻ��˲���Ҫ֪��ϵͳ�ڲ��ĸ�����ϵ������ϵͳֻ���ṩһ��"�Ӵ�Ա"���ɡ� 2������ϵͳ����ڡ�

��ν�����ͻ��˲���ϵͳ��ϣ��������ϵͳ��ϡ�

�ؼ����룺�ڿͻ��˺͸���ϵͳ֮���ټ�һ�㣬��һ�㽫����˳��������ϵ�ȴ���á�

Ӧ��ʵ���� 1��ȥҽԺ����������Ҫȥ�Һš�������ۡ�ȡҩ���û��߻��߼������úܸ��ӣ�������ṩ�Ӵ���Ա��ֻ�ýӴ���Ա�������ͺܷ��㡣 2��JAVA �����㿪��ģʽ��

�ŵ㣺 1������ϵͳ�໥������ 2���������ԡ� 3������˰�ȫ�ԡ�

ȱ�㣺�����Ͽ���ԭ�����Ҫ�Ķ������鷳���̳���д�������ʡ�

ʹ�ó����� 1��Ϊ���ӵ�ģ�����ϵͳ�ṩ�����ʵ�ģ�顣 2����ϵͳ��Զ����� 3��Ԥ����ˮƽ��Ա�����ķ��ա�

ע������ڲ�λ��ṹ�У�����ʹ�����ģʽ����ϵͳ��ÿһ�����ڡ�
**************************************************************************/


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
};


class Rectangle : public Shape
{
public:
	void draw() override
	{
		cout << "Rectangle::draw()" << endl;
	}
};

class Square: public Shape
{
public:
	void draw() override
	{
		cout << "Square::draw()" << endl;
	}
};

class Circle : public Shape
{
public:
	void draw() override
	{
		cout << "Circle::draw()" << endl;
	}
};

class ShapeMaker
{
public:
	ShapeMaker() {
		circle = new Circle();
		rectangle = new Rectangle();
		square = new Square();
	}

	void drawCircle() {
		circle->draw();
	}
	void drawRectangle() {
		rectangle->draw();
	}
	void drawSquare() {
		square->draw();
	}

private:
	Shape* circle;
	Shape* rectangle;
	Shape* square;
};

void FacadePatternDemo()
{
	ShapeMaker* shapeMaker = new ShapeMaker();

	shapeMaker->drawCircle();
	shapeMaker->drawRectangle();
	shapeMaker->drawSquare();
}

int main()
{

	FacadePatternDemo();
	return 0;
}