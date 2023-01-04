#include <iostream>
#include <fstream>
using namespace std; //Олег, сделала так, как сама думаю. Отдельно проработала (новым проектом), то что вместе на последнем занятии решали 

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 20;
	char mac_buffer[SIZE] = {};
	char ip_buffer[SIZE] = {};
	int number = 0;
	std::ifstream fin;
	fin.open("201 RAW.txt");
	if (fin.is_open())
	{
		while (!fin.eof()) // Почему-то записывает еще 13-ую строку без значений ip и mac
		{
			fin >> mac_buffer;
			fin >> ip_buffer;
			std::ofstream fout;
			fout.open("201 RAW.dhcpd", std::ios_base::app);
			fout << "host 201-" << ++number << endl << "{" << endl;
			fout << "\thardware ethernet\t";
		    fout << mac_buffer;
			fout << "; \n";
			fout << "\tfixed-address\t";
			fout << ip_buffer;
			fout << "; \n" << "}" << endl << endl;
			fout.close();
		}
		fin.close();
		cout << "Operation is completed";
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
}
