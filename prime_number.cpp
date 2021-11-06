//
// kuchynskiandrei@gmail.com
// 2021
//

#include <iostream>  
#include <vector>
#include <cmath>
#include <iterator>

template <std::size_t max>
class PrimeNumbers
{
private:
	std::vector<unsigned long> results;
public:
	PrimeNumbers()
	{
		auto func_init = [](const auto n) { return (n > 1)? n / 2 - 1 : 0;};
		auto func_convert = [](const auto n) { return n + n + 3;};

		constexpr auto max_value = func_init(max);
		std::vector<char> data(max_value, 1);
		auto index = 0;

		std::for_each_n(data.begin(), sqrt(max_value / 2), 
			[&index, &data, &func_convert](int n) {
				if(n) {
					const auto step = func_convert(index);
					for(auto it = data.begin() + index + step; it < data.end(); it += step) {
						*it = 0;	// it isn't a prime number
					}
				}
				index++;
			}
		);
		
		results.push_back(2); // 2 is a prime number we don't have to calculate
		index = 0;
		for(auto n : data) {
			if(n)
				results.push_back(func_convert(index));
			index++;
		}
	}
	
	void PrintAll(std::ostream &stream) const
	{
		std::copy(results.begin(), results.end(), std::ostream_iterator<int>(stream, " "));
		stream << std::endl;
	}

	auto GetSize() const {return results.size();}
	bool IsItPrime(const auto n) const {return std::find(results.begin(), results.end(), n) != results.end();}
};

int main(void)
{	
	const PrimeNumbers<100000000> primes;
	
	std::cout << "There are " << primes.GetSize() << " prime numbers." << std::endl;
	//primes.PrintAll(std::cout);
	
	for(int n : {3, 7, 9, 11, 25, 79})
		if(primes.IsItPrime(n))
			std::cout << n << " ";
	std::cout << std::endl;

	return 0;
}
