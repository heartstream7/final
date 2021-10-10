#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
void showmenu()
{
	cout << "**************************" << endl;
	cout << "*******" << "1.�����ϵ��" << "*******" << endl;
	cout << "*******" << "2.��ʾ��ϵ��" << "*******" << endl;
	cout << "*******" << "3.ɾ����ϵ��" << "*******" << endl;
	cout << "*******" << "4.������ϵ��" << "*******" << endl;
	cout << "*******" << "5.�޸���ϵ��" << "*******" << endl;
	cout << "*******" << "6.�����ϵ��" << "*******" << endl;
	cout << "*******" << "0.�˳�ͨѶ¼" << "*******" << endl;
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
		cout << "���ˣ���������" << endl;
		return;
	}
	else {
		string name;
		cout << "��������ϵ������" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
	}
	//�Ա�
	cout << "�������Ա�" << endl;
	cout << "1---��" << endl;
	cout << "2---Ů" << endl;//��ֹ�û�Ϲ����ĳЩ��Ϣ
	int sex = 0;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personarray[abs->m_size].m_sex = sex;
			break;// �����breakΪʲô������if�ڲ��أ�����ifѭ����
		}
		cout << "������������������" << endl;
	}
	//����
	int age = 0;
	cout << "����������" << endl;
	while (true)
	{
		cin >> age;
		if (age <= 150 )//�������ѧ��Ĳ�һ��,��ֻ�ܰ���Ū�ɵ�������
		{
			abs->personarray[abs->m_size].m_age = age;
			break;
		}
		cout << "���ٴ�ȷ����������" << endl;
		}
	//�±��е������
	string phone =" ";//�������������
	cout << "������绰����" << endl;
	cin >> phone;
	abs->personarray[abs->m_size].m_phone = phone;
	string address;
	cout << "�������ͥסַ" << endl;
	cin >> address;
	abs->personarray[abs->m_size].m_addr = address;
	abs->m_size++;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}
//��ʾ���е���ϵ��
void showperson(addressbooks* abs)
{
	//�ж�ͨѶ¼������
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	} 
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personarray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personarray[i].m_sex == 1 ? "��" : "Ů") << "\t";//���з��Ŷ�Ҫ��Ӣ�ĵ�
			cout << "���䣺" << abs->personarray[i].m_age << "\t";
			cout << "�绰��" << abs->personarray[i].m_phone << "\t";
			cout << "��ַ��" << abs->personarray[i].m_addr << endl;
		} 
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����,������ھͷ�����ϵ���������еľ���λ�ã������ڷ���-1
int isexist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;//�ҵ��˾ͷ�������˵��±���
		}
	}
	return -1;
}
void deleteperson(addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret=isexist(abs,name);
	if (ret != -1)//��ǰŲ���ݣ��ú���ĸ�����ǰ�棬ǰ�Ʋ����������ͨ��¼��¼����Ա��Ŀ��һ����
    {
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout<<"ɾ���ɹ�" << endl;
		}
	else
	{
		cout<<"���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personarray[ret].m_name << "\t";
		cout << "�Ա�" <<( abs->personarray[ret].m_sex==1?"��":"Ů") << "\t";
		cout << "���䣺" << abs->personarray[ret].m_age << "\t";
		cout << "�绰��" << abs->personarray[ret].m_phone << "\t";
		cout << "��ַ��" << abs->personarray[ret].m_addr << endl;
	}
	else
	{
		cout<<"δ�ҵ���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}
//�޸�ָ������ϵ����Ϣ
void modifyperson(addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;//��ô�ֲ����ˣ��������Ĳ����������
	string name;//��ʵ������©�˲��ٲ��裬ע�ⲻҪ������cin©����
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "��������Ҫ�޸ĵ�����" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		cout << "��������Ҫ�޸ĵ��Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}cout << "��������" << endl;
		}
		cout << "��������Ҫ�޸ĵ�����" << endl;
		int age = 0;
		cin >> age;
		while (true)
		{
			if (age <= 150)
			{
				abs->personarray[ret].m_age = age;
				break;
			}
			cout << "���������������" << endl;
		}
		cout << "��������Ҫ�޸ĵ���ϵ�绰 " << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;
		cout << "��������Ҫ�޸ĵļ�ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanperson(addressbooks* abs)
{
	cout << "ͨѶ¼�����" << endl;//���ݻ��ڣ��Ⲣ�������������ϵ�ɾ��
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
			addperson(&abs);//���õ�ַ���ݣ���������ʵ��
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
		/* {	cout << "������ɾ����ϵ������" << endl;//�������Ҫ�ԣ�̫���Ĵ�����case��֧�лᱨ��
		string name;
		cin >> name;
		if (isexist(&abs, name)==-1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout<<"�ҵ�����" << endl;
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
			cleanperson(&abs);//���ԸĽ���һ��ȷ����յĲ���
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