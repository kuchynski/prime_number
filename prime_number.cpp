//
// kuchynskiandrei@gmail.com
// 2021
//

#include <iostream>  
#include <vector>
#include <math.h>
#include <unordered_set>
#include <functional>

class PrimeNumbers
{
private:
	std::unordered_set<unsigned int> results;
public:
	PrimeNumbers(const auto max)
	{
		auto func_init = [](auto n) { return (n > 1)? n / 2 - 1 : 0;};
		auto func_convert = [](auto n) { return n + n + 3;};

		const auto max_value = func_init(max);
		std::vector<char> data(max_value, 1);
		const std::vector<char>::iterator iter_border = data.begin() + sqrt(max_value / 2);
		auto index = 0;

		std::for_each(data.begin(), iter_border, 
			[&index, &max_value, &data, &func_convert](int n) {
				if(n) {
					const auto number = func_convert(index);
					std::vector<char>::iterator it = data.begin() + index + number;
					for(; it < data.end(); it += number) {
						*it = 0;	// it isn't a prime number
					}
				}
				index++;
			}
		);
		
		results.insert(2); // 2 is a prime number we don't have to calculate
		results.reserve(1 + std::count_if(data.begin(), data.end(), [](auto &n){return n == 1;}));
		index = 0;
		for(auto n : data) {
			if(n)
				results.insert(func_convert(index));
			index++;
		}
	}
	
	void PrintAll(std::ostream &stream) const
	{
		std::for_each(results.begin(), results.end(), 
			[&stream](auto value) { stream << value << " "; });
		stream << "\n";
	}

	auto GetSize() const {return results.size();}
	bool IsItPrime(auto n) const {return results.find(n) != results.end();} // .contains(n) since C++20
};

int main(void)
{
	PrimeNumbers primes(100000000);
	
	std::cout << "There are " << primes.GetSize() << " prime numbers." << std::endl;
	//primes.PrintAll(std::cout);
	
	for(int n : {3, 7, 9, 11, 25, 79})
		if(primes.IsItPrime(n))
			std::cout << n << " ";
	std::cout << std::endl;

	return 0;
}
