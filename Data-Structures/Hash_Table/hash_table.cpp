#include "hash_table.h"

Node::Node()
{
	_key = "";
	_next = NULL;
}

Node::Node(std::string key)
{
	_key = key;
	_next = NULL;
}

std::string Node::key()
{
	return _key;
}

List::List()
{
	_head = new Node;
}

List::~List()
{
	Node *cur = _head, *cur_next = NULL;
	while (cur != NULL)
	{
		cur_next = cur->_next;
		delete cur;
		cur = cur_next;
	}
}

List::List(const List& L)
{
	Node *cur = L._head, *self_cur = _head;
	while (cur != NULL)
	{
		self_cur = new Node(cur->_key);
		self_cur = self_cur->_next;
		cur = cur->_next;
	}
}

void List::operator=(List& L)
{
	Node *cur = L._head, *cur_next = NULL;
	while (cur != NULL)
	{
		cur_next = cur->_next;
		delete cur;
		cur = cur_next;
	}
	
	cur = L._head;
	Node *self_cur = _head;
	while (cur != NULL)
	{
		self_cur = new Node(cur->_key);
		self_cur = self_cur->_next;
		cur = cur->_next;
	}
}

std::ostream& operator<<(std::ostream& os, List& L)
{
	if (L.size() > 0)
	{
		Node* cur = L._head->_next;
		while (cur->_next != NULL)
		{
			os << cur->_key << " -> ";
			cur = cur->_next;
		}
		os << cur->_key;
	}
	return os;
}

int List::size()
{
	int size = 0;
	Node* cur = _head->_next;
	while (cur != NULL)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

std::string List::key()
{
	if (_head->_next != NULL)
		return _head->_next->key();
	else
		return "";
}

void List::insert(std::string key)
{
	Node* n = new Node(key);
	n->_next = _head->_next;
	_head->_next = n;
}

HashTable::HashTable(int table_size, char mode)
{
	_table_size = table_size;
	_table = new List[_table_size];
	_mode = mode;
}

HashTable::~HashTable()
{
	delete[]_table;
}

HashTable::HashTable(const HashTable& HT)
{
	_table_size = HT._table_size;
	_table = new List[_table_size];
	for (int i = 0; i < _table_size; i++)
	{
		_table[i] = HT._table[i];
	}
	_mode = HT._mode;
}

void HashTable::operator=(HashTable& HT)
{
	delete[]_table;
	_table_size = HT._table_size;
	_table = new List[_table_size];
	for (int i = 0; i < _table_size; i++)
	{
		_table[i] = HT._table[i];
	}
	_mode = HT._mode;
}

int HashTable::table_size()
{
	return _table_size;
}

int HashTable::list_size(int index)
{
	if (index >= _table_size)
	{
		std::cerr << "Index out of range!" << std::endl;
		exit(-1);
	}
	else
	{
		return _table[index].size();
	}
	
}

unsigned int HashTable::BKDRHash(std::string key)
{
	const char* str = key.c_str();
	unsigned int seed = 131;
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7fffffff);
}

unsigned int HashTable::APHash(std::string key)
{
	const char* str = key.c_str();
	unsigned int hash = 0;
	for (int i = 0; *str; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
		}
		else
		{
			hash ^= (~(hash << 11) ^ (*str++) ^ (hash >> 5));
		}
	}
	return (hash & 0x7fffffff);
}

unsigned int HashTable::linear_detect_hash(std::string key, unsigned int index)
{
	return (BKDRHash(key) + index) % _table_size;
}

unsigned int HashTable::double_detect_hash(std::string key, unsigned int index)
{
	return (BKDRHash(key) + index * APHash(key)) % _table_size;
}

std::ostream& operator<<(std::ostream& os, HashTable& HT)
{
	for (int i = 0; i < HT._table_size - 1; i++)
	{
		if (HT._table[i].size() > 0)
			os << "0 -> " << HT._table[i] << std::endl;
		else
			os << "0" << std::endl;
	}
	if (HT._table[HT._table_size - 1].size() > 0)
		os << "0 -> " << HT._table[HT._table_size - 1];
	else
		os << "0";
	return os;
}

void HashTable::insert(std::string key)
{
	unsigned int index = 0;
	if (_mode == 'l')
	{
		bool inserted = false;
		for (unsigned int j = linear_detect_hash(key, index); index < (unsigned)_table_size; index++, j = linear_detect_hash(key, index))
		{
			if ((_table[j]._head->_next == NULL) || (_table[j]._head->_next->_key == key))
			{
				_table[j].insert(key);
				inserted = true;
				break;
			}
		}
		if (!inserted)
		{
			std::cerr << "Hash Table Overflow!" << std::endl;
			exit(-1);
		}
			
	}
	else if (_mode == 'd')
	{
		bool inserted = false;
		for (unsigned int j = double_detect_hash(key, index); index < (unsigned)_table_size; index++, j = double_detect_hash(key, index))
		{
			if ((_table[j]._head->_next == NULL) || (_table[j]._head->_next->_key == key))
			{
				_table[j].insert(key);
				inserted = true;
				break;
			}
		}
		if (!inserted)
		{
			std::cerr << "Hash Table Overflow!" << std::endl;
			exit(-1);
		}
	}
	else
	{
		std::cerr << "Illegal mode: " << _mode << ", legal options: 'l' or 'd'. " << std::endl;
		exit(-1);
	}	
}

std::string HashTable::key(int index)
{
	if (index >= _table_size)
	{
		std::cerr << "Index out of range!" << std::endl;
		exit(-1);
	}
	else
	{
		return _table[index].key();
	}
}

bool test_hash(HashTable& HT, std::map<std::string, int> ground_truth)
{
	for (int i = 0; i < HT.table_size(); i++)
	{
		if (ground_truth[HT.key(i)] != HT.list_size(i))
		{
			std::cout << i << " \"" << HT.key(i) << "\" " << ground_truth[HT.key(i)] << " " << HT.list_size(i) << std::endl;
			return false;
		}
	}
	return true;
}