#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m\033[1m"
ORANGE="\001\033[38;5;208m\002"
BLUE="\033[0;34m"
PURPLE="\033[0;35m"
CYAN="\033[0;36m"
YELLOW="\x1b[33m"
ROSE="\x1B[38;2;255;151;203m"
LIGHT_BLUE="\x1B[38;2;53;149;240m"
LIGHT_GREEN="\x1B[38;2;17;245;120m"
GRAY="\x1B[38;2;176;174;174m"
RESET="\033[0m"

test_case() 
{
	local test_num=$1
	local cmd=$2
	local expected=$3

	echo -e "${GREEN} ${test_num} ------ $4 -----${RESET}"
	printf "\n       $cmd\n\n"

	local output=$(eval $cmd 2>&1)
	echo "$output" | sed 's/^/       /'

	if echo "$output" | grep -q "$expected"; then
		echo -e "       ${GREEN}✅ PASS${RESET}"
		((passed_tests++))
	else
		echo -e "       ${RED}❌ FAILED${RESET}"
	fi
	echo
}

ex00()
{
	cd CPP_01/ex00 && make &> /dev/null

	echo

	total_tests=0
	passed_tests=0

	echo -e "${YELLOW} ====================== ex00  =======================${RESET}"
	printf " Tests PASSED: ${GREEN}%d${RESET}/%d ${YELLOW}(%.0f%%)${RESET}\n" $passed_tests $total_tests $((passed_tests * 100 / total_tests))
	echo -e "${YELLOW} =============================================${RESET}\n"

	make fclean &> /dev/null
}

ex01()
{
	cd CPP_01/ex01 && make &> /dev/null

	echo

	total_tests=0
	passed_tests=0

	echo -e "${YELLOW} ====================== ex01  =======================${RESET}"
	printf " Tests PASSED: ${GREEN}%d${RESET}/%d ${YELLOW}(%.0f%%)${RESET}\n" $passed_tests $total_tests $((passed_tests * 100 / total_tests))
	echo -e "${YELLOW} =============================================${RESET}\n"

	make fclean &> /dev/null
}

ex02()
{
	cd CPP_01/ex02 && make &> /dev/null

	echo

	total_tests=0
	passed_tests=0

	echo -e "${YELLOW} ====================== ex02  =======================${RESET}"
	printf " Tests PASSED: ${GREEN}%d${RESET}/%d ${YELLOW}(%.0f%%)${RESET}\n" $passed_tests $total_tests $((passed_tests * 100 / total_tests))
	echo -e "${YELLOW} =============================================${RESET}\n"

	make fclean &> /dev/null
}

ex03()
{
	cd CPP_01/ex03 && make &> /dev/null

	echo

	total_tests=0
	passed_tests=0

	echo -e "${YELLOW} ====================== ex03  =======================${RESET}"
	printf " Tests PASSED: ${GREEN}%d${RESET}/%d ${YELLOW}(%.0f%%)${RESET}\n" $passed_tests $total_tests $((passed_tests * 100 / total_tests))
	echo -e "${YELLOW} =============================================${RESET}\n"

	make fclean &> /dev/null
}

ex04()
{
	cd CPP_01/ex04 && make &> /dev/null

	echo 

	total_tests=9
	passed_tests=0

	test_case 1 "./replace files/empty A B" "is empty" "TESTING WITH EMPTY INPUT FILE"
	test_case 2 "./replace files/empty_ln A B" "only contains line breaks" "TESTING WITH EMPTY INPUT FILE WITH NEW LINES"
	test_case 3 "./replace \"\" \"\" \"\"" "Filename is empty" "TESTING WITH NO INPUT"
	test_case 4 "./replace \"more\" \"input\" \"testing\" \"file.txt\"" "Invalid number of arguments" "TESTING WITH MORE THAN 3 ARGUMENTS"
	test_case 5 "./replace \"more\" \"input\"" "Invalid number of arguments" "TESTING WITH MORE LESS 3 ARGUMENTS"
	test_case 6 "./replace files/content_different_lines S p" "was not found in the file" "TESTING WITH CONTENT IN DIFFERENT LINES AND NO CHAR TO LOOK FOR"
	test_case 7 "./replace files/empty_ln \"\" \"\"" "lookFor is empty" "TESTING WITH NO lookFor INPUT"
	test_case 8 "./replace files/empty_ln A \"\"" "replaceWith is empty" "TESTING WITH NO replaceWith INPUT"
	test_case 9 "./replace files/content_different_lines h H" "" "TESTING WITH NO lookFor INPUT"

	echo -e "${YELLOW} ====================== ex04  =======================${RESET}"
	printf " Tests PASSED: ${GREEN}%d${RESET}/%d ${YELLOW}(%.0f%%)${RESET}\n" $passed_tests $total_tests $((passed_tests * 100 / total_tests))
	echo -e "${YELLOW} =============================================${RESET}\n"

	make fclean &> /dev/null
}

ex05()
{
	cd CPP_01/ex05 && make &> /dev/null

	total_tests=6
	passed_tests=0

	echo

	test_case 1 "./harl" "Usage: ./harl < MESSAGE LEVEL >" "TESTING WITH NO LEVEL"
	test_case 2 "./harl DEBUG" "I love having extra bacon" "TESTING WITH DEBUG LEVEL"
	test_case 3 "./harl INFO" "I cannot believe adding extra bacon" "TESTING WITH INFO LEVEL"
	test_case 4 "./harl WARNING" "I think I deserve to have some extra bacon for free" "TESTING WITH WARNING LEVEL"
	test_case 5 "./harl ERROR" "This is unacceptable" "TESTING WITH ERROR LEVEL"
	test_case 6 "./harl INVALID" "insignificant problems" "TESTING WITH INVALID LEVEL"

	echo -e "${YELLOW} ====================== ex05  =======================${RESET}"
	printf " Tests PASSED: ${GREEN}%d${RESET}/%d ${YELLOW}(%.0f%%)${RESET}\n" $passed_tests $total_tests $((passed_tests * 100 / total_tests))
	echo -e "${YELLOW} =============================================${RESET}\n"

	make fclean &> /dev/null
}

harl_test() 
{
	local test_num=$1
	local level=$2
	local expected_levels=$3
	local title=$4

	echo -e "${GREEN} ${test_num} ------ $title ----- ${RESET}"
	printf "\n       ./harlFilter $level\n\n"

	output=$(./harlFilter "$level" 2>&1)
	echo "$output" | sed 's/^/       /'

	IFS=',' read -ra levels <<< "$expected_levels"
	local count=0
	for level in "${levels[@]}"; do
		if echo "$output" | grep -q "$level"; then
			((count++))
		fi
	done

	if [ $count -eq ${#levels[@]} ]; then
		echo -e "       ${GREEN}✅ PASS${RESET}"
		((passed_tests++))
	else
		echo -e "       ${RED}❌ FAIL${RESET}"
	fi
	echo
}


ex06()
{
	cd CPP_01/ex06 && make &> /dev/null

	passed_tests=0
	total_tests=6

	test_case 1 "./harlFilter" "Usage: ./harlFilter < MESSAGE LEVEL >" "TESTING WITH NO LEVEL"
	harl_test 2 "DEBUG" "DEBUG,INFO,WARNING,ERROR" "DEBUG (CASCADA COMPLETA)"
	harl_test 3 "INFO" "INFO,WARNING,ERROR" "TESTING WITH INFO LEVEL"
	harl_test 4 "WARNING" "WARNING,ERROR" "TESTING WITH WARNING LEVEL"
	harl_test 5 "ERROR" "ERROR" "TESTING WITH ERROR LEVEL"
	test_case 6 "./harlFilter INVALID" "insignificant problems" "TESTING WITH INVALID LEVEL"

	echo -e "${YELLOW} ====================== ex06  =======================${RESET}"
	printf " Tests PASSED: ${GREEN}%d${RESET}/%d ${YELLOW}(%.0f%%)${RESET}\n" $passed_tests $total_tests $((passed_tests * 100 / total_tests))
	echo -e "${YELLOW} =============================================${RESET}\n"

	make fclean &> /dev/null
}


echo -e "${PURPLE} ===========================================${RESET}"
echo -e "${YELLOW}           CPP 01 - TESTER${RESET}"
echo -e "${PURPLE} ===========================================${RESET}\n"

echo -e "${YELLOW} ⚠️  WARNING: This tester relies on specific error messages being returned by the script.${RESET}\n\n"

echo -e "${GREEN} ¿What exercise do you want to evaluate? ${RESET}"
echo -e "0) ${ROSE} ex00 - Zombie ${RESET}"
echo -e "1) ${ROSE} ex01 - Zombie Horde ${RESET}"
echo -e "2) ${ROSE} ex02 - Reference ${RESET}"
echo -e "3) ${ROSE} ex03 - Weapon & Human ${RESET}"
echo -e "4) ${ROSE} ex04 - Replace${RESET}"
echo -e "5) ${ROSE} ex05 - Harl${RESET}"
echo -e "6) ${ROSE} ex06 - Harl Filter${RESET}"
echo -ne "${YELLOW} Elige (0-6): ${RESET}"

read choice

case $choice in

	0)
		echo -e "\n${GREEN}🚀 Evaluating EX00...${RESET}"
		ex00
		;;
	1)
		echo -e "\n${GREEN}🚀 Evaluating EX01...${RESET}"
		ex01
		;;
	2)
		echo -e "\n${GREEN}🚀 Evaluating EX02...${RESET}"
		ex02
		;;
	3)
		echo -e "\n${GREEN}🚀 Evaluating EX03...${RESET}"
		ex03
		;;
	4)
		echo -e "\n${GREEN}🚀 Evaluating EX04...${RESET}"
		ex04
		;;
	5)
		echo -e "\n${GREEN}🚀 Evaluating EX05...${RESET}"
		ex05
		;;
	6)
		echo -e "\n${GREEN}🚀 Evaluating EX06...${RESET}"
		ex06
		;;
	*)
		echo -e "${RED} ❌ Opción inválida ${RESET}"
		exit 1
		;;
esac

