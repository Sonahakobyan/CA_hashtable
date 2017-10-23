#include "stdafx.h"
#include "CA_HashTable.h"
#include <iostream>
using namespace std;

CA_HashTable::CA_HashTable(int size) :
	size_(size), table_(new Node*[size])
{
	for (int i = 0; i<size; i++)
		table_[i] = 0;
}

CA_HashTable::~CA_HashTable(void)
{
	Node* temp;
	for (int i = 0; i<size_; i++)
		while (table_[i] != 0)
		{
			temp = table_[i];
			table_[i] = temp->next_;
			delete temp;
		}
	delete[]table_;
}

int
CA_HashTable::hashCode(int key)const
{
	return (10 * key) % size_;
}

bool
CA_HashTable::search(int key)const
{
	int code = hashCode(key);
	Node* cur = table_[code];
	while (cur != nullptr)
	{
		if (cur->key_ == key)
		{
			return true;
		}
		cur = cur->next_;
	}
	return false;
}

void
CA_HashTable::insert(int key)
{
	if (search(key))
	{
		return;
	}
	int code = hashCode(key);
	Node* cur = table_[code];
	if (cur == nullptr)
	{
		table_[code] = new Node(key, 0);
	}
	else
	{
		while (cur->next_ != 0)
		{
			cur = cur->next_;
		}
		cur->next_ = new Node(key, 0);
	}
}

void
CA_HashTable::remove(int key)
{
	int code = hashCode(key);
	Node* cur = table_[code];
	Node* tmp = cur;
	while (cur != nullptr)
	{
		if (cur->key_ == key)
		{
			if (cur->next_ != nullptr) {
				Node* temp = cur->next_;
				if (tmp == cur)
					table_[code] = temp;
				else
					tmp->next_ = temp;
				delete cur;
			}
			else if (tmp == cur) {
				delete cur;
				table_[code] = nullptr;
			}
			else {
				delete cur;
				tmp->next_ = nullptr;
			}
			return;
		}
		tmp = cur;
		cur = cur->next_;
	}
}

void
CA_HashTable::print()const
{
	Node* current;
	for (int i = 0; i<size_; i++)
	{
		cout << i << ": ";
		for (current = table_[i]; current != 0; current = current->next_)
			cout << current->key_ << " ";
		cout << endl;
	}
	cout << endl;
}
