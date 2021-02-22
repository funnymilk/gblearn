#include <iostream>

enum xzero{lline = 92, rline = 47, gline = 45, vline = 124, x = 120, o = 111};

typedef struct tableXzero {
	xzero xz;
	int player1 = 1;
	int player2 = 2;
	bool turn;
	std::string player = "player";
	std::string win = "win!";
	std::string draw = "draw";
} table;

union pobit_type{
	int p0;
	float p1;
	char p2;

};

struct pbt {
	union pobit_type type;
	int is_char : 1;
	int is_float : 1;
	int is_int : 1;
};

int main(int argc, char const *argv[]){
	/*int p0;
	float p1;
	char p2;
	bool b3;
	double p4;
	long p5;*/

	char xz[6];
	xz[0] = lline;
	xz[1] = rline;
	xz[2] = gline;
	xz[3] = vline;
	xz[4] = x;
	xz[5] = o;

	//вывод для проверки
	//std::cout << xz[0] << std::endl; 

	pbt K;
	K.type.p0 = 2;
	K.is_char = 0;
	K.is_int = 1;
	K.is_float = 0;
	int d = 1;
	std::cout << K.type.p0 << std::endl; 
	//хотел вывести для проверки и побитовое число(флаг, как угодно) ничего не получилось
	//выводит всегда -1
	std::cout << K.is_int << std::endl; 


	return 0;
}