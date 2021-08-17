#include <iostream>
#include <string>

#define TEA_NUM 3
#define STU_NUM 5

//创建学生结构体
struct student
{
	std::string name;
	unsigned short int score;
};

//创建老师结构体
struct teacher
{
	std::string name;
	struct student stuarr[STU_NUM];
};

//声明数据输入函数
void indata(teacher* tea, unsigned short int teachernum, unsigned short int studentnum);
//声明打印结构体函数
void printdata(teacher* tea, unsigned short int teachernum, unsigned short int studentnum);

int main(void)
{
	teacher	teaarr[TEA_NUM];
	indata(teaarr, TEA_NUM, STU_NUM);
	printdata(teaarr, TEA_NUM, STU_NUM);

	return 0;
}

//输入数据
void indata(teacher* ptea, unsigned short int tea, unsigned short int stu)
{
	std::cout << "正在输入信息" << std::endl;
	for (unsigned short int i = 0; i < tea; i++)
	{
		std::cout << "请输入第" << i + 1 << "位老师的姓名 ";
		std::cin >> (ptea + i)->name;
		putchar('\n');

		for (unsigned short int j = 0; j < stu; j++)
		{
			std::cout << "请输入第" << i + 1 << "位老师带领的第" << j + 1 << "位学生的姓名 ";
			std::cin >> (ptea + i)->stuarr[j].name;
			std::cout << "请输入第" << i + 1<< "位老师带领的第" << j + 1 << "位学生的成绩 ";
			std::cin >> (ptea + i)->stuarr[j].score;
		}
	}

	return;
}

//打印数据
void printdata(teacher* ptea, unsigned short int tea, unsigned short int stu)
{
	for (unsigned short int i = 0; i < tea; i++)
	{
		std::cout << "第" << i + 1 << "位老师的数据:" << std::endl;
		std::cout << "姓名: " << (ptea + i)->name << std::endl;
		
		for (unsigned short int j = 0; j < stu; j++)
		{
			std::cout << "学生" << j + 1 << "姓名: " << (ptea + i)->stuarr[j].name << std::endl;
			std::cout << "学生" << j + 1 << "成绩: " << (ptea + i)->stuarr[j].score << std::endl;
		}
		putchar('\n');
	}

	return;
}