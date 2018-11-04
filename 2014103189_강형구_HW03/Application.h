
#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "ConferenceType.h"

enum ModeNum { START, USER, MANAGE };

/*
*	application class for item management simply.
*/
class Application
{
public:
	/*
	*	application class for item management simply.
	*/
	Application()
	{
		m_Command = 0;
		m_List.MakeTreeEmpty();
	}

	/*
	*	Destructor.
	*/
	~Application()
	{
		m_List.MakeTreeEmpty();
	}

	/*
	*	@brief	Program driver.
	*	@pre	Program is started.
	*	@post	Program is finished.
	*/
	void Run();

	/*
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	None.
	*	@post	None.
	*	@return	User's command.
	*/
	int GetCommand(ModeNum modeNum);

	/*
	*	@brief	User mode start.
	*	@pre	User mode is started.
	*	@post	User mode is finished.
	*/
	void UserMode();

	/*
	*	@brief	Search the conference by keyword and display it.
	*	@pre	None.
	*	@post	None.
	*/
	void RetrieveByName();

	/*
	*	@brief	Management mode start.
	*	@pre	Management mode is started.
	*	@post	Management mode is finished.
	*/
	void ManageMode();

	/*
	*	@brief	Delete data user want.
	*	@pre	List should be initialized.
	*	@post	List without data user want.
	*/
	void DeleteConference();

	/*
	*	@brief	Replace data user want.
	*	@pre	List should be initialized.
	*	@post	List with replaced data.
	*/
	void ReplaceConference();

	/*
	*	@brief	Add new record into list.
	*	@pre	List should be initialized.
	*	@post	New record is added into the list.
	*/
	void AddConference();

	/*
	*	@brief	Display all records in the tree on screen.
	*	@pre	None.
	*	@post	None.
	*/
	void DisplayAllConference();

	/*
	*	@brief	Display all results in the tree on screen.
	*	@pre	None.
	*	@post	None.
	*/
	void DisplayAllResult(ResultDisplayMode mode);

	/*
	*	@brief	Paper management mode start.
	*	@pre	List and parameter should be initialized.
	*	@post	PaperList is changed.
	*/
	void PaperManagementMode();

	/*
	*	@brief	파일로 부터 데이터를 불러와서 Tree에 저장한다
	*	@pre	파일의 데이터 형식을 잘 판별하여 Tree에 저장할 수 있도록 텍스트 파일에 데이터가 일관 되게 저장되어있어야 한다
	*	@post	Tree에 데이터 저장
	*/
	void FileIn();

private:
	RedBlackTree<ConferenceType> m_List;		///< item list.
	int m_Command;								///< current command number.

	RedBlackTree<ResultType<ConferenceType>> CRL;
};

#endif	// _APPLICATION_H
