#!/bin/bash

# ==============================================================================
# LEAK TEST SCRIPT FOR CUB3D
# ==============================================================================

# Colors
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
RESET="\033[0m"

echo -e "${YELLOW}==============================================================================${RESET}"
echo -e "${YELLOW}=                     CUB3D AUTOMATED VALGRIND TESTER                        =${RESET}"
echo -e "${YELLOW}==============================================================================${RESET}"

# Maps to test
MANDATORY_MAPS=(
    "assets/maps/mandatory/complex_maze.cub"
    "assets/maps/mandatory/complex_rooms_a.cub"
    "assets/maps/mandatory/complex_rooms_b.cub"
    "assets/maps/mandatory/mandatory_test.cub"
)

BONUS_MAPS=(
    "assets/maps/bonus/arena.cub"
    "assets/maps/bonus/complex.cub"
    "assets/maps/bonus/complex2.cub"
    "assets/maps/bonus/test.cub"
    "assets/maps/bonus/two_rooms.cub"
)

# Invalid maps / Error testing (Testing how it handles bad files, no segfaults/leaks expected on exit)
INVALID_MAPS=(
    "assets/invalid_map.cub"
    "assets/does_not_exist.cub"
)

VALGRIND_CMD="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42"

run_tests() {
    local EXECUTABLE=$1
    local MAPS=("${@:2}")
    
    if [ ! -f "$EXECUTABLE" ]; then
        echo -e "${RED}[ERROR] Executable $EXECUTABLE not found. Please compile first.${RESET}"
        return
    fi
    
    echo -e "\n${YELLOW}Testing $EXECUTABLE ...${RESET}\n"
    
    for MAP in "${MAPS[@]}"; do
        echo -e "Testing map: ${GREEN}$MAP${RESET}"
        
        # We limit the output since Valgrind can be verbose with MLX
        # Note: MLX has internal leaks the student cannot fix. We suppress them ideally or just look at them.
        LOG_FILE="valgrind_$(basename $MAP).log"
        
        # Running valgrind
        $VALGRIND_CMD ./$EXECUTABLE $MAP > $LOG_FILE 2>&1
        EXIT_CODE=$?
        
        # We can search the log for reachable / leaks
        DEFI_LEAKS=$(grep "definitely lost:" $LOG_FILE | awk '{print $4}')
        INDI_LEAKS=$(grep "indirectly lost:" $LOG_FILE | awk '{print $4}')
        
        if [ "$DEFI_LEAKS" == "0" ] && [ "$INDI_LEAKS" == "0" ]; then
             echo -e "${GREEN}[OK] No definitely/indirectly lost leaks found in $MAP${RESET}"
        else
             echo -e "${RED}[FAIL] Leaks detected in $MAP ! Check $LOG_FILE${RESET}"
        fi
        
        echo "------------------------------------------------------------"
    done
}

# 1. Compile everything
echo -e "${YELLOW}Compiling...${RESET}"
make > /dev/null 2>&1
make bonus > /dev/null 2>&1

echo -e "\n${YELLOW}Running Mandatory Tests...${RESET}"
run_tests "cub3D" "${MANDATORY_MAPS[@]}"

echo -e "\n${YELLOW}Running Bonus Tests...${RESET}"
run_tests "cub3D_bonus" "${BONUS_MAPS[@]}"

echo -e "\n${YELLOW}Running Error Handling Tests (Mandatory)...${RESET}"
run_tests "cub3D" "${INVALID_MAPS[@]}"

echo -e "\n${YELLOW}==============================================================================${RESET}"
echo -e "${YELLOW}Done! Review the valgrind_*.log files for detailed memory analysis.${RESET}"
echo -e "${YELLOW}Note: MinilibX internal leaks may appear in 'still reachable' or MLX internals, which are expected in 42.${RESET}"
echo -e "${YELLOW}==============================================================================${RESET}"
