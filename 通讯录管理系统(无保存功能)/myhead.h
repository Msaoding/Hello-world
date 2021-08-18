#ifndef _MYHEAD_H_
#define _MYHEAD_H_
#define MAXINUM 1000

#include <iostream>
#include <string>
#include <cstdlib>

//定义通讯录结构体，包含姓名 性别 年龄 联系电话 住址
struct BOOK
{
	std::string name = "未添加";
	std::string sex = "未添加";
	std::string age = "未添加";
	std::string number = "未添加";
	std::string address = "未添加";
};

//用于判断是否取消
bool cancle(const char ch);
//用于返回输入的字符
char input(void);
//用于清理换行符
void cleam(void);
//用于打印菜单
void menu(void);
//用于输入并跳转至对应函数
void choose(void);
//用于向结构体添加联系人
void add(unsigned int* count, struct BOOK* pstu);
//用于显示联系人
void show(const unsigned int start, const unsigned int count, struct BOOK const* pstu);
void show(struct BOOK const* pstu, const unsigned int num);
//用于删除联系人
void del(struct BOOK* pstu, unsigned int* count);
//用于查找联系人
void find(struct BOOK const* pstu, const int count);
//用于修改联系人
void revise(struct BOOK* pstu);
//用于删除整个通讯录
void delall(struct BOOK* pstu, unsigned int* count);

#endif