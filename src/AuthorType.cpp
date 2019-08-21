#include "AuthorType.h"

string AuthorType::GetName()
{
	return m_wName;
}

void AuthorType::SetName(string inName)
{
	m_wName = inName;
}

void AuthorType::SetPaperName(string inName)
{
	m_aPaper = inName;
}

void AuthorType::SetRecord(string inName)
{
	SetName(inName);
}

void AuthorType::SetNameFromKB()
{
	cout << "\t  Writer of Paper  : ";
	getline(cin, m_wName);
}

void AuthorType::SetRecordFromKB()
{
	SetNameFromKB();
}

void AuthorType::DisplayNameOnScreen()
{
	cout << "\t   " << m_wName;
}

void AuthorType::DisplayRecordOnScreen()
{
	DisplayNameOnScreen();
}

RelationType AuthorType::CompareByName(AuthorType & data)
{
	if (this->GetName() > data.m_wName) // name of the current itemType > the name of parameter's
		return GREATER;
	else if (this->GetName() < data.m_wName) // name of the current itemType < the name of parameter's
		return LESS;
	else // name of the current ItemType = the name of parameter's
		return EQUAL;
}

void AuthorType::RetrieveByName(string dummyString, int &dummyInt)
{
}
