#pragma once
#include "Tree.h"
template <typename T>
class Tree;
template <typename T>
class TreeNode
{
private:
	friend class Tree < T > ;
	TreeNode<T>* m_left = nullptr;
	TreeNode<T>* m_parent = nullptr;
	TreeNode<T>* m_right = nullptr;
	T m_value;
public:
	TreeNode(const T value) : m_value(value)
	{
	}

	TreeNode<T>* GetLeft() const
	{
		return m_left;
	}

	TreeNode<T>* GetParent() const
	{
		return m_parent;
	}

	TreeNode<T>* GetRight() const
	{
		return m_right;
	}

	T GetValue() const
	{
		return m_value;
	}

	void SetLeft(TreeNode<T>* const left)
	{
		m_left = left;
	}

	void SetParent(TreeNode<T>* const parent)
	{
		m_parent = parent;
	}

	void SetRight(TreeNode<T>* const right)
	{
		m_right = right;
	}
};