#include<iostream>
using namespace std;
int* func()//函数指针，表示一个函数的入口地址
{
	int a = 10;//好处是在处理“运行时根据数据的具体状态来选择相应的处理方式”这种需求时更加灵活
	return &a;
}
int main()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	system("pause");
	return 0;
}