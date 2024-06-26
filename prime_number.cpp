//
// kuchynskiandrei@gmail.com
// 2024
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <memory>

template <std::size_t min_value,  std::size_t max_value>
class PrimeNumbers: public std::vector<unsigned long>
{
public:
	PrimeNumbers()
	{
		if(min_value < max_value) {
			constexpr auto func_init = [](const auto n) { return (n > 1)? n / 2 - 1 : 0;};
			auto func_convert = [](const auto n) { return n + n + 3;};
			constexpr auto start = func_init(min_value);
			constexpr auto finish = func_init(max_value);
			auto pdata = std::make_unique<std::array<bool, finish>>();
			std::fill(pdata->begin(), pdata->end(), true);

			std::for_each_n(pdata->begin(), sqrt(finish / 2),
				[index = 0, &pdata, &func_convert](auto n) mutable {
					if(n) {
						const auto step = func_convert(index);
						const auto iter_data_end = pdata->end();
						for(auto it = pdata->begin() + index + step; it < iter_data_end; it += step) {
							*it = false;	// it isn't a prime number
						}
					}
					index++;
				}
			);

			if(min_value <= 2)
				push_back(2); // 2 is a prime number we don't have to calculate
			std::for_each(pdata->begin() + start, pdata->end(),
				[&, index = start](const auto e) mutable{
					if(e)
						push_back(func_convert(index));
					index++;
				}
			);
		}
	}

	static constexpr auto min = min_value;
	static constexpr auto max = max_value;
};

int main(void)
{
	const auto min_value = 1'234'567'890;
	const auto max_value = 1'234'567'999;
	const PrimeNumbers<min_value, max_value> primes;

	std::cout << "There are " << primes.size() << " prime numbers in range [" << primes.min << ":" << primes.max << ")" << std::endl;
	std::copy(primes.begin(), primes.end(), std::ostream_iterator<unsigned long>(std::cout, " "));
	std::cout << std::endl;

	for(auto n : {3, 7, 9, 11, 25, 79, 1234567891, 1234567907, 1234567913, 1234567927, 1234567949, 1234567967, 1234567981})
		if(find(primes.begin(), primes.end(), n) != primes.end())
			std::cout << n << " ";
	std::cout << std::endl;

	return 0;
}
