#include <iostream>
#include <cmath>
#include <stdarg.h>
namespace home {

	//задание 4
	void shift(int a[], int b = 2){
		int buff;
		int inc;
		if (b >= 0){
			for (int i=0; i<b; i++){
				inc = 0;
				buff = a[inc];
				while (inc < 4){				
					a[inc] = a[inc+1];
					inc++;
					}
				a[4] = buff;
			}
		}
		else {
			b = abs(b);
			for (int i=0; i<b; i++){
				inc = 4;
				buff = a[inc];
				while (inc > 0){				
					a[inc] = a[inc-1];
					inc--;
					}
				a[0] = buff;
			}		
		}
		for (int i=0; i<5; i++){
				std::cout << a[i];
				std::cout << " ";
		}	
		std::cout << " " << std:: endl;
	}
	
}
