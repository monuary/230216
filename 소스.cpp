#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS
{
	enum{CLERK,SENIOR,ASSIST,MANAGER};	//������
	void ShowPositionInfo(int pos)	//�������� int������ �����ȴ�.
	{
		switch (pos)
		{
		case CLERK:	//switch-case�� ��Ȳ�� ���� ����� ����
			cout << "���";
			break;
		case SENIOR:
			cout << "����";
			break;
		case ASSIST:
			cout << "�븮";
			break;
		case MANAGER:
			cout << "����";
			break;
		}
	}
}
class NameCard
{
	char* Name;
	char* Company;
	char* PhoneNum;
	int Position;
public:
	NameCard(const char* myname, const char* mycompany, const char* num, int pos)
	{
		Name = new char[strlen(myname) + 1];
		strcpy(Name, myname);	//�� ������ �Ҵ��ϴ� �޸� ũ�⸦ �ּ�ȭ �� �� �ִ�.
		Company = new char[strlen(mycompany) + 1];
		strcpy(Company, mycompany);	//strcpy�� ���� �� ��ó���⿡ _CRT_SECURE_NO_WARNINGS�� �ٿ��� �Ѵ�. ������ ���ؿ� �ȸ±� ����.
		PhoneNum = new char[strlen(num)+1];
		strcpy(PhoneNum, num);
		Position = pos;
	}
	void ShowNameCardInfo()
	{
		cout << "�̸�: " << Name << endl;
		cout << "ȸ��: " << Company << endl;
		cout << "��ȭ��ȣ: " << PhoneNum << endl;
		cout << "����: "; COMP_POS::ShowPositionInfo(Position); cout << endl;
	}
};

int main()
{
	NameCard manClerk("LEE", "ABC", "000-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("HONG", "ORG", "333-4444-5555", COMP_POS::SENIOR);
	NameCard manAssist("KIM", "SOG", "666-7777-8888", COMP_POS::ASSIST);
	NameCard manManager("KANG", "SAM", "999-9999-9999", COMP_POS::MANAGER);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	manManager.ShowNameCardInfo();
	return 0;
}