#pragma once
#include <chrono>
#include <iostream>

long fibonacci(unsigned n)
{
	if (n < 2) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int chrono_main()
{
	unsigned n = 42;
	std::cout << "number: ";
	std::cin >> n;
	auto start = std::chrono::steady_clock::now();
	std::cout << "\nf(" << n << ") = " << fibonacci(n) << '\n';
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	return 0;
}