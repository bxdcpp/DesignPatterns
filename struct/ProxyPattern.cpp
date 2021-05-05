/**************************************************************************
�ڴ���ģʽ��Proxy Pattern��
һ���������һ����Ĺ��ܡ��������͵����ģʽ���ڽṹ��ģʽ��
�ڴ���ģʽ�У����Ǵ����������ж���Ķ����Ա�������ṩ���ܽӿ�

��ͼ��Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�

��Ҫ�������ֱ�ӷ��ʶ���ʱ���������⣬����˵��Ҫ���ʵĶ�����Զ�̵Ļ����ϡ�
		���������ϵͳ�У���Щ��������ĳЩԭ�򣨱�����󴴽������ܴ󣬻���ĳЩ������Ҫ��ȫ���ƣ�������Ҫ������ķ��ʣ���
		ֱ�ӷ��ʻ��ʹ���߻���ϵͳ�ṹ�����ܶ��鷳�����ǿ����ڷ��ʴ˶���ʱ����һ���Դ˶���ķ��ʲ㡣

��ʱʹ�ã����ڷ���һ����ʱ��һЩ���ơ�

��ν���������м�㡣

�ؼ����룺ʵ���뱻���������

�ŵ㣺 1��ְ�������� 2������չ�ԡ� 3�����ܻ���

ȱ�㣺 1�������ڿͻ��˺���ʵ����֮�������˴�����������Щ���͵Ĵ���ģʽ���ܻ��������Ĵ����ٶȱ�����
		2��ʵ�ִ���ģʽ��Ҫ����Ĺ�������Щ����ģʽ��ʵ�ַǳ����ӡ�

**************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Image {
public:
	virtual void display() = 0;
};

class RealImage : public Image {

public:
	RealImage(string fileName) {
		this->fileName = fileName;
		loadFromDisk(fileName);
	}

		void display() override {
		std::cout<<("Displaying " + fileName)<<endl;
	}
private:
	void loadFromDisk(string fileName) {
		std::cout << ("Loading " + fileName)<<endl;
	}
	string fileName;
};
class ProxyImage : public Image {


public:

 ProxyImage(string fileName) {
		this->fileName = fileName;
	}

	void display() override {
		if (realImage == nullptr) {
			realImage = new RealImage(fileName);
		}
		realImage->display();
	}
private:
	RealImage* realImage = nullptr;
	string fileName;
};


int main()
{
	Image* image = new ProxyImage("test_10mb.jpg");

	// ��һ��ͼ�񽫴Ӵ��̼���
	image->display();
	cout <<("");
	// ͼ����Ҫ�Ӵ��̼���
	image->display();
	return 0;
}