#include <iostream>
#include <cmath>
#include <stdarg.h>
namespace home {

	//задание 3
	bool checkBalance(int a[]){
		int s1 = 0;
		int s2 = 0;	
		bool result;
		for (int i=0; i<5; i++){
			s1 = s1 + a[i];
			for (int j=i+1; j<5; j++){
				s2 = s2 + a[j];
			}		
			if (s1 == s2) {
				//std::cout << s1 << std::endl;
				//std::cout << "true" << std::endl;
				//std::cout << s2 << std::endl;
				result = true;
				break;
			}
			else {
				result = false;
				s2 = 0;
				
			}
		}
		return result;
	}
}
