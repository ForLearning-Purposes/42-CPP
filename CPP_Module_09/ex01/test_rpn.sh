#!/bin/bash

EXE=./RPN
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Define test cases: "input" => expected_output
declare -a tests=(
    "1 2 + => 3"
    "5 1 2 + 4 * + 3 - => 14"
    "3 + => Error: Invalid RPN expression"
    "4 0 / => Error: Division by zero"
    "8 9 * 9 - 9 - 9 - 4 - 1 + => 42"
    "1 2 3 + + + => Error: Invalid RPN expression"
    "10 2 + => Error: Invalid RPN expression"   # 10 is not a single-digit
    "a b + => Error: Invalid RPN expression"
    "9 9 9 9 9 9 * * * * * => 531441"
    "8 9 * 9 - 9 - 9 - 4 - 1 + => 42" # example form the subjet
    "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 - => 42" # example form the subjet
    "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / => 15" # example form the subjet
)

pass=0
fail=0

for test_case in "${tests[@]}"; do
    input="${test_case%%=>*}"     # Extract input
    expected="${test_case##*=> }" # Extract expected output

    output=$($EXE "$input" 2>&1)

    if [ "$output" == "$expected" ]; then
        echo -e "${GREEN}✔ PASS${NC}  '$input' → $output"
        ((pass++))
    else
        echo -e "${RED}✖ FAIL${NC}  '$input' → Got '$output', expected '$expected'"
        ((fail++))
    fi
done

echo ""
echo "Total: $pass passed, $fail failed"
