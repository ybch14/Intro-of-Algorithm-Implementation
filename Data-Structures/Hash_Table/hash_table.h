#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include <string>
#include <iostream>

class Node
{
private:
	std::string _key;
	Node* _next;
public:
	Node();
	Node(std::string key);
	std::string key();
	friend class List;
	friend class HashTable;
	friend std::ostream& operator<<(std::ostream& os, List& L);
	friend std::ostream& operator<<(std::ostream& os, HashTable& HT);
};

class List
{
private:
	Node* _head;
public:
	List();
	~List();
	List(const List& L);
	void operator=(List& L);
	friend std::ostream& operator<<(std::ostream& os, List& L);
	friend std::ostream& operator<<(std::ostream& os, HashTable& HT);
	int size();
	std::string key();
	void insert(std::string key);
	friend class HashTable;
};

class HashTable
{
private:
	List* _table;
	int _table_size;
	char _mode;
	unsigned int BKDRHash(std::string key);
	unsigned int APHash(std::string key);
	unsigned int linear_detect_hash(std::string key, unsigned int index);
	unsigned int double_detect_hash(std::string key, unsigned int index);
public:
	~HashTable();
	HashTable(int table_size, char mode='d');
	HashTable(const HashTable& HT);
	void operator=(HashTable& HT);
	int table_size();
	void insert(std::string key);
	std::string key(int index);
	int list_size(int index);
	friend std::ostream& operator<<(std::ostream& os, HashTable& HT);
};

#endif