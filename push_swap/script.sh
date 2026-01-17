for ((i = 0 ; i < 5 ; i++ )); do ARG=($(shuf -i 1-2500 -n 5))
./a.out "${ARG[@]}"| ./checker_linux $ARG
./a.out "${ARG[@]}"| wc -l
printf "\n"; done

