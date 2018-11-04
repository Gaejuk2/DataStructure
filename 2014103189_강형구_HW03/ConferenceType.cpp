#include "ConferenceType.h"

string ConferenceType::GetName()
{
	return m_cName;
}

string ConferenceType::GetDateTime()
{
	return m_cDateTime;
}

void ConferenceType::SetName(string inName)
{
	m_cName = inName;
}

void ConferenceType::SetDateTime(string inDateTime)
{
	m_cDateTime = inDateTime;
}

void ConferenceType::SetRecord(string inName, string inDateTime)
{
	SetName(inName);
	SetDateTime(inDateTime);
}

void ConferenceType::DisplayNameOnScreen()
{
	cout << "\t  Conference Name  : " << m_cName << endl;
}

void ConferenceType::DisplayDateTimeOnScreen()
{
	cout << "\t  Conference Date  : " << m_cDateTime << endl;
}

void ConferenceType::DisplayPaperOnScreen()
{
	if (paperList.GetCount())
	{
		cout << "\t  Paper List:" << endl;
		paperList.DisplayAllName();
	}
}

void ConferenceType::DisplayRecordOnScreen()
{
	DisplayNameOnScreen();
	DisplayDateTimeOnScreen();
	DisplayPaperOnScreen();
}

void ConferenceType::SetNameFromKB()
{
	cout << "\t  Conference Name  : ";
	getline(cin, m_cName);
}

void ConferenceType::SetDateTimeFromKB()
{
	cout << "\t  Conference Date  : ";
	getline(cin, m_cDateTime);
}

void ConferenceType::SetRecordFromKB()
{
	SetNameFromKB();
	SetDateTimeFromKB();
}

RelationType ConferenceType::CompareByName(ConferenceType & data)
{
	if (this->GetName() > data.m_cName) // name of the current PaperType > the name of parameter's
		return GREATER;
	else if (this->GetName() < data.m_cName) // name of the current PaperType < the name of parameter's
		return LESS;
	else // name of the current PaperType = the name of parameter's
		return EQUAL;
}

void ConferenceType::PaperManagement()
{
	bool goback = false;

	while (!goback)
	{
		int command;
		cout << endl << endl;
		cout << "\t  Conference \"" << GetName() << "\"" << endl;
		cout << "\t  Paper Management Mode" << endl;
		cout << "\t-- ID - Command ---------------------------- " << endl;
		cout << "\t    1 : Display all paper" << endl;
		cout << "\t    2 : Add paper" << endl;
		cout << "\t    3 : Delete paper" << endl;
		cout << "\t    4 : Replace paper" << endl;
		cout << "\t    5 : Author Management Mode" << endl;
		cout << "\t    0 : Quit" << endl;
		cout << "\t-------------------------------------------- " << endl;
		cout << "\t  -> Choose a Command : ";
		cin >> command;
		cin.ignore();
		cout << endl;

		switch (command)
		{
		case 1:	// display all of session information
			system("cls");
			DisplayAllPaper();
			break;
		case 2: // add a session
			AddPaper();
			break;
		case 3: // Remove the session from the list
			DeletePaper();
			break;
		case 4:	// replace the session from the list
			ReplacePaper();
			break;
		case 5: // paper management mode on
			AuthorManagementMode();
			break;
		case 0: // go back
			system("cls");
			goback = true;
			break;
		default: // force program termination
			system("cls");
			cout << "\n\n\t  ** ERROR : Illegal selection. Shut down the Program";
			Sleep(1000);
			exit(400);
		}
	}
}

void ConferenceType::DisplayAllPaper()
{
	if (paperList.GetCount())
	{
		system("cls");
		
		// list의 모든 데이터를 화면에 출력
		cout << "\n\t-- Current list ----------------------------\n\n";
		paperList.DisplayAllRecord();
		cout << "\t--------------------------------------------" << endl << endl;
	}
}

void ConferenceType::DisplayAllResult(ResultDisplayMode mode)
{
	if (mode == PAPER)
		PRL.DisplayAllRecord();
	else
		paperList.DisplayAllResult(AUTHOR);
}

void ConferenceType::AddPaper()
{
	PaperType tempPaper; // temporary data set to store new data
	tempPaper.SetRecordFromKB();
	tempPaper.SetConference(GetName());

	bool addResult = paperList.Insert(tempPaper);

	system("cls");
	if (addResult) // add success
		DisplayAllPaper();
	else // duplication occurred
		cout << "\n\t  ** ERROR : Duplication error occurred." << endl;

	return;
}

void ConferenceType::DeletePaper()
{
	string deleteDataName; // string for store input keyword
	PaperType tempData; // temporary data set to store deleteDataName

	cout << "\t  [Delete Paper] " << endl;
	cout << "\t   -> Input keyword of Paper name : ";
	getline(cin, deleteDataName);

	tempData.SetName(deleteDataName);
	bool process = paperList.Find(tempData);
	bool startOrNot = false;

	if (process)
	{
		cout << "\n\t  Delete ";
		startOrNot = paperList.StartFunction(tempData);
	}

	if (process && startOrNot) // delete success
	{
		paperList.Remove(tempData);
		system("cls");
		DisplayAllPaper();
	}
	else if (!process) // can not found
	{
		system("cls");
		cout << "\n\t  ** ERROR : Can not found." << endl;
	}
	else if (!startOrNot) // cancel delete
	{
		system("cls");
		cout << "\n\t  ** Cancel Delete." << endl;
		DisplayAllPaper();
	}
	else
	{
		system("cls");
		cout << "\n\t ** ERROR : Unexpected Error occurred. Exit Program." << endl;
		Sleep(1000);
		exit(400);
	}
}

void ConferenceType::ReplacePaper()
{
	string replaceDataName;	// string for store input keyword
	PaperType tempData; // temporary data set to store replaceDataName

	cout << "\t  [Replace Paper] " << endl;
	cout << "\t   -> Input keyword of Paper name : ";
	getline(cin, replaceDataName);

	tempData.SetName(replaceDataName);
	bool process = paperList.Find(tempData);

	if (process)
	{
		cout << "\n\t  Replace ";
		bool startOrNot = paperList.StartFunction(tempData);
		if (startOrNot)
		{
			paperList.Replace(tempData);
			DisplayAllPaper();
		}
		else // cancel replace
		{
			system("cls");
			cout << "\n\t  ** Cancel Replace." << endl;
			DisplayAllPaper();
		}
	}
	else if (!process) // can not found
	{
		system("cls");
		cout << "\n\t  ** ERROR : Can not found." << endl;
	}
	else
	{
		system("cls");
		cout << "\n\t ** ERROR : Unexpected Error occurred. Exit Program." << endl;
		Sleep(1000);
		exit(400);
	}
}

void ConferenceType::AuthorManagementMode()
{
	string AuthorManagementName; // storing store input keyword
	PaperType tempData; // to store retrieveName

	cout << "\t  Author Management Mode." << endl;
	cout << "\t   Search for the name of the paper that want to manage AuthorList." << endl;
	cout << "\t    -> Input keyword of paper name : ";
	getline(cin, AuthorManagementName);
	cout << endl;

	tempData.SetName(AuthorManagementName);
	bool process = paperList.Find(tempData);

	if (process) // retrieve success
	{
		PaperType *Pointer = paperList.GetCurDataPointer(tempData);
		system("cls");
		Pointer->AuthorManagement(); // start paper management mode
	}
	else if (!process) // can not found
	{
		system("cls");
		cout << "\n\t  ** ERROR : Can not found." << endl;
	}
	else
	{
		system("cls");
		cout << "\n\t ** ERROR : Unexpected Error occurred. Exit Program." << endl;
		Sleep(1000);
		exit(400);
	}
}

void ConferenceType::RetrieveByName(string searchName, int &location)
{
	location--;
	PRL.MakeTreeEmpty();
	paperList.RetrieveWithKeyword(searchName, PRL, location);
}

char ConferenceType::FileIn(ifstream & read, PaperType temp)
{
	paperList.Insert(temp);
	cout << "\t  >> Add Paper Complete." << temp.GetName() << ", " << temp.GetPages() << endl;
	PaperType *tempPointer;
	string space;
	
	char dataType;
	read.get(dataType);
	while (dataType != 'c' && dataType != 'p')
	{
		if (dataType == 'a' && dataType != '\n')
		{
			getline(read, space, '\t');
			tempPointer = paperList.GetCurDataPointer(temp);
			AuthorType temp;
			string tempName;
			getline(read, tempName, '\t');
			while (tempName.find("\n") == string::npos)
			{
				temp.SetRecord(tempName);
				tempPointer->FileIn(temp);
				getline(read, tempName, '\t');
			}
		}
		read.get(dataType);
	}
	return dataType;
}

