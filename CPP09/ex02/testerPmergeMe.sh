#!/bin/bash

YELLOW='\033[0;33m';
GREEN='\033[0;32m';
RED='\033[0;31m';
RESET='\033[0m';

make
echo ""
echo -e "${GREEN}---------------------------------------------------------------"
echo "                          VALID INPUT"
echo "---------------------------------------------------------------"
echo ""

# Test case 10: valid input with 3000 different integers
echo -e "${YELLOW}./PmergeMe \"7 99 54 395 18 2 87\"${RESET}"
./PmergeMe 7 99 54 395 18 2 87
echo ""

# Test case 8: valid input
echo -e "${YELLOW}./PmergeMe \"shuf -i 1-100000 -n 3000 | tr "\n" " "\"${RESET}"
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")
echo ""

# Test case 9: valid input with 3000 different integers
echo -e "${YELLOW}./PmergeMe \"shuf -i 1-100000 -n 1000 | tr "\n" " "\"${RESET}"
./PmergeMe $(shuf -i 1-100000 -n 1000 | tr "\n" " ")
echo ""

echo -e "${RED} --------------------------------------------------------------"
echo "                         INVALID INPUT"
echo " --------------------------------------------------------------"
echo ""

# Test case 1: no input
echo -e "${YELLOW}./PmergeME${RESET}"
./PmergeMe
echo ""

# Test case 2: just one number
echo -e "${YELLOW}./PmergeMe 8${RESET}"
./PmergeMe 8
echo ""

# Test case 3: non-digit input
echo -e "${YELLOW}./PmergeME 1 42 b 7${RESET}"
./PmergeMe 1 42 b 7
echo ""

# Test case 4: negative numbers
echo -e "${YELLOW}./PmergeME -3 5 9 7 4${RESET}"
./PmergeMe -3 5 9 7 4
echo ""

# Test case 5: decimal numbers
echo -e "${YELLOW}./PmergeMe 3.5 5.2 9.1 7.3 4.6${RESET}"
./PmergeMe 3.5 5.2 9.1 7.3 4.6
echo ""

# Test case 6: input outside of int limits
echo -e "${YELLOW}./PmergeMe 2147483648 5 9 7 4${RESET}"
./PmergeMe 2147483648 5 9 7 4
echo ""

# Test case 7: input is already sorted
echo -e "${YELLOW}./PmergeMe 1 2 3 4 5${RESET}"
./PmergeMe 1 2 3 4 5
echo ""
