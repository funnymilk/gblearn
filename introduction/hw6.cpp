/*

Написать программу, которая создаст два текстовых файла, примерно по 50-100 символов в каждом (особого значения не имеет);
Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера.
* Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).

*/

#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, const char** argv){
//задание 1*
	//открытие потока
	std::ofstream file1("hw1.txt");
	std::ofstream file2("hw2.txt");
	//file << "test" << std::endl;
	for (int i=0; i<50; i++){
		file1 << "l" << " ";
		file2 << "b" << " ";
		//file2 << static_cast<char>(i+51) << std::endl;
	}
	file1.close();
	file2.close();
	
	//потоковая переменная? чтоаоаоа?!?!
	//std::string word;


	
//задание 2
	//заполнение файла3 содержимым первого
	std::ifstream fil1("hw1.txt"); 							//поток для чтения из файла
	std::ofstream file3("hw3.txt", std::ofstream::app); 	//поток для записи в файл
	std::string f;											//переменная стрингового типа

	getline(fil1, f);										//запись всей строки из fil1 в f
	char *buff = new char(f.length()*50);						//выделение памяти типа чар, размер под переменную f
	//std::cout << sizeof(buff) << std::endl; 				//проверка размера выделенной памяти
		  std::cout << f.length() << std::endl; 			//проверка размера выделяемой памяти
	strcpy(buff, f.c_str());								//запись значение из переменной f в выделенную памямть(буфер), предварительно приведя типа к чар
	file3 << buff; 											//направляем потоk с выделенной памяти в file3
	fil1.close();											// закрываем fil1
	file3.close();											// закрываем file3
	delete buff; 											//высвобождаем выделенную раннее память
	
	//заполнение файла3 содержимым первого	
	std::ifstream fil2("hw2.txt");							//поток для чтения из файла
	std::ofstream file33("hw3.txt", std::ofstream::app); 	//поток для записи в файл
	std::string f1; 										//переменная стрингового типа
	getline(fil2, f1);										//запись всей строки из fil2 в f1
	char *buff2 = new char(f1.length()); 					//выделение памяти типа чар, размер под переменную 1
		std::cout << f1.length() << std::endl; 				//проверка размера выделяемой памяти
	strcpy(buff2, f1.c_str());  							//запись значение из переменной f1 в выделенную памямть(буфер), предварительно приведя типа к чар
	file33 << buff2; 
	fil2.close();
	file33.close();
	delete buff2;
		


//задание3
	//std::cout << argv[1];
	std::string word;
	std::ifstream sfile("testfile.txt"); 					//поток для чтения из файла
	int d = 0;
	while (!sfile.eof()) {
		sfile >> word;
		if (word == argv[1]) d++;
	}
	
	if (d > 0) {
		std::cout << "There is '" << argv[1] << "'" << " in the file!" << std::endl;
	}
	else {
		std::cout << "There isn't '" << argv[1] << "'" << " in the file!" << std::endl;
	}
	sfile.close();
	
	return 0;
}




