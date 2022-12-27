#include <iostream>
#include <fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE


void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//1)������� �����
	std::ofstream fout;
	//2) ������� �����
	fout.open("File.txt", std::ios_base::app);// std::ios_base::app - ����� ���������� ������������ � ����
	// 3)����� � �����
	fout << "Hello, Files" << endl;
	fout << "������ ���" << endl;
	//4) ��������� ����� ����� ����, ��� �� ��� �� �����. ��� �����������!!
	fout.close();

	system("notepad File.txt");
#endif // WRITE_TO_FILE


#ifdef READ_FROM_FILE
	std::ifstream fin("File.txt"); //1) ������� � ��������� �����
	//2) ��������� ������ �� ��� �����
	if (fin.is_open())
	{
		//3) ��������� ������ �� �����

		//4) ������� ������ ������
		const int SIZE = 1024; //������ ������ ������
		char sz_buffer[SIZE] = {}; //������
		//5) ���� �� ����� �����, ������ ��� ����������
		while (!fin.eof())
		{
			//fin >> sz_buffer; //������ �� �������!
			// 
			//��� ����, ����� ��������� ������ � ��������� ����� ������������
			//fin.getline()
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer<<endl;
		}

		fin.close(); //6)��������� �����, ������ � ��� ������, ����� �� ������
	}

	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	cout << "Reading complit" << endl;

#endif // READ_FROM_FILE

}