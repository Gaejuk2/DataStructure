#pragma once

#ifndef _AUTHORTYPE_H
#define _AUTHORTYPE_H

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

/*
*	Relation between two writer.
*/
enum RelationType { LESS, GREATER, EQUAL };

enum ResultDisplayMode { CONFERENCE, PAPER, AUTHOR };

class AuthorType
{
public:
	/*
	*	Default Constructor
	*/
	AuthorType()
	{
		m_wName = "";
	}

	/*
	*	Destructor
	*/
	~AuthorType()
	{

	}

	/*
	*	@brief	Get name of writer.
	*	@pre	Name of writer is set.
	*	@post	None.
	*	@return	Name of writer.
	*/
	string GetName();

	/*
	*	@brief	Set name of writer.
	*	@pre	None.
	*	@post	Name of writer is set.
	*	@param	Name of writer.
	*/
	void SetName(string inName);

	/*
	*	@brief	Set name of Paper.
	*	@pre	None.
	*	@post	Name of paper is set.
	*	@param	Name of paper.
	*/
	void SetPaperName(string inName);

	/*
	*	@brief	Set record of writer.
	*	@pre	None.
	*	@post	Record of writer is set.
	*	@param	Record of writer.
	*/
	void SetRecord(string inName);

	/*
	*	@brief	Set name of writer from keyboard.
	*	@pre	None.
	*	@post	Name of writer is set.
	*/
	void SetNameFromKB();

	/*
	*	@brief	Set record of session from keyboard.
	*	@pre	None.
	*	@post	Record of session is set.
	*/
	void SetRecordFromKB();

	/*
	*	@brief	Display name of writer on screen.
	*	@pre	Name of writer is set.
	*	@post	Name of writer is on screen.
	*/
	void DisplayNameOnScreen();

	/*
	*	@brief	Display record of writer on screen.
	*	@pre	Record of writer is set.
	*	@post	Record of writer is on screen.
	*/
	void DisplayRecordOnScreen();


	/*
	*	@brief	Compare two item types by item Name.
	*	@pre	Two item types should be initialized.
	*	@post	The target file is included the new item record.
	*	@param	Target item for comparing.
	*	@return	Return LESS if this.name < data.name,
	*			Return GREATER if this.name > data.name then,
	*			Otherwise return EQUAL.
	*/
	RelationType CompareByName(AuthorType &data);

	/*
	*	@brief	template를 이용하기 위한 dummy 함수로써 실제로 사용되지 않는다.
	*/
	void RetrieveByName(string dummyString, int &dummyInt);

protected:
	string m_aPaper;

	string m_wName;
};

#endif //_WRITERTYPE_H