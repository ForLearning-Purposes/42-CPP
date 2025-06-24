#!/bin/bash

EXE=./RPN
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Define test cases: "input" => expected_output
declare -a tests=(
    "1 2 + => 3"
    "5 1 2 + 4 * + 3 - => 14"
    "3 + => Error"
    "4 0 / => Error"
    "8 9 * 9 - 9 - 9 - 4 - 1 + => 42"
    "1 2 3 + + + => Error"
    "10 2 + => Error"   # 10 is not a single-digit
    "a b + => Error"
    "9 9 9 9 9 9 * * * * * => 531441"
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
