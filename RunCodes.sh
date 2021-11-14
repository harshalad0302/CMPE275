#! /bin/bash
echo "Enter the number of Kmers "
read kmers

echo "Running Python Code "
echo "-----------------------------------"
python3 KmerPurePython.py $kmers
echo "-----------------------------------"
echo ""
echo "Running cpp code"
echo ""
echo "-----------------------------------"
./KmerPureCode $kmers
echo "-----------------------------------"
echo ""

