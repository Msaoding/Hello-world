#include "myhead.h"

//包含姓名 性别 年龄 联系电话 住址
static struct BOOK bookarr[MAXINUM];
//联系人的数量
static unsigned int count = 0;

//用于判断是否取消
bool cancle(const char ch)
{
	if (ch == 'Y' || ch == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//用于返回输入的字符
char input(void)
{
	char result = 0;
	std::cin >> result;

	return result;
}

//用于清理换行符
void cleam(void)
{
	while (getchar() != '\n');

	return;
}

//用于打印菜单
void menu(void)
{
	system("cls");

	std::cout << "************************************************************************\n";
	std::cout << "                          欢迎使用通讯录管理系统                          \n\n";
	std::cout << "   A.添加联系人            B.显示联系人            C.删除联系人   \n";
	std::cout << "   D.查找联系人            F.修改联系人            G.清空通讯录   \n";
	std::cout << "                           Q.退出通讯录                          \n";
	std::cout << "************************************************************************\n";

	return;
}

//用于输入并跳转至对应函数
void choose(void)
{
	char input = '\0';

	system("cls");
	menu();
	std::cout << "\n请选择(输入对应的字母): ";

	while (std::cin >> input, input != 'Q' && input != 'q')
	{
		switch (input)
		{
			case 'a':
			case 'A': add(&count, bookarr); break;
			case 'b':
			case 'B': show(0, count, bookarr); break;
			case 'c':
			case 'C': del(bookarr, &count); break;
			case 'd':
			case 'D': find(bookarr, count); break;
			case 'f':
			case 'F': revise(bookarr); break;
			case 'g':
			case 'G': delall(bookarr, &count); break;

			default: \
			{
				cleam();
				std::cout << "输入的数据无效，请重试";
				_sleep(1000);
			}
		}
		
		menu();
		std::cout << "\n请选择(输入对应的字母): ";
	}

	return;
}

//用于向结构体添加联系人
void add(unsigned int* count, struct BOOK* pstu)
{
	if (*count < MAXINUM)
	{
		do
		{
			system("cls");
			std::cout << "\n**************** 正在添加联系人" << *count + 1 << " ****************\n";
			std::cout << "\n姓名: ";
			std::cin >> pstu[*count].name;
			std::cout << "\n性别: ";
			std::cin >> pstu[*count].sex;
			std::cout << "\n年龄: ";
			std::cin >> pstu[*count].age;
			std::cout << "\n联系电话: ";
			std::cin >> pstu[*count].number;
			std::cout << "\n家庭住址: ";
			std::cin >> pstu[*count].address;
			std::cout << "\n添加成功\n";

			*count += 1;
			std::cout << "\n继续添加(Y/N) ";
		} while (cancle(input()));
	}

	else
	{
		std::cout << "通讯录已满，无法添加联系人\n";
		_sleep(1000);
	}

	return;
}

//用于显示联系人
void show(const unsigned int start, const unsigned int count, struct BOOK const* pstu)
{
	system("cls");
	std::cout << "共 " << count << '\\' << MAXINUM << " 人\n";

		for (unsigned int i = start; i < count; i++)
		{
				std::cout << "\n联系人" << i + 1 << std::endl;
				std::cout << "\t姓名: " << pstu[i].name << std::endl;
				std::cout << "\t性别: " << pstu[i].sex << std::endl;
				std::cout << "\t年龄: " << pstu[i].age << std::endl;
				std::cout << "\t联系电话: " << pstu[i].number << std::endl;
				std::cout << "\t家庭住址: " << pstu[i].address << std::endl;
		}

	putchar('\n');
	system("pause");
	return;
}
//用于显示单个联系人
void show(struct BOOK const* pstu, const unsigned int num)
{
	system("cls");

	std::cout << "\n联系人" << num << std::endl;
	std::cout << "\t姓名: " << pstu[num - 1].name << std::endl;
	std::cout << "\t性别: " << pstu[num - 1].sex << std::endl;
	std::cout << "\t年龄: " << pstu[num - 1].age << std::endl;
	std::cout << "\t联系电话: " << pstu[num - 1].number << std::endl;
	std::cout << "\t家庭住址: " << pstu[num - 1].address << std::endl;

	putchar('\n');
	return;
}

//用于删除联系人
void del(struct BOOK* pstu, unsigned int* count)
{
	do	
	{	
		int num = 0;

		system("cls");
		std::cout << "\n**************** 正在删除联系人 ****************\n";
		std::cout << "请指定要删除的联系人的序号 ";
		std::cin >> num;
		if (num > 0 && num <= *count)
		{
			for (unsigned int i = (unsigned int)num - 1; i < *count; i++)
			{
				bookarr[i] = bookarr[i + 1];
			}

			*count -= 1;
			std::cout << "\n成功删除联系人" << num << std::endl;
		}
		else
		{
			std::cout << "删除联系人失败，找不到联系人" << num << std::endl;
		}

		std::cout << "\n继续删除(Y/N) ";
	} while (cancle(input()));

	return;
}

//用于查找联系人
void find(struct BOOK const* pstu, const int count)
{
	do
	{
		int num = 0;

		system("cls");
		std::cout << "\n**************** 正在查找联系人 ****************\n";
		std::cout << "\n请输入你要查找的联系人的序号 ";
		std::cin >> num;

		if (num > 0 && num <= count)
		{
			show(bookarr, num);
		}
		else
		{
			std::cout << "找不到联系人" << num << std::endl;
		}

		std::cout << "\n继续查找(Y/N) ";
	} while (cancle(input()));

	return;
}

//用于修改联系人
void revise(struct BOOK* pstu)
{
	do
	{
		int num = 0;

		system("cls");
		std::cout << "\n请指定要修改的联系人的序号 ";
		std::cin >> num;

		if (num > 0 && num <= count)
		{
			std::cout << "\n**************** 正在修改联系人" << num << " ****************\n";
			std::cout << "\n姓名: ";
			std::cin >> pstu[num - 1].name;
			std::cout << "\n性别: ";
			std::cin >> pstu[num - 1].sex;
			std::cout << "\n年龄: ";
			std::cin >> pstu[num - 1].age;
			std::cout << "\n联系电话: ";
			std::cin >> pstu[num - 1].number;
			std::cout << "\n家庭住址: ";
			std::cin >> pstu[num - 1].address;
			std::cout << "\n修改成功\n";
		}
		else
		{
			std::cout << "找不到联系人" << num << std::endl;
		}

		std::cout << "\n继续修改(Y/N) ";
	} while (cancle(input()));

	return;
}

void delall(struct BOOK* pstu, unsigned int* count)
{
	system("cls");
	std::cout << "\n确定删除整个通讯录(Y/N) ";

	if (cancle(input()))
	{
		*count = 0;
	}

	std::cout << "\n成功删除通讯录\n";
	_sleep(1000);

	return;
}