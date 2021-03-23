/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_generator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:44:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/03/23 15:11:43 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <vector>

using namespace std;

int		main(int argc, char *argv[])
{
	int								stack_len(0);
	int								actual_int(0);
	bool							is_present(false);
	vector<int>						present_int;
	string							str_int;
	string							stack;
		// only used once to initialise (seed) engine
	random_device					rd;
		// random-number engine used (Mersenne-Twister in this case)
	mt19937 						rng(rd());
		// guaranteed unbiased
	uniform_int_distribution<int>	uni(INT32_MIN,INT32_MAX);
	
	srand(static_cast<unsigned int>(time(NULL)));
	if (argc != 2)
		return EXIT_FAILURE;
	stack_len = atoi(argv[1]);
	for (int i(0); i < stack_len; i++)
	{
		actual_int = uni(rng);
		// cout << actual_int << endl;
		is_present = false;
		for (int j(0); j < present_int.size(); j++)
			if (present_int[j] == actual_int)
				is_present = true;
		if (is_present == false)
		{
			present_int.push_back(actual_int);
			stack += to_string(actual_int);
			stack += ' ';
		}
		else
			i--;
	}
	cout << stack;
	return EXIT_SUCCESS;
}