/**************************************************************************
Copyright:zzuli
Author: bxd

Date:2014-08-11
Last Review:2019-3-1

Description:�ַ���ƥ��
ԭ�����ӣ�https://blog.csdn.net/v_JULY_v/article/details/7041827
**************************************************************************/

#include<stdio.h>
#include<string.h>
#include <iostream>

int next[7] = { 0 };
//��������������������һ�����⣺��һ���ı���S����һ��ģʽ��P������Ҫ����P��S�е�λ�ã���ô�����أ�
//����ñ���ƥ���˼·�������������ı���Sƥ�䵽 i λ�ã�ģʽ��Pƥ�䵽 j λ�ã����У�
//�����ǰ�ַ�ƥ��ɹ�����S[i] == P[j]������i++��j++������ƥ����һ���ַ���
//���ʧ�䣨��S[i]!= P[j]������i = i - (j - 1)��j = 0���൱��ÿ��ƥ��ʧ��ʱ��i ���ݣ�j ����Ϊ0

int ViolentMatch(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);
	int i = 0;
	int j = 0;

	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			//�������ǰ�ַ�ƥ��ɹ�����S[i] == P[j]������i++��j++ 
			i++;
			j++;
		}
		else
		{
			//�����ʧ�䣨��S[i]! = P[j]������i = i - (j - 1)��j = 0    
			i = i - j + 1;
			j = 0;
		}
	}
	//ƥ��ɹ�������ģʽ��p���ı���s�е�λ�ã����򷵻�-1
	if (j == pLen)
		return i - j;
	return -1;
}

void getNext(char* p, int next[])
{
	int pLen = strlen(p);
	int k = -1;
	int j = 0;
	next[0] = k;
	while (j < pLen - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

void getNext2(char* p, int next[])
{
	int pLen = strlen(p);
	int k = -1;
	int j = 0;
	next[0] = k;
	while (j < pLen - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			//��֮ǰnext�����󷨣��Ķ�������4��
			if(p[j] != p[k])
				next[j] = k;
			else
				//��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}

int KMPSearch(char* s, char* p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{
		//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++    
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]    
			//next[j]��Ϊj����Ӧ��nextֵ      
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

void main()
{
	char* sStr = "BBC ABCDAB ABCDABCDABDE";
	char* pStr = "ABCDABD";
	getNext2(pStr, next);
	int index = KMPSearch(sStr,pStr);
	std::cout << "index:"<< index << std::endl;
}