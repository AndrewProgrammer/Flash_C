#pragma once

#include <iostream>

#include "Treenode.h"

template < typename T>
class TreeNode;
template <typename T>
class Tree
{
private:
	friend class  TreeNode < T > ;
	TreeNode<T>* m_root = nullptr;
	int m_length;
public:
	Tree()
	{

	}
	Tree(const Tree<T>& tree)
	{
		Tree<T>* root = tree.m_root;
		for (size_t i = 0; i < list.m_length; i++)
		{
			this->Add(root->GetValue());
			root = root->GetRoot();
		}
	}

	Tree(Tree<T>&& tree)
	{
		this->m_root = tree.m_root;
		this->m_length = tree.m_length;
		tree.m_root = nullptr;
		tree.m_length = 0;
	}
	void DelTree(TreeNode<T> const * node)
	{
		if (node != nullptr)
		{
			DelTree(node->GetLeft());
			DelTree(node->GetRight());
			delete node;
			node = nullptr;
		}
	}
	~Tree()
	{
		DelTree(m_root);
	}

	Tree<T>& operator=(const Tree<T>& right)
	{
		if (this != &right)
		{
			delete m_root;
			TreeNode<T> * node = right.m_root;
			for (size_t i = 0; i < right.m_length; i++)
			{
				this->Add(node->GetValue());
				node = node->GetNext();
			}
		}

		return *this;
	}

	Tree<T>& operator=(Tree<T>&& right)
	{
		if (this != &right)
		{
			delete m_root;
			m_length = right.m_length;
			m_root = right.m_root;
			right.m_root = nullptr;
		}
		return *this;
	}

	void Add(const T value)
	{
		Add(new TreeNode<T>(value));
	}

	void Add(TreeNode<T>* const node)
	{
		if (node == nullptr)
		{
			std::cout << "ERROR: Node cannot be nullptr." << endl;
		}

		if (IsEmpty())
		{
			m_root = node;
		}
		else
		{
			TreeNode<T>* current = m_root;
			TreeNode<T>* m_parent = nullptr;

			while (current != nullptr)
			{
				m_parent = current;

				if (node->GetValue() < current->GetValue())
				{
					current = current->GetLeft();
				}
				else
				{
					current = current->GetRight();
				}
			}

			node->SetParent(m_parent);

			if (node->GetValue() < m_parent->GetValue())
			{
				m_parent->SetLeft(node);
			}
			else
			{
				m_parent->SetRight(node);
			}
		}
		++m_length;
	}

	TreeNode<T>* GetRoot() const
	{
		return m_root;
	}

	bool IsEmpty() const
	{
		return m_root == nullptr;
	}

	TreeNode<T>* Maximum(TreeNode<T>* const node) const //Поиск махимума в под дереве 
	{
		TreeNode<T> * max = nullptr;
		if (node != nullptr)
		{
			max = node;
			while (max->GetRight() != nullptr)
			{
				max = max->GetRight();
			}
			return max;

		}
		else
		{
			return node;
		}
	}

	TreeNode<T>* Minimum(TreeNode<T>* const node) const
	{
		TreeNode<T> * min = nullptr;
		if (node != nullptr)
		{
			min = node;
			while (min->GetLeft() != nullptr)
			{
				min = min->GetLeft();
			}
			return min;

		}
		else
		{
			return node;
		}
	}

	TreeNode<T>* Next(const TreeNode<T>* const node) const // Следующий элемент(узел) который больший по возрастанию
	{
		if (!IsEmpty())
		{
			if (node->GetRight() == nullptr && node->GetValue() < node->GetParent()->GetValue())
			{
				return node->GetParent();
			}
			if (node->GetLeft() != nullptr)
			{
				return Minimum(node->GetRight());
			}
		}
		else
		{
			return nullptr;
		}
	}

	TreeNode<T>* Previous(const TreeNode<T>* const node) const //
	{
		if (!IsEmpty())
		{
			if (node->GetRight() == nullptr && node->GetValue() < node->GetParent()->GetValue())
			{
				return node->GetParent();
			}
			if (node->GetLeft() != nullptr)
			{
				return Maximum(node->GetLeft());
			}
		}
		else
		{
			return nullptr;
		}
	}

	bool Remove(const T value) // 

	{
		return Remove(Search(value));
	}

	bool Remove(TreeNode<T>* const node)
	{
		if (node == nullptr)
		{
			return false;
		}
		else
		{
			if (node->GetLeft() == nullptr && node->GetRight() == nullptr)
			{
				if (node->GetParent() == nullptr)
				{
					m_root = nullptr;
				}
				else
				{
					if (node->GetValue() < node->GetParent()->GetValue())
					{
						node->GetParent()->SetLeft(nullptr);
					}
					else
					{
						node->GetParent()->SetRight(nullptr);
					}
				}
			}
			else if (node->GetLeft() != nullptr && node->GetRight() != nullptr)
			{
				node->GetRight()->SetParent(node->GetParent());
				if (node->GetParent() == nullptr)
				{
					m_root = node->GetRight();
				}
				else
				{
					if (node->GetValue() < node->GetParent()->GetValue())
					{
						node->GetParent()->SetLeft(node->GetRight());
					}
					else
					{
						node->GetParent()->SetRight(node->GetRight());
					}
				}
				node->GetLeft()->SetParent(Minimum(node->GetRight()));
				Minimum(node->GetRight())->SetLeft(node->GetLeft());
			}
			else if (node->GetLeft() != nullptr)
			{
				node->GetLeft()->SetParent(node->GetParent());
				if (node->GetValue() < node->GetParent()->GetValue())
				{
					node->GetParent()->SetLeft(node->GetLeft());
				}
				else
				{
					node->GetParent()->SetRight(node->GetLeft());
				}
			}
			else if (node->GetRight() != nullptr)
			{
				node->GetRight()->SetParent(node->GetParent());
				if (node->GetValue() < node->GetParent()->GetValue())
				{
					node->GetParent()->SetLeft(node->GetRight());
				}
				else
				{
					node->GetParent()->SetRight(node->GetRight());
				}
			}
			delete node;
			return true;
		}
	}

	TreeNode<T>* Search(const T value) // Находим узел с таким значением
	{
		if (!IsEmpty())
		{
			TreeNode<T> * node = m_root;
			while (node != nullptr)
			{
				if (value < node->GetValue())
				{
					node = node->GetLeft();
				}
				if (value > node->GetValue())
				{
					node = node->GetRight();
				}
				if (value == node->GetValue())
				{
					return node;
				}
			}
		}
		else
		{
			return nullptr;
		}
	}
};

template <typename T>
void Show(std::ostream& os, const TreeNode<T>* const node)
{
	if (node != nullptr)
	{
		Show(os, node->GetLeft());
		os << node->GetValue() << ' ';
		Show(os, node->GetRight());
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& tree)
{
	Show(os, tree.GetRoot());

	return os;
}