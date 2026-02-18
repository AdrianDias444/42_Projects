This project has been created as part of the 42 curriculum by addias.

## Description
The objective of push_swap is to return all the instructions needed to sort a stack.

I used the logic of quicksort. We need to define a pivot for each cycle.

The pivot is determined by the return of `ft_return_mid.c` if we have less than 110 numbers to sort, or `ft_return_mid_mid.c` if we have more than 110 numbers to sort.


## Instructions
For testing you can use this test script:
This script test:
- memory leaks
- if the instructions are correct using the checker, from the subject
- how many instructions are our program doing

```bash
soma=0
for ((i = 0; i < 10; i++)); do
    ARG=($(shuf -i 1-2500 -n 100))

    output=$(./a.out "${ARG[@]}")
    
    echo "$output" | ./checker_linux "${ARG[@]}"
    
    nb=$(echo "$output" | wc -l)
    soma=$((soma + nb))
    
    valgrind --leak-check=full ./a.out "${ARG[@]}" 2>&1 | grep "total heap usage"

    printf "Iteração %d: %d linhas\n" "$i" "$nb"
    echo "-----------------------------------"
done

media=$((soma / 10))
printf "\nA média é: %d\n" "$media"
```

## Resources
A lot of websites and web research was used for understading how the base quick sort work, AI also was used for it