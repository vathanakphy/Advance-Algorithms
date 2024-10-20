#!/bin/bash

# Compile the C++ program
g++ ex2.cpp -o date_comparison.out

# Define test cases with inputs and expected outputs
declare -a test_cases=(
    "2000 1 1 2001 1 1"        # Person 1 is older
    "2001 2 28 2001 3 1"       # Person 1 is older
    "2000 2 29 2001 2 28"      # Person 2 is younger (leap year)
    "2000 2 29 2000 3 1"       # Same year, person 2 is younger
    "2000 3 1 2000 2 29"       # Person 2 is older
    "2000 12 31 2000 12 31"    # Same date
    "2000 1 1 -1 1 1"          # Invalid second date
    "2000 1 1 2000 0 1"        # Invalid second date
    "2000 1 1 2000 1 32"       # Invalid second date
    "2005 3 5 2005 5 3"        # Person 2 is younger
)

declare -a expected_outputs=(
    "The second person is the youngest"
    "The second person is the youngest"
    "The second person is the youngest"
    "The second person is the youngest"
    "The first person is the youngest"
    "Both persons have the same age"
    "Invalid dates"
    "Invalid dates"
    "Invalid dates"
    "The second person is the youngest"
)

# Initialize score
score=0

# Function to test each case
run_test() {
    input="$1"
    expected_output="$2"
    
    # Execute the program and feed the input
    output=$(echo -e "$input" | ./date_comparison.out)
    
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
