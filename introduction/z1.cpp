#include <iostream>
#include <cmath>
#include <stdarg.h>
namespace home {
	//задание 1
	void changearr(int a[]){
		
		for (int i=0; i<10; i++){
			if (a[i] == 1) a[i] = 0;
			else a[i] = 1;
			std::cout << a[i];
		}
	}

	//задание 1**
	void carr(int a[]){
		int x[10];
		for (int i=0; i<10; i++){
			x[i] = a[i] ^ 1;
			std::cout << x[i];
		}
		std::cout << "" << std::endl;
	}

	
}
