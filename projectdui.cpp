#include<iostream> 
using namespace std;
int* func()
{
	int* p = new int(10);
	return p;
}
int main()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	delete p;//数据已经被释放，不能再次输出
	cout << *p << endl;
	system("pause");
	return 0;
}