// INFO450Ticket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class Ticket
{
private:
	static int IDGenerator;
	int ID;
	string IssStatus = "OPEN";
	char IssType;
	string Issue;
	string IssPriority;
	string CallName;
	string IssDesc;
	static int NumAffect;
public:
	Ticket() {};

	void Identifier();
	void CaptureTicket();
	void ShowTicket();};

int Ticket::IDGenerator = 1;
int Ticket::NumAffect = 0;

void Ticket::Identifier()
{
	
}

void Ticket::CaptureTicket()
{
	cin.ignore();
	cin.clear();
	cout << "Enter Caller Name: ";
	getline(cin, CallName, '\n');
	cout << "Select Issue Type: [S]erver, [A]pplication, or a[C]cess. Press respective key to continue..";
	cin >> IssType;
	cin.ignore();
	cin.clear();
	if (IssType == 'S' || IssType == 's')
	{
		Issue = "Server Error";
	}
	else if (IssType == 'A' || IssType == 'a')
	{
		Issue = "Application Error";
	}
	else if (IssType == 'C' || IssType == 'c')
	{
		Issue = "Access Error";
	}
	else cout << "INVALID SELECTION.";
	cout << "Describe the issue: ";
	getline(cin, IssDesc);
	cout << "Number of users affected: ";
	cin >> NumAffect;
	cin.ignore();
	cin.clear();
	if (NumAffect < 10)
	{
		IssPriority = "LOW";
	}
	else if (NumAffect >= 10 && NumAffect < 50)
	{
		IssPriority = "MED";
	}
	else (IssPriority = "HIGH!");

	ID = IDGenerator++;
	cout << "Your ticket number is: #" << ID << endl;
	cout << "------------------------------" << endl;
}



void Ticket::ShowTicket()
{
	cout << "Ticket #: " << ID << endl;
	cout << "Caller Name: " << CallName << endl;
	cout << "Issue: " << Issue <<endl;
	cout << "Priority: " << IssPriority << endl;
}



int main()
{
	Ticket **myTicket;
	const int NUMTICKETS = 100;
	char NewTicket;

		myTicket = new Ticket*[NUMTICKETS];

	cout << "Welcome to Help Center." << endl;
	cout << "Press enter  to continue.." << endl;

	for (int i = 0; i < NUMTICKETS; i++)
	{
		myTicket[i] = new Ticket();

		myTicket[i]->CaptureTicket();

		cout << "Continue or Quit? Select [C] or [Q]" << endl;
		cin >> NewTicket;
		if (NewTicket == 'C' || NewTicket == 'c')
		{
			continue;
		}
		else if (NewTicket == 'Q' || NewTicket == 'q')
		{
			break;
		}
	}

	for (int i = 0; i < NUMTICKETS; i++)
	{
		myTicket[i]->ShowTicket();
		cout << endl;
		delete myTicket[i];
	}
	delete myTicket;

	return 0;
}

