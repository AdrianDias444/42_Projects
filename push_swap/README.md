_This project has been created as part of the 42 curriculum by addias._

## Description
The objective of the push_swal is return all of the instructions to sort a stack.

I use the logic of the quick sort. We need to define a pivot every single for every cicle.

The pivot is the return of `ft_return_mid.c` if we have less of 110 numbers or `ft_return_mid_mid.c` if we have more of 110 numbers to sort. 
## Instructions
For testing you can use this test script

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
## Resources

