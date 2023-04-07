RED='\033[31m';
GREEN='\033[32m';
END='\033[0m';

max_op=$1;
count=0;
echo "" > out.txt
make
echo -e "\033[34m
██╗  ██╗███████╗██╗     ██╗      ██████╗  █████╗ ███████╗███████╗██████╗ 
██║  ██║██╔════╝██║     ██║     ██╔════╝ ██╔══██╗██╔════╝██╔════╝██╔══██╗
███████║█████╗  █║     ██║     ██║  ███╗███████║█████╗  █████╗  ██████╔╝
██╔══██║██╔══╝  ██║     ██║     ██║   ██║██╔══██║██╔══╝  ██╔══╝  ██╔══██╗
██║  ██║███████╗███████╗███████╗╚██████╔╝██║  ██║███████╗███████╗██║  ██║
╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝
\033[0mPush Swap"
echo "push_swap" | figlet -f slant
while [ $count -lt $max_op ]
do
    num=$(seq -1001 1000 | sort -R | awk '!a[$0]++' | head -n $2 | tr '\n' ' ')
    ok=$(./push_swap $num | wc -l)
    
    if [ $ok -lt 5500 ] && [ $2 -eq 500 ]; then
        echo -e "test $count:${GREEN}$ok${END} your point: 5"
    elif [ $ok -ge 5500 ] && [ $2 -eq 500 ]; then
        echo $num >> out.txt
        echo -e "test $count:${RED}$ok${END}"
        sleep 1;
        # exit;
    elif [ $ok -lt 600 ] && [ $2 -eq 100 ]; then
        echo -e "test $count:${GREEN}$ok${END} your point: 5"
    elif [ $ok -ge 600 ] && [ $2 -eq 100 ]; then
        echo $num >> out.txt
        echo -e "test $count:${RED}$ok${END}"
        # echo "i will sleep because you have a cas > 600"
        sleep 1;
        # exit;
    else
        echo -e "test $count:${RED}$ok${END}"
    fi
    ((count++))
done
make fclean
