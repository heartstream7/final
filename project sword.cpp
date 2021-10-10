#include<iostream>
using namespace std;
#include<ctime>
int main() {
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int val = 0;
	int n = 0;
	while (n < 7)
	{
		n++;
		cin >> val;

		if (val > num)
		{
			cout << "biger" << endl;
		}
		else if (val < num)
		{
			cout << "smaller" << endl;
		}
		else
		{
			cout << "¹§Ï²Äú²Â¶ÔÁË" << endl;
			break;
		}
	}
}
