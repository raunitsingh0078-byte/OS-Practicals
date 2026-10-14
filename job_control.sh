#!/bin/bash

echo "===== Linux Job Control Demonstration ====="

echo ""
echo "1. Running a command in background..."
sleep 100 &
echo "Background process started."

echo ""
echo "2. Displaying active jobs..."
jobs

echo ""
echo "3. Now run the following command manually:"
echo "   sleep 100"
echo "   Then press Ctrl+Z to suspend it."

echo ""
echo "4. After suspending, run:"
echo "   jobs"
echo "   bg"
echo "   jobs"
echo "   fg"

echo ""
echo "5. To terminate a foreground process, press Ctrl+C."

echo ""
echo "===== Demonstration Complete ====="
