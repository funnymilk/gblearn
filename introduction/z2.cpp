#include <iostream>
#include <cmath>
#include <stdarg.h>
namespace home {
	
	//задание 2
	void incl(int a[]){
		int i = 1;
		int k = 0;
		while (i<=22){
			a[k] = i;		
			std::cout << a[k];
			std::cout << "  ";
			i = i+3;
			k++;
		} 
			std::cout << "" << std::endl;
	}
}
