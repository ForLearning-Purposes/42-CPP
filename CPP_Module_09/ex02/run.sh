#!/bin/sh

# Compile using make
make re
echo "******************************************************************"
echo "\n"
if [ $? -eq 0 ]; then
    echo "-> Compilation successful. Running program...\n\n"
    # Run with a sequence of 10 numbers (1 2 3 ... 10)
    ./PmergeMe 1 2 3 4 5 6 7 8 9 10
else
    echo "Compilation failed."
fi
