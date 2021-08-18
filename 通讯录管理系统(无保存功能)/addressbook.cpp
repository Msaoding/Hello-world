#include "myhead.h"

//�������� �Ա� ���� ��ϵ�绰 סַ
static struct BOOK bookarr[MAXINUM];
//��ϵ�˵�����
static unsigned int count = 0;

//�����ж��Ƿ�ȡ��
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

//���ڷ���������ַ�
char input(void)
{
	char result = 0;
	std::cin >> result;

	return result;
}

//���������з�
void cleam(void)
{
	while (getchar() != '\n');

	return;
}

//���ڴ�ӡ�˵�
void menu(void)
{
	system("cls");

	std::cout << "************************************************************************\n";
	std::cout << "                          ��ӭʹ��ͨѶ¼����ϵͳ                          \n\n";
	std::cout << "   A.�����ϵ��            B.��ʾ��ϵ��            C.ɾ����ϵ��   \n";
	std::cout << "   D.������ϵ��            F.�޸���ϵ��            G.���ͨѶ¼   \n";
	std::cout << "                           Q.�˳�ͨѶ¼                          \n";
	std::cout << "************************************************************************\n";

	return;
}

//�������벢��ת����Ӧ����
void choose(void)
{
	char input = '\0';

	system("cls");
	menu();
	std::cout << "\n��ѡ��(�����Ӧ����ĸ): ";

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
				std::cout << "�����������Ч��������";
				_sleep(1000);
			}
		}
		
		menu();
		std::cout << "\n��ѡ��(�����Ӧ����ĸ): ";
	}

	return;
}

//������ṹ�������ϵ��
void add(unsigned int* count, struct BOOK* pstu)
{
	if (*count < MAXINUM)
	{
		do
		{
			system("cls");
			std::cout << "\n**************** ���������ϵ��" << *count + 1 << " ****************\n";
			std::cout << "\n����: ";
			std::cin >> pstu[*count].name;
			std::cout << "\n�Ա�: ";
			std::cin >> pstu[*count].sex;
			std::cout << "\n����: ";
			std::cin >> pstu[*count].age;
			std::cout << "\n��ϵ�绰: ";
			std::cin >> pstu[*count].number;
			std::cout << "\n��ͥסַ: ";
			std::cin >> pstu[*count].address;
			std::cout << "\n��ӳɹ�\n";

			*count += 1;
			std::cout << "\n�������(Y/N) ";
		} while (cancle(input()));
	}

	else
	{
		std::cout << "ͨѶ¼�������޷������ϵ��\n";
		_sleep(1000);
	}

	return;
}

//������ʾ��ϵ��
void show(const unsigned int start, const unsigned int count, struct BOOK const* pstu)
{
	system("cls");
	std::cout << "�� " << count << '\\' << MAXINUM << " ��\n";

		for (unsigned int i = start; i < count; i++)
		{
				std::cout << "\n��ϵ��" << i + 1 << std::endl;
				std::cout << "\t����: " << pstu[i].name << std::endl;
				std::cout << "\t�Ա�: " << pstu[i].sex << std::endl;
				std::cout << "\t����: " << pstu[i].age << std::endl;
				std::cout << "\t��ϵ�绰: " << pstu[i].number << std::endl;
				std::cout << "\t��ͥסַ: " << pstu[i].address << std::endl;
		}

	putchar('\n');
	system("pause");
	return;
}
//������ʾ������ϵ��
void show(struct BOOK const* pstu, const unsigned int num)
{
	system("cls");

	std::cout << "\n��ϵ��" << num << std::endl;
	std::cout << "\t����: " << pstu[num - 1].name << std::endl;
	std::cout << "\t�Ա�: " << pstu[num - 1].sex << std::endl;
	std::cout << "\t����: " << pstu[num - 1].age << std::endl;
	std::cout << "\t��ϵ�绰: " << pstu[num - 1].number << std::endl;
	std::cout << "\t��ͥסַ: " << pstu[num - 1].address << std::endl;

	putchar('\n');
	return;
}

//����ɾ����ϵ��
void del(struct BOOK* pstu, unsigned int* count)
{
	do	
	{	
		int num = 0;

		system("cls");
		std::cout << "\n**************** ����ɾ����ϵ�� ****************\n";
		std::cout << "��ָ��Ҫɾ������ϵ�˵���� ";
		std::cin >> num;
		if (num > 0 && num <= *count)
		{
			for (unsigned int i = (unsigned int)num - 1; i < *count; i++)
			{
				bookarr[i] = bookarr[i + 1];
			}

			*count -= 1;
			std::cout << "\n�ɹ�ɾ����ϵ��" << num << std::endl;
		}
		else
		{
			std::cout << "ɾ����ϵ��ʧ�ܣ��Ҳ�����ϵ��" << num << std::endl;
		}

		std::cout << "\n����ɾ��(Y/N) ";
	} while (cancle(input()));

	return;
}

//���ڲ�����ϵ��
void find(struct BOOK const* pstu, const int count)
{
	do
	{
		int num = 0;

		system("cls");
		std::cout << "\n**************** ���ڲ�����ϵ�� ****************\n";
		std::cout << "\n��������Ҫ���ҵ���ϵ�˵���� ";
		std::cin >> num;

		if (num > 0 && num <= count)
		{
			show(bookarr, num);
		}
		else
		{
			std::cout << "�Ҳ�����ϵ��" << num << std::endl;
		}

		std::cout << "\n��������(Y/N) ";
	} while (cancle(input()));

	return;
}

//�����޸���ϵ��
void revise(struct BOOK* pstu)
{
	do
	{
		int num = 0;

		system("cls");
		std::cout << "\n��ָ��Ҫ�޸ĵ���ϵ�˵���� ";
		std::cin >> num;

		if (num > 0 && num <= count)
		{
			std::cout << "\n**************** �����޸���ϵ��" << num << " ****************\n";
			std::cout << "\n����: ";
			std::cin >> pstu[num - 1].name;
			std::cout << "\n�Ա�: ";
			std::cin >> pstu[num - 1].sex;
			std::cout << "\n����: ";
			std::cin >> pstu[num - 1].age;
			std::cout << "\n��ϵ�绰: ";
			std::cin >> pstu[num - 1].number;
			std::cout << "\n��ͥסַ: ";
			std::cin >> pstu[num - 1].address;
			std::cout << "\n�޸ĳɹ�\n";
		}
		else
		{
			std::cout << "�Ҳ�����ϵ��" << num << std::endl;
		}

		std::cout << "\n�����޸�(Y/N) ";
	} while (cancle(input()));

	return;
}

void delall(struct BOOK* pstu, unsigned int* count)
{
	system("cls");
	std::cout << "\nȷ��ɾ������ͨѶ¼(Y/N) ";

	if (cancle(input()))
	{
		*count = 0;
	}

	std::cout << "\n�ɹ�ɾ��ͨѶ¼\n";
	_sleep(1000);

	return;
}