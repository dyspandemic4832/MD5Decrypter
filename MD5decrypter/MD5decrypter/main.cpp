#include "dependencies.h"
#include "md5.h"
#include "decrypt.h"

#define INFO std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [INFO]  >> "
#define DEBUG std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [DEBUG] >> "
#define ERROR std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [ERROR] >> "

static std::time_t time_now = std::time(nullptr);

void printHelp(char* name)
{
	INFO << "Usage: " << std::endl;
	INFO << "  " << name << " [options]\n" << std::endl;
	INFO << "General Options:" << std::endl;
	INFO << "  -h, --help       Show help." << std::endl;
	INFO << "  -v, --version    Show version and exit" << std::endl;
}
void printVersion(char* name)
{
	INFO << "Version:" << std::endl;
	INFO << "  " << name << "  v." << MAJOR_RELEASE << "." << MINAR_RELEASE << "." << PATCH_RELEASE << std::endl;
	INFO << "  licensed under the" << LICENSE << std::endl;
	INFO << "  This Programm was written by " << AUTHOR << std::endl;
}
void parOptions(char options, char* name)
{
	switch (options)
	{
	case 'h':
		printHelp(name);
		break;
	case 'v':
		printVersion(name);
		break;
	case 'd':
		OUTPUT = false;
		break;
	default:
		break;
	}
}
int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		bool success = false;
		std::string name = argv[0];
		std::string wordlist;
		std::string MD5Hash;
		char choice;

		INFO << name << " by " << AUTHOR << std::endl;
		INFO << "Please enter the MD5 Hash: " << std::endl;
		std::cin >> MD5Hash;
		while (true)
		{
			INFO << "Do you want to Bruteforce this Hash? [y/n]: ";
			std::cin >> choice;
			INFO << std::endl;

			switch (choice)
			{
			case 'y':
				success = decrypt::bruteforce(MD5Hash);
				break;
			case 'n':
				INFO << "Do you want to use the default Wordlist? [y/n]: ";
				std::cin >> choice;
				INFO << std::endl;
				if (choice == 'y') { success = decrypt::wordlist(MD5Hash, wordlist); }
				else
				{
					INFO << "Please enter the full filename: ";
					std::cin >> wordlist;
					INFO << std::endl;
					success = decrypt::wordlist(MD5Hash, wordlist);
				}
				break;
			case 'q':
				INFO << name << "is going to quit" << std::endl;
				break;
			default:
				ERROR << "Only enter \"y\" or \"n\"" << std::endl;
				break;
			}
			break;
		}
		if(success == true)
		{
			INFO << "";
		}
	}
	else
	{
		std::string parameter = argv[1];
		if (parameter.at(0) == '-')
		{
			static std::string hlp = "help";
			static std::string vrsn = "version";
			static std::string dbg = "debug";
			char h = hlp.at(0);
			char v = vrsn.at(0);
			char d = dbg.at(0);

			int parLenght = parameter.length();

			if (parameter.at(1) == '-')
			{
				std::string parLong = parameter.substr(2, parameter.length());

				if (parLong.compare(hlp) == 0) { parOptions(parameter.at(2), argv[0]); }
				else if (parLong.compare(vrsn) == 0) { parOptions(parameter.at(2), argv[0]); }
				else if (parLong.compare(dbg) == 0) { parOptions(parameter.at(2), argv[0]); }
				else {
					ERROR << "unknow command \"" << parameter << "\"\n" << std::endl;
					printHelp(argv[0]);
				}
			}
			else if (parLenght == 2)
			{
				char parShort = parameter.at(1);
				if (parShort == h || parShort == v || parShort == d) { parOptions(parShort, argv[0]); }
				else {
					ERROR << "unknow command \"" << parameter << "\"\n" << std::endl;
					printHelp(argv[0]);
				}
			}
			else
			{
				printHelp(argv[0]);
			}
		}
		else if (argc == 2) { decrypt::bruteforce(argv[1]); }
		else if (argc == 3) { decrypt::wordlist(argv[1], argv[2]); }
		else
		{
			ERROR << "unknow command \"" << parameter << "\"\n" << std::endl;
			printHelp(argv[0]);
		}
	}
	return 0;
}