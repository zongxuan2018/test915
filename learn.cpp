#include<iostream>
#include <string>
#include"circle.h"
#include"point.h"
#include <fstream>
#include<vector>
#include<algorithm>//��׼�㷨��
using namespace std;

//ͨѶ¼����ϵͳ
#if 0
constexpr auto MAX = 1000;//-------------------------����
//1����ʾͨѶ¼Ŀ¼
//2���˳�ͨѶ¼
//3�����ͨѶ¼
//4����ʾͨѶ¼
//5������

//��ʾĿ¼
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.���ͨѶ¼ *****" << endl;
	cout << "***** 2.��ʾͨѶ¼ *****" << endl;
	cout << "***** 3.ɾ��ͨѶ¼ *****" << endl;
	cout << "***** 4.����ͨѶ¼ *****" << endl;
	cout << "***** 5.�޸�ͨѶ¼ *****" << endl;
	cout << "***** 6.���ͨѶ¼ *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}

//��ϵ�˽ṹ��
struct person
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

//ͨѶ¼�ṹ��
struct addrbook
{
	struct person;
	int num;
};

//���ͨѶ¼
void addperson(person *p_array,int num)
{

	cout << "������������ " << endl;
	cin >> p_array[num].name;
	cout << "�������Ա� " << endl << "1 �� " << endl << "2 Ů " << endl;
	cin >> p_array[num].sex;
	cout << "���������䣺 " << endl;
	cin >> p_array[num].age;
	cout << "��������ϵ��ʽ�� " << endl;
	cin >> p_array[num].phone;
	cout << "�������ͥסַ�� " << endl;
	cin >> p_array[num].addr;
}

//��ʾͨѶ¼
void showperson(person* p_array, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "������\t" << p_array[i].name << "\t�Ա�" << (p_array[i].sex == 1 ? "��" : "Ů") << "\t���䣺\t" << p_array[i].age 
			<< "\t��ϵ��ʽ��" << p_array[i].phone << "\t��ͥסַ��" << p_array[i].addr << endl;
	}
	
}

//����ͨѶ¼
int findperson(person* p_array, int num)
{
	int t = -1;
	string name = "0000";
	cout << "������������ " << endl;
	cin >> name;
	for (int i = 0; i < num; i++)
	{
		if (name == p_array[i].name)
		{
			t = i;
		}
	}
	return t;
}

//��ʾ����ͨѶ¼
void showone(person* p_array, int t)
{
	cout << "������\t" << p_array[t].name << "\t�Ա�" << (p_array[t].sex == 1 ? "��" : "Ů") << "\t���䣺\t" << p_array[t].age
		<< "\t��ϵ��ʽ��\t" << p_array[t].phone << "\t��ͥסַ��" << p_array[t].addr << endl;
}

//ɾ������ͨѶ¼-----------------------------------------����ɾ����ֱ������һ���������
void deleteperson(person* p_array, int find,int num)
{
	//p_array[find].name = "0";
	//p_array[find].sex = 0;
	//p_array[find].age = 0;
	//p_array[find].phone = "0";
	//p_array[find].addr = "0";-------------------------��tempɾ������Ҫһ��һ����ֵ
	
	for (int i = find; i <= num; i++)
	{
		p_array[i].name = p_array[i + 1].name;
		p_array[i].sex  = p_array[i + 1].sex;
		p_array[i].age  = p_array[i + 1].age;
		p_array[i].phone = p_array[i + 1].phone;
		p_array[i].addr = p_array[i + 1].addr;
	}
}

//���ͨѶ¼
void clearperson(person* p_array, int num)
{
	for (int i = 0; i <= num; i++)
	{
		person temp = { "0", 0, 0, "0", "0" };
		p_array[i] = temp;

	}
}

//�޸�ͨѶ¼
void corperson(person* p_array, int find)
{

	cout << "������������ " << endl;
	cin >> p_array[find].name;
	cout << "�������Ա� " << endl << "1 �� " << endl << "2 Ů " << endl;
	cin >> p_array[find].sex;
	cout << "���������䣺 " << endl;
	cin >> p_array[find].age;
	cout << "��������ϵ��ʽ�� " << endl;
	cin >> p_array[find].phone;
	cout << "�������ͥסַ�� " << endl;
	cin >> p_array[find].addr;
}


int main()
{

	//�ṹ������
	struct person p_array[MAX];
	int num = 0;//��ʼ������


	while (true)
	{
		showMenu();
		int input = 0;
		int find = 0;
		cin >> input;

		switch (input)
		{
		case 1:
			//���жϿռ��Ƿ�Ϊ��
			if (num == MAX)
			{
				cout << "ͨѶ¼�ռ�����" << endl;

			}
			else
			{
				addperson(&p_array[0], num);
			}
			num++;
			cout << "ͨѶ¼��ӳɹ���" << endl;
			//system("cls");
			break;
		case 2:
			if (num == 0)
			{
				cout << "ͨѶ¼Ϊ�գ�" << endl;
			}
			else
			{
				showperson(&p_array[0], num);
			}
			break;
		case 3:
			if (num == 0)
			{
				cout << "ͨѶ¼Ϊ�գ�" << endl;
			}
			else
			{
				find = findperson(&p_array[0], num);
				if (find == -1)
				{
					cout << "δ�ҵ�����ϵ�ˣ�" << endl;
				}
				else
				{
					deleteperson(&p_array[0], find, num);
					//ͨѶ¼��������
					num--;
					cout << "�ɹ�ɾ������ϵ�ˣ�" << endl;
				}
			}
			break;
		case 4:
			if (num == 0)
			{
				cout << "ͨѶ¼Ϊ�գ�" << endl;
			}
			else
			{
				find = findperson(&p_array[0], num);
				if (find == 0)
				{
					cout << "δ�ҵ�����ϵ�ˣ�" << endl;
				}

				showone(&p_array[0], find);
			}
			break;
		case 5:
			//�Ȳ���
			//����д
			if (num == 0)
			{
				cout << "ͨѶ¼Ϊ�գ�" << endl;
			}
			else
			{
				find = findperson(&p_array[0], num);//���ص�tֵ
				if (find == 0)
				{
					cout << "δ�ҵ�����ϵ�ˣ�" << endl;
				}

				showone(&p_array[0], find);
				corperson(&p_array[0], find);
			}
			break;
		case 6:
			if (num == 0)
			{
				cout << "ͨѶ¼Ϊ�գ�" << endl;
			}
			else
			{
				clearperson(&p_array[0], num);
				num = 0;
			}
			cout << "ͨѶ¼�����" << endl;
			break;
		case 0:
			cout << "�ɹ��˳�ͨѶ¼" << endl;
			system("pause");
			//system("cls");
			return 0;
			break;
		default:
			break;
		}
	}




	system("pause");
	return 0;
}	
#endif 

//ȫ�ֱ�������̬������ȫ�ֳ���
#if 0

//����������Ŷ����ƴ��루����ֻ����
//ȫ������ȫ�ֱ�������̬�������������ַ���������const���ε�ȫ�ֱ�����ȫ�ֳ�����       �ɲ���ϵͳ�ͷ� 
//���ϣ� ��������ǰ���е�

//ջ��������

int g_a = 10;
int g_b = 10;
int c_g_a = 10;
int c_g_b = 10;

int main()
{
	int a = 10;
	int b = 10;
	int c_l_a = 10;
	int c_l_b = 10;

	cout << "�ֲ�����a�ĵ�ַΪ�� " << (int)&a << endl;
	cout << "�ֲ�����b�ĵ�ַΪ�� " << (int)&b << endl;

	cout << "ȫ�ֱ���g_a�ĵ�ַΪ�� " << (int)&g_a << endl;
	cout << "ȫ�ֱ���g_b�ĵ�ַΪ�� " << (int)&g_b << endl;

	//��̬���� ����ͨ����ǰ+static�����ھ�̬����
	static int s_a = 10;
	static int s_b = 10;
	cout << "��̬����s_a�ĵ�ַΪ�� " << (int)&s_a << endl;
	cout << "��̬����s_b�ĵ�ַΪ�� " << (int)&s_b << endl;

	//�ַ������� 
	cout << "�ַ��������ĵ�ַΪ�� " << (int)&"hello world" << endl;

	//const���εı��� (�ֲ�����ȫ�֣�c-const g-gloa l-

	cout << "ȫ�ֳ���c_g_a�ĵ�ַΪ�� " << (int)&c_g_a << endl;
	cout << "ȫ�ֳ���c_g_b�ĵ�ַΪ�� " << (int)&c_g_b << endl;

	cout << "�ֲ�����c_l_a�ĵ�ַΪ�� " << (int)&c_l_a << endl;
	cout << "�ֲ�����c_l_b�ĵ�ַΪ�� " << (int)&c_l_b << endl;

	return 0;
}



#endif // 0

//ջ��  �ֲ����� �β�
#if 0

//ջ�� �������Զ������ͷ� �����Ĳ������ֲ�����
//---------��Ҫ���ؾֲ������ĵ�ַ

int* func(int b)
{
	b = 10;
	int a = 10;//�ֲ������������ջ����ջ���������ں���ִ������Զ��ͷ�
	return &a;//���ؾֲ������ĵ�ַ
}

int main()
{
	int* p = func(1);

	cout << *p << endl;//��һ�ο��Դ�ӡ�����������˱���
	cout << *p << endl;//�ڶ��β�����

	return 0;
}
#endif// 0 

//���� new
#if 0
//���� �ɳ���Ա�����ͷ�
//����new�ڶ�����������
//ָ�� ����Ҳ�Ǿֲ�����������ջ�ϣ�ָ�뱣��������Ƿ��ڶ�����
//main����û��ִ���ָ꣬������ݲ����ͷ�
int* func()
{
	int *p = new int(10);//���ﷵ�ص������ݵ�ַ�ı�ţ���ָ��ȥ����
	return p;//����ָ��ĵ�ַ
}
int main()
{
	int *p = func();

	cout << *p << endl;
	cout << *p << endl;

	return 0;
}
#endif // 0

//���� new �ͷ� delete
#if 0
//new�Ļ����﷨����delete�ͷſռ�
//�ڶ�������new�������飬�������ݶ�Ӧ������ָ��

int* func()
{
	//�ڶ���������������
	//new���ص��� ���������͵�ָ��
	//double* p = new double(10.0);
	int* p = new int(10);
	return p;
}

void test0()
{
	int * p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//���������ݣ��ɳ���Ա���٣�����Ա�ͷţ���delete�ͷ�
	delete p;
	//cout << *p << endl;//�ڴ��ѱ��ͷţ��ٴη��ʾ��ǷǷ��������ᱨ��
}

void test1()
{
	int* arr = new int[10];//10Ϊ��������ݸ���Ϊ10

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//�ͷŶ������� ��Ҫ��[]
	delete[] arr;
}

int main()
{
	test0();
	cout << endl;
	test1();

	return 0;
}

#endif // 1

//����
#if 0
//��һ�����������
//int a =10;

//�������� &���� = ԭ��
//int &b = a;

//b = 20;
//cout<<a<<endl;

//���ñ���Ҫ��ʼ��-------------------------------------
//int &b;-------���Ǵ����

//����һ����ʼ�����Ͳ��ɸ���


int main()
{
	int a = 10;
	int& b = a;
	b = 20;
	cout << a << endl;
	cout << b << endl;


	return 0;
}
#endif // 1

//�������������������β�����ʵ�Σ���ָ���޸�ʵ��
#if 0
//��������
//1��ֵ����

void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

	cout << "mySwap01 a = " << a << endl;
	cout << "mySwap01 b = " << b << endl;
}

//2����ַ����

void mySwap02(int *a,int *b)//aָ��� ��Ԫ�� ��ֵ
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3�����ô���

void mySwap03(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;

	cout << "mySwap03 a = " << a << endl;
	cout << "mySwap03b = " << b << endl;
}

int main()
{
	int a = 10;
	int b = 20;
	mySwap01(a, b);//ֵ���ݣ��ββ�����ʵ��

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	mySwap02(&a, &b);//��ַ���ݣ��βλ�����ʵ��

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	mySwap03(a, b);//���ô��ݣ��βλ�����ʵ��
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}

#endif // 0

// ������ ��������ֵ
#if 0
//��Ҫ���ؾֲ����������ã�������������ֵ
//���ؾֲ���������
int& test01()
{
	int a = 10; //�ֲ����� �����ջ������test01ִ�й����ڴ���ͷ���
	return a;
}
//���ؾ�̬��������
int& test02()
{
	static int a = 20;//��̬�����������ȫ�������ڳ����������ϵͳ�ͷ�
	return a;
}


int main()
{

	//���ܷ��ؾֲ�����������
	int& ref = test01();
	cout << "ref = " << ref << endl;//��ִ��test02ʱ���ڴ���ͷ��ˣ�����һ����ȷ��ֵ���ò���
	cout << "ref = " << ref << endl;

	//�����������ֵ����ô���뷵������
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;//��a��ֵ1000��ref��a�ı���

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");

	return 0;
}

#endif // 0

//����
#if 0
//�����������ķ���ֵ����Ҫ���ؾֲ�����������
int& test01()
{
	int a = 10;
	return a;
}
int main()
{
	int& ref = test01();
	cout << ref << endl;
	cout << ref << endl;
	return 0;
}

#endif // 1

//����  ���ֵ�������
#if 0
int& test01()
{
	int a = 10;
	cout << a << endl;
	return a;
}

int main()
{
	int& ref = test01();//refǰ����& �����δ�ӡ������ȷ��
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;

	return 0;
}

#endif // 0

//���õı���  ָ�볣������ָ���ǳ�����ָ�򲻿ɸ��ģ�ֵ�ɸ���
#if 0
//���������ã�ת��Ϊ int* const ref = &a;
void func(int& ref)
{
	ref = 100; // ref�����ã�ת��Ϊ*ref = 100
}
int main()
{
	int a = 10;

	//�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref = a;
	ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);
	cout << "ref:" << ref << endl;//���ú�����������ʼ������ʹ�ã�
	return 0;
}


#endif // 1

//�������ã������βΣ���ֹ�����------------------------------
#if 0
void ShowValue(int &val)
{
	val = 1000;
	cout << "val= " << val << endl;
}

void ShowValue02(const int& val)
{
	//val = 1000;�������޸�
	cout << "val= " << val << endl;
}

int main()
{
	int a = 10;
	//int& ref = 10;//��������һ��Ϸ����ڴ�ռ�
	const int& ref = 10;//�������������޸�  int temp = 10; const int& ref = temp;�������Լ�����ԭ��temp
	//ref = 20;����const��Ϊֻ�� ָ�볣��

	ShowValue(a);
	ShowValue02(a);

	return 0;
}
#endif // 1

//������� ������Ĭ�ϲ���
//������������Ĭ�ϲ���������ʵ�ֲ�����Ĭ�ϲ���
#if 0
//�﷨�� ����ֵ���� ������ ������ = Ĭ��ֵ��{}
//������ʾ��Ĭ��ʵ�β����β��б�Ľ�β
int func(int a,int b = 20,int c= 30)//���ĳ��λ����Ĭ��ֵ����ô�����λ�����󣬴����Ҷ�����Ҫ��Ĭ��ֵ
{
	return a + b + c;
}
 
//����������
int func02(int a = 10, int b = 10);
int main()
{
	cout << func(10) << endl;
	cout << func(10,30) << endl;//��������Լ�������ֵ�������Լ������ݣ�û�У���Ĭ��ֵ
	cout << func02() << endl;
	return 0;
}

int func02(int a, int b)//���ﲻ�ܼ�Ĭ�ϲ���
{
	return a + b;
}



#endif // 1

//����ռλ����
#if 0
//�﷨������ֵ���� ������ ���������ͣ�{}
//Ŀǰ�ò���
//ռλ������������Ĭ�ϲ���
void func(int a, int)
//void func(int a, int =10)
{
	cout << "This is func " << endl;
}
int main()
{
	func(10, 20);

	return 0;
}
#endif // 1

//��������  ������������ͬ����߸�����
#if 0
//ͬһ����������
//������������ͬ
//�����������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
//��������ֵ��ͬ���ܺ�������
void func()
{
	cout << " func�ĵ��� " << endl;
}
void func(int a)
{
	cout << " func(int a)�ĵ��� " << endl;
}
void func(double a)
{
	cout << " func(double a)�ĵ��� " << endl;
}
void func(int a,double b)
{
	cout << " func(int a,double b)�ĵ��� " << endl;
}
void func(double b, int a)
{
	cout << " func(double b, int a)�ĵ��� " << endl;
}
int main()
{
	func();
	func(10);
	func(3.14);
	func(10,3.14);
	func(3.14,10);
	return 0;
}
#endif // 1

//��������+��������
//��������+Ĭ�ϲ���
#if 0
void func(int &a)//int &a = 10���Ϸ�
{
	cout << "func(int &a)�ĵ���" << endl;
}
void func(const int& a)//const int &a = 10;�Ϸ�
{
	cout << "func(const int& a)�ĵ���" << endl;
}

void func2(int a,int b = 20)
{
	cout << "func2(int a��int b = 20)�ĵ��� " << endl;
}
void func2(int a)
{
	cout << "func2(int a)�ĵ��� " << endl;
}

int main()
{
	int a = 10;
	func(a);//aΪ�������ɶ���д
	func(10);
	func2(10,20);
	//func2(10);  Ĭ�ϲ����������壬��֪���õ����ĸ�
	return 0;
}
#endif // 1

//�������
#if 0
//���һ��Բ�࣬��Բ���ܳ�
//�ܳ���ʽ��2 * PI *�뾶
//#define PI 3.14��
const double PI = 3.14;//ȫ�ֳ���

//class ����࣬+����
class Circle
{
	//����Ȩ��
	//����Ȩ��
public:
	//���� �뾶
	int m_r;
	//��Ϊ ��Բ���ܳ�
	double calculateZC()
	{
		return 2 * PI * m_r;
	}
};

int main()
{
	//ͨ��Բ�� ���������Բ������
	//ʵ���� ��ͨ��һ���� ����һ������Ĺ��̣�
	Circle cl;
	//��Բ���� �����Խ��и�ֵ
	cl.m_r = 10;
	//2*3.14*10=62.8
	cout << "Բ���ܳ�Ϊ�� " << cl.calculateZC() << endl;

	return 0;
}
#endif // 1

//���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
#if 0
class Student
{
public:
	//��Ա����
	
	//����
	string m_name;
	//ѧ��
	int m_id;
	//��ʾ����ѧ��

public:
	//��Ա����
	void ShowStudent()
	{
		cout << "������ " << m_name << "   ѧ�ţ�" << m_id << endl;
	}

	void setname(string name)
	{
		m_name = name;
	}
	void setid(int id)
	{
		m_id = id;
	}
};


int main()
{
	Student s1;
	s1.m_name = "����";
	s1.m_id = 1;
	s1.ShowStudent();

	Student s2;
	s2.setname("����");
	s2.setid(2);
	s2.ShowStudent();
	
	return 0;
}
#endif // 1

//public ���� protected ���� private ˽��
#if 0
//����Ȩ��
//����Ȩ��  public     ���ڿ��Է���  ������Է���
//����Ȩ��  protected  ���ڿ��Է���  ���ⲻ���Է���
//˽��Ȩ��  private    ���ڿ��Է���  ���ⲻ���Է���

class Person
{
	//����  ����Ȩ��
public:
	string m_Name;

	//����  ����Ȩ��
protected:
	string m_Car;

	//���п�����  ˽��Ȩ��
private:
	int m_Password;

public:
	void func()
	{
		m_Name = "����";
		m_Car = "������";
		m_Password = 123456;
	}
};

int main() {

	Person p;
	p.m_Name = "����";
	//p.m_Car = "����";  //����Ȩ��������ʲ���
	//p.m_Password = 123; //˽��Ȩ��������ʲ���

	return 0;
}
#endif // 1

//classĬ��˽��  structĬ�Ϲ���
#if 0

class C1
{
	int  m_A; //Ĭ����˽��Ȩ��
};

struct C2
{
	int m_A;  //Ĭ���ǹ���Ȩ��
};

int main() {

	C1 c1;
	c1.m_A = 10; //���󣬷���Ȩ����˽��

	C2 c2;
	c2.m_A = 10; //��ȷ������Ȩ���ǹ���

	return 0;
}

#endif // 1

//��Ա��������Ϊ˽��
#if 0
class Person 
{
public:
	//�������ÿɶ���д
	void setName(string name) {  			// д���в���
		m_Name = name;
	}
	string getName()    				// �����޲���
	{
		return m_Name;
	}

	//��ȡ���� 
	int getAge() {      				// ��
		return m_Age;
	}
	//��������
	void setAge(int age) {				// д
		if (age < 0 || age > 150) {
			cout << "���������!" << endl;
			return;
		}
		m_Age = age;
	}

	//��������Ϊֻд
	void setLover(string lover) {			// д
		m_Lover = lover;
	}

private:
	string m_Name; //�ɶ���д  ����
	int m_Age; 	//ֻ��  ����
	string m_Lover; //ֻд  ����
};


int main() {
	Person p;
	//��������
	p.setName("����");
	cout << "������ " << p.getName() << endl;

	//��������
	p.setAge(50);
	cout << "���䣺 " << p.getAge() << endl;

	//��������
	p.setLover("�Ծ�");
	//cout << "���ˣ� " << p.m_Lover << endl;  //ֻд���ԣ������Զ�ȡ

	return 0;
}
#endif // 1

//�����������(Cube)  ������������������  �ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
#if 0
class Cube
{
	
public:
	//��ȡ���� ������� �����
	void setL(int L)
	{
		m_L = L;
	}
	int getL()
	{
		return m_L;
	}

	void setW(int W)
	{
		m_W = W;
	}
	int getW()
	{
		return m_W;
	}

	void setH(int H)
	{
		m_H = H;
	}
	int getH()
	{
		return m_H;
	}

	//���㳤������������
	double Cube_S()
	{
		return (m_L * m_H + m_L * m_W + m_H * m_W) * 2;
	}

	double Cube_V()
	{
		return m_L * m_H * m_W;
	}

	//�ж����������Ƿ����
	bool equal_cube(Cube &c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		return false;
	}

private:
	double m_L;
	double m_H;
	double m_W;

};
 
bool equal_Cube(Cube& c1, Cube& c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.setL(10.0);
	c1.setW(10.0);
	c1.setH(10.0);
	cout << "c1����� " << c1.Cube_S() << endl;
	cout << "c1����� " << c1.Cube_V() << endl;
	cout << endl;

	Cube c2;
	c2.setL(20.0);
	c2.setW(20.0);
	c2.setH(20.0);
	cout << "c2����� " << c2.Cube_S() << endl;
	cout << "c2����� " << c2.Cube_V() << endl;

	bool ret = equal_Cube(c1, c2);//ȫ�ֺ�����Ҫ������������

	if (ret)
	{
		cout << "c1��c2����ȵ�" << endl;
	}
	else
	{
		cout << "c1��c2�ǲ���ȵ�" << endl;
	}

	ret = c1.equal_cube(c2);//��Ա������ֻ�����һ�������ͺ�

	if (ret)
	{
		cout << "c1��c2����ȵ�" << endl;
	}
	else
	{
		cout << "c1��c2�ǲ���ȵ�" << endl;
	}

	return 0;
}
#endif // 1

//���һ��Բ���ࣨCircle������һ�����ࣨPoint����������Բ�Ĺ�ϵ��//Բ�ڣ�Բ�ϣ�Բ��
#if 0
//class Point
//{
//public:
//	//���û�ȡ���X����
//	void setX(int x)
//	{
//		m_x = x;
//	}
//	int getX()
//	{
//		return m_x;
//	}
//
//	//���û�ȡ���X����
//	void setY(int y)
//	{
//		m_y = y;
//	}
//	int getY()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//
//class circle//Բ��
//{
//public:
//	//��ȡ�뾶
//	void setR(int r)
//	{
//		m_r = r;
//	}
//	int getR()
//	{
//		return m_r;
//	}
//
//	//��ȡԲ�ĵ�����
//	void setCenter(Point center)
//	{
//		m_center = center;
//	}
//	Point getCenter()//---------------------------------------------------------!!!
//	{
//		return m_center;
//	}
//	
//private:
//	//�뾶
//	int m_r;
//	//Բ��
//	Point m_center;
//};

	//��������֮��ľ����ƽ��
void weizhi(circle& c, Point& p)
{
	int disdance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	cout << disdance << endl;
	int rdistance = c.getR() * c.getR();
	cout << rdistance << endl;
	if (disdance > rdistance)
	{
		cout << " ����Բ�� " << endl;
	}
	else if(disdance = rdistance)
	{
		cout << " ����Բ�� " << endl;
	}
	else if (disdance < rdistance)
	{
		cout << " ����Բ�� " << endl;
	}
}

int main()
{
	//����Բ�͵�
	circle c;
	Point p;

	Point center;
	c.setR(10);
	center.setX(0);
	center.setY(0);
	c.setCenter(center);

	p.setX(0);
	p.setY(1);
	

	weizhi(c, p);

	return 0;
}
#endif // 1

//��дABBѭ������
#if 0

void test01()
{
	ofstream ofs;
	ofs.open("D:\\study\\vs_text\\test.txt", ios::out);

	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	ofs.close();
}

void test02()
{
	int i = 0;
	ofstream ofs;
	ofs.open("D:\\study\\vs_text\\test0503.txt", ios::out);

	
	//ofs << "path 10" << endl;
	//ofs << "MoveL Offs(Target_10,0,i+k,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//for (int i = 20; i < 150; i = i + 10)
	//{
	//	ofs << "MoveL Offs(Target_" << i << ",0,i+k,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	//}
	//ofs << "MoveL Offs(Target_150,0,i+k,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//ofs << endl;
	//
	//ofs << "path 20" << endl;
	//ofs << "MoveL Offs(Target_160,0,i+k,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//for (int i = 170; i < 300; i = i + 10)
	//{
	//	ofs << "MoveL Offs(Target_" << i << ",0,i+k,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	//}
	//ofs << "MoveL Offs(Target_300,0,i+k,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//ofs << endl;


	//ofs << "path 30" << endl;
	//ofs << "MoveL Offs(Target_310,0,i+k,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//for (int i = 320; i < 450; i = i + 10)
	//{
	//	ofs << "MoveL Offs(Target_" << i << ",0,i+k,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	//}
	//ofs << "MoveL Offs(Target_450,0,i+k,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//ofs << endl;

	//ofs << "path 40" << endl;
	//ofs << "MoveL Offs(Target_460,0,i+k,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//for (int i = 470; i < 600; i = i + 10)
	//{
	//	ofs << "MoveL Offs(Target_" << i << ",0,i+k,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	//}
	//ofs << "MoveL Offs(Target_600,0,i+k,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//ofs << endl;

	//ofs << "path 50" << endl;
	//ofs << "MoveL Offs(Target_610,0,i,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//for (int i = 620; i < 840; i = i + 10)
	//{
	//	ofs << "MoveL Offs(Target_" << i << ",0,i,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	//}
	//ofs << "MoveL Offs(Target_840,0,i,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//ofs << endl;

	//ofs << "path 60" << endl;
	//ofs << "MoveL Offs(Target_850,0,i,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//for (int i = 860; i < 1080; i = i + 10)
	//{
	//	ofs << "MoveL Offs(Target_" << i << ",0,i,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	//}
	//ofs << "MoveL Offs(Target_1080,0,i,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//ofs << endl;

	//ofs << "path 70" << endl;
	//ofs << "MoveL Offs(Target_2080,0,i+0.25,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//for (int i = 2090; i < 2310; i = i + 10)
	//{
	//	ofs << "MoveL Offs(Target_" << i << ",0,i+0.25,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	//}
	//ofs << "MoveL Offs(Target_2310,0,i+0.25,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//ofs << endl;

	//ofs << "path 80" << endl;
	//ofs << "MoveL Offs(Target_2320,0,i,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//for (int i = 2330; i < 2550; i = i + 10)
	//{
	//	ofs << "MoveL Offs(Target_" << i << ",0,i,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	//}
	//ofs << "MoveL Offs(Target_2550,0,i,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	//ofs << endl;

	//95
	ofs << "movel offs(target_2000,-2,-2.25+14,0),v,fine,mynewpen\\wobj:=workobject_1;" << endl;
	for (int i = 1990; i > 1940; i = i - 10)
	{
		ofs << "movel offs(target_" << i << ",-2,-2.25+14,0),v,z5,mynewpen\\wobj:=workobject_1;" << endl;
	}
	ofs << "movel offs(target_1940,-2,-2.25+14,0),v,fine,mynewpen\\wobj:=workobject_1;" << endl;
	ofs << endl;

	//96
	ofs << "MoveL Offs(Target_2070,-2,-2.25+14,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	for (int i = 2060; i > 2010; i = i - 10)
	{
		ofs << "MoveL Offs(Target_" << i << ",-2,-2.25+14,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	}
	ofs << "MoveL Offs(Target_2010,-2,-2.25+14,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	ofs << endl;

	//90
	ofs << "MoveL Offs(Target_1150,-2,14,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	for (int i = 1140; i >1090; i = i - 10)
	{
		ofs << "MoveL Offs(Target_" << i << ",-2,14,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	}
	ofs << "MoveL Offs(Target_1090,-2,14,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	ofs << endl;

	//91
	ofs << "MoveL Offs(Target_1220,-2,14,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	for (int i = 1210; i > 1160; i = i - 10)
	{
		ofs << "MoveL Offs(Target_" << i << ",-2,14,0),v,z5,Mynewpen\\WObj:=Workobject_1;" << endl;
	}
	ofs << "MoveL Offs(Target_1160,-2,14,0),v,fine,Mynewpen\\WObj:=Workobject_1;" << endl;
	ofs << endl;

	ofs.close();
}


void test03()
{
	ofstream ofs;
	ofs.open("D:\\LCEDA\\123\\111.txt", ios::out);

	ofs << "copy/b ";
	ofs << "kye0" ;
	for (int  i = 0; i < 155 ; i++)
	{
		ofs << "+" << "Y2hlbmppbmdjb25n" << i;
	}
	ofs << " new.ts";
	ofs.close();
	cout << "1" << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
#endif // 1

//���캯������������
#if 0
class person
{
public:
	person()
	{
		cout << "This is ���캯��" << endl;
	}
	~person()
	{
		cout << "This is ��������" << endl;
	}
};


void test01()
{
	person p;
}

int main()
{
	test01();

	return 0;
}
#endif // 1

//���캯���ķ��࣬�����ǳ����
#if 0
int main()
{


	return 0;
}
#endif  //δ��д

//�����ʼ�� �� ��ʼ���б�
#if 0

class person
{

public:
	//��Ա����
	person(int a, int b, int c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}

	
	//��Ա����
	int m_a;
	int m_b;
	int m_c;

};
class cube
{
public:
	cube(int a, int b, int c) :c_a(a), c_b(b), c_c(c) {};
	void printpersson()
	{
		cout << "c_a= " << c_a << endl;
		cout << "c_b= " << c_b << endl;
		cout << "c_c= " << c_c << endl;
	}
	 
private:
	int c_a;
	int c_b;
	int c_c;
};

void test01()
{
	person p(10, 20, 30);
	//p.printpersson();
	cout << "m_a= " << p.m_a << endl;
	cout << "m_b= " << p.m_b << endl;
	cout << "m_c= " << p.m_c << endl;
}

void test02()
{
	cube c(1, 2, 3);
	c.printpersson();
	
}

int main()
{
	test01();
	cout << endl;
	test02();
	return 0;
}
#endif // 1

//c++ ���еĳ�Ա������ ��һ����Ķ���  �ĳ�Ա��  �����Ա
#if 0
//class A {};
//class B { A b;};
//B���� �ж���A ��Ϊ��Ա ����Aδ�����Ա

class phone
{
	
public:
	//���캯��
	phone()
	{

	}
	//��ʼ�� 
	phone(string p_name):pname(p_name)
	{

	}

//private:
	string pname;
};

class people
{
public:
	people()
	{

	}
	//��Ա�к�����Ķ���ĳ�ʼ��
	people(string input_name,string input_pname):name(input_name),PhoneName(input_pname)
	{

	}

	void showpeople()
	{
		cout << "run" << endl;
		cout << name << "ʹ�ã� " << PhoneName.pname << "�ֻ�" << endl;
	}

private:
	string name;
	phone PhoneName;
};

void test01()
{
	people p("����", "С��");
	p.showpeople();
}

int main()
{
	test01();

	return 0;
}
#endif // 1

//��̬��Ա����
#if 0
//��̬��Ա�����ǹ����
//��̬��Ա����ֻ�ܷ��ʾ�̬����

class person
{
public:
	static int m_a;
	int m_b = 1;
	static void func()
	{
		
		m_a = 500;
		//m_b = 2;//�Ǿ�̬���������ܵ���
		cout << m_a << endl;
		cout << "static void func�ĵ���" << endl;
	}

private:
	static void func2()
	{
		cout << "static void func2�ĵ���" << endl;
	}


};
int person::m_a = 100;

void test01()
{
	//��̬��Ա�����ĵ���
	person p;
	p.func();

	person::func();
	//person::func2();//��̬�����ĵ���Ҳ��Ȩ��
	
}


int main()
{
	test01();

	return 0;
}
#endif // 1

//this ָ��-----------------------------û���
#if 0
//���βκͳ�Ա����ͬ��ʱ������thisָ��������
//��ʹ��return *this

class person
{
public:
	person(int age)
	{
		this->age = age;
	}

	int age;

	person & personaddage(person p1)
	{
		age += p1.age;

		return *this;
	}
};
void test01()
{
	person p1(18);
	cout << "p1����ͣ� " << p1.age << endl;
}

void test02()
{
	person p2(10);

	person p3(10);

	cout << "p3�����䣺 " << p3.age << endl;
}

void test03()
{
	person p2(10);

	person p3(10);

	p3.personaddage(p2).personaddage(p2).personaddage(p2);

	cout << "p3�����䣺 " << p3.age << endl;
		
}

int main()
{
	test01();
	//test02();
	test03();
	return 0;
}
#endif // 1

//��ָ����ó�Ա����������Ҫ��
#if 0

class person
{
public:
	void showclassname()
	{
		cout << "This is person class." << endl;
	}

	void showage()
	{
		//��֤����Ľ�׳��
		if (this == NULL)
		{
			return;
		}

		cout << "age is: " << this->m_Age << endl;
	}
	int m_Age;
};

void test01()
{
	person * P = NULL;//----------------
	
	P->showclassname();
	P->showage();
}

int main()
{
	test01();

	return 0;
}
#endif // 1

//const���γ�Ա����
#if 0
//������
class person
{
public:
	//this ָ��ı����� ָ�볣�� ��ָ���ָ���ǲ������޸ĵ�
	//const person * const this;
	//�ڳ�Ա���������const ,���ε���this, ʹָ��ָ���ֵҲ�����޸�
	void showclass() const
	{
		this->m_b = 100;

		//this->m_a = 100;
		//this = NULL;//this ָ�벻���޸�ָ���ָ���
	}
	void func()
	{
		m_a = 100;
	}
	int m_a;
	mutable int m_b;
};

void test01()
{
	person p;
	p.showclass();
}

//������
void test02()
{
	const person p;//�ڶ���ǰ��const ��ɳ�����
	p.m_b = 100;//m_bΪ����ֵ����������Ҳ�����޸�ֵ
	//p.m_a = 100;
	p.showclass();
	//p.func();//�����󲻿ɵ�����ͨ��Ա���� ����ͨ��Ա���������޸�����
}

int main()
{
	test01();

	return 0;
}
#endif  //

//��Ԫ������ʵ��  ȫ�ֺ���
#if 0

class Building
{
	friend void goodGay(Building& building);
public:
	string m_SittingRoom;

	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}

private:
	string m_BedRoom;
};

//ȫ�ֺ��� ����ճ�������м��� ǰ��friend ��������Ԫ������
void goodGay(Building& building)
{
	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ� " << building.m_SittingRoom << endl;
	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��ʣ� " << building.m_BedRoom << endl;
}

int main()
{
	Building building;
	goodGay(building);

	return 0;
}
#endif  //

//������Ԫ
#if 0

class Building;
class goodGay
{
public:	
	goodGay();//���캯��

	void visit();//�ιۺ��� ����building �ĺ���

private:
	Building* building;//�����õģ� �ڲ�ά��һ��ָ��
};

class Building
{
	//���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
	friend class goodGay;
public:
	string m_SittingRoom;
	Building();//��ʼ��
private:
	string m_BedRoom;
};

//����д��Ա����
Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}
goodGay::goodGay()
{
	building = new Building;	// ��������һ������buliding���ն����ַ
}

void goodGay::visit()//--------��Ա������������ �� ���캯��  �Ĳ�ͬ
{
	cout << "�û������ڷ��ʣ� " << building->m_BedRoom << endl;
	cout << "�û������ڷ��ʣ� " << building->m_SittingRoom << endl;
}
void test01()
{
	goodGay gg;
	gg.visit();
}

int main()
{
	test01();

	return 0;
}
#endif  //

//��Ա��������Ԫ
#if 0
class Building;
class goodGay
{
public:
	goodGay();//���캯��
	void visit();//
	void visit2();//���ɷ���building��˽�г�Ա
private:
	Building* building;
};
class Building
{
	friend void goodGay::visit();
public:
	Building();//���캯��

public:
	string m_SittingRoom;
private:
	string m_BedRoom;

};

goodGay::goodGay()
{
	building = new Building;
}
Building::Building()
{
	m_SittingRoom = "����";
	m_BedRoom = "����";
}
void goodGay::visit()
{
	cout << "���ʣ� " << building->m_SittingRoom << endl;
	cout << "���ʣ� " << building->m_BedRoom << endl;
}
void goodGay::visit2()
{
	cout << "2���ʣ� " << building->m_SittingRoom << endl;
}
void test01()
{
	goodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{
	test01();

	return 0;
}
#endif  //

//��������أ�+)  ��Ա��������
#if 0
class Person
{
public:
	Person() ;//���캯��
	Person operator+(Person& p)
	{
		Person temp;
		temp.m_a = this->m_a + p.m_b;
		temp.m_b = this->m_b + p.m_b;
		return temp;
	};
public:
	int m_a;
	int m_b;
};
Person:: Person()
{
	m_a = 10;
	m_b = 10;
}
//Person operator+(const Person& p)
//{
//	Person temp;
//	temp.m_a = this->m_a + p.m_b;
//	temp.m_b = this->m_b + p.m_b;
//	return temp;
//}

void test01()
{
	Person p1;
	Person p2;

	Person p3;
	p3 = p1 + p2;

	cout << p1.m_a << endl;
	cout << p1.m_b << endl;

	cout << p2.m_a << endl;
	cout << p2.m_b << endl;

	cout << p3.m_a << endl;
	cout << p3.m_b << endl;
}


int main()
{
	test01();

	return 0;
}
#endif  //

//ȫ�ֺ�������
#if 0
int main()
{


	return 0;
}
#endif  //


//�����ѧϰ  �ṹ������Ļ��
#if 0

class List {
public:
	List() { create_List(); }
	~List() { clear(); }
	//����ͷ���
	void create_List();
	//���뺯��
	void insert(const int& d);
	//��ָ��λ�ò���
	void insert_pos(const int& d, const int& d1);
	//ɾ��ָ�����ݵĽڵ�
	void erase(const int& d);
	//�޸�ָ������
	void updata(const int& d, const int& d1);
	//��ת������
	void reverse();
	//��ӡ
	void print();
private:
	//�ڵ�ṹ
	struct Node {
		int data;
		Node* next;
		Node(const int& d) :data(d), next(NULL) {}//----------������ָ������γ�ʼ���ģ�
	};
	Node* head;//ͷ�ڵ�
	//����������
	void clear() {
		Node* p = head;
		//��ͷ�ڵ㿪ʼѭ��ɾ��
		while (p) {
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	//��������d����һ���ڵ�λ�õĺ���
	//Ϊ�˷������ɾ������
	Node* find(const int& d) {
		Node* p = head;
		for (; p; p = p->next) {
			if (p->next->data == d)
				break;
		}
		return p;
	}
};

//����ͷ���
void List::create_List()
{
	head = new Node(0);//�������0��ʾɶ������d����һ��ָ��ΪNULL��������ͷ��㣬���0
}
//��ͷ����һ���ڵ�
void List::insert(const int& d)
{
	Node* p = new Node(d);
	p->next = head->next;
	head->next = p;
}
//��ӡ����
void List::print()
{
	for (Node* p = head->next; p; p = p->next) {
		cout << p->data << endl;
	}
}
//��dλ��֮ǰ����d1
void List::insert_pos(const int& d, const int& d1)
{
	Node* p = find(d);
	Node* q = new Node(d1);
	q->next = p->next;
	p->next = q;
}

//ɾ��
void List::erase(const int& d)
{
	Node* p = find(d);
	//��Ϊp����һ���ڵ��λ�ã���q������
	//Ҫɾ���Ľڵ�ĵ�ַ
	Node* q = p->next;
	//ͨ������һ���ڵ��nextָ��ָ��Ҫɾ���ڵ��nextָ
	//��־��Ľڵ�ʵ�ֶϿ�Ҫɾ���ڵ��Ŀ��
	p->next = p->next->next;
	//ɾ��Ҫɾ���Ľڵ�q
	delete q;
}

//�޸�ָ������
void List::updata(const int& d, const int& d1)
{
	Node* p = find(d);
	p->next->data = d1;
}

//��ת����
void List::reverse()
{
	Node* p = head->next;//ͷ���֮��ĵ�1���ڵ�
	Node* q = head->next->next;//ͷ���֮��ĵ�2�ڵ�
	Node* m = head->next->next->next;//ͷ���֮��ĵ�3���ڵ�
	p->next = NULL;//��ͷ�ӵ�֮��ĵ�1���ڵ��nextָ����Ϊ��
	//����m�Ƿ�Ϊ�����ж� �Դ�����ÿһ���ڵ�
	while (m) {
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	//�����һ���ڵ�����
	q->next = p;
	//��ͷ����ָ���µĵĵ�1���ڵ�(֮ǰ�����һ���ڵ�)
	head->next = q;
}

int main(int argc, const char* argv[])
{

	// insert code here...
	List list;
	list.insert(30);
	list.insert(20);
	list.insert(10);
	list.insert_pos(10, 5);
	list.print();
	cout << "---------------------" << endl;
	list.erase(10);
	list.print();
	cout << "---------------------" << endl;
	list.reverse();
	list.print();
	cout << "---------------------" << endl;
	list.updata(5, 8);
	list.print();
	return 0;
}

#endif  //

//STL��ʶ
#if 0
//�������������������װ���̳С���̬
//��׼ģ���
//�������㷨ͨ������������
//�������㷨�����������º��������������ռ�������

void myPrint(int val) {
	cout << val << endl;
}

void test01() {
	//����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ����ݵ�����
	vector<int> v;
	//�������з�����
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//ÿһ�����������Լ��ĵ����������������������������е�Ԫ��

	//��һ�ֱ�����ʽ
	if (0)
	{
		vector<int>::iterator itBegin = v.begin();//��ʼ������ ָ�������еĵ�һ��Ԫ��
		vector<int>::iterator itEnd = v.end();//����������  ָ�����һ��Ԫ�ص���һ��λ��

		while (itBegin != itEnd)
		{
			cout << *itBegin << endl;
			itBegin++;
		}
	}



	//�ڶ��ֱ�����ʽ
	if (0)
	{
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}
	}

	//�����ֱ�����ʽ  �ñ�׼�㷨��
	if (1)
	{
		for_each(v.begin(), v.end(), myPrint);	
	}

}
int main()
{
	test01();

	return 0;
}
#endif  //

//vector �����д���Զ������������
#if 0
class Person
{
public:
	//Ĭ�Ϲ��캯��
	Person() {};
	//��ֵ���캯��
	Person(string _name, int _age) {
		m_name = _name;
		m_age = _age;
	}
	//��������
	~Person() {};
public:
	string m_name;
	int m_age;

};

void test01() {

	vector<Person>v;

	//����5�������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//��������������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//������������ӡ�����Ϣ
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "������ " << (*it).m_name << " ���䣺 " << (*it).m_age << endl;
	}
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "-������ " << it->m_name << " -���䣺 " << it->m_age << endl;
	}
	
}

void test02() {

	vector<Person *>v;//�����д��p1-p5�ĵ�ַ

	//����5�������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//��������������
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);


	for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "*������ " << (*it)->m_name << " *���䣺 " << (*it)->m_age << endl;
	}
}

int main()
{
	test01();
	test02();

	return 0;
}
#endif  //

//������Ƕ������
#if 0
void test01() {
	vector<vector<int>> v;

	//����4��С����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	//С���������Ԫ��
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//��С������ӵ���������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//ͨ�������� ���� ��������
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end() ; it++)
	{
		for (vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			cout << *itt << " ";
		}
		cout << endl;
	}
}
int main()
{
	test01();

	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //


//
#if 0
int main()
{


	return 0;
}
#endif  //