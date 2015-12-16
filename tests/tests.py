'''
COMP20007 Design of Algorithms
Semester 1 2015
Assignment 1 
Algorithm testing.
 
Luther Carroll
391929
luthercarroll@runbox.com	
24 - 3 - 2015

Generate lists of random integers in increasing amounts,
record timings of quicksort and mergesort on them,
and plot the results.
Lists are between 1 and 100000 items in length
Random integers are between 0 and 100000
'''

import random
import subprocess
import math

# External library.
import matplotlib.pyplot

# Generate a range of amounts.
amounts = [1]
for i in range(1000, 110000, 1000):
    amounts.append(i)

# A smaller range for pathalogical input
pathological_amounts = [1]
for i in range(1000, 11000, 1000):
    pathological_amounts.append(i)

# Create some lists for recording the timings.
quicksort_random_times = []
mergesort_random_times = []

quicksort_sorted_times = []
mergesort_sorted_times = []

quicksort_unique_times = []
mergesort_unique_times = []

# Iterate through the amounts.
for i in amounts:

    # Random input:

    # Open a new list file
    with open('list{}'.format(i), 'w') as f:

        # Write the random integers to the list
        for j in range(0, i, 1):
            f.write('{}\n'.format(random.randint(0, 100000)))

    # Get timings

    # Random input.
    out = subprocess.check_output('../assn1 q < list{}'.format(i), stderr=subprocess.STDOUT, shell=True)
    time = (out.split()[3].decode('utf-8').strip('ms'))

    quicksort_random_times.append(time)

    out = subprocess.check_output('../assn1 m < list{}'.format(i), stderr=subprocess.STDOUT, shell=True)
    time = (out.split()[3].decode('utf-8').strip('ms'))

    mergesort_random_times.append(time)


# Iterate through the pathalogical amounts.
for i in pathological_amounts:

    # Sorted input:

    # Open a new list file
    with open('sorted_list{}'.format(i), 'w') as f:

        # Write the sorted integers to the list
        for j in range(0, i, 1):
            f.write('{}\n'.format(j))

    # Input with a unique items:

    # Open a new list file
    with open('unique_list{}'.format(i), 'w') as f:

        # Write the integers to the list
        for j in range(0, i, 1):
            f.write('{}\n'.format(1))

    # Get timings

    # Sorted input.
    out = subprocess.check_output('../assn1 q < sorted_list{}'.format(i), stderr=subprocess.STDOUT, shell=True)
    time = (out.split()[3].decode('utf-8').strip('ms'))

    quicksort_sorted_times.append(time)

    out = subprocess.check_output('../assn1 m < sorted_list{}'.format(i), stderr=subprocess.STDOUT, shell=True)
    time = (out.split()[3].decode('utf-8').strip('ms'))

    mergesort_sorted_times.append(time)

    # Unique input.
    out = subprocess.check_output('../assn1 q < unique_list{}'.format(i), stderr=subprocess.STDOUT, shell=True)
    time = (out.split()[3].decode('utf-8').strip('ms'))

    quicksort_unique_times.append(time)

    out = subprocess.check_output('../assn1 m < unique_list{}'.format(i), stderr=subprocess.STDOUT, shell=True)
    time = (out.split()[3].decode('utf-8').strip('ms'))

    mergesort_unique_times.append(time)
    
# Plot the random times.
matplotlib.pyplot.figure(0)

matplotlib.pyplot.plot(quicksort_random_times, amounts, 'b')
matplotlib.pyplot.plot(mergesort_random_times, amounts, 'g')

# Plot a rough expected time.
expected_times = [n*math.log1p(n)/60000 for n in amounts]
matplotlib.pyplot.plot(expected_times, amounts, 'r--')

matplotlib.pyplot.title('Running Time of Algorithms - Random Input')
matplotlib.pyplot.xlabel('Time (ms)')
matplotlib.pyplot.ylabel('Amount sorted');

matplotlib.pyplot.show()

# Plot the sorted times.
matplotlib.pyplot.figure(1)

matplotlib.pyplot.plot(quicksort_sorted_times, pathological_amounts, 'b')
matplotlib.pyplot.plot(mergesort_sorted_times, pathological_amounts, 'g')

# Plot a rough expected time.
expected_times = [n*math.log1p(n)/60000 for n in pathological_amounts]
n2_times = [n*n/60000 for n in pathological_amounts]
matplotlib.pyplot.plot(expected_times, pathological_amounts, 'r--')
matplotlib.pyplot.plot(n2_times, pathological_amounts, 'r-')

matplotlib.pyplot.title('Running Time of Algorithms - Sorted Input')
matplotlib.pyplot.xlabel('Time (ms)')
matplotlib.pyplot.ylabel('Amount sorted');

matplotlib.pyplot.show()

# Plot the unique times.
matplotlib.pyplot.figure(2)

matplotlib.pyplot.plot(quicksort_unique_times, pathological_amounts, 'b')
matplotlib.pyplot.plot(mergesort_unique_times, pathological_amounts, 'g')

# Plot a rough expected time.
matplotlib.pyplot.plot(expected_times, pathological_amounts, 'r--')
matplotlib.pyplot.plot(n2_times, pathological_amounts, 'r-')

matplotlib.pyplot.title('Running Time of Algorithms - Unique input')
matplotlib.pyplot.xlabel('Time (ms)')
matplotlib.pyplot.ylabel('Amount sorted');

matplotlib.pyplot.show()
