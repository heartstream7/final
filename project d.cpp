#include<iostream>
using namespace std;
#include<string>
struct hero
{
	string name;
	int score;
	int id;
}; 
void bubblesort(struct hero heroarray[5],int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (heroarray[j].score > heroarray[j + 1].score)
			{
				struct hero temp = heroarray[j];
				heroarray[j] = heroarray[j + 1];
				heroarray[j + 1] = temp;
			}

		}
	}
}
void printhero(struct hero heroarray[5], int len)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "������  " << heroarray[i].name << "������  " << heroarray[i].score
			<< "id:  " << heroarray[i].id << endl;
	}
}
int main()
{
	struct hero heroarray[5] =
	{
		{"����",652,981},
		{"����",648,982},
		{"����",666,983},
		{"����",672,984},
		{"����",642,985},
	};
	int len = sizeof(heroarray) / sizeof(heroarray[0]);
	bubblesort(heroarray, len);
	printhero(heroarray, len);
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "������" << heroarray[i].name << "����:" << heroarray[i].score << "id:" << heroarray[i].id 
	//		<< endl;
	//}
	system("pause");
	return 0;
}
