#include <iostream>
#include <cmath>
#include <stdarg.h>
namespace home {
	//задание 5
	void ar(int size, ...){
		int a[size];
		va_list lst;
		va_start(lst, size);
		for (int i=0; i<size; i++){
			a[i] = va_arg(lst, int) ^ 1;
			std::cout << a[i];
			std::cout << " ";
		}
		va_end(lst);
	}
}
