#include<iostream>
using namespace std;
int main()
{
	for (int i = 99; i < 1000; i++)
	{
		int a = 0;
	    int b = 0;
		int c = 0;
		a = i % 10;//��λ
	    b = i / 10 % 10;//ʮλ
		c = i / 100;//��λ
			if (i==a*a*a+b*b*b+c*c*c)
			{
				cout << "�������Ҫ�ҵ�ˮ�ɻ���:" << i << endl;
		    }
	}
	system("pause");
	return 0;
}