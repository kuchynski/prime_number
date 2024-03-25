#
# kuchynskiandrei@gmail.com
# 2021
#

import math

MIN_VALUE = 0
MAX_VALUE = 100000
N_MAX_VALUE = int(MAX_VALUE / 2 - 1)
N_MIN_VALUE = int(MIN_VALUE / 2)

def get_number(n):
    return n + n + 3

# Init
numbers = [True for i in range(0,N_MAX_VALUE)]
end = int(math.sqrt(N_MAX_VALUE/2))
# Calculate
for index in range(0, end):
    if(numbers[index] == True):
        number = get_number(index)
        i = index + number
        while(i < N_MAX_VALUE):
            numbers[i] = False
            i += number

# Print results
total_number = 0
if(MIN_VALUE < 3):
    total_number = 1
    #print("1 - 2")

for i in range(N_MIN_VALUE, N_MAX_VALUE):
    if(numbers[i] == True):
        total_number += 1
        #print("%d - %d" % (total_number, get_number(i)))
print("There are %d primes in the range %d - %d" % (total_number, MIN_VALUE, MAX_VALUE))
