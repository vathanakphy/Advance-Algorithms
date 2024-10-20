#!/bin/bash

# Compile the C++ program
g++ ex1.cpp -o is_inside.out

# Define test cases as an array
declare -a test_cases=(
    "5 1 10"
    "1 1 10"
    "10 1 10"
    "0 1 10"
    "11 1 10"
    "10 1 1" 
    "5 5 5"
    "1000000 999999 1000000"
    "-5 -10 -1"
    "-5 10 5 -5 5 10" # invalid and do the second attemp
)

# Define expected outputs
declare -a expected_outputs=(
    "inside"
    "inside"
    "inside"
    "outside"
    "outside"
    "outside"
    "inside"
    "inside"
    "inside"
    "Minimum cannot be greater than maximum. Please re-enter the values."
)

# Initialize score
score=0

# Function to test each case
run_test() {
    input="$1"
    expected_output="$2"
    output=$(echo -e "${input// /\\n}" | ./is_inside.out)

    # Compare the actual output with expected output
    if [[ "$output" == *"$expected_output"* ]]; then
        ((score+=10))
    fi
}

# Run tests
for i in "${!test_cases[@]}"; do
    run_test "${test_cases[$i]}" "${expected_outputs[$i]}"
done

# Calculate final score out of 100
echo "Final Score: $score/100"
