#pragma once

typedef unsigned int uint;

class String
{
	uint m_length = 0;
	uint m_capacity = 32;
	char* m_string = nullptr;
	//�������� ��� ����, � ��� ������ � private
	//��������� ���� �����,� ��� � ��������� ������� ����������� �������� ��� ����� ������� �� ��������, � ��� � ����������� �����������
public:
	~String();
	//
	//static String Empty()
	//{
	//	String str(" ");
	//	retunr str;
	//}
	//
	//
	String(String&& string); // Move ctor.
	String& operator=(String&& right); // Move assignment oper.
	void Swap(String& string);
	//
	String();//������� ������ ����������� ������ ������(����� �� 0)
	//
	String(const uint capacity);//������ � ����� �������� ����������� ������(������ ������)
	//
	String(const char character, const uint count);//������ �� ���������� ������ �������
	//
	String(const char* const string);//��������� ������(����������)
	//
	String(const char* const string, const uint length);//������� �������� �� ������ �������� �� ���� ������ �����
	//
	String(const String& string);//����� ���(����������� �����������)
	//
	String(const String& string, const uint startIndex);//��������� �� ������� �� �����
	//
	String(const String& string, const uint startIndex, const uint length);//������� ������ �� ��������� ����� ������ ������

	String& operator =(const String& right);
	String& operator +=(const String& right);
	String operator +(const String& right)const;
	bool operator >(const String& right)const;
	bool operator <(const String& right)const;
	bool operator >=(const String& right)const;
	bool operator <=(const String& right)const;
	bool operator ==(const String& right)const;
	bool operator !=(const String& right)const;

	//
	void Append(const String& string);//�������� � ������� ������,���
	//
	void Append(const String& string, const uint startIndex);//���������� � ������� ������, � ������ �� ������� �� �����
	//
	void Append(const String& string, const uint startIndex, const uint length);//���������� � ������� ������, � ������ �� ������� �� ������-��.(� �����)
	//
	void Assign(const String& string);//������������,��������� ��� ������(strcpy)
	//
	void Assign(const String& string, const uint startIndex);//��������� � ������� � �� �����
	//
	void Assign(const String& string, const uint startIndex, const uint length);//��������� � ������� � �� ������-��
	//
	int CompareTo(const String& string)const;//��� ������� ������������ �� �������� ������,������,�����(�� ��������� ACSII)� ���������� int -1 ��� ������ ������ �������, 1- ��� ������ ��� ��� ������� ��������, 0 - ���������
	//
	int CompareTo(const String& string, const bool ignoreCase)const;//����� �� ��� ������������ �������,���� true ���������� ������� �������(stricmp)
	//
	int CompareTo(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length)const;//��������� ���� ��������
	//
	int CompareTo(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length, const bool ignoreCase)const;//��������� ���� �������� � ������� ��������
	//
	bool EndsWith(const String& string)const;//������������� ���� ������ �� ��� ����� ��� ������
	//
	bool EndsWith(const String& string, const bool ignoreCase)const;//������������� ���� ������ �� ��� ����� ������ � ������������ ���������
	//
	bool EqualsTo(const String& string)const;//����� �� ������(0)
	//
	bool EqualsTo(const String& string, const bool ignoreCase)const;//����� �� ������(0) � ����������� ��������
	//
	const char* GetCString()const;//������ ������� ����� ������
	//
	uint GetLength()const;//�������� ����� ������
	//
	int IndexOf(const char character) const;//����� ������ ������� ���������(����� ������ � ������),���� ��� ������� -1
	//
	int IndexOf(const char character, const uint startIndex) const;//����� ���� ������ startIndex � �� �����
	//
	int IndexOf(const char character, const uint startIndex, const uint length) const;//����� ������ �� ���� ������ � ������
	//
	int IndexOf(const String& string)const;//�� ���� ��������� � ����� ������
	//
	int IndexOf(const String& string, const uint startIndex) const;
	//
	int IndexOf(const String& string, const uint startIndex, const uint length) const;
	//
	void Insert(const uint thisStartIndex, const String& string) const;//������� ������ � ���� ������
	//
	void Insert(const uint thisStartIndex, const String& string, const uint otherStartIndex);
	//---
	void Insert(const uint thisStartIndex, const String& string, const uint otherStartIndex, const uint length);//������� ��������� �� ������� � ���� ������(������� �������)
	//
	bool IsEmpty()const;//������ �� ������(true ���� ����� ����� ����)
	//
	int LastIndexOf(const char character)const;//����� ������� ������� � �����(���� ��������� ��������� ������, ��� �������)
	//
	int LastIndexOf(const char character, const uint startIndex)const;
	//
	int LastIndexOf(const char character, const uint startIndex, const uint length)const;
	//
	int LastIndexOf(const String& string)const;
	//
	int LastIndexOf(const String& string, const uint startIndex)const;
	//
	int LastIndexOf(const String& string, const uint startIndex, const uint length)const;
	//
	uint PadLeft(const uint totalWidth);//������ ����� ������� ����� ��� ����� ������� �������(������� ����������� ��������)
	//
	uint PadLeft(const uint totalWidth, const char padCharacter);//������ ����� ����� - �� �������� ����� ��� ����� ������� �������,������������ ����������� ���������� ��������
	//
	uint PadRight(const uint totalWidth);
	//
	uint PadRight(const uint totalWidth, const char padCharacter);
	//
	void Remove(const uint startIndex);//������� �������� ������,������� � ������ �� ������� � �� ����� � ������� ����� ����� ������
	//
	void Remove(const uint startIndex, const uint length);//������ ��������
	//
	void Replace(const char oldCharacter, const char newCharacter);//������ ���� �������� � ������ �� ����� �������(��������:��� 1 � ������ �� 2)
	//
	void Replace(const String& oldString, const String& newString);//�������� ��������� �� ���������
	//
	void Reverse();//����������� ������
	//
	bool StartsWith(const String& string)const;//���������� �� ������ � ���������
	//
	bool StartsWith(const String& string, const bool ignoreCase)const;//���������� �� ������ � ��������� � ���������
	//
	String Substring(const uint startIndex)const;//�� ����� �������� ����� ������ ������� ������ �� � ���� ��������� �� ����� ������
	//
	String Substring(const uint startIndex, const uint length)const;//�� ����� �������� ����� ������ ������� ������ �� � ���� ��������� �� ����� ������(� �������)
	//
	void ToLower();//������� � ������ ������� ���� ������
	//
	void ToUpper();//������� � ������� ������� ���� ������
	//
	uint Trim();//�������� ��� ������� � ���� ������(��������� �������)
	//
	uint Trim(const char trimCharacter);//�������� ������� �� ���� ������ 
	//
	uint TrimBegin();//�������� ������� ������
	//
	uint TrimBegin(const char trimCharacter);//�������� ������� � ������
	//
	uint TrimEnd();//�������� ��� ������� � �����
	//
	uint TrimEnd(const char trimCharacter);//�������� ��� ������� � �����
};