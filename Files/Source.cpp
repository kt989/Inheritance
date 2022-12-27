#include <iostream>
#include <fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE


void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//1)создаем поток
	std::ofstream fout;
	//2) Создаем поток
	fout.open("File.txt", std::ios_base::app);// std::ios_base::app - чтобы информация дописывалась в файл
	// 3)Пишем в поток
	fout << "Hello, Files" << endl;
	fout << "Привет мир" << endl;
	//4) Закрываем поток после того, как он уже не нужен. Это обязательно!!
	fout.close();

	system("notepad File.txt");
#endif // WRITE_TO_FILE


#ifdef READ_FROM_FILE
	std::ifstream fin("File.txt"); //1) Создаем и открываем поток
	//2) Проверяем открыт ли наш поток
	if (fin.is_open())
	{
		//3) Выполняем чтение из файла

		//4) Создаем буффер чтения
		const int SIZE = 1024; //размер буфера чтения
		char sz_buffer[SIZE] = {}; //буффер
		//5) ПОКА НЕ КОНЕЦ ФАЙЛА, ЧИТАЕМ ЕГО СОДЕРЖИМОЕ
		while (!fin.eof())
		{
			//fin >> sz_buffer; //чтение до пробела!
			// 
			//для того, чтобы прочитать строку с пробелами нужно использовать
			//fin.getline()
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer<<endl;
		}

		fin.close(); //6)Закрываем поток, только в том случае, когда он открыт
	}

	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	cout << "Reading complit" << endl;

#endif // READ_FROM_FILE

}