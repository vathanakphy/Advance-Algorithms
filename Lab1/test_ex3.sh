#!/bin/bash

# Compile the student's program
g++ -o student_program.out -std=c++11 ex3.cpp

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    echo "Score: 0/100"
    exit 1
fi

# Define test cases (input and expected output)
expected="Student ID Name Average Score GPA Grade 1 Alice 87.40 3.00 B 2 Bob 78.60 2.00 C 3 Charlie 90.40 4.00 A 4 David 70.00 2.00 C 5 Eve 67.20 1.00 D"

# Execute the student's program and process its output
output=$(./student_program.out | tr -d '|-\n' | tr -s ' ' | xargs)

# Optional: Print the expected and actual output for debugging
echo "Expected Output:"
echo "$expected"
echo "Actual Output:"
echo "$output"

# Initialize score
test_pass=50

# Compare the output with the expected value
if [[ "$output" == "$expected" ]]; then
    echo "Correct!"
    ((test_pass+=50))
else
    echo "Wrong!"
fi

# Output the result
echo "Score: $test_pass/100"
