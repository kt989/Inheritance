#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

#define IP_MAC_EXCHANGE
//#define IP_MAC_INFORMATION

void main()
{
	setlocale(LC_ALL, "");
	char sz_room_number[FILENAME_MAX] = {};
	//int room_number;
	cout << "Введите номер аудитории: "; cin >> sz_room_number;
	char sz_source_filename[FILENAME_MAX] = {};
	strcat(sz_source_filename, sz_room_number); //strcat - конкатенация строк, т.е. склеивает две строки в одну
	strcat(sz_source_filename, " RAW.txt");
	cout << sz_source_filename << endl;
	char sz_wal_filename[FILENAME_MAX] = {};
	strcat(sz_wal_filename, sz_room_number);
	strcat(sz_wal_filename, " ready.txt");
	char sz_dhcp_filename[FILENAME_MAX] = {};
	strcat(sz_dhcp_filename, sz_room_number);
	strcat(sz_dhcp_filename, ".dhcpd.txt");
	cout << sz_wal_filename << endl;
	cout << sz_dhcp_filename << endl;


	const int IP_SIZE = 16;
	const int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE] = {}; //sz_- String Zero or NullTerminated Line 
	char sz_mac_buffer[MAC_SIZE] = {};
	
#ifdef IP_MAC_EXCHANGE
	std::ofstream fout(sz_wal_filename);
	std::ifstream fin(sz_source_filename);
	if (fin.is_open())
	{
		//Будем читать файл

		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			fout << sz_mac_buffer << "\t\t";
			fout << sz_ip_buffer << endl;
		}
		fin.close();
		fout.close();
	    char sz_command_1[FILENAME_MAX] = "notepad ";
	    strcat(sz_command_1, sz_wal_filename);
	    std::system(sz_command_1);
    }
	else
	{
		std::cerr << "File not found" << endl;
	}


#endif // IP_MAC_EXCHANGE
#ifdef IP_MAC_INFORMATION
	std::ofstream fout(sz_dhcp_filename);
	std::ifstream fin(sz_source_filename);
	if (fin.is_open())
	{
		//TODO read file:
		for (int i = 0; !fin.eof(); i++)
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			if (sz_ip_buffer[0] == NULL && sz_mac_buffer[0] == NULL)continue;
			for (int j = 0; sz_mac_buffer[j]; j++)
				if (sz_mac_buffer[j] == '-') sz_mac_buffer[j] = ':';
			fout << "host " << sz_room_number << "-" << i + 1 << endl;
			fout << "{\n";
			fout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			fout << "\tfixed-address \t\t" << sz_ip_buffer << ";\n";
			fout << "}\n\n";
		}

		fin.close();
		fout.close();
		char sz_command_2[FILENAME_MAX] = "start notepad ";//start - позволяет параллельно открыть сразу насколько файлов
		strcat(sz_command_2, sz_dhcp_filename);
		std::system(sz_command_2);
	}
	else
	{
		std::cerr << "File not found" << endl;
	}
#endif // IP_MAC_INFORMATION

}