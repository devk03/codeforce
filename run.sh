#!/bin/bash

# Check for --new or -n flag
if [[ "$1" == "--new" || "$1" == "-n" ]]; then
    # Ensure solutions folder exists
    mkdir -p solutions

    # Prompt for solution filename
    echo -n "Enter solution name (without .cpp): "
    read solution_name

    # Validate input
    if [ -z "$solution_name" ]; then
        echo "[ERROR] Solution name cannot be empty!"
        exit 1
    fi

    # Copy main.cpp to solutions folder
    cp main.cpp "solutions/${solution_name}.cpp"
    echo "[STEP] Saved current solution to solutions/${solution_name}.cpp"

    # Reset main.cpp from template
    cp config/template.cpp main.cpp
    echo "[STEP] Reset main.cpp from template"

    # Clear input.txt
    > input.txt
    echo "[STEP] Cleared input.txt"

    echo "[DONE] Ready for new problem!"
    exit 0
fi

# Ensure input.txt and output.txt exist
touch input.txt output.txt

# Compile and run the program
./config/compile.sh

if [ $? -eq 0 ]; then
    echo "[STEP] Running the program"

    # Start timing
    start_time=$(date +%s%N)

    # Run with input file if it exists, otherwise use stdin
    if [ -f "input.txt" ]; then
        ./main < input.txt > output.txt
    else
        ./main > output.txt
    fi

    # End timing
    end_time=$(date +%s%N)
    elapsed=$((end_time - start_time))
    elapsed_us=$((elapsed / 1000))
    elapsed_ms=$((elapsed / 1000000))

    echo "[TIME] Execution time: ${elapsed_ms}ms (${elapsed_us}µs)"

    # Clean up - delete the executable
    rm -f main
    echo "[STEP] Executable cleaned up."
else
    echo "Cannot run - compilation failed!"
fi