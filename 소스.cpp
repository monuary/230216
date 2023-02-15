#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS
{
	enum{CLERK,SENIOR,ASSIST,MANAGER};	//열거형
	void ShowPositionInfo(int pos)	//열거형은 int형으로 지정된다.
	{
		switch (pos)
		{
		case CLERK:	//switch-case로 상황에 따른 명령이 가능
			cout << "사원";
			break;
		case SENIOR:
			cout << "주임";
			break;
		case ASSIST:
			cout << "대리";
			break;
		case MANAGER:
			cout << "과장";
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
		strcpy(Name, myname);	//이 구조로 할당하는 메모리 크기를 최소화 할 수 있다.
		Company = new char[strlen(mycompany) + 1];
		strcpy(Company, mycompany);	//strcpy를 쓰는 한 전처리기에 _CRT_SECURE_NO_WARNINGS를 붙여야 한다. 마소의 기준에 안맞기 때문.
		PhoneNum = new char[strlen(num)+1];
		strcpy(PhoneNum, num);
		Position = pos;
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << Name << endl;
		cout << "회사: " << Company << endl;
		cout << "전화번호: " << PhoneNum << endl;
		cout << "직급: "; COMP_POS::ShowPositionInfo(Position); cout << endl;
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