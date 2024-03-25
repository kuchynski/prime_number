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
class PrimeNumbers
{
private:
	std::vector<unsigned long> results;
public:
	PrimeNumbers()
	{
		if(min_value < max_value) {
			constexpr auto func_init = [](const auto n) { return (n > 1)? n / 2 - 1 : 0;};
			auto func_convert = [](const auto n) { return n + n + 3;};
			constexpr auto start = func_init(min_value);
			constexpr auto finish = func_init(max_value);
			auto pdata = std::make_unique<std::array<char, finish>>();
			std::for_each(pdata->begin(), pdata->end(), [](auto &e) {e = 1;});
			auto index = 0;

			std::for_each_n(pdata->begin(), sqrt(finish / 2),
				[&index, &pdata, &func_convert](int n) {
					if(n) {
						const auto step = func_convert(index);
						const auto iter_data_end = pdata->end();
						for(auto it = pdata->begin() + index + step; it < iter_data_end; it += step) {
							*it = 0;	// it isn't a prime number
						}
					}
					index++;
				}
			);

			if(min_value <= 2)
				results.push_back(2); // 2 is a prime number we don't have to calculate
			index = start;
			std::for_each(pdata->begin() + start, pdata->end(),
				[&](auto &e) {
					if(e)
						results.push_back(func_convert(index));
					index++;
				}
			);
		}
	}

	static constexpr auto min = min_value;
	static constexpr auto max = max_value;
	auto size() const {return results.size();}
	auto begin() const {return results.begin();}
	auto end() const {return results.end();}
	auto find(const auto n) const {return std::find(results.begin(), results.end(), n);}
};

int main(void)
{
	const auto min_value = 1'234'567'890;
	const auto max_value = 1'234'567'999;
	const PrimeNumbers<min_value, max_value> primes;

	std::cout << "There are " << primes.size() << " prime numbers in range [" << primes.min << ":" << primes.max << ")" << std::endl;
	std::copy(primes.begin(), primes.end(), std::ostream_iterator<unsigned long>(std::cout, " "));
	std::cout << std::endl;

	for(int n : {3, 7, 9, 11, 25, 79, 1234567891, 1234567907, 1234567913, 1234567927, 1234567949, 1234567967, 1234567981})
		if(primes.find(n) != primes.end())
			std::cout << n << " ";
	std::cout << std::endl;

	return 0;
}
