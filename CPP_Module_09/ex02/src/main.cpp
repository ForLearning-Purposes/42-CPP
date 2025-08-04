#include <iostream>

/*
You must use at least two different containers in your code to
validate this exercise. Your program must be able to handle at
least 3000 different integers.
*/

/*
It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.
*/

/*
The management of errors related to duplicates is left to your
discretion.
*/

/*
must use the merge-insert sort algorithm to sort the positive integer
sequence
*/

int main(int ac, char **av) {
    (void) av;
    if (ac < 3) {
        std::cerr << "Usage: ./PmergeMe <number> <number> ..." << std::endl;
        return 1;
    }

    return 0;
}

/*
1) On the first line you must display an explicit text followed by the unsorted positive
integer sequence.

2) On the second line you must display an explicit text followed by the sorted positive
integer sequence.

3) On the third line, you must display an explicit message indicating the time taken
by your algorithm, specifying the first container used to sort the positive integer
sequence.

4) On the last line you must display an explicit text indicating the time used by
your algorithm by specifying the second container used to sort the positive integer
sequence.
*/

/*
EXAMPLE:

$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>
*/