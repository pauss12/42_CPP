#!/usr/bin/env bash

# tester_improved.sh
# Versión mejorada del tester para ScalarConverter (C++ Module 06 ex00)
# - Compila un ejecutable llamado "convert" (usa temp_main.cpp igual que el tester original)
# - Ejecuta una batería de tests (char,int,float,double)
# - Muestra PASS/FAIL por campo y resumen

set -u

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
NC="\033[0m"

workdir="$(cd "$(dirname "$0")" && pwd)"
cd "$workdir" || exit 1

cleanup() {
    rm -f temp_main.cpp convert temp_main.o scalar_test *.gch
}
trap cleanup EXIT

write_temp_main() {
    cat > temp_main.cpp <<'EOF'
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1) {
        ScalarConverter::convert(std::string(argv[1]));
        return 0;
    }
    std::cout << "Usage: convert <literal>" << std::endl;
    return 1;
}
EOF
}

compile() {
    echo -e "${BLUE}Compiling ScalarConverter into './convert'...${NC}"
    write_temp_main
    if ! c++ -Wall -Wextra -Werror -std=c++98 ScalarConverter.cpp temp_main.cpp -o convert 2> compile.err; then
        echo -e "${RED}Compilation failed. See compile.err for details.${NC}"
        sed -n '1,200p' compile.err
        return 1
    fi
    echo -e "${GREEN}Compilation OK${NC}"
    return 0
}

# Tests: each test is 4 expected substrings (char,int,float,double)
# The check is substring-based (flexible with spacing/precision), but can be strict by editing expectations below.

inputs=(
    "0"
    "nan"
    "42.0f"
    "c"
    "3.14f"
    "3.14"
)

expect_char=(
    "Non displayable"
    "impossible"
    "'\*'"
    "'c'"
    "impossible"
    "impossible"
)
expect_int=(
    "int: 0"
    "impossible"
    "int: 42"
    "impossible"
    "impossible"
    "impossible"
)
expect_float=(
    "float: 0.0f"
    "nanf"
    "float: 42.0f"
    "impossible"
    "float: 3.14f"
    "impossible"
)
expect_double=(
    "double: 0.0"
    "nan"
    "double: 42.0"
    "impossible"
    "impossible"
    "double: 3.14"
)

run_single() {
    local input="$1"
    echo -e "${BLUE}\n🔍 DETALLE: '$input'${NC}"
    echo -e "${YELLOW}TU INPUT:${NC} '$input'"
    echo -e "${YELLOW}TU SALIDA:${NC}"
    ./convert "$input"
}

run_tests() {
    local total=${#inputs[@]}
    local passed=0
    local idx

    for idx in "${!inputs[@]}"; do
        local input="${inputs[$idx]}"
        local exp_c="${expect_char[$idx]}"
        local exp_i="${expect_int[$idx]}"
        local exp_f="${expect_float[$idx]}"
        local exp_d="${expect_double[$idx]}"

        echo -e "\n${BLUE}>> TEST $((idx+1)) ---------------------------${NC}"
        output=$(./convert "$input" 2>&1)

        # TU INPUT / TU SALIDA
        echo -e "  TU INPUT: '$input'"
        echo -e "  TU SALIDA:"
        echo "$output" | sed 's/^/    /'

        echo
        # ESPERADO block
        # Reformat numeric expected float/double to 1 decimal when applicable
        exp_f_display="$exp_f"
        exp_d_display="$exp_d"
        # extract numeric part for float (e.g. "float: 42.0f")
        num_f=$(echo "$exp_f" | sed -n "s/.*float: \([+-]\{0,1\}[0-9]\+\(\.[0-9]\+\)\?\)f.*/\1/p")
        if [ -n "$num_f" ]; then
            formatted_f=$(printf "%.1f" "$num_f")
            exp_f_display="float: ${formatted_f}f"
        fi
        # extract numeric part for double
        num_d=$(echo "$exp_d" | sed -n "s/.*double: \([+-]\{0,1\}[0-9]\+\(\.[0-9]\+\)\?\).*/\1/p")
        if [ -n "$num_d" ]; then
            formatted_d=$(printf "%.1f" "$num_d")
            exp_d_display="double: ${formatted_d}"
        fi

        echo -e "  ${BLUE}ESPERADO:${NC}\n"
        printf "    %-6s : %s\n" "char" "$exp_c"
        printf "    %-6s : %s\n" "int" "$exp_i"
        printf "    %-6s : %s\n" "float" "$exp_f_display"
        printf "    %-6s : %s\n" "double" "$exp_d_display"
        echo
        echo -e "  ----------------------------------------"

    # Field checks: compute pass/fail and capture actual lines
        line_char=$(echo "$output" | grep -E '^char:' || true)
        line_int=$(echo "$output" | grep -E '^int:' || true)
        line_float=$(echo "$output" | grep -E '^float:' || true)
        line_double=$(echo "$output" | grep -E '^double:' || true)

        ok_char=0; ok_int=0; ok_float=0; ok_double=0

        printf "  %-10s : " "char"
        if echo "$output" | grep -F -q "$exp_c"; then
            echo -e "${GREEN}PASS${NC}  (found: $exp_c)"; ok_char=1
        else
            echo -e "${RED}FAIL${NC}";
        fi

        printf "  %-10s : " "int"
        if echo "$output" | grep -F -q "$exp_i"; then
            echo -e "${GREEN}PASS${NC}  (found: $exp_i)"; ok_int=1
        else
            echo -e "${RED}FAIL${NC}";
        fi

        printf "  %-10s : " "float"
        if echo "$output" | grep -F -q "$exp_f_display"; then
            echo -e "${GREEN}PASS${NC}  (found: $exp_f_display)"; ok_float=1
        else
            echo -e "${RED}FAIL${NC}";
        fi

        printf "  %-10s : " "double"
        if echo "$output" | grep -F -q "$exp_d_display"; then
            echo -e "${GREEN}PASS${NC}  (found: $exp_d_display)"; ok_double=1
        else
            echo -e "${RED}FAIL${NC}";
        fi

        # Determine overall pass for this test using the ok_* flags
        if [ "$ok_char" -eq 1 ] && [ "$ok_int" -eq 1 ] && [ "$ok_float" -eq 1 ] && [ "$ok_double" -eq 1 ]; then
            echo -e "  ${GREEN}TEST $((idx+1)) PASS${NC}"
            passed=$((passed+1))
        else
            echo -e "  ${RED}TEST $((idx+1)) FAIL${NC}"
            echo -e "\n  RAZÓN:"
            if [ "$ok_char" -ne 1 ]; then
                echo "    char   : expected '$exp_c'  | got: ${line_char:-'(no line)'}"
            fi
            if [ "$ok_int" -ne 1 ]; then
                echo "    int    : expected '$exp_i'  | got: ${line_int:-'(no line)'}"
            fi
            if [ "$ok_float" -ne 1 ]; then
                echo "    float  : expected '$exp_f_display'  | got: ${line_float:-'(no line)'}"
            fi
            if [ "$ok_double" -ne 1 ]; then
                echo "    double : expected '$exp_d_display'  | got: ${line_double:-'(no line)'}"
            fi
            echo
        fi
    done

    echo -e "\n${BLUE}SUMMARY${NC}: $passed / $total tests passed"
    if [ "$passed" -eq "$total" ]; then
        echo -e "${GREEN}All good ✅${NC}"
        return 0
    else
        echo -e "${RED}Some tests failed ❌${NC}"
        return 1
    fi
}

# Main entry
if [ $# -gt 0 ]; then
    # If arguments provided, compile and run those literals one by one in detailed mode
    if ! compile; then exit 1; fi
    for arg in "$@"; do
        run_single "$arg"
    done
    exit 0
else
    if ! compile; then exit 1; fi
    run_tests
    exit $?
fi
