/**************************************************************************
* ������ģʽ
* ��ͼ����һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�������ģʽʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ������

��Ҫ�������Ҫ��������ϵͳ�У�����Ҫ��һЩ"�ִ�Ķ���"�ŵ��µĻ����У����»���Ҫ��Ľӿ����ֶ���������ġ�

��ʱʹ�ã� 1��ϵͳ��Ҫʹ�����е��࣬������Ľӿڲ�����ϵͳ����Ҫ�� 2����Ҫ����һ�������ظ�ʹ�õ��࣬������һЩ�˴�֮��û��̫�������һЩ�࣬����һЩ�����ڽ�����������һ��������ЩԴ�಻һ����һ�µĽӿڡ� 3��ͨ���ӿ�ת������һ���������һ����ϵ�С��������ϻ��ͷ��ݣ����ڶ���һ���ɻ����ڲ�����ʵ��������£�����һ�������������������һ��������ʵ�ַɵĽӿڡ���

��ν�����̳л��������Ƽ�����

�ؼ����룺�������̳л��������еĶ���ʵ����Ҫ��Ŀ��ӿڡ�

Ӧ��ʵ���� 1���������� 110V���й� 220V����Ҫ��һ���������� 110V ת��Ϊ 220V�� 2��JAVA JDK 1.1 �ṩ�� Enumeration �ӿڣ����� 1.2 ���ṩ�� Iterator �ӿڣ���Ҫʹ�� 1.2 �� JDK����Ҫ����ǰϵͳ�� Enumeration �ӿ�ת��Ϊ Iterator �ӿڣ���ʱ����Ҫ������ģʽ�� 3���� LINUX ������ WINDOWS ���� 4��JAVA �е� jdbc��

�ŵ㣺 1���������κ�����û�й�������һ�����С� 2���������ĸ��á� 3�����������͸���ȡ� 4������Ժá�

ȱ�㣺 1�������ʹ��������������ϵͳ�ǳ����ң�����������а��ա����磬�����������õ��� A �ӿڣ���ʵ�ڲ���������� B �ӿڵ�ʵ�֣�һ��ϵͳ���̫��������������������һ�����ѡ����������Ǻ��б�Ҫ�����Բ�ʹ��������������ֱ�Ӷ�ϵͳ�����ع��� 2.���� JAVA ����̳�һ���࣬��������ֻ������һ���������࣬����Ŀ��������ǳ����ࡣ

ʹ�ó������ж������޸�һ���������е�ϵͳ�Ľӿڣ���ʱӦ�ÿ���ʹ��������ģʽ��

ע�������������������ϸ���ʱ��ӵģ����ǽ�����ڷ��۵���Ŀ�����⡣

**************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class MediaPlayer
{
public:
	MediaPlayer() = default;
	~MediaPlayer() = default;
	virtual void play(string audioTyope, string fileName) {};
private:

};

class  AdvancedMediaPlayer 
{
public:
	AdvancedMediaPlayer() = default;
	~AdvancedMediaPlayer() = default;
	virtual void playVlc(string fileName) {};
	virtual void playMp4(string fileName) {};
};

class VlcPlayer : public AdvancedMediaPlayer 
{

public:
	VlcPlayer() = default;
	~VlcPlayer() = default;
	void playVlc(string fileName) override
	{
		cout << ("Playing vlc file. Name: " + fileName) << endl;
	}

	void playMp4(string fileName) override
	{
		//ʲôҲ����
	}
};

class Mp4Player : public AdvancedMediaPlayer {

public:
	Mp4Player() = default;
	~Mp4Player() = default;
	void playVlc(string fileName) override
	{
		//ʲôҲ����
	}

	void playMp4(string fileName) override 
	{
		cout << ("Playing mp4 file. Name: " + fileName);
	}
};

class MediaAdapter : public MediaPlayer {

	
public:
	MediaAdapter(string audioType) {
		if (audioType._Equal("vlc")) {
			advancedMusicPlayer = new VlcPlayer();
		}
		else if (audioType._Equal("mp4")) {
			advancedMusicPlayer = new Mp4Player();
		}
	}

	void play(string audioType, string fileName) override {
		if (audioType._Equal("vlc")) {
			advancedMusicPlayer->playVlc(fileName);
		}
		else if (audioType._Equal("mp4")) {
			advancedMusicPlayer->playMp4(fileName);
		}
	}
private:
	AdvancedMediaPlayer* advancedMusicPlayer = nullptr;
};

class AudioPlayer : public MediaPlayer {

public:
	void play(string audioType, string fileName) override
	{

		//���� mp3 �����ļ�������֧��
		if (audioType._Equal("mp3")) 
		{
			cout << ("Playing mp3 file. Name: " + fileName) << endl;
		}
		//mediaAdapter �ṩ�˲��������ļ���ʽ��֧��
		else if (audioType._Equal("vlc")
			|| audioType._Equal("mp4")) 
		{
			mediaAdapter = new MediaAdapter(audioType);
			mediaAdapter->play(audioType, fileName);
		}
		else
		{
			cout << ("Invalid media. " +
				audioType + " format not supported") << endl;
		}
	}
private:
	MediaAdapter* mediaAdapter = nullptr;
};

//class person
//{
//public:
//	string name = "myName";
//protected:
//	string  address = "Beijing";
//private:
//	string m_ID = "111111";
//};
//
//class BeiJingPerson:public person
//{
//public:
//	void show()
//	{
//		cout << name<<address;
//	}
//
//};
//
//
//class TianJingPerson :protected person
//{
//public:
//	void show()
//	{
//		cout << name <<address;
//	}
//
//};
//class HeNanJingPerson :private person
//{
//public:
//	void show()
//	{
//		cout << name << address;
//	}
//
//};
//
//class mm : public TianJingPerson
//{
//public:
//	void show()
//	{
//		cout << name << address;
//	}
//};





void main()
{
	/*TianJingPerson tp; HeNanJingPerson hp; BeiJingPerson bp;
	tp.show();
	hp.show();
	bp.name;*/

	AudioPlayer* audioPlayer = new AudioPlayer();

	audioPlayer->play("mp3", "beyond the horizon.mp3");
	audioPlayer->play("mp4", "alone.mp4");
	audioPlayer->play("vlc", "far far away.vlc");
	audioPlayer->play("avi", "mind me.avi");




}