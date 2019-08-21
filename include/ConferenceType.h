
#ifndef _CONFERENCETYPE_H
#define _CONFERENCETYPE_H

#include "PaperType.h"

/*
*	conference information class.
*/
class ConferenceType
{
public:
	/*
	*	Default Constructor.
	*/
	ConferenceType()
	{
		m_cName = "";
		m_cDateTime = "";
		paperList.MakeTreeEmpty();
	}

	/*
	*	Destructor.
	*/
	~ConferenceType()
	{

	}

	/*
	*	@brief	Get conference name.
	*	@pre	Conference name is set.
	*	@post	None.
	*	@return	Conference name.
	*/
	string GetName();

	/*
	*	@brief	Get conference date.
	*	@pre	Conference date is set.
	*	@post	None.
	*	@return	Conference date.
	*/
	string GetDateTime();

	/*
	*	@brief	Set conference name.
	*	@pre	None.
	*	@post	Conference name is set.
	*	@param	Conference name.
	*/
	void SetName(string inName);

	/*
	*	@brief	Set conference date and time.
	*	@pre	None.
	*	@post	Conference date and time is set.
	*	@param	Conference date and time.
	*/
	void SetDateTime(string inDateTime);

	/*
	*	@brief	Set conference record.
	*	@pre	none.
	*	@post	conference record is set.
	*	@param	conference name.
	*	@param	Date and time of the conference held.
	*	@param	Place where conference held.
	*	@param	number of times of conference.
	*	@param	conference organization.
	*	@param	ISBN of conference.
	*/
	void SetRecord(string inName, string inDateTime);

	/*
	*	@brief	Display conference name on screen.
	*	@pre	Conference name is set.
	*	@post	Conference name is on screen.
	*/
	void DisplayNameOnScreen();

	/*
	*	@brief	Display conference date and time on screen.
	*	@pre	Conference date and time is set.
	*	@post	Conference date and time is on screen.
	*/
	void DisplayDateTimeOnScreen();

	/*
	*	@brief	Display sessionList on screen.
	*	@pre	SessionList is set.
	*	@post	SessionList is on screen.
	*/
	void DisplayPaperOnScreen();

	/*
	*	@brief	Display an conference record on screen.
	*	@pre	Conference record is set.
	*	@post	Conference record is on screen.
	*/
	void DisplayRecordOnScreen();

	/*
	*	@brief	Set conference name from keyboard.
	*	@pre	None.
	*	@post	Conference name is set.
	*/
	void SetNameFromKB();

	/*
	*	@brief	Set conference date from keyboard.
	*	@pre	None.
	*	@post	Conference date is set.
	*/
	void SetDateTimeFromKB();

	/*
	*	@brief	Set conference record from keyboard.
	*	@pre	None.
	*	@post	Conference record is set.
	*/
	void SetRecordFromKB();

	/*
	*	@brief	Compare two item types by item Name.
	*	@pre	Two item types should be initialized.
	*	@post	The target file is included the new item record.
	*	@param	Target item for comparing.
	*	@return	Return LESS if this.name < data.name,
	*			Return GREATER if this.name > data.name then,
	*			Otherwise return EQUAL.
	*/
	RelationType CompareByName(ConferenceType &data);

	/*
	*	@brief	Session Management Mode.
	*	@pre	None.
	*	@post	SessionList change.
	*/
	void PaperManagement();

	/*
	*	@brief	Add new record into list.
	*	@pre	None.
	*	@post	New record is added into the list.
	*/
	void AddPaper();

	/*
	*	@brief	Delete data user want.
	*	@pre	List should be initialized.
	*	@post	List without data user want.
	*/
	void DeletePaper();

	/*
	*	@brief	Replace data user want.
	*	@pre	List should be initialized.
	*	@post	List with replaced data.
	*/
	void ReplacePaper();

	/*
	*	@brief	Display all records in the tree on screen.
	*	@pre	None.
	*	@post	None.
	*/
	void DisplayAllPaper();

	/*
	*	@brief	Display all results in the tree on screen.
	*	@pre	None.
	*	@post	None.
	*/
	void DisplayAllResult(ResultDisplayMode mode);

	/*
	*	@brief	Enter author management mode.
	*	@pre	List and parameter should be initialized.
	*	@post	PaperList is changed.
	*	@param	Paper to manage in author management mode.
	*/
	void AuthorManagementMode();

	/*
	*	@brief	Retrieve Paper in paperList by keyword.
	*	@pre	None.
	*	@post	PRL, ARL have data that find by keyword.
	*	@param	Keyword.
	*	@param	int value that indicates which stage the search is at.
	*/
	void RetrieveByName(string searchName, int &location);

	/*
	*	@brief	Import data from a file and save it to a tree.
	*	@pre	Files should be stored consistently so that they can be stored in a tree by determining the type of data in the file.
	*	@post	Tree where data is stored.
	*/
	char FileIn(ifstream &read, PaperType temp);
	
protected:
	string m_cName;							///< conference name
	string m_cDateTime;						///< conference date and time
	RedBlackTree<PaperType> paperList;		///< conference session

	RedBlackTree<ResultType<PaperType>> PRL;
};

#endif	// _ConferenceType_H
