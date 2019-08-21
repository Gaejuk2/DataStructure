#include "PaperType.h"

string PaperType::GetName()
{
	return m_pTitle;
}

string PaperType::GetPages()
{
	return m_pPages;
}

void PaperType::SetName(string inTitle)
{
	m_pTitle = inTitle;
}

void PaperType::SetPages(string inPages)
{
	m_pPages = inPages;
}

void PaperType::SetConference(string inConference)
{
	m_pConference = inConference;
}

void PaperType::SetRecord(string inTitle, string inPages)
{
	SetName(inTitle);
	SetPages(inPages);
}

void PaperType::SetNameFromKB()
{
	cout << "\t  Title of Paper                 : ";
	getline(cin, m_pTitle);
}

void PaperType::SetPagesFromKB()
{
	cout << "\t  Paper pages      : ";
	getline(cin, m_pPages);
}

void PaperType::SetRecordFromKB()
{
	SetNameFromKB();
	SetPagesFromKB();
}

void PaperType::DisplayConferenceOnScreen()
{
	cout << "\t  Conference \" " << m_pConference << " \"" << endl;
}

void PaperType::DisplayNameOnScreen()
{
	cout << "\t  Title of Paper   : " << m_pTitle << endl;
}

void PaperType::DisplayPagesOnScreen()
{
	cout << "\t  Paper pages      : " << m_pPages << endl;
}

void PaperType::DisplayAuthorOnScreen()
{
	if (authorList.GetCount())
	{
		cout << "\t  Author List:" << endl;
		authorList.DisplayAllName();
	}
}

void PaperType::DisplayRecordOnScreen()
{
	DisplayNameOnScreen();
	DisplayPagesOnScreen();
	DisplayAuthorOnScreen();
}

RelationType PaperType::CompareByName(PaperType & data)
{
	if (this->GetName() > data.m_pTitle) // name of the current PaperType > the name of parameter's
		return GREATER;
	else if (this->GetName() < data.m_pTitle) // name of the current PaperType < the name of parameter's
		return LESS;
	else // name of the current PaperType = the name of parameter's
		return EQUAL;
}

void PaperType::AuthorManagement()
{
	bool goback = false;

	while (!goback)
	{
		int command;
		cout << endl << endl;
		cout << "\t  Paper \"" << GetName() << "\"" << endl;
		cout << "\t  Author Management Mode" << endl;
		cout << "\t-- ID - Command ---------------------------- " << endl;
		cout << "\t    1 : Display all Author" << endl;
		cout << "\t    2 : Add Author" << endl;
		cout << "\t    3 : Delete Author" << endl;
		cout << "\t    4 : Replace Author" << endl;
		cout << "\t    0 : Quit" << endl;
		cout << "\t-------------------------------------------- " << endl;
		cout << "\t  -> Choose a Command : ";
		cin >> command;
		cin.ignore();
		cout << endl;

		switch (command)
		{
		case 1:	// display all of session information
			system("clear");
			DisplayAllAuthor();
			break;
		case 2: // add a session
			AddAuthor();
			break;
		case 3: // Remove the session from the list
			DeleteAuthor();
			break;
		case 4:	// replace the session from the list
			ReplaceAuthor();
			break;
		case 0: // go back
			system("clear");
			goback = true;
			break;
		default: // force program termination
			system("clear");
			cout << "\n\n\t  ** ERROR : Illegal selection. Shut down the Program";
			sleep(2);
			exit(400);
		}
	}
}

void PaperType::AddAuthor()
{
	AuthorType tempSession; // temporary data set to store new data
	tempSession.SetRecordFromKB();
	tempSession.SetPaperName(GetName());
	int addResult = authorList.Insert(tempSession);

	system("clear");
	if (addResult == 1)	// add success
		DisplayAllAuthor();
	else if (addResult == 0) // duplication occurred
		cout << "\n\t  ** ERROR : Duplication error occurred." << endl;
	else if (addResult == -1) // list is full
		cout << "\n\t  ** ERROR : List is full." << endl;
	else // unexpected error occurred
		cout << "\n\t  ** ERROR : Unexpected ERROR occurred." << endl;

	return;
}

void PaperType::DeleteAuthor()
{
	string deleteDataName; // string for store input keyword
	AuthorType tempData; // temporary data set to store deleteDataName

	cout << "\t  [Delete Author] " << endl;
	cout << "\t   -> Input keyword of Author name : ";
	getline(cin, deleteDataName);

	tempData.SetName(deleteDataName);
	bool process = authorList.Find(tempData);
	bool startOrNot = false;

	if (process)
	{
		cout << "\n\t  Delete ";
		startOrNot = authorList.StartFunction(tempData);
	}

	if (process && startOrNot) // delete success
	{
		authorList.Remove(tempData);
		system("clear");
		DisplayAllAuthor();
	}
	else if (!process) // can not found
	{
		system("clear");
		cout << "\n\t  ** ERROR : Can not found." << endl;
	}
	else if (!startOrNot) // cancel delete
	{
		system("clear");
		cout << "\n\t  ** Cancel Delete." << endl;
		DisplayAllAuthor();
	}
	else
	{
		system("clear");
		cout << "\n\t ** ERROR : Unexpected Error occurred. Exit Program." << endl;
		sleep(2);
		exit(400);
	}
}

void PaperType::ReplaceAuthor()
{
	string replaceDataName;	// string for store input keyword
	AuthorType tempData; // temporary data set to store replaceDataName

	cout << "\t  [Replace Author] " << endl;
	cout << "\t   -> Input keyword of Author name : ";
	getline(cin, replaceDataName);

	tempData.SetName(replaceDataName);
	bool process = authorList.Find(tempData);
	bool startOrNot = false;

	if (process)
	{
		cout << "\n\t  Replace ";
		startOrNot = authorList.StartFunction(tempData);
	}

	if (process && startOrNot) // replace success
	{
		authorList.Remove(tempData);
		DisplayAllAuthor();
	}
	else if (!process) // can not found
	{
		system("clear");
		cout << "\n\t  ** ERROR : Can not found." << endl;
	}
	else if (!startOrNot) // cancel replace
	{
		system("clear");
		cout << "\n\t  ** Cancel Replace." << endl;
		DisplayAllAuthor();
	}
	else
	{
		system("clear");
		cout << "\n\t ** ERROR : Unexpected Error occurred. Exit Program." << endl;
		sleep(2);
		exit(400);
	}
}

void PaperType::DisplayAllAuthor()
{
	if (authorList.GetCount())
	{
		system("clear");
		// Tree�� ��� �����͸� ȭ�鿡 ���
		cout << "\n\t-- Current list ----------------------------\n\n";
		authorList.DisplayAllRecord();
		cout << "\t--------------------------------------------" << endl << endl;
	}
}

void PaperType::DisplayAllResult(ResultDisplayMode mode)
{
	if( mode == PAPER )
		ARL.DisplayAllRecord();
}

void PaperType::RetrieveByName(string searchName, int &location)
{
	location--;
	ARL.MakeTreeEmpty();
	authorList.RetrieveWithKeyword(searchName, ARL, location);
}

void PaperType::FileIn(AuthorType temp)
{
	authorList.Insert(temp);
	cout << "\t  >> Add Author Complete." << temp.GetName() << endl;
}
