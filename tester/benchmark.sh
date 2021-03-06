# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/31 10:32:05 by ldutriez          #+#    #+#              #
#    Updated: 2021/04/08 10:28:57 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

MAX=0
ITERATIONS=0
LIMIT=5500
FILE=tester/problem_500
SUM=0

echo "___Debug file___" > $FILE
for i in {1..100}
do
		./stack_gen 500 > stack.txt
		ARG=$(cat stack.txt)
		if ./push_swap $ARG | ./checker $ARG | grep -q KO
		then
			echo "Error!"
			echo $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$LIMIT" ]
			then
			echo $NUMBER >> $FILE
			echo $ARG >> $FILE
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		if [ "$NUMBER" -eq "0" ]
			then
			echo $NUMBER >> $FILE
			echo $ARG >> $FILE
		fi
		echo $i ":" $NUMBER
		let SUM+=$NUMBER;
		let ITERATIONS+=1
done

echo "AVG: $(($SUM / $ITERATIONS))"
echo "MAX: " $MAX
