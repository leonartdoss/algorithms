#!/bin/bash

# Directory containing the C and C++ files
REPO_DIR="."

# Find all .c and .cpp files in the repository
C_FILES=$(find "$REPO_DIR" -name "*.c")
CPP_FILES=$(find "$REPO_DIR" -name "*.cpp")

# Counters for successful and failed compilations
SUCCESS_COUNT=0
FAIL_COUNT=0
FAILED_FILES=()

# Compile each .c file
for FILE in $C_FILES; do
    echo "Compiling $FILE..."
    gcc "$FILE" -o "${FILE%.c}.bin"
    if [ $? -eq 0 ]; then
        echo "Compilation successful: $FILE"
        SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
    else
        echo "Compilation failed: $FILE"
        FAIL_COUNT=$((FAIL_COUNT + 1))
        FAILED_FILES+=("$FILE")
    fi
done

# Compile each .cpp file
for FILE in $CPP_FILES; do
    echo "Compiling $FILE..."
    g++ "$FILE" -o "${FILE%.cpp}.bin"
    if [ $? -eq 0 ]; then
        echo "Compilation successful: $FILE"
        SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
    else
        echo "Compilation failed: $FILE"
        FAIL_COUNT=$((FAIL_COUNT + 1))
        FAILED_FILES+=("$FILE")
    fi
done

# Remove all generated binaries
find "$REPO_DIR" -name "*.bin" -exec rm -f {} \;

# Print summary
echo "Compilation check completed."
echo "Number of files successfully compiled: $SUCCESS_COUNT"
echo "Number of files with errors: $FAIL_COUNT"
if [ $FAIL_COUNT -gt 0 ]; then
    echo "Files with errors:"
    for FILE in "${FAILED_FILES[@]}"; do
        echo "$FILE"
    done
fi