#include <iostream>
#include <string>

#define TEA_NUM 3
#define STU_NUM 5

//����ѧ���ṹ��
struct student
{
	std::string name;
	unsigned short int score;
};

//������ʦ�ṹ��
struct teacher
{
	std::string name;
	struct student stuarr[STU_NUM];
};

//�����������뺯��
void indata(teacher* tea, unsigned short int teachernum, unsigned short int studentnum);
//������ӡ�ṹ�庯��
void printdata(teacher* tea, unsigned short int teachernum, unsigned short int studentnum);

int main(void)
{
	teacher	teaarr[TEA_NUM];
	indata(teaarr, TEA_NUM, STU_NUM);
	printdata(teaarr, TEA_NUM, STU_NUM);

	return 0;
}

//��������
void indata(teacher* ptea, unsigned short int tea, unsigned short int stu)
{
	std::cout << "����������Ϣ" << std::endl;
	for (unsigned short int i = 0; i < tea; i++)
	{
		std::cout << "�������" << i + 1 << "λ��ʦ������ ";
		std::cin >> (ptea + i)->name;
		putchar('\n');

		for (unsigned short int j = 0; j < stu; j++)
		{
			std::cout << "�������" << i + 1 << "λ��ʦ����ĵ�" << j + 1 << "λѧ�������� ";
			std::cin >> (ptea + i)->stuarr[j].name;
			std::cout << "�������" << i + 1<< "λ��ʦ����ĵ�" << j + 1 << "λѧ���ĳɼ� ";
			std::cin >> (ptea + i)->stuarr[j].score;
		}
	}

	return;
}

//��ӡ����
void printdata(teacher* ptea, unsigned short int tea, unsigned short int stu)
{
	for (unsigned short int i = 0; i < tea; i++)
	{
		std::cout << "��" << i + 1 << "λ��ʦ������:" << std::endl;
		std::cout << "����: " << (ptea + i)->name << std::endl;
		
		for (unsigned short int j = 0; j < stu; j++)
		{
			std::cout << "ѧ��" << j + 1 << "����: " << (ptea + i)->stuarr[j].name << std::endl;
			std::cout << "ѧ��" << j + 1 << "�ɼ�: " << (ptea + i)->stuarr[j].score << std::endl;
		}
		putchar('\n');
	}

	return;
}