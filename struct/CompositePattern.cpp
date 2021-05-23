/**************************************************************************
* ���ģʽ
*
��ͼ����������ϳ����νṹ�Ա�ʾ"����-����"�Ĳ�νṹ�����ģʽʹ���û��Ե����������϶����ʹ�þ���һ���ԡ�

��Ҫ����������������ͽṹ�������У�ģ���˼�Ԫ�غ͸���Ԫ�صĸ���ͻ�������������Ԫ��һ����������Ԫ�أ��Ӷ�ʹ�ÿͻ������븴��Ԫ�ص��ڲ��ṹ���

��ʱʹ�ã� 1�������ʾ����Ĳ���-�����νṹ�����νṹ���� 2����ϣ���û�������϶����뵥������Ĳ�ͬ���û���ͳһ��ʹ����Ͻṹ�е����ж���

��ν������֦��Ҷ��ʵ��ͳһ�ӿڣ���֦�ڲ���ϸýӿڡ�

�ؼ����룺��֦�ڲ���ϸýӿڣ����Һ����ڲ����� List������� Component��

Ӧ��ʵ���� 1���������ʽ����������������������һ�������������У���һ��������Ҳ�����ǲ�����������������һ���������� 2���� JAVA AWT �� SWING �У����� Button �� Checkbox ����Ҷ��Container ����֦��

�ŵ㣺 1���߲�ģ����ü򵥡� 2���ڵ��������ӡ�

ȱ�㣺��ʹ�����ģʽʱ����Ҷ�Ӻ���֦����������ʵ���࣬�����ǽӿڣ�Υ������������ԭ��

ʹ�ó��������֡����峡���������β˵����ļ����ļ��еĹ���

ע���������ʱΪ�����ࡣ
**************************************************************************/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Employee
{
public:
	Employee(string name, string  dept, int sal)
		:name(name)
		, dept(dept)
		, salary(sal)
	{
		subordinates.reserve(100);
	}
	void add(Employee* e)
	{
		subordinates.push_back(e);
	}
	void remove(Employee *e)
	{
		std::remove(subordinates.begin(), subordinates.end(), e);
	}

	bool operator == (const Employee* e)
	{
		return  (this->name == e->name && this->dept == e->dept && this->salary == e->salary);
	}
	vector<Employee*> getSubordinates()
	{
		return subordinates;
	}
	string Info() const
	{
		string info = "Employee :[ Name : ";
		info += this->name;
		info += ", dept : ";
		info += this->dept;
		info += ", salary :";
		info += to_string(this->salary);
		info += " ]";
		return info;
	}
private:
	string name;
	string dept;
	int salary;
	vector<Employee*> subordinates;
};

void printEmployee(Employee* emp)
{
	auto eVec = emp->getSubordinates();
	for (auto it : eVec)
	{
		auto subord = it->getSubordinates();
		for_each(subord.cbegin(), subord.cend(), [=](const Employee* e)->void {cout << "e:" << e->Info(); });
		cout << endl;
	}
	
}

int main()
{
	Employee* CEO = new Employee("John", "CEO", 30000);

	Employee* headSales = new Employee("Robert", "Head Sales", 20000);

	Employee* headMarketing = new Employee("Michel", "Head Marketing", 20000);

	Employee* clerk1 = new Employee("Laura", "Marketing", 10000);
	Employee* clerk2 = new Employee("Bob", "Marketing", 10000);

	Employee* salesExecutive1 = new Employee("Richard", "Sales", 10000);
	Employee* salesExecutive2 = new Employee("Rob", "Sales", 10000);

	CEO->add(headSales);
	CEO->add(headMarketing);

	headSales->add(salesExecutive1);
	headSales->add(salesExecutive2);

	headMarketing->add(clerk1);
	headMarketing->add(clerk2);
	//printEmployee(CEO);

	cout << CEO->Info() << endl;
	for (auto headEmployee : CEO->getSubordinates())
	{
		cout << headEmployee->Info() << endl;
		for (auto employee : headEmployee->getSubordinates())
		{
			cout << employee->Info() << endl;
		}
	}
	return 0;
}