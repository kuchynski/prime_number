# The algorithm for obtaining prime numbers

It is a small and fast realization of the Sieve of Eratosthenes algorithm.


<span style="color:yellow">Python</span>

- set MIN_VALUE and MAX_VALUE to the range of prime numbers you are looking for
- uncomment the print function if you'd like to print the result
- run:
> python ./prime_number.py

Running time is about 8 seconds for 0 - 10.000.000 range on the RaspberryPi 4.

<span style="color:yellow">C</span>

- set MIN_VALUE and MAX_VALUE to the range of prime numbers you are looking for
- uncomment the printf function if you'd like to print the result
- build:
> make
- run:
> ./prime_number

It takes about 48 seconds for 0 - 1.000.000.000 range on the RaspberryPi 4 and about 8 seconds on the i3-8100 CPU.

