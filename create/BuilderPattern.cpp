/*
建造者模式（Builder Pattern）使用多个简单的对象一步一步构建成一个复杂的对象。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。
一个 Builder 类会一步一步构造最终的对象。该 Builder 类是独立于其他对象的。
意图:将一个复杂的构建与其表示相分离，使得同样的构建过程可以创建不同的表示。

主要解决:主要解决在软件系统中，有时候面临着"一个复杂对象"的创建工作，其通常由各个部分的子对象用一定的算法构成；由于需求的变化，这个复杂对象的各个部分经常面临着剧烈的变化，但是将它们组合在一起的算法却相对稳定。

何时使用:一些基本部件不会变，而其组合经常变化的时候。

如何解决:将变与不变分离开。

关键代码:建造者:创建和提供实例，导演:管理建造出来的实例的依赖关系。
优点: 1、建造者独立，易扩展。 2、便于控制细节风险。

缺点: 1、产品必须有共同点，范围有限制。 2、如内部变化复杂，会有很多的建造类。

使用场景: 1、需要生成的对象具有复杂的内部结构。 2、需要生成的对象内部属性本身相互依赖。

注意事项:与工厂模式的区别是:建造者模式更加关注与零件装配的顺序。
*/




#include <iostream>
#include <mutex>
#include <list>

using namespace std;

void log(string str)
{
	cout << str << endl;
}
//打包
class  Packing 
{
public:
	virtual string pack() = 0;
};


//食物条目
class Item 
{
public:
	virtual string name() = 0;
	virtual Packing* packing() = 0;
	virtual float price() = 0;
};


//包装纸 
class Wrapper : public Packing
{

public:
	string pack()
	{
		return "Wrapper";
	}
};

//瓶子
class Bottle : public Packing {

public:
	string pack()
	{
		return "Bottle";
	}
};

//汉堡
 class Burger : public Item {

 public:
	 Packing* packing() override
	 {
		 return new Wrapper();
	 }

	 float price() override = 0;
};

//冷饮 
 class ColdDrink : public Item
 {

 public:
	  Packing* packing() override
	 {
		 return new Bottle();
	 }

	 float price() override = 0;
 };

//素食汉堡
 class VegBurger : public Burger {

 public:
	 float price() override {
		 return 25.0f;
	 }

	 string name() override {
		 return "Veg Burger";
	 }
 };

//鸡肉汉堡
 class ChickenBurger : public  Burger {

 public:
	 float price() override {
		 return 50.5f;
	 }

	 string name() override {
		 return "Chicken Burger";
	 }
 };

//可乐
 class Coke : public ColdDrink {

 public:
	 float price()override {
		 return 30.0f;
	 }

	 string name() override {
		 return "Coke";
	 }
 };

 //百事可乐
 class Pepsi : public ColdDrink {

 public:
	 float price()override {
		 return 35.0f;
	 }

	 string name() override {
		 return "Pepsi";
	 }
 };


//一顿饭
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