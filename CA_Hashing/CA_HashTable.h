#pragma once

//*** REPETITIONS ARE NOT ALLOWED ***//
class CA_HashTable
{
	struct Node{
		int		key_;
		Node*	next_;
		Node(int key=0, Node* next=0):key_(key), next_(next){} 
	};
	
	int hashCode(int key)const;

public:
	CA_HashTable(int size);
	~CA_HashTable(void);
	
	/*1*/ bool  search(int key)const;
	
	//precondition: search(key)==false
	/*2*/ void  insert(int key);
	
	//precondition: search(key)==true
	/*3*/ void  remove(int key);
	
	void  print()const;

private:
	Node**			table_;
	int				size_; 
};



