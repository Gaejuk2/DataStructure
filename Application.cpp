#include "Application.h"

int Application::GetCommand(ModeNum modeNum)
{
	if (modeNum == USER) // user mode menu
	{
		int command;
		cout << endl << endl;
		cout << "\t  User Mode" << endl;
		cout << "\t-- ID - Command ---------------------------- " << endl;
		cout << "\t    1 : Display Conference name list" << endl;
		cout << "\t    2 : Retrieve by keyword" << endl;
		cout << "\t    0 : Quit" << endl;
		cout << "\t-------------------------------------------- " << endl;
		cout << "\t  -> Choose a Command : ";
		cin >> command;
		cin.ignore();
		cout << endl;

		return command;
	}
	else if (modeNum == MANAGE) // management mode menu
	{
		int command;
		cout << endl << endl;
		cout << "\t  Management Mode" << endl;
		cout << "\t-- ID - Command ---------------------------- " << endl;
		cout << "\t    1 : Display Conference list" << endl;
		cout << "\t    2 : Add conference" << endl;
		cout << "\t    3 : Delete conference" << endl;
		cout << "\t    4 : Replace conference" << endl;
		cout << "\t    5 : Paper Management Mode" << endl;
		cout << "\t    0 : Quit" << endl;
		cout << "\t-------------------------------------------- " << endl;
		cout << "\t  -> Choose a Command : ";
		cin >> command;
		cin.ignore();
		cout << endl;

		return command;
	}
	else // start menu
	{
		int command;
		cout << endl << endl;
		cout << "\t  Conference Information Management Program" << endl;
		cout << "\t-- ID - Command ----------------------------- " << endl;
		cout << "\t    1 : User Mode" << endl;
		cout << "\t    2 : Manage Mode" << endl;
		cout << "\t    3 : Import Data From a Text File" << endl;
		cout << "\t    0 : Quit" << endl;
		cout << "\t--------------------------------------------- " << endl;
		cout << "\t  -> Choose a Command : ";
		cin >> command;
		cin.ignore();
		cout << endl;

		return command;
	}

}

void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand(START);

		switch (m_Command)
		{
		case 1: // User Mode
			system("cls");
			UserMode();
			break;
		case 2: // Management Mode
			system("cls");
			ManageMode();
			break;
		case 3: // 파일로 부터 불러오기
			FileIn();
			break;
		case 0:	// program exit
			system("cls");
			cout << "\n\n	Shut down the Program";
			Sleep(1000);
			exit(400);
		default: // force program termination
			system("cls");
			cout << "\n\n\t  ** ERROR : Illegal selection. Shut down the Program";
			Sleep(1000);
			exit(400);
		}

	}
}

void Application::UserMode()
{
	bool goback = false;

	while (!goback)
	{
		m_Command = GetCommand(USER);

		switch (m_Command)
		{
		case 1: // display all conference name
			system("cls");
			DisplayAllConference();
			break;
		case 2: // retrieve by name and if user choose one, display detail inforamtion
			RetrieveByName();
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

void Application::ManageMode()
{
	bool goback = false;

	while (!goback)
	{
		m_Command = GetCommand(MANAGE);

		switch (m_Command)
		{
		case 1: // display all of conference information
			system("cls");
			DisplayAllConference();
			break;
		case 2: // add a conference
			AddConference();
			break;
		case 3: // remove the conference from the list
			DeleteConference();
			break;
		case 4: // replace the conference from the list
			ReplaceConference();
			break;
		case 5: // paper management mode on
			PaperManagementMode();
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

void Application::DisplayAllConference()
{
	if (m_List.GetCount())
	{
		system("cls");
		// list의 모든 데이터를 화면에 출력
		cout << "\n\t-- Current list ----------------------------\n\n";
		m_List.DisplayAllRecord();
		cout << "\t--------------------------------------------" << endl;
	}
}

void Application::DisplayAllResult(ResultDisplayMode mode)
{
	if (mode == CONFERENCE)
	{
		system("cls");
		cout << "\n\n\t  [Search Result]" << endl;

		cout << "\t  >> Conference" << endl;
		CRL.DisplayAllRecord();

		cout << "\t  >> Paper" << endl;
		m_List.DisplayAllResult(PAPER);

		cout << "\t  >> Author" << endl;
		m_List.DisplayAllResult(AUTHOR);
	}
}

void Application::AddConference()
{
	ConferenceType item; // temporary data set to store new data
	cout << "\t  [Add Conference] " << endl;
	item.SetRecordFromKB();

	bool process = m_List.Insert(item);
	if (process) // add success
	{
		system("cls");
		DisplayAllConference();
		return;
	}
	else
	{
		system("cls");
		cout << endl << "\t  ** ERROR : Can not Add conference." << endl;
		return;
	}
}

void Application::DeleteConference()
{
	string deleteDataName; // string for store input keyword
	ConferenceType tempData; // temporary data set to store deleteDataName

	cout << "\t  [Delete Conference] " << endl;
	cout << "\t   -> Input keyword of conference : ";
	getline(cin, deleteDataName);

	tempData.SetName(deleteDataName);
	system("cls");
	bool process = m_List.Find(tempData);
	
	if (process)
	{
		cout << "\n\t  Delete ";
		bool startOrNot = m_List.StartFunction(tempData);
		if (startOrNot)
		{
			m_List.Remove(tempData);
			system("cls");
			DisplayAllConference();
		}
		else
		{
			system("cls");
			cout << "\n\t  ** Cancel Delete." << endl;
			DisplayAllConference();
		}
	}
	else if (!process)
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

void Application::ReplaceConference()
{
	string replaceDataName;	// string for store input keyword
	ConferenceType tempData; // temporary data set to store replaceDataName

	cout << "\t  [Replace Conference] " << endl;
	cout << "\t   -> Input keyword of conference : ";
	getline(cin, replaceDataName);

	tempData.SetName(replaceDataName);
	system("cls");
	bool process = m_List.Find(tempData);

	if (process) // replace success
	{
		cout << "\n\t  Replace ";
		bool startOrNot = m_List.StartFunction(tempData);
		if (startOrNot)
		{
			m_List.Replace(tempData);
			DisplayAllConference();
		}
		else
		{
			system("cls");
			cout << "\n\t  ** Cancel Replace." << endl;
			DisplayAllConference();
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

void Application::RetrieveByName()
{
	string retrieveName; // storing for store input keyword
	cout << "\t  [Retrieve by Keyword]" << endl;
	cout << "\t   -> Input keyword : ";
	getline(cin, retrieveName);

	int location = 2;
	CRL.MakeTreeEmpty();
	m_List.RetrieveWithKeyword(retrieveName, CRL, location);

	DisplayAllResult(CONFERENCE);
}

void Application::PaperManagementMode()
{
	string conferenceManagementName; // storing for store input keyword
	ConferenceType tempData; // to store retrieveName

	cout << "\t  Paper Management Mode." << endl;
	cout << "\t   Search for the name of the conference that want to manage Conferencelist." << endl;
	cout << "\t    -> Input keyword of conference: ";
	getline(cin, conferenceManagementName);
	cout << endl;

	tempData.SetName(conferenceManagementName);
	bool process = m_List.Find(tempData);

	if (process) // retrieve success
	{
		ConferenceType *Pointer = m_List.GetCurDataPointer(tempData);
		system("cls");
		Pointer->PaperManagement(); // start conference management mode
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

void Application::FileIn()
{
	system("cls");
	cout << "\n\t  >> Load data from File" << endl << endl;

	char dataType;
	string space;

	ifstream read;
	read.open("dblp.txt");
	
	if (read.fail()) 
	{
		cout << "\t  ** ERROR : File loading Fail" << endl;
		return;
	}

	read.get(dataType);
	while (!read.eof())
	{
		read.get(dataType);
		if (dataType == 'c')
		{
			read.get(dataType);
			ConferenceType temp;
			ConferenceType *tempPointer;
			string tempName;
			getline(read, tempName, '\t');
			string tempDate;
			getline(read, tempDate, '\t');
			temp.SetRecord(tempName, tempDate);

			m_List.Insert(temp);
			cout << "\t  >> Add Conference Complete." << temp.GetName() << ", " <<temp.GetDateTime() << endl;

			read.get(dataType);
			while (dataType != 'c')
			{
				if (dataType == 'p')
				{
					getline(read, space, '\t');
					tempPointer = m_List.GetCurDataPointer(temp);
					PaperType temp;
					string tempName;
					getline(read, tempName, '\t');
					string tempPage;
					getline(read, tempPage, '\t');
					temp.SetRecord(tempName, tempPage);

					dataType = tempPointer->FileIn(read, temp);
				}
				else
					read.get(dataType);
			}
		}
	}

	read.close();
}
