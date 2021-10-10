#include<iostream>//打印一个毕业设计，一名老师带五个学生
#include<string>
#include<ctime>
using namespace std;
struct student
{
	string sname;
	int score;
};
struct teacher
{
	string tname;
	struct student sarray[5];
};
void allocatespace(struct teacher tarray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		string nameseed = "ABCDE";
		tarray[i].tname = "teacher_";
		tarray[i].tname += nameseed[i];
		for (int j = 0; j < 5; j++)
		{
			tarray[i].sarray;
			tarray[i].sarray[j].sname = "student_";
			tarray[i].sarray[j].sname += nameseed[j];
			int random = rand() % 61 + 40;
			tarray[i].sarray[j].score = random;
		}
	}
}
void printinfo(struct teacher tarray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名:" << tarray[i].tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "学生姓名:" << tarray[i].sarray[j].sname
				<< "学生毕设分数：" << tarray[i].sarray[j].score << endl;
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	struct teacher tarray[3];
	int len = sizeof(tarray) / sizeof(tarray[0]);
	allocatespace(tarray, len);
	printinfo(tarray, len);
	system("pause");
	return 0;
}