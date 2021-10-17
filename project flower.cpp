#include<iostream>
using namespace std;
int main()
{
	for (int i = 99; i < 1000; i++)
	{
		int a = 0;
	    int b = 0;
		int c = 0;
		a = i % 10;//个位
	    b = i / 10 % 10;//十位
		c = i / 100;//百位
			if (i==a*a*a+b*b*b+c*c*c)
			{
				cout << "这就是你要找的水仙花数:" << i << endl;
		    }
	}
	system("pause");
	return 0;
}