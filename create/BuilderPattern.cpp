/*
������ģʽ��Builder Pattern��ʹ�ö���򵥵Ķ���һ��һ��������һ�����ӵĶ����������͵����ģʽ���ڴ�����ģʽ�����ṩ��һ�ִ����������ѷ�ʽ��
һ�� Builder ���һ��һ���������յĶ��󡣸� Builder ���Ƕ�������������ġ�
��ͼ:��һ�����ӵĹ��������ʾ����룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��

��Ҫ���:��Ҫ��������ϵͳ�У���ʱ��������"һ�����Ӷ���"�Ĵ�����������ͨ���ɸ������ֵ��Ӷ�����һ�����㷨���ɣ���������ı仯��������Ӷ���ĸ������־��������ž��ҵı仯�����ǽ����������һ����㷨ȴ����ȶ���

��ʱʹ��:һЩ������������䣬������Ͼ����仯��ʱ��

��ν��:�����벻����뿪��

�ؼ�����:������:�������ṩʵ��������:�����������ʵ����������ϵ��
�ŵ�: 1�������߶���������չ�� 2�����ڿ���ϸ�ڷ��ա�

ȱ��: 1����Ʒ�����й�ͬ�㣬��Χ�����ơ� 2�����ڲ��仯���ӣ����кܶ�Ľ����ࡣ

ʹ�ó���: 1����Ҫ���ɵĶ�����и��ӵ��ڲ��ṹ�� 2����Ҫ���ɵĶ����ڲ����Ա����໥������

ע������:�빤��ģʽ��������:������ģʽ���ӹ�ע�����װ���˳��
*/




#include <iostream>
#include <mutex>
#include <list>

using namespace std;

void log(string str)
{
	cout << str << endl;
}
//���
class  Packing 
{
public:
	virtual string pack() = 0;
};


//ʳ����Ŀ
class Item 
{
public:
	virtual string name() = 0;
	virtual Packing* packing() = 0;
	virtual float price() = 0;
};


//��װֽ 
class Wrapper : public Packing
{

public:
	string pack()
	{
		return "Wrapper";
	}
};

//ƿ��
class Bottle : public Packing {

public:
	string pack()
	{
		return "Bottle";
	}
};

//����
 class Burger : public Item {

 public:
	 Packing* packing() override
	 {
		 return new Wrapper();
	 }

	 float price() override = 0;
};

//���� 
 class ColdDrink : public Item
 {

 public:
	  Packing* packing() override
	 {
		 return new Bottle();
	 }

	 float price() override = 0;
 };

//��ʳ����
 class VegBurger : public Burger {

 public:
	 float price() override {
		 return 25.0f;
	 }

	 string name() override {
		 return "Veg Burger";
	 }
 };

//���⺺��
 class ChickenBurger : public  Burger {

 public:
	 float price() override {
		 return 50.5f;
	 }

	 string name() override {
		 return "Chicken Burger";
	 }
 };

//����
 class Coke : public ColdDrink {

 public:
	 float price()override {
		 return 30.0f;
	 }

	 string name() override {
		 return "Coke";
	 }
 };

 //���¿���
 class Pepsi : public ColdDrink {

 public:
	 float price()override {
		 return 35.0f;
	 }

	 string name() override {
		 return "Pepsi";
	 }
 };


//һ�ٷ�
class Meal 
{

public:

 void addItem(Item* item) {
		items.push_back(item);
	}

float getCost() {
		float cost = 0.0f;
		for (auto& item : items) {
			cost += item->price();
		}
		return cost;
	}
void showItems() {
		for (auto item : items) {
			std::cout<<("Item : " + item->name());
			std::cout<<(", Packing : " + item->packing()->pack());
			std::cout << ", Price : " << item->price()<<endl;
		}
	}
private:
	list<Item*> items;
};


class MealBuilder 
{
public:
	 Meal* prepareVegMeal() {
		Meal* meal = new Meal();
		meal->addItem(new VegBurger());
		meal->addItem(new Coke());
		return meal;
	}
	 Meal* prepareNonVegMeal() {
		Meal* meal = new Meal();
		meal->addItem(new ChickenBurger());
		meal->addItem(new Pepsi());
		return meal;
	}
};

int main()
{

	MealBuilder* mealBuilder = new MealBuilder();

	Meal* vegMeal = mealBuilder->prepareVegMeal();
	log("Veg Meal");
	vegMeal->showItems();
	cout<<"Total Cost: " << vegMeal->getCost();

	Meal* nonVegMeal = mealBuilder->prepareNonVegMeal();
	std::cout <<("\n\nNon-Veg Meal\n");
	nonVegMeal->showItems();
	cout << "Total Cost: " <<nonVegMeal->getCost();
	return 0;
}