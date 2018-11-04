
#ifndef _PAPERTYPE_H
#define _PAPERTYPE_H

#include "AuthorType.h"
#include "ResultType.h"
#include "RedBlackTree.h"

/*
*	Paper informaion class
*/
class PaperType
{
public:
	/*
	*	Default Contructor.
	*/
	PaperType()
	{
		m_pConference = "";
		m_pTitle = "";
		m_pPages = -1;
		authorList.MakeTreeEmpty();
	}

	/*
	*	Destructor
	*/
	~PaperType()
	{

	}

	/*
	*	@brief	Get title of paper.
	*	@pre	Title of paper is set.
	*	@post	None.
	*	@return	Title of paper.
	*/
	string GetName();

	/*
	*	@brief	Get number of paper pages.
	*	@pre	Number of paper pages is set.
	*	@post	None.
	*	@return	Number of paper pages.
	*/
	string GetPages();

	/*
	*	@brief	Set title of paper.
	*	@pre	None.
	*	@post	Title of paper is set.
	*	@param	Title of paper.
	*/
	void SetName(string inTitle);

	/*
	*	@brief	Set number of paper pages.
	*	@pre	None.
	*	@post	Number of paper pages is set.
	*	@param	Number of paper pages.
	*/
	void SetPages(string inPages);

	/*
	*	@brief	Set Conference and Session of paper.
	*	@pre	None.
	*	@post	Conference and Session of paper are set.
	*	@param	Conference name.
	*	@paprm	Session name.
	*/
	void SetConference(string inConference);

	/*
	*	@brief	Set paper record.
	*	@pre	None.
	*	@post	Paper record set.
	*	@param	Title of paper.
	*	@param	Number of paper pages.
	*/
	void SetRecord(string inTitle, string inPages);

	/*
	*	@brief	Set title of paper from keyboard.
	*	@pre	None.
	*	@post	Title of paper is set.
	*/
	void SetNameFromKB();

	/*
	*	@brief	Set number of paper pages from keyboard.
	*	@pre	None.
	*	@post	Number of paper pages is set.
	*/
	void SetPagesFromKB();

	/*
	*	@brief	Set paper record from keyboard.
	*	@pre	None.
	*	@post	Paper record is set.
	*/
	void SetRecordFromKB();

	/*
	*	@brief	Display Conference of paper on screen.
	*	@pre	Conference of paper is set.
	*	@post	Conference of paper is on screen.
	*/
	void DisplayConferenceOnScreen();

	/*
	*	@brief	Display title of paper on screen.
	*	@pre	Title of paper is set.
	*	@post	Title of paper is on screen.
	*/
	void DisplayNameOnScreen();

	/*
	*	@brief	Display number of paper pages on screen.
	*	@pre	Number of paper pages is set.
	*	@post	Number of paper pages is on screen.
	*/
	void DisplayPagesOnScreen();

	/*
	*	@brief	Display authorList on screen.
	*	@pre	AuthorList is set.
	*	@post	AuthorList is on screen.
	*/
	void DisplayAuthorOnScreen();

	/*
	*	@brief	Display paper record on screen.
	*	@pre	Paper record is set.
	*	@post	Paper record is on screen.
	*/
	void DisplayRecordOnScreen();

	/*
	*	@brief	Compare two Paper types by title.
	*	@pre	two paper types should be initialized.
	*	@post	the target data is included the new item record.
	*	@param	target data for comparing.
	*	@return	return LESS if this.name < data.name,
	*			return GREATER if this.name > data.name then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByName(PaperType &data);

	/*
	*	@brief	Author Management Mode.
	*	@pre	None.
	*	@post	AuthorList change.
	*/
	void AuthorManagement();

	/*
	*	@brief	Add new record into list.
	*	@pre	None.
	*	@post	New record is added into the list.
	*/
	void AddAuthor();

	/*
	*	@brief	Delete data user want.
	*	@pre	List should be initialized.
	*	@post	List without data user want.
	*/
	void DeleteAuthor();

	/*
	*	@brief	Replace data user want.
	*	@pre	List should be initialized.
	*	@post	List with replaced data.
	*/
	void ReplaceAuthor();

	/*
	*	@brief	Display all records in the tree on screen.
	*	@pre	None.
	*	@post	None.
	*/
	void DisplayAllAuthor();

	/*
	*	@brief	Display all results in the tree on screen.
	*	@pre	None.
	*	@post	None.
	*/
	void DisplayAllResult(ResultDisplayMode mode);

	/*
	*	@brief	Retrieve Author in AuthorList by keyword.
	*	@pre	None.
	*	@post	WRL have data that find by keyword.
	*	@param	Keyword.
	*	@param	AuthorList where the found data wil be stored.
	*/
	void RetrieveByName(string searchName, int &location);

	/*
	*	@brief	파일로 부터 데이터를 불러와서 Tree에 저장한다
	*	@pre	파일의 데이터 형식을 잘 판별하여 Tree에 저장할 수 있도록 텍스트 파일에 데이터가 일관 되게 저장되어있어야 한다
	*	@post	Tree에 데이터 저장
	*/
	void FileIn(AuthorType temp);

protected:
	string m_pConference;
	RedBlackTree<ResultType<AuthorType>> ARL;

	string m_pTitle;
	string m_pPages;
	RedBlackTree<AuthorType> authorList;
};

#endif

