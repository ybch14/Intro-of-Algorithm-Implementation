#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <time.h>
#include "hash_table.h"

int main()
{
	bool test_hash(HashTable& HT, std::map<std::string, int> ground_truth);
	std::cout << "Test HashTable:" << std::endl;
	HashTable ht(23);
	for (int i = 0; i < 50; i++)
	{
		ht.insert(std::to_string(i%20));
	}
	std::cout << ht << std::endl;
	
	int length = 1000000;
	int distinct_length = 300000;
	int table_size = 300007;
	std::string *strings = new std::string[length];
	std::map<std::string, int> ground_truth;
	std::ifstream data("data.txt", std::ios_base::in);
	std::string tmp; int tmp_number;
	for (int i = 0; i < length; i++)
	{
		data >> tmp;
		strings[i] = tmp;
	}
	data.close(); data.clear();
	std::ifstream gt("ground_truth.txt", std::ios_base::in);
	for (int i = 0; i < distinct_length; i++)
	{
		gt >> tmp;
		gt >> tmp_number;
		ground_truth[tmp] = tmp_number;
	}
	ground_truth[""] = 0;
	gt.close(); gt.clear();
	std::cout << "Data loaded!" << std::endl;
	HashTable query_table_double(table_size);
	HashTable query_table_linear(table_size, 'l');
	clock_t start = clock();
	for (int i = 0; i < length; i++)
	{
		query_table_double.insert(strings[i]);
	}
	std::cout << "Double Hashing: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Double Hashing correct? " << (test_hash(query_table_double, ground_truth) ? "Yes! :)" : "No! :(") << std::endl;

	start = clock();
	for (int i = 0; i < length; i++)
	{
		query_table_linear.insert(strings[i]);
	}
	std::cout << "Linear Hashing: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s. " << std::endl;
	std::cout << "Linear Hashing correct? " << (test_hash(query_table_linear, ground_truth) ? "Yes! :)" : "No! :(") << std::endl;
	delete[]strings;
}