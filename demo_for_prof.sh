#!/bin/bash
# Demo script for professor
# Shows multiple algorithm runs

echo "=== DEMONSTRATION FOR PROFESSOR ==="
echo ""
echo "Running Interactive Sorting Demo..."
echo ""

# Demo 1: Quick Sort with 5000 elements
echo "Demo 1: Quick Sort on 5000 random elements"
echo "5000
5
0" | ./sort_interactive

echo ""
echo "Press Enter for next demo..."
read

# Demo 2: Compare all algorithms with 2000 elements
echo "Demo 2: Compare ALL algorithms on 2000 random elements"
echo "2000
8
0" | ./sort_interactive

echo ""
echo "=== DEMONSTRATION COMPLETE ==="
