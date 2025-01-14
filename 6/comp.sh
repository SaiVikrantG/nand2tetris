#!/bin/bash

file1="$1"
file2="$2"

# Check if both files exist
if [[ ! -f "$file1" || ! -f "$file2" ]]; then
  echo "Both files must exist."
  exit 1
fi

# Read both files line by line
while IFS= read -r line1 && IFS= read -r line2 <&3; do
  # Compare each character in the lines
  for ((i = 0; i < ${#line1} || i < ${#line2}; i++)); do
    char1="${line1:i:1}"
    char2="${line2:i:1}"

    if [[ "$char1" != "$char2" ]]; then
      echo "Difference at line $((i + 1)): '$char1' != '$char2'"
    fi
  done
done <"$file1" 3<"$file2"
