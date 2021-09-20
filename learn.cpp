#include<iostream>
#include <string>
#include"circle.h"
#include"point.h"
#include <fstream>
#include<vector>
#include<algorithm>//标准算法库
using namespace std;

//通讯录管理系统
#if 0
constexpr auto MAX = 1000;//-------------------------疑问
//1、显示通讯录目录
//2、退出通讯录
//3、添加通讯录
//4、显示通讯录
//5、查找

//显示目录
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加通讯录 *****" << endl;
	cout << "***** 2.显示通讯录 *****" << endl;
	cout << "***** 3.删除通讯录 *****" << endl;
	cout << "***** 4.查找通讯录 *****" << endl;
	cout << "***** 5.修改通讯录 *****" << endl;
	cout << "***** 6.清空通讯录 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}

//联系人结构体
struct person
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

//通讯录结构体
struct addrbook
{
	struct person;
	int num;
};

//添加通讯录
void addperson(person *p_array,int num)
{

	cout << "请输入姓名： " << endl;
	cin >> p_array[num].name;
	cout << "请输入性别： " << endl << "1 男 " << endl << "2 女 " << endl;
	cin >> p_array[num].sex;
	cout << "请输入年龄： " << endl;
	cin >> p_array[num].age;
	cout << "请输入联系方式： " << endl;
	cin >> p_array[num].phone;
	cout << "请输入家庭住址： " << endl;
	cin >> p_array[num].addr;
}

//显示通讯录
void showperson(person* p_array, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "姓名：\t" << p_array[i].name << "\t性别：" << (p_array[i].sex == 1 ? "男" : "女") << "\t年龄：\t" << p_array[i].age 
			<< "\t联系方式：" << p_array[i].phone << "\t家庭住址：" << p_array[i].addr << endl;
	}
	
}

//查找通讯录
int findperson(person* p_array, int num)
{
	int t = -1;
	string name = "0000";
	cout << "请输入姓名： " << endl;
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

//显示单个通讯录
void showone(person* p_array, int t)
{
	cout << "姓名：\t" << p_array[t].name << "\t性别：" << (p_array[t].sex == 1 ? "男" : "女") << "\t年龄：\t" << p_array[t].age
		<< "\t联系方式：\t" << p_array[t].phone << "\t家庭住址：" << p_array[t].addr << endl;
}

//删除单个通讯录-----------------------------------------不用删除，直接用下一个数据替代
void deleteperson(person* p_array, int find,int num)
{
	//p_array[find].name = "0";
	//p_array[find].sex = 0;
	//p_array[find].age = 0;
	//p_array[find].phone = "0";
	//p_array[find].addr = "0";-------------------------用temp删除，不要一个一个赋值
	
	for (int i = find; i <= num; i++)
	{
		p_array[i].name = p_array[i + 1].name;
		p_array[i].sex  = p_array[i + 1].sex;
		p_array[i].age  = p_array[i + 1].age;
		p_array[i].phone = p_array[i + 1].phone;
		p_array[i].addr = p_array[i + 1].addr;
	}
}

//清空通讯录
void clearperson(person* p_array, int num)
{
	for (int i = 0; i <= num; i++)
	{
		person temp = { "0", 0, 0, "0", "0" };
		p_array[i] = temp;

	}
}

//修改通讯录
void corperson(person* p_array, int find)
{

	cout << "请输入姓名： " << endl;
	cin >> p_array[find].name;
	cout << "请输入性别： " << endl << "1 男 " << endl << "2 女 " << endl;
	cin >> p_array[find].sex;
	cout << "请输入年龄： " << endl;
	cin >> p_array[find].age;
	cout << "请输入联系方式： " << endl;
	cin >> p_array[find].phone;
	cout << "请输入家庭住址： " << endl;
	cin >> p_array[find].addr;
}


int main()
{

	//结构体数组
	struct person p_array[MAX];
	int num = 0;//初始化数据


	while (true)
	{
		showMenu();
		int input = 0;
		int find = 0;
		cin >> input;

		switch (input)
		{
		case 1:
			//先判断空间是否为满
			if (num == MAX)
			{
				cout << "通讯录空间已满" << endl;

			}
			else
			{
				addperson(&p_array[0], num);
			}
			num++;
			cout << "通讯录添加成功！" << endl;
			//system("cls");
			break;
		case 2:
			if (num == 0)
			{
				cout << "通讯录为空！" << endl;
			}
			else
			{
				showperson(&p_array[0], num);
			}
			break;
		case 3:
			if (num == 0)
			{
				cout << "通讯录为空！" << endl;
			}
			else
			{
				find = findperson(&p_array[0], num);
				if (find == -1)
				{
					cout << "未找到该联系人！" << endl;
				}
				else
				{
					deleteperson(&p_array[0], find, num);
					//通讯录重新排序
					num--;
					cout << "成功删除该联系人！" << endl;
				}
			}
			break;
		case 4:
			if (num == 0)
			{
				cout << "通讯录为空！" << endl;
			}
			else
			{
				find = findperson(&p_array[0], num);
				if (find == 0)
				{
					cout << "未找到该联系人！" << endl;
				}

				showone(&p_array[0], find);
			}
			break;
		case 5:
			//先查找
			//再填写
			if (num == 0)
			{
				cout << "通讯录为空！" << endl;
			}
			else
			{
				find = findperson(&p_array[0], num);//返回的t值
				if (find == 0)
				{
					cout << "未找到该联系人！" << endl;
				}

				showone(&p_array[0], find);
				corperson(&p_array[0], find);
			}
			break;
		case 6:
			if (num == 0)
			{
				cout << "通讯录为空！" << endl;
			}
			else
			{
				clearperson(&p_array[0], num);
				num = 0;
			}
			cout << "通讯录已清空" << endl;
			break;
		case 0:
			cout << "成功退出通讯录" << endl;
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

//全局变量、静态变量、全局常量
#if 0

//代码区：存放二进制代码（共享、只读）
//全局区：全局变量、静态变量、常量（字符串常量、const修饰的全局变量即全局常量）       由操作系统释放 
//以上， 程序运行前就有的

//栈区、堆区

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

	cout << "局部变量a的地址为： " << (int)&a << endl;
	cout << "局部变量b的地址为： " << (int)&b << endl;

	cout << "全局变量g_a的地址为： " << (int)&g_a << endl;
	cout << "全局变量g_b的地址为： " << (int)&g_b << endl;

	//静态变量 在普通变量前+static，属于静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a的地址为： " << (int)&s_a << endl;
	cout << "静态变量s_b的地址为： " << (int)&s_b << endl;

	//字符串常量 
	cout << "字符串常量的地址为： " << (int)&"hello world" << endl;

	//const修饰的变量 (局部）（全局）c-const g-gloa l-

	cout << "全局常量c_g_a的地址为： " << (int)&c_g_a << endl;
	cout << "全局常量c_g_b的地址为： " << (int)&c_g_b << endl;

	cout << "局部常量c_l_a的地址为： " << (int)&c_l_a << endl;
	cout << "局部常量c_l_b的地址为： " << (int)&c_l_b << endl;

	return 0;
}



#endif // 0

//栈区  局部变量 形参
#if 0

//栈区 编译器自动分配释放 函数的参数、局部变量
//---------不要返回局部变量的地址

int* func(int b)
{
	b = 10;
	int a = 10;//局部变量，存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;//返回局部变量的地址
}

int main()
{
	int* p = func(1);

	cout << *p << endl;//第一次可以打印，编译器做了保存
	cout << *p << endl;//第二次不保存

	return 0;
}
#endif// 0 

//堆区 new
#if 0
//堆区 由程序员分配释放
//利用new在堆区开辟数据
//指针 本质也是局部变量，放在栈上，指针保存的数据是放在堆区的
//main函数没有执行完，指针的数据不会释放
int* func()
{
	int *p = new int(10);//这里返回的是数据地址的编号，用指针去接收
	return p;//返回指针的地址
}
int main()
{
	int *p = func();

	cout << *p << endl;
	cout << *p << endl;

	return 0;
}
#endif // 0

//堆区 new 释放 delete
#if 0
//new的基本语法，用delete释放空间
//在堆区利用new开辟数组，返回数据对应的类型指针

int* func()
{
	//在堆区创建整型数据
	//new返回的是 该数据类型的指针
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
	//堆区的数据，由程序员开辟，程序员释放，用delete释放
	delete p;
	//cout << *p << endl;//内存已被释放，再次访问就是非法操作，会报错
}

void test1()
{
	int* arr = new int[10];//10为数组的数据个数为10

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//释放堆区数组 需要加[]
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

//引用
#if 0
//给一个变量起别名
//int a =10;

//数据类型 &别名 = 原名
//int &b = a;

//b = 20;
//cout<<a<<endl;

//引用必须要初始化-------------------------------------
//int &b;-------这是错误的

//引用一旦初始化，就不可更改


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

//引用做函数参数，让形参修饰实参，简化指针修改实参
#if 0
//交换函数
//1、值传递

void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

	cout << "mySwap01 a = " << a << endl;
	cout << "mySwap01 b = " << b << endl;
}

//2、地址传递

void mySwap02(int *a,int *b)//a指向的 单元的 数值
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3、引用传递

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
	mySwap01(a, b);//值传递，形参不修饰实参

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	mySwap02(&a, &b);//地址传递，形参会修饰实参

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	mySwap03(a, b);//引用传递，形参会修饰实参
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}

#endif // 0

// 引用做 函数返回值
#if 0
//不要返回局部变量的引用，函数可以做左值
//返回局部变量引用
int& test01()
{
	int a = 10; //局部变量 存放在栈区，在test01执行过后，内存就释放了
	return a;
}
//返回静态变量引用
int& test02()
{
	static int a = 20;//静态变量，存放在全局区，在程序结束后，由系统释放
	return a;
}


int main()
{

	//不能返回局部变量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl;//在执行test02时，内存就释放了，这里一个正确的值都得不到
	cout << "ref = " << ref << endl;

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;//给a赋值1000，ref是a的别名

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");

	return 0;
}

#endif // 0

//补充
#if 0
//引用做函数的返回值，不要返回局部变量的引用
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

//补充  发现的新问题
#if 0
int& test01()
{
	int a = 10;
	cout << a << endl;
	return a;
}

int main()
{
	int& ref = test01();//ref前不加& 则两次打印都是正确的
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;

	return 0;
}

#endif // 0

//引用的本质  指针常量：该指针是常量，指向不可更改，值可更改
#if 0
//发现是引用，转换为 int* const ref = &a;
void func(int& ref)
{
	ref = 100; // ref是引用，转换为*ref = 100
}
int main()
{
	int a = 10;

	//自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int& ref = a;
	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);
	cout << "ref:" << ref << endl;//引用函数可以做初始化函数使用！
	return 0;
}


#endif // 1

//常量引用，修饰形参，防止误操作------------------------------
#if 0
void ShowValue(int &val)
{
	val = 1000;
	cout << "val= " << val << endl;
}

void ShowValue02(const int& val)
{
	//val = 1000;不允许修改
	cout << "val= " << val << endl;
}

int main()
{
	int a = 10;
	//int& ref = 10;//必须引用一块合法的内存空间
	const int& ref = 10;//编译器将代码修改  int temp = 10; const int& ref = temp;编译器自己起了原名temp
	//ref = 20;加入const后，为只读 指针常量

	ShowValue(a);
	ShowValue02(a);

	return 0;
}
#endif // 1

//函数提高 函数的默认参数
//函数的声明有默认参数，函数实现不能有默认参数
#if 0
//语法： 返回值类型 函数名 （参数 = 默认值）{}
//错误提示：默认实参不在形参列表的结尾
int func(int a,int b = 20,int c= 30)//如果某个位置有默认值，那么从这个位置往后，从左到右都必须要有默认值
{
	return a + b + c;
}
 
//函数的声明
int func02(int a = 10, int b = 10);
int main()
{
	cout << func(10) << endl;
	cout << func(10,30) << endl;//如果我们自己传入数值，就用自己的数据，没有，用默认值
	cout << func02() << endl;
	return 0;
}

int func02(int a, int b)//这里不能加默认参数
{
	return a + b;
}



#endif // 1

//函数占位参数
#if 0
//语法：返回值类型 函数名 （数据类型）{}
//目前用不上
//占位参数，可以有默认参数
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

//函数重载  函数名可以相同，提高复用性
#if 0
//同一个作用域下
//函数的名称相同
//函数参数类型不同，或者个数不同，或者顺序不同
//函数返回值不同不能函数重载
void func()
{
	cout << " func的调用 " << endl;
}
void func(int a)
{
	cout << " func(int a)的调用 " << endl;
}
void func(double a)
{
	cout << " func(double a)的调用 " << endl;
}
void func(int a,double b)
{
	cout << " func(int a,double b)的调用 " << endl;
}
void func(double b, int a)
{
	cout << " func(double b, int a)的调用 " << endl;
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

//函数引用+函数重载
//函数重载+默认参数
#if 0
void func(int &a)//int &a = 10不合法
{
	cout << "func(int &a)的调用" << endl;
}
void func(const int& a)//const int &a = 10;合法
{
	cout << "func(const int& a)的调用" << endl;
}

void func2(int a,int b = 20)
{
	cout << "func2(int a，int b = 20)的调用 " << endl;
}
void func2(int a)
{
	cout << "func2(int a)的调用 " << endl;
}

int main()
{
	int a = 10;
	func(a);//a为变量，可读可写
	func(10);
	func2(10,20);
	//func2(10);  默认参数产生歧义，不知道该调用哪个
	return 0;
}
#endif // 1

//类与对象
#if 0
//设计一个圆类，求圆的周长
//周长公式：2 * PI *半径
//#define PI 3.14；
const double PI = 3.14;//全局常量

//class 设计类，+类名
class Circle
{
	//访问权限
	//公共权限
public:
	//属性 半径
	int m_r;
	//行为 求圆的周长
	double calculateZC()
	{
		return 2 * PI * m_r;
	}
};

int main()
{
	//通过圆类 创建具体的圆（对象）
	//实例化 （通过一个类 创建一个对象的过程）
	Circle cl;
	//给圆对象 的属性进行赋值
	cl.m_r = 10;
	//2*3.14*10=62.8
	cout << "圆的周长为： " << cl.calculateZC() << endl;

	return 0;
}
#endif // 1

//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
#if 0
class Student
{
public:
	//成员属性
	
	//姓名
	string m_name;
	//学号
	int m_id;
	//显示姓名学号

public:
	//成员函数
	void ShowStudent()
	{
		cout << "姓名： " << m_name << "   学号：" << m_id << endl;
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
	s1.m_name = "张三";
	s1.m_id = 1;
	s1.ShowStudent();

	Student s2;
	s2.setname("李四");
	s2.setid(2);
	s2.ShowStudent();
	
	return 0;
}
#endif // 1

//public 共有 protected 保护 private 私有
#if 0
//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问

class Person
{
	//姓名  公共权限
public:
	string m_Name;

	//汽车  保护权限
protected:
	string m_Car;

	//银行卡密码  私有权限
private:
	int m_Password;

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;
	}
};

int main() {

	Person p;
	p.m_Name = "李四";
	//p.m_Car = "奔驰";  //保护权限类外访问不到
	//p.m_Password = 123; //私有权限类外访问不到

	return 0;
}
#endif // 1

//class默认私有  struct默认公有
#if 0

class C1
{
	int  m_A; //默认是私有权限
};

struct C2
{
	int m_A;  //默认是公共权限
};

int main() {

	C1 c1;
	c1.m_A = 10; //错误，访问权限是私有

	C2 c2;
	c2.m_A = 10; //正确，访问权限是公共

	return 0;
}

#endif // 1

//成员属性设置为私有
#if 0
class Person 
{
public:
	//姓名设置可读可写
	void setName(string name) {  			// 写，有参数
		m_Name = name;
	}
	string getName()    				// 读，无参数
	{
		return m_Name;
	}

	//获取年龄 
	int getAge() {      				// 读
		return m_Age;
	}
	//设置年龄
	void setAge(int age) {				// 写
		if (age < 0 || age > 150) {
			cout << "你个老妖精!" << endl;
			return;
		}
		m_Age = age;
	}

	//情人设置为只写
	void setLover(string lover) {			// 写
		m_Lover = lover;
	}

private:
	string m_Name; //可读可写  姓名
	int m_Age; 	//只读  年龄
	string m_Lover; //只写  情人
};


int main() {
	Person p;
	//姓名设置
	p.setName("张三");
	cout << "姓名： " << p.getName() << endl;

	//年龄设置
	p.setAge(50);
	cout << "年龄： " << p.getAge() << endl;

	//情人设置
	p.setLover("苍井");
	//cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取

	return 0;
}
#endif // 1

//设计立方体类(Cube)  求出立方体的面积和体积  分别用全局函数和成员函数判断两个立方体是否相等。
#if 0
class Cube
{
	
public:
	//获取设置 长方体的 长宽高
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

	//计算长方体面积和体积
	double Cube_S()
	{
		return (m_L * m_H + m_L * m_W + m_H * m_W) * 2;
	}

	double Cube_V()
	{
		return m_L * m_H * m_W;
	}

	//判断两立方体是否相等
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
	cout << "c1面积： " << c1.Cube_S() << endl;
	cout << "c1体积： " << c1.Cube_V() << endl;
	cout << endl;

	Cube c2;
	c2.setL(20.0);
	c2.setW(20.0);
	c2.setH(20.0);
	cout << "c2面积： " << c2.Cube_S() << endl;
	cout << "c2体积： " << c2.Cube_V() << endl;

	bool ret = equal_Cube(c1, c2);//全局函数需要调用两个参数

	if (ret)
	{
		cout << "c1和c2是相等的" << endl;
	}
	else
	{
		cout << "c1和c2是不相等的" << endl;
	}

	ret = c1.equal_cube(c2);//成员函数，只需调用一个参数就好

	if (ret)
	{
		cout << "c1和c2是相等的" << endl;
	}
	else
	{
		cout << "c1和c2是不相等的" << endl;
	}

	return 0;
}
#endif // 1

//设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。//圆内，圆上，圆外
#if 0
//class Point
//{
//public:
//	//设置获取点的X坐标
//	void setX(int x)
//	{
//		m_x = x;
//	}
//	int getX()
//	{
//		return m_x;
//	}
//
//	//设置获取点的X坐标
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
//class circle//圆类
//{
//public:
//	//获取半径
//	void setR(int r)
//	{
//		m_r = r;
//	}
//	int getR()
//	{
//		return m_r;
//	}
//
//	//获取圆心的坐标
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
//	//半径
//	int m_r;
//	//圆心
//	Point m_center;
//};

	//计算两点之间的距离的平方
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
		cout << " 点在圆外 " << endl;
	}
	else if(disdance = rdistance)
	{
		cout << " 点在圆上 " << endl;
	}
	else if (disdance < rdistance)
	{
		cout << " 点在圆内 " << endl;
	}
}

int main()
{
	//创建圆和点
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

//编写ABB循环程序
#if 0

void test01()
{
	ofstream ofs;
	ofs.open("D:\\study\\vs_text\\test.txt", ios::out);

	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

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

//构造函数与析构函数
#if 0
class person
{
public:
	person()
	{
		cout << "This is 构造函数" << endl;
	}
	~person()
	{
		cout << "This is 析构函数" << endl;
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

//构造函数的分类，深拷贝与浅拷贝
#if 0
int main()
{


	return 0;
}
#endif  //未编写

//常规初始化 与 初始化列表
#if 0

class person
{

public:
	//成员函数
	person(int a, int b, int c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}

	
	//成员属性
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

//c++ 类中的成员可以是 另一个类的对象  改成员是  对象成员
#if 0
//class A {};
//class B { A b;};
//B类中 有对象A 作为成员 ，则A未对象成员

class phone
{
	
public:
	//构造函数
	phone()
	{

	}
	//初始化 
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
	//成员中含对象的对象的初始化
	people(string input_name,string input_pname):name(input_name),PhoneName(input_pname)
	{

	}

	void showpeople()
	{
		cout << "run" << endl;
		cout << name << "使用： " << PhoneName.pname << "手机" << endl;
	}

private:
	string name;
	phone PhoneName;
};

void test01()
{
	people p("张三", "小米");
	p.showpeople();
}

int main()
{
	test01();

	return 0;
}
#endif // 1

//静态成员函数
#if 0
//静态成员函数是共享的
//静态成员函数只能访问静态变量

class person
{
public:
	static int m_a;
	int m_b = 1;
	static void func()
	{
		
		m_a = 500;
		//m_b = 2;//非静态函数，不能调用
		cout << m_a << endl;
		cout << "static void func的调用" << endl;
	}

private:
	static void func2()
	{
		cout << "static void func2的调用" << endl;
	}


};
int person::m_a = 100;

void test01()
{
	//静态成员函数的调用
	person p;
	p.func();

	person::func();
	//person::func2();//静态函数的调用也有权限
	
}


int main()
{
	test01();

	return 0;
}
#endif // 1

//this 指针-----------------------------没理解
#if 0
//当形参和成员变量同名时，可用this指针来区分
//可使用return *this

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
	cout << "p1的年纪： " << p1.age << endl;
}

void test02()
{
	person p2(10);

	person p3(10);

	cout << "p3的年龄： " << p3.age << endl;
}

void test03()
{
	person p2(10);

	person p3(10);

	p3.personaddage(p2).personaddage(p2).personaddage(p2);

	cout << "p3的年龄： " << p3.age << endl;
		
}

int main()
{
	test01();
	//test02();
	test03();
	return 0;
}
#endif // 1

//空指针调用成员函数（不重要）
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
		//保证代码的健壮性
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

//const修饰成员函数
#if 0
//常函数
class person
{
public:
	//this 指针的本质是 指针常量 ，指针的指向是不可以修改的
	//const person * const this;
	//在成员函数后面加const ,修饰的是this, 使指针指向的值也不可修改
	void showclass() const
	{
		this->m_b = 100;

		//this->m_a = 100;
		//this = NULL;//this 指针不可修改指针的指向的
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

//常对象
void test02()
{
	const person p;//在对象前加const 变成常对象
	p.m_b = 100;//m_b为特殊值，常对象下也可以修改值
	//p.m_a = 100;
	p.showclass();
	//p.func();//常对象不可调用普通成员函数 而普通成员函数可以修改属性
}

int main()
{
	test01();

	return 0;
}
#endif  //

//友元的三种实现  全局函数
#if 0

class Building
{
	friend void goodGay(Building& building);
public:
	string m_SittingRoom;

	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

private:
	string m_BedRoom;
};

//全局函数 复制粘贴在类中即可 前加friend （类似友元申明）
void goodGay(Building& building)
{
	cout << "好基友的全局函数 正在访问： " << building.m_SittingRoom << endl;
	cout << "好基友的全局函数 正在访问： " << building.m_BedRoom << endl;
}

int main()
{
	Building building;
	goodGay(building);

	return 0;
}
#endif  //

//类做友元
#if 0

class Building;
class goodGay
{
public:	
	goodGay();//构造函数

	void visit();//参观函数 访问building 的函数

private:
	Building* building;//干嘛用的？ 内部维护一个指针
};

class Building
{
	//告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class goodGay;
public:
	string m_SittingRoom;
	Building();//初始化
private:
	string m_BedRoom;
};

//类外写成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
goodGay::goodGay()
{
	building = new Building;	// 堆区创建一个对象，buliding接收对象地址
}

void goodGay::visit()//--------成员函数的类外表达 与 构造函数  的不同
{
	cout << "好基友正在访问： " << building->m_BedRoom << endl;
	cout << "好基友正在访问： " << building->m_SittingRoom << endl;
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

//成员函数做友元
#if 0
class Building;
class goodGay
{
public:
	goodGay();//构造函数
	void visit();//
	void visit2();//不可访问building类私有成员
private:
	Building* building;
};
class Building
{
	friend void goodGay::visit();
public:
	Building();//构造函数

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
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
void goodGay::visit()
{
	cout << "访问： " << building->m_SittingRoom << endl;
	cout << "访问： " << building->m_BedRoom << endl;
}
void goodGay::visit2()
{
	cout << "2访问： " << building->m_SittingRoom << endl;
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

//运算符重载（+)  成员函数重载
#if 0
class Person
{
public:
	Person() ;//构造函数
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

//全局函数重载
#if 0
int main()
{


	return 0;
}
#endif  //


//链表的学习  结构体与类的混搭
#if 0

class List {
public:
	List() { create_List(); }
	~List() { clear(); }
	//创建头结点
	void create_List();
	//插入函数
	void insert(const int& d);
	//在指定位置插入
	void insert_pos(const int& d, const int& d1);
	//删除指定数据的节点
	void erase(const int& d);
	//修改指定数据
	void updata(const int& d, const int& d1);
	//反转链表函数
	void reverse();
	//打印
	void print();
private:
	//节点结构
	struct Node {
		int data;
		Node* next;
		Node(const int& d) :data(d), next(NULL) {}//----------这个结点指针是如何初始化的？
	};
	Node* head;//头节点
	//清理链表函数
	void clear() {
		Node* p = head;
		//从头节点开始循环删除
		while (p) {
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	//查找数据d的上一个节点位置的函数
	//为了方便后面删除操作
	Node* find(const int& d) {
		Node* p = head;
		for (; p; p = p->next) {
			if (p->next->data == d)
				break;
		}
		return p;
	}
};

//创建头结点
void List::create_List()
{
	head = new Node(0);//括号里的0表示啥？传入d，下一个指向为NULL，这里是头结点，序号0
}
//从头插入一个节点
void List::insert(const int& d)
{
	Node* p = new Node(d);
	p->next = head->next;
	head->next = p;
}
//打印函数
void List::print()
{
	for (Node* p = head->next; p; p = p->next) {
		cout << p->data << endl;
	}
}
//在d位置之前插入d1
void List::insert_pos(const int& d, const int& d1)
{
	Node* p = find(d);
	Node* q = new Node(d1);
	q->next = p->next;
	p->next = q;
}

//删除
void List::erase(const int& d)
{
	Node* p = find(d);
	//因为p是上一个节点的位置，用q来保存
	//要删除的节点的地址
	Node* q = p->next;
	//通过将上一个节点的next指针指向要删除节点的next指
	//针志向的节点实现断开要删除节点的目的
	p->next = p->next->next;
	//删除要删除的节点q
	delete q;
}

//修改指定数据
void List::updata(const int& d, const int& d1)
{
	Node* p = find(d);
	p->next->data = d1;
}

//反转链表
void List::reverse()
{
	Node* p = head->next;//头结点之后的第1个节点
	Node* q = head->next->next;//头结点之后的第2节点
	Node* m = head->next->next->next;//头结点之后的第3个节点
	p->next = NULL;//将头接点之后的第1个节点的next指针置为空
	//根据m是否为空来判断 以此逆序每一个节点
	while (m) {
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	//将最后一个节点逆序
	q->next = p;
	//将头从新指向新的的第1个节点(之前的最后一个节点)
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

//STL初识
#if 0
//面向对象三大特征：封装、继承、多态
//标准模板库
//容器和算法通过迭代器连接
//容器、算法、迭代器、仿函数、适配器、空间配置器

void myPrint(int val) {
	cout << val << endl;
}

void test01() {
	//创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
	vector<int> v;
	//像容器中放数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素

	//第一种遍历方式
	if (0)
	{
		vector<int>::iterator itBegin = v.begin();//起始迭代器 指向容器中的第一个元素
		vector<int>::iterator itEnd = v.end();//结束迭代器  指向最后一个元素的下一个位置

		while (itBegin != itEnd)
		{
			cout << *itBegin << endl;
			itBegin++;
		}
	}



	//第二种遍历方式
	if (0)
	{
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}
	}

	//第三种遍历方式  用标准算法库
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

//vector 容器中存放自定义的数据类型
#if 0
class Person
{
public:
	//默认构造函数
	Person() {};
	//赋值构造函数
	Person(string _name, int _age) {
		m_name = _name;
		m_age = _age;
	}
	//析构函数
	~Person() {};
public:
	string m_name;
	int m_age;

};

void test01() {

	vector<Person>v;

	//创建5个具体的
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//将类存放在容器里
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器，打印类的信息
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名： " << (*it).m_name << " 年龄： " << (*it).m_age << endl;
	}
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "-姓名： " << it->m_name << " -年龄： " << it->m_age << endl;
	}
	
}

void test02() {

	vector<Person *>v;//容器中存放p1-p5的地址

	//创建5个具体的
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//将类存放在容器里
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);


	for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "*姓名： " << (*it)->m_name << " *年龄： " << (*it)->m_age << endl;
	}
}

int main()
{
	test01();
	test02();

	return 0;
}
#endif  //

//容器来嵌套容器
#if 0
void test01() {
	vector<vector<int>> v;

	//创建4个小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	//小容器中添加元素
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//将小容器添加到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器 遍历 所有数据
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