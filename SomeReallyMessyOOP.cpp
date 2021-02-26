#include <string>
#include <iostream>
using namespace std;

class Account
{
public:
	int idNumber;
	string password;
};

Account accounts[100];
string inputIdNum;
string inputPassword;

class mainClass
{
public:
	database Database;

	void userInput()
	{
		cout << "enter your 4 didgit ID: ";
		cin >> inputIdNum;
		cout << "enter your password: ";
		cin >> inputPassword;
		Database.verifyID();
	}
};

class database
{
private:
	string details[100] = { "1637:password", "6235:bobisAwsome" };

public:
	string idNum;
	string password;

	void verifyID()
	{
		if (idNum.length() == 4)
		{			
			int i = 0;
			for (string item : details)
			{
				if (item != "")
				{
					Account account;
					int IdToInt = stoi(item.substr(0, 4));
					account.idNumber = IdToInt;
					account.password = item.substr(5, item.length());
					accounts[i] = account;
					i++;
				}
				else break;
			}
		}
		for (Account account : accounts)
		{
			if(account.idNumber != NULL && account.password != "")
			{
				int IDint = stoi(inputIdNum);
				if (account.idNumber == IDint)
				{
					verifyPass(IDint);
				}
			}
		}
	}

	void verifyPass(int IDint) {
		for (Account account : accounts)
		{
			if (account.idNumber != NULL && account.password != "")
			{								
				if (account.idNumber == IDint) 
				{
					if (account.password == inputPassword) acceptDetails();
					else 
					{
						cout << "-------------------\n" << "The ID or password you enter was inncorect" << "-------------------\n";
						mainClass restart;
						restart.userInput();
					}
				}
			}
		}
	}

	void acceptDetails() 
	{
		cout << "Welcome Back user " << inputIdNum;
	}
};

int main()
{
	mainClass mainObj;
	mainObj.userInput();
}
