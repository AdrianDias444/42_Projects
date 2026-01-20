#!/bin/bash

soma=0

for ((i = 0; i < 10; i++)); do
    ARG=($(shuf -i 1-2500 -n 500))

    output=$(./a.out "${ARG[@]}")

    echo "$output" | ./checker_linux "${ARG[@]}"

    nb=$(echo "$output" | wc -l)
    soma=$((soma + nb))

    printf "Iteração %d: %d linhas\n" "$i" "$nb"
done

media=$((soma / 10))
printf "\nA média é: %d\n" "$media"
