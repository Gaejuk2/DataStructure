#pragma once
#ifndef _RESULTTYPE_H
#define _RESULTTYPE_H

template <typename T>
class ResultType
{
public:
	/*
	*	Default Constructor
	*/
	ResultType()
	{
		Pointer = 0;
	}

	/*
	*	Destructor
	*/
	~ResultType()
	{

	}

	/*
	*	@brief	Pointer를 초기화하기 위한 함수
	*	@pre	None
	*	@post	Pointer가 초기화 된다.
	*	@param	초기화할 주솟값을 가지는 포인터
	*/
	void SetPointer(T* inPointer);

	/*
	*	@brief	template를 이용하기 위해 GetName이라 명명. Pointer가 가르키는 데이터의 이름을 반환한다
	*	@pre	Pointer가 초기화 되어있어야한다
	*	@post	None
	*	@return	Pointer가 가르키는 데이터의 이름
	*/
	string GetName();

	/*
	*	@brief	Pointer를 반환하는 함수
	*	@pre	Pointer가 초기화되어있어야 한다
	*	@post	None
	*	@return	Pointer
	*/
	T* GetPointer();

	/*
	*	@brief	Compare two item types by item Name.
	*	@pre	Two item types should be initialized.
	*	@post	The target file is included the new item record.
	*	@param	Target item for comparing.
	*	@return	Return LESS if this.name < data.name,
	*			Return GREATER if this.name > data.name then,
	*			Otherwise return EQUAL.
	*/
	RelationType CompareByName(ResultType & data);

	/*
	*	@brief	포인터가 가르키는 데이터의 이름을 출력하는 함수
	*	@pre	Pointer가 초기화되어있어야 한다
	*	@post	데이터의 이름들 화면에 출력
	*/
	void DisplayRecordOnScreen();

private:
	T* Pointer;
};

#endif //_RESULTTYPE_H

template<typename T>
inline void ResultType<T>::SetPointer(T * inInfo)
{
	Pointer = inInfo;
}

template<typename T>
inline string ResultType<T>::GetName()
{
	return Pointer->GetName();
}

template<typename T>
inline T * ResultType<T>::GetPointer()
{
	return Pointer;
}

template<typename T>
inline RelationType ResultType<T>::CompareByName(ResultType & data)
{
	if (data.GetPointer() == NULL)
		return GREATER;

	if (this->GetName() > data.GetName()) // name of the current PaperType > the name of parameter's
		return GREATER;
	else if (this->GetName() < data.GetName()) // name of the current PaperType < the name of parameter's
		return LESS;
	else // name of the current PaperType = the name of parameter's
		return EQUAL;
}

template<typename T>
inline void ResultType<T>::DisplayRecordOnScreen()
{
	Pointer->DisplayRecordOnScreen();
}

