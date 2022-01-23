#! /bin/bash
clear
g++ -Wall -pedantic "$1" -fsanitize=address -g
if [ "$#" -eq 3 ]; then {
    if [ "$2" = "to" ]; then {
        ./a.out > "$3";
    }
    else ./a.out < "$3";
    fi
}
else ./a.out
fi
rm a.out