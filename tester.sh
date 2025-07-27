# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 21:54:17 by adrocha           #+#    #+#              #
#    Updated: 2025/07/27 21:54:20 by adrocha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[1;33m"
RESET="\033[0m"

make re > /dev/null

run_test() {
  input="$1"
  expected_output="$2"

  echo -e "${YELLOW}Testing: ./push_swap $input${RESET}"

  output=$(./push_swap $input)
  valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 ./push_swap $input 2>&1)

  if [[ "$output" == "$expected_output" ]]; then
    echo -e "${GREEN}[OK] Output${RESET}"
  else
    echo -e "${RED}[FAIL] Output${RESET}"
    echo "Expected:"
    echo "$expected_output"
    echo "Got:"
    echo "$output"
  fi

  if echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
    echo -e "${GREEN}[OK] Valgrind${RESET}"
  else
    echo -e "${RED}[LEAK] Valgrind${RESET}"
    echo "$valgrind_output"
  fi

  echo "------------------------------"
}

# Testes válidos
run_test "1 2 3" $'1\n2\n3'
run_test "4 5 6" $'4\n5\n6'
run_test "42" "42"
run_test "10 -5 1000" $'10\n-5\n1000'

# Testes inválidos (espera "Error")
run_test "1 a 2" "Error"
run_test "2147483648" "Error"  # maior que INT_MAX
run_test "" ""                 # Nenhum argumento
run_test "5 5" "Error"         # Duplicado

