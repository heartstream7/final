#include<iostream>
using namespace std;
int* func()//����ָ�룬��ʾһ����������ڵ�ַ
{
	int a = 10;//�ô����ڴ�������ʱ�������ݵľ���״̬��ѡ����Ӧ�Ĵ���ʽ����������ʱ�������
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