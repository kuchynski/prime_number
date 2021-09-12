//
// kuchynskiandrei@gmail.com
// 2021
//

#include <iostream>  
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

class PrimeNumbers
{
private:
	std::vector<unsigned int> results;
public:
	PrimeNumbers(const auto min, const auto max)
	{
		auto func_init = [](auto n) { return (n > 1)? n / 2 - 1 : 0;};
		auto func_convert = [](auto n) { return n + n + 3;};

		const auto min_value = func_init(min);
		const auto max_value = func_init(max);
		std::vector<char> data(max_value, 1);
		const std::vector<char>::iterator iter_border = data.begin() + sqrt(max_value / 2);
		auto index = 0;
	
		if(min < 3)
			results.push_back(2); // 2 is a prime number we don't have to calculate
		
		for_each(data.begin(), iter_border, 
			[&index, &results=results, &max_value, &data, &func_convert](int n) {
				if(n) {
					const auto number = func_convert(index);
					results.push_back(number);
					std::vector<char>::iterator it = data.begin() + index + number;
					for(; it < data.end(); it += number)
						*it = 0;	// it isn't a prime number
				}
				index++;
			}
		);

		for_each(iter_border, data.end(), 
			[&index, &results=results, &func_convert](auto& n) {
				if(n) results.push_back(func_convert(index));
				index++;
			}
		);
	}
	void PrintAll(std::ostream &stream) const
	{
		for_each(results.begin(), results.end(), 
			[&stream](auto value) { stream << value << " "; });
		stream << "\n";
	}

	auto GetSize() const {return results.size();}
	unsigned operator[](auto n) const { return (n < GetSize())? results[n] : 0;}
};

int main(void)
{
	const PrimeNumbers primes(0, 100);
	
	std::cout << "There are " << primes.GetSize() << " prime numbers" << std::endl;
	primes.PrintAll(std::cout);

	return 0;
}
