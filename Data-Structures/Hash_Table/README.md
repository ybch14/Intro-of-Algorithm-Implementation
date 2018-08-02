# Hash Table

Hash table data structure implementation. To compare the average detect time, linear hash and double hash algorithms are implemented. 

## Task definition

Given 1000000 strings (distinct strings 300000), count the appearance time of every distinct string. Since some of the strings are duplicated, we combine link method and open address method to solve collision.

## Data Structure

```C++
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
```

## File List

- [`hash_table.h`](hash_table.h): hash table class definition.
- [`hash_table.cpp`](hash_table.cpp): implementation of hash table class member functions.
- [`main.cpp`](main.cpp): test samples.
- [`generate_data.py`](generate_data.py): test sample generation.
- [`data.txt`](data.txt): 1000000 strings.
- [`ground_truth.txt`](ground_truth.txt): actual appear time of each distinct string.

## Test sample

- `['0', '1', '2', ..., '19', '0', '1', '2', ..., '19', '0', '1', '2', ..., '9']`
- random generalized strings, distinct count 300000. ([`generate_data.py`](generate_data.py))

## Output

```
Test HashTable:
0 -> 18 -> 18
0 -> 17 -> 17
0 -> 0 -> 0 -> 0
0 -> 1 -> 1 -> 1
0 -> 2 -> 2 -> 2
0 -> 3 -> 3 -> 3
0 -> 4 -> 4 -> 4
0 -> 5 -> 5 -> 5
0 -> 6 -> 6 -> 6
0 -> 7 -> 7 -> 7
0 -> 8 -> 8 -> 8
0 -> 9 -> 9 -> 9
0 -> 16 -> 16
0 -> 14 -> 14
0
0 -> 13 -> 13
0 -> 15 -> 15
0 -> 12 -> 12
0
0 -> 11 -> 11
0
0 -> 10 -> 10
0 -> 19 -> 19
Data loaded!
Double Hashing: 3.488s.
Double Hashing correct? Yes! :)
Linear Hashing: 123.683s.
Linear Hashing correct? Yes! :)
```