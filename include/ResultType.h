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
	*	@brief	initialize pointer
	*	@pre	None
	*	@post	initialized pointer
	*	@param	Pointer with address to initialize
	*/
	void SetPointer(T* inPointer);

	/*
	*	@brief	template�� �̿��ϱ� ���� GetName�̶� ����. Pointer�� ����Ű�� �������� �̸��� ��ȯ�Ѵ�
	*	@pre	Pointer�� �ʱ�ȭ �Ǿ��־���Ѵ�
	*	@post	None
	*	@return	Pointer�� ����Ű�� �������� �̸�
	*/
	string GetName();

	/*
	*	@brief	Pointer�� ��ȯ�ϴ� �Լ�
	*	@pre	Pointer�� �ʱ�ȭ�Ǿ��־�� �Ѵ�
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
	*	@brief	�����Ͱ� ����Ű�� �������� �̸��� ����ϴ� �Լ�
	*	@pre	Pointer�� �ʱ�ȭ�Ǿ��־�� �Ѵ�
	*	@post	�������� �̸��� ȭ�鿡 ���
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

