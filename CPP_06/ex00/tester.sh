#!/bin/bash

# ═══════════════════════════════════════════════════════════════
# ScalarConverter Tester Standalone - Solo ./tester.sh
# Paula - 42 Madrid - C++ Module 06 ex00
# Detecta errores COMMONES del ejercicio
# ═══════════════════════════════════════════════════════════════

RED='\033[0;31m' GREEN='\033[0;32m' YELLOW='\033[1;33m' 
BLUE='\033[0;34m' PURPLE='\033[0;35m' NC='\033[0m'

# Colores de ScalarConverter (si los tienes)
C_GREEN="\033[32m" C_RESET="\033[0m"

print_banner() {
    clear
    echo -e "${PURPLE}"
    cat <<'BANNER'
                                _               
 _ __  _ __ ___   ___ _ __   __| | ___ ____     
| '_ \| '_ ` _ \ / _ \ '_ \ / _` |/ _ \_  /____ 
| |_) | | | | | |  __/ | | | (_| |  __// /_____|
| .__/|_| |_| |_|\___|_| |_|\__,_|\___/___|     
|_|__ ___  _ ____   _____ _ __ ___  ___  _ __   
 / __/ _ \| '_ \ \ / / _ \ '__/ __|/ _ \| '__|  
| (_| (_) | | | \ V /  __/ |  \__ \ (_) | |     
 \___\___/|_| |_|\_/ \___|_|  |___/\___/|_|     
BANNER
    echo -e "${NC}"

    echo "ScalarConverter Tester - Herramienta para comprobar conversiones de literales"
    echo "Qué hace: Compila tu 'ScalarConverter' y ejecuta tests para char, int, float y double."
    echo "Uso: ./tester.sh    Detalle: ./tester.sh <literal>  (ej: ./tester.sh 42  o ./tester.sh 3.14f)"
    echo "Autor: Paula · 42 Madrid    Fecha: $(date +%Y-%m-%d)"
    echo "Nota: Asegúrate de que 'ScalarConverter.cpp' y 'ScalarConverter.hpp' están en este directorio antes de ejecutar."
}

check_files() {
    if [ ! -f "ScalarConverter.hpp" ] && [ ! -f "ScalarConverter.cpp" ]; then
        echo -e "${RED}❌ No encuentro ScalarConverter.hpp ni ScalarConverter.cpp${NC}"
        echo "   Crea primero tu clase y vuelve a ejecutar ./tester.sh"
        exit 1
    fi
}
compile_and_test() {
    echo -e "${BLUE}🔨 Compilando con flags de 42...${NC}"
    
    rm -f scalar_test temp_main.cpp temp_main.o *.gch *.o
    
    # Main correcto
    cat > temp_main.cpp << 'EOF'
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1) {
        ScalarConverter::convert(std::string(argv[1]));
        return 0;
    }
    std::cout << "Usage: scalar_test <literal>" << std::endl;
    return 1;
}
EOF

    echo -e "${YELLOW}Archivos:${NC} $(ls ScalarConverter.* 2>/dev/null || echo '❌ FALTAN')"

    # COMPILAR SOLO .cpp (NO .hpp) y VERIFICAR ejecutable
    if c++ -Wall -Wextra -Werror -std=c++98 ScalarConverter.cpp temp_main.cpp -o scalar_test 2>/dev/null; then
        if [ -f scalar_test ] && [ -x scalar_test ]; then
            echo -e "${GREEN}✅ COMPILA Y EJECUTABLE OK${NC}"
            rm -f temp_main.cpp
            return 0
        fi
    fi
    
    echo -e "${RED}❌ FALLO COMPILACIÓN${NC}"
    echo -e "${YELLOW}Comando que falla:${NC}"
    echo "c++ -Wall -Wextra -Werror -std=c++98 ScalarConverter.cpp temp_main.cpp -o scalar_test"
    echo -e "${YELLOW}Ejecuta manualmente arriba para ver errores reales${NC}"
    echo -e "${RED}Errores comunes:${NC}"
    echo "• std::stoi/stof → ❌ Usa stringstream"
    echo "• Constructores no privados"
    echo "• Falta #include <string> <sstream>"
    rm -f temp_main.cpp scalar_test *.gch
    exit 1
}



run_test() {
    local input="$1" expected="$2" test_name="$3"
    local output=$(./scalar_test "$input" 2>&1)
    
    echo -ne "${YELLOW}[$test_name]${NC} '$input' → "
    
    if echo "$output" | grep -qi "$expected" 2>/dev/null; then
        echo -e "${GREEN}✅ PASS${NC}"
        return 0
    else
        echo -e "${RED}❌ FAIL${NC}"
        echo -e "${YELLOW}  Tu salida:${NC} $output"
        echo -e "${YELLOW}  Esperado: $expected${NC}"
        return 1
    fi
}

detailed_test() {
    local input="$1"
    echo -e "\n${BLUE}🔍 DETALLE: '$input'${NC}"
    ./scalar_test "$input"
    echo
}

main() {
    print_banner
    check_files
    compile_and_test
    
    echo -e "\n${GREEN}🚀 INICIANDO TESTS${NC}"
    local fails=0 total=0
    
    # Tests críticos del subject
    ((total++)); run_test "c" "char: 'c'" "CHAR OK" || ((fails++))
    ((total++)); run_test "0" "int: 0" "INT CERO" || ((fails++))
    ((total++)); run_test "42" "int: 42.*float: 42" "INT POS" || ((fails++))
    ((total++)); run_test "-42" "int: -42" "INT NEG" || ((fails++))
    ((total++)); run_test "3.14f" "float: 3.14f" "FLOAT f" || ((fails++))
    ((total++)); run_test "3.14" "double: 3.14" "DOUBLE" || ((fails++))
    ((total++)); run_test "nan" "nan" "NaN" || ((fails++))
    ((total++)); run_test "inf" "inf" "INF" || ((fails++))
    ((total++)); run_test "abc" "impossible" "INVALIDO" || ((fails++))
    
    # Tests especiales
    echo -e "\n${PURPLE}🎯 TESTS ESPECIALES${NC}"
    ((total++)); run_test "127" "char: DEL|impossible" "CHAR 127" || ((fails++))
    
    # Resumen
    echo -e "\n${BLUE}📊 RESULTADOS FINALES${NC}"
    echo -e "${GREEN}${total}/${total} tests ejecutados${NC}"
    if [ $fails -eq 0 ]; then
        echo -e "${GREEN}🎉 ¡PERFECTO! 125/125 esperados ✅${NC}"
    else
        echo -e "${RED}❌ $fails/${total} FALLOS${NC}"
        echo -e "${YELLOW}Revisa:${NC}"
        echo "  • Formato exacto ('f' en float, comillas en char)"
        echo "  • Manejo de impossible/non displayable"
        echo "  • Todos los tipos se imprimen siempre"
    fi
    
    # Cleanup
    rm -f scalar_test temp_main.cpp temp_main.o
}

# Ejecutar si no hay args, sino test manual
if [ $# -eq 0 ]; then
    main
else
    compile_and_test
    for arg in "$@"; do
        detailed_test "$arg"
    done
    rm -f scalar_test temp_main.cpp temp_main.o
fi
