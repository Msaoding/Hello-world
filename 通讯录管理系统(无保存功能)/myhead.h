#ifndef _MYHEAD_H_
#define _MYHEAD_H_
#define MAXINUM 1000

#include <iostream>
#include <string>
#include <cstdlib>

//����ͨѶ¼�ṹ�壬�������� �Ա� ���� ��ϵ�绰 סַ
struct BOOK
{
	std::string name = "δ���";
	std::string sex = "δ���";
	std::string age = "δ���";
	std::string number = "δ���";
	std::string address = "δ���";
};

//�����ж��Ƿ�ȡ��
bool cancle(const char ch);
//���ڷ���������ַ�
char input(void);
//���������з�
void cleam(void);
//���ڴ�ӡ�˵�
void menu(void);
//�������벢��ת����Ӧ����
void choose(void);
//������ṹ�������ϵ��
void add(unsigned int* count, struct BOOK* pstu);
//������ʾ��ϵ��
void show(const unsigned int start, const unsigned int count, struct BOOK const* pstu);
void show(struct BOOK const* pstu, const unsigned int num);
//����ɾ����ϵ��
void del(struct BOOK* pstu, unsigned int* count);
//���ڲ�����ϵ��
void find(struct BOOK const* pstu, const int count);
//�����޸���ϵ��
void revise(struct BOOK* pstu);
//����ɾ������ͨѶ¼
void delall(struct BOOK* pstu, unsigned int* count);

#endif