/**************************************************************************
��ͼ�������󲿷���ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ı仯��

��Ҫ��������ж��ֿ��ܻ�仯������£��ü̳л�����౬ը���⣬��չ��������

��ʱʹ�ã�ʵ��ϵͳ�����ж���Ƕȷ��࣬ÿһ�ֽǶȶ����ܱ仯��

��ν���������ֶ�Ƕȷ����������������Ƕ����仯����������֮����ϡ�

�ؼ����룺����������ʵ���ࡣ

Ӧ��ʵ���� 1����˽������Ԫ˧ת��Ͷ̥����ת��Ͷ̥�Ļ��ƽ���������Ϊ�����ȼ��������������壬ǰ���൱�ڳ��󻯣������൱��ʵ�ֻ�������ͨ�����ܵ�ί�ɣ������������Ĺ��ܣ�ʹ��������Զ�̬��ѡ�� 2��ǽ�ϵĿ��أ����Կ����Ŀ����ǳ���ģ����ù����������ôʵ�ֵġ�

�ŵ㣺 1�������ʵ�ֵķ��롣 2���������չ������ 3��ʵ��ϸ�ڶԿͻ�͸����

ȱ�㣺�Ž�ģʽ�����������ϵͳ�����������Ѷȣ����ھۺϹ�����ϵ�����ڳ���㣬Ҫ�󿪷�����Գ������������̡�

ʹ�ó����� 1�����һ��ϵͳ��Ҫ�ڹ����ĳ��󻯽�ɫ�;��廯��ɫ֮�����Ӹ��������ԣ��������������֮�佨����̬�ļ̳���ϵ��ͨ���Ž�ģʽ����ʹ�����ڳ���㽨��һ��������ϵ�� 2��������Щ��ϣ��ʹ�ü̳л���Ϊ���μ̳е���ϵͳ��ĸ����������ӵ�ϵͳ���Ž�ģʽ��Ϊ���á� 3��һ����������������仯��ά�ȣ���������ά�ȶ���Ҫ������չ��

ע������������������仯��ά�ȣ�ʹ���Ž�ģʽ���ʺϲ����ˡ�
**************************************************************************/

#include <iostream>

class DrawAPI
{
public:
	virtual void drawCircle(int radius, int x, int y) {};
private:

};

class RedCircle : public DrawAPI
{
public:
	void drawCircle(int radius, int x, int y)
	{
		std::cout << "Drawing Circle[ color: red, radius: "
			<< radius << ", x: " << x << ", " << y << "]"<<std::endl;
	}
};

class GreenCircle : public DrawAPI
{
public:
	void drawCircle(int radius, int x, int y)
	{
		std::cout << "Drawing Circle[ color: green, radius: "
			<< radius << ", x: " << x << ", " << y <<"]"<<std::endl;
	}
};

class Shape
{
public:
	virtual void draw() = 0;

protected:
	DrawAPI* drawAPI;
	Shape(DrawAPI* drawAPI) {
		this->drawAPI = drawAPI;
	}

private:

};

class Circle : public Shape {
private:
	int x, y, radius;

public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) :
		x(x), y(y), radius(radius), Shape(drawAPI)
	{

	}

	void draw() {
		drawAPI->drawCircle(radius, x, y);
	}
};




void main()
{
	//�����ʵ�ַ���
	//shape ��֪��DrawAPI��ʵ�ֺͱ仯��ͨ�����������Ӿ����ʵ�֣���̬��
	DrawAPI* a = new RedCircle();
	DrawAPI* b = new GreenCircle();
	Shape* redCircle = new Circle(100, 100, 10, a);
	Shape* greenCircle = new Circle(100, 100, 10,b);

	redCircle->draw();
	greenCircle->draw();
}