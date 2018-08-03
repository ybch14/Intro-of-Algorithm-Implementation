#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>

int main()
{
	std::pair<double, std::vector<int>> rod_cutting(double* price, int length);
	double price[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	//int length = 10;
	for (int length = 1; length <= 10; length++)
	{
		auto result = rod_cutting(price, length);
		std::cout << "Length " << std::setw(2) << length 
			<< " optimal Price: " << std::setw(2) << result.first;
		auto solution = result.second;
		std::cout << " (" << solution[0];
		for (int i = 1; i < (int)solution.size(); i++)
			std::cout << '+' << solution[i];
		std::cout << ")" << std::endl;
	}
	return 0;
}