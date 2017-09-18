#pragma once
template <typename TArr>
class Delete
{
public:
	void operator()(TArr* const ptr)
	{
		delete ptr;
	}
};
template <typename TArr>
class Delete <TArr[]>
{
public:
	void operator()(TArr * const ptr)
	{
		delete[] ptr;
	}
};
//Another classes with algoritms
//template <typename TCArr>
//class ComDeleter
//{
//public:
//	void operator()(TCArr* const pointer)
//	{
//		pointer->Release();//Not realised
//	}
//};