#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
void showmenu()
{
	cout << "**************************" << endl;
	cout << "*******" << "1.添加联系人" << "*******" << endl;
	cout << "*******" << "2.显示联系人" << "*******" << endl;
	cout << "*******" << "3.删除联系人" << "*******" << endl;
	cout << "*******" << "4.查找联系人" << "*******" << endl;
	cout << "*******" << "5.修改联系人" << "*******" << endl;
	cout << "*******" << "6.清空联系人" << "*******" << endl;
	cout << "*******" << "0.退出通讯录" << "*******" << endl;
	cout << "**************************" << endl;
}
struct person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
struct addressbooks
{
	struct person personarray[MAX];
	int m_size;
};
void addperson(addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "满了，别输入了" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入联系人姓名" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
	}
	//性别
	cout << "请输入性别" << endl;
	cout << "1---男" << endl;
	cout << "2---女" << endl;//防止用户瞎操作某些信息
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personarray[abs->m_size].m_sex = sex;
			break;// 这里的break为什么包含在if内部呢？跳出if循环。
		}
		cout << "输入有误，请重新输入" << endl;
	}
	//年龄
	int age = 0;
	cout << "请输入年龄" << endl;
	while (true)
	{
		cin >> age;
		if (age <= 150 )//这里和数学里的不一样,我只能把他弄成单项引号
		{
			abs->personarray[abs->m_size].m_age = age;
			break;
		}
		cout << "请再次确认您的输入" << endl;
		}
	//下边有点点问题
	string phone =" ";//这里可能有问题
	cout << "请输入电话号码" << endl;
	cin >> phone;
	abs->personarray[abs->m_size].m_phone = phone;
	string address;
	cout << "请输入家庭住址" << endl;
	cin >> address;
	abs->personarray[abs->m_size].m_addr = address;
	abs->m_size++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}
//显示所有的联系人
void showperson(addressbooks* abs)
{
	//判断通讯录中人数
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	} 
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personarray[i].m_name << "\t";
			cout << "性别：" << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";//所有符号都要用英文的
			cout << "年龄：" << abs->personarray[i].m_age << "\t";
			cout << "电话：" << abs->personarray[i].m_phone << "\t";
			cout << "地址：" << abs->personarray[i].m_addr << endl;
		} 
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在,如果存在就返回联系人在数组中的具体位置，不存在返回-1
int isexist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;//找到了就返回这个人的下标编号
		}
	}
	return -1;
}
void deleteperson(addressbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret=isexist(abs,name);
	if (ret != -1)//往前挪数据，让后面的覆盖在前面，前移操作，最后让通信录记录的人员数目减一即可
    {
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout<<"删除成功" << endl;
		}
	else
	{
		cout<<"查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personarray[ret].m_name << "\t";
		cout << "性别：" <<( abs->personarray[ret].m_sex==1?"男":"女") << "\t";
		cout << "年龄：" << abs->personarray[ret].m_age << "\t";
		cout << "电话：" << abs->personarray[ret].m_phone << "\t";
		cout << "地址：" << abs->personarray[ret].m_addr << endl;
	}
	else
	{
		cout<<"未找到联系人" << endl;
	}
	system("pause");
	system("cls");
}
//修改指定的联系人信息
void modifyperson(addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;//怎么又不行了，接下来的步骤给我吞了
	string name;//事实上是你漏了不少步骤，注意不要把输入cin漏掉了
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入您要修改的姓名" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		cout << "请输入您要修改的性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}cout << "输入有误" << endl;
		}
		cout << "请输入你要修改的年龄" << endl;
		int age = 0;
		cin >> age;
		while (true)
		{
			if (age <= 150)
			{
				abs->personarray[ret].m_age = age;
				break;
			}
			cout << "您的输入可能有误" << endl;
		}
		cout << "请输入您要修改的联系电话 " << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		cout << "请输入您要修改的家庭住址" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs)
{
	cout << "通讯录已清空" << endl;//数据还在，这并不是真正意义上的删除
	abs->m_size = 0;
	system("pause");
	system("cls");
}
		
int main()
{
	addressbooks abs;
	abs.m_size=0;
	int select = 0;
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);//利用地址传递，可以修饰实参
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
		/* {	cout << "请输入删除联系人姓名" << endl;//语句块的重要性，太长的代码在case分支中会报错
		string name;
		cin >> name;
		if (isexist(&abs, name)==-1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout<<"找到此人" << endl;
		}
		}*/
			deleteperson(&abs);
			break;
		case 4:
			findperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			cleanperson(&abs);//可以改进加一个确认清空的步骤
		    break;

		case 0:
				cout << "welcome your use" << endl;
				return 0;
				break;
        default:
			break;
		}
	}
	system("pause");
	return 0;
}