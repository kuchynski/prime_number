//
// kuchynskiandrei@gmail.com
// 2021
//

#include <iostream>  
#include <vector>
#include <math.h>
#include <algorithm>

class PrimeNumbers
{
private:
	std::vector<unsigned> results;
public:
	PrimeNumbers(const auto min, const auto max)
	{
		auto func_init = [](auto n) { return (n > 1)? n / 2 - 1 : 0;};
		auto func_convert = [](auto n) { return n + n + 3;};

		const auto m_min_value = func_init(min);
		const auto m_max_value = func_init(max);
		std::vector<char> data(m_max_value, 1);
	
		for(auto i = 0; i < sqrt(m_max_value / 2); i++) {
			if(data[i]) {
				const auto number = func_convert(i);
				for(auto j = i + number; j < m_max_value; j += number) {
					data[j] = 0;
				}
			}
		}
		if(min < 3)
			results.push_back(2); // 2 is a prime number we don't have to calculate
		for(auto i = m_min_value; i < m_max_value; i++) {
			if(data[i]) {
				results.push_back(func_convert(i));
			}
		}
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
	const PrimeNumbers primes(0, 1000);
	
	std::cout << "There are " << primes.GetSize() << " prime numbers" << std::endl;
	primes.PrintAll(std::cout);

	return 0;
}
