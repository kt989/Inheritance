#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 25;
	char mac_buffer[SIZE] = {};
	char ip_buffer[SIZE] = {};
	std::ifstream fin;
	fin.open("201 RAW.txt");
	if (fin.is_open())
	{

		std::ofstream fout;
		fout.open("201_RAW.txt");
		fout << " ";
		fout.close();
		while (!fin.eof())
		{
			fin >> ip_buffer;
			fin >> mac_buffer;
			fout.open("201_RAW.txt", std::ios_base::app);
			fout << mac_buffer << "\t" << ip_buffer<<endl;
			fout.close();
			//cout << ip_buffer << endl;
			//cout << mac_buffer << endl;
		}

		//system("201_RAW.txt");
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found"<<endl;
	}
	//std::ifstream fin("201_RAW.txt");
	std::ofstream fout;
    fout.open("201 RAW.txt");
	fout << NULL;
	fout.close();
	fin.open("201_RAW.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> ip_buffer;
			fin >> mac_buffer;
			std::ofstream fout;
			fout.open("201 RAW.txt", std::ios_base::app);
			fout << ip_buffer << "\t" << mac_buffer << endl;
			fout.close();
		}
		system("201_RAW.txt");			
		fin.close();
	}
	else
	{
		std::cerr << "Error" << endl;
	}

		cout << "Change is complit" << endl;


}

