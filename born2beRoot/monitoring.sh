cpu_cores=$(lscpu | grep "Core(s)" | awk '{print $4}')
Vcpu_cores=$(lscpu | grep "CPU(s):" | head -1 | awk '{print $2}')

use_mem=$(free --mega | grep "Mem:" | awk '{print$3}')
total_mem=$(free --mega | grep "Mem:" | awk '{print$2}')
percent_mem=$(echo "scale=2; $use_mem * 100/ $total_mem" | bc)

disk_use=$(df -h | grep "/$" | awk '{print $3}')
disk_total=$(df -h | grep "/$" | awk '{print $2}')
percent_disk=$(df -h | grep "/$" | awk '{print $5}')

cpu_load=$(vmstat | tail -1 | awk '{printf "%.1f", 100 - $15}')

last_boot=$(who -b | grep "system" | awk '{print $3 && " " $4}')

lvm_use=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")

TCP_con=$(ss -tun | grep "ESTAB" | wc -l)

user_log=$(who | awk '{print $1}' | sort -u | wc -l)

ip=$(hostname -I)

mac=$(ip addr | grep "link/ether" | awk '{print $2}')

sudo=$(sudo journalctl _COMM=sudo -q | grep -v "NOT in sudoers" | grep "COMMAND" | wc -l)

printf "\n"
printf "\t#Architecture: %s\n" "$(uname -a)"
printf "\t#CPU physical : %s\n" "$cpu_cores"
printf "\t#vCPU : %s\n" "$Vcpu_cores"
printf "\t#Memory Usage: %s/%sMB (%s%%)\n" "$use_mem" "$total_mem" "$percent_mem"
printf "\t#Disk Usage: %s/%s (%s)\n" "$disk_use" "$disk_total" "$percent_disk"
printf "\t#CPU load: %s%%\n" "$cpu_load"
printf "\t#Last boot: %s\n" "$last_boot"
printf "\t#LVM use: %s\n" "$lvm_use"
printf "\t#Connections TCP: %d ESTABLISHED\n" "$TCP_con"
printf "\t#User log: %d\n" "$user_log"
printf "\t#Network: IP %s (%s)\n" "$ip" "$mac"
printf "\t#Sudo : %d cmd\n" "$sudo"
