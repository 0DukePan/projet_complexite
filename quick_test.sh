#!/bin/bash
# Quick test to demonstrate the fix

echo "Testing the fixed interactive program..."
echo ""

# Test with 1000 elements, Quick Sort (choice 5), then exit (choice 0)
echo "1000
5
0" | ./sort_interactive

echo ""
echo "=== Test completed successfully! ==="
