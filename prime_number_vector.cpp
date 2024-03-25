//
// kuchynskiandrei@gmail.com
// 2024
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <memory>

class PrimeNumbers: public std::vector<unsigned long>
{
public:
	const size_t min;
	const size_t max;

	PrimeNumbers(size_t min_value, size_t max_value): min(min_value), max(max_value)
	{
		if(min_value < max_value) {
			constexpr auto func_init = [](const auto n) { return (n > 1)? n / 2 - 1 : 0;};
			auto func_convert = [](const auto n) { return n + n + 3;};
			auto start = func_init(min_value);
			auto finish = func_init(max_value);
			vector<char> data(finish);
			std::fill(data.begin(), data.end(), 1);

			std::for_each_n(data.begin(), sqrt(finish / 2),
				[index = 0, &data, &func_convert](auto n) mutable {
					if(n) {
						const auto step = func_convert(index);
						for(auto it = data.begin() + index + step; it < data.end(); it += step) {
							*it = 0;	// it isn't a prime number
						}
					}
					index++;
				}
			);

			if(min_value <= 2)
				push_back(2); // 2 is a prime number we don't have to calculate
			std::for_each(data.begin() + start, data.end(),
				[&](auto e) mutable{
					if(e)
						push_back(func_convert(start));
					start++;
				}
			);
		}
	}
};

int main(void)
{
	const auto min_value = 1'234'567'890;
	const auto max_value = 1'234'567'999;
	const PrimeNumbers primes(min_value, max_value);

	std::cout << "There are " << primes.size() << " prime numbers in range [" << primes.min << ":" << primes.max << ")" << std::endl;
	std::copy(primes.begin(), primes.end(), std::ostream_iterator<unsigned long>(std::cout, " "));
	std::cout << std::endl;

	for(auto n : {3, 7, 9, 11, 25, 79, 1234567891, 1234567907, 1234567913, 1234567927, 1234567949, 1234567967, 1234567981})
		if(find(primes.begin(), primes.end(), n) != primes.end())
			std::cout << n << " ";
	std::cout << std::endl;

	return 0;
}
