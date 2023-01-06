#include "dependencies.h"
#include "md5.h"

#define INFO std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [INFO]  >> "
#define DEBUG std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [DEBUG] >> "
#define ERROR std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [ERROR] >> "

static std::time_t time_now = std::time(nullptr);

char asciiList(int number)
{
	switch (number)
	{
	case 0:
		return '!';
		break;
	case 1:
		return '"';
		break;
	case 2:
		return '#';
		break;
	case 3:
		return '$';
		break;
	case 4:
		return '%';
		break;
	case 5:
		return '&';
		break;
	case 6:
		return '\'';
		break;
	case 7:
		return '\(';
		break;
	case 8:
		return '\)';
		break;
	case 9:
		return '*';
		break;
	case 10:
		return '+';
		break;
	case 11:
		return ',';
		break;
	case 12:
		return '-';
		break;
	case 13:
		return '.';
		break;
	case 14:
		return '/';
		break;
	case 15:
		return '0';
		break;
	case 16:
		return '1';
		break;
	case 17:
		return '2';
		break;
	case 18:
		return '3';
		break;
	case 19:
		return '4';
		break;
	case 20:
		return '5';
		break;
	case 21:
		return '6';
		break;
	case 22:
		return '7';
		break;
	case 23:
		return '8';
		break;
	case 24:
		return '9';
		break;
	case 25:
		return ':';
		break;
	case 26:
		return ';';
		break;
	case 27:
		return '<';
		break;
	case 28:
		return '=';
		break;
	case 29:
		return '>';
		break;
	case 30:
		return '?';
		break;
	case 31:
		return '@';
		break;
	case 32:
		return 'A';
		break;
	case 33:
		return 'B';
		break;
	case 34:
		return 'C';
		break;
	case 35:
		return 'D';
		break;
	case 36:
		return 'E';
		break;
	case 37:
		return 'F';
		break;
	case 38:
		return 'G';
		break;
	case 39:
		return 'H';
		break;
	case 40:
		return 'I';
		break;
	case 41:
		return 'J';
		break;
	case 42:
		return 'K';
		break;
	case 43:
		return 'L';
		break;
	case 44:
		return 'M';
		break;
	case 45:
		return 'N';
		break;
	case 46:
		return 'O';
		break;
	case 47:
		return 'P';
		break;
	case 48:
		return 'Q';
		break;
	case 49:
		return 'R';
		break;
	case 50:
		return 'S';
		break;
	case 51:
		return 'T';
		break;
	case 52:
		return 'U';
		break;
	case 53:
		return 'V';
		break;
	case 54:
		return 'W';
		break;
	case 55:
		return 'X';
		break;
	case 56:
		return 'Y';
		break;
	case 57:
		return 'Z';
		break;
	case 58:
		return '[';
		break;
	case 59:
		return '\\';
		break;
	case 60:
		return ']';
		break;
	case 61:
		return '^';
		break;
	case 62:
		return '_';
		break;
	case 63:
		return '`';
		break;
	case 64:
		return 'a';
		break;
	case 65:
		return 'b';
		break;
	case 66:
		return 'c';
		break;
	case 67:
		return 'd';
		break;
	case 68:
		return 'e';
		break;
	case 69:
		return 'f';
		break;
	case 70:
		return 'g';
		break;
	case 71:
		return 'h';
		break;
	case 72:
		return 'i';
		break;
	case 73:
		return 'j';
		break;
	case 74:
		return 'k';
		break;
	case 75:
		return 'l';
		break;
	case 76:
		return 'm';
		break;
	case 77:
		return 'n';
		break;
	case 78:
		return 'o';
		break;
	case 79:
		return 'p';
		break;
	case 80:
		return 'q';
		break;
	case 81:
		return 'r';
		break;
	case 82:
		return 's';
		break;
	case 83:
		return 't';
		break;
	case 84:
		return 'u';
		break;
	case 85:
		return 'v';
		break;
	case 86:
		return 'w';
		break;
	case 87:
		return 'x';
		break;
	case 88:
		return 'y';
		break;
	case 89:
		return 'z';
		break;
	case 90:
		return '{';
		break;
	case 91:
		return '|';
		break;
	case 92:
		return '}';
		break;
	case 93:
		return '~';
		break;
	default:
		ERROR << "Wrong Value inserted in asciiList" << std::endl;
		break;
	}
}
//0 = ! | 93 = ~

namespace decrypt
{
	bool bruteforce(std::string MD5Hash)
	{
		const int MAX_LENGTH = 128;
		const int ASCIITABLE_LENGTH = 93;

		int currentLength;
		int clearTextInt[MAX_LENGTH];

		std::string clearText = " ";

		bool bnewChar = false;
		bool success = false;

		long int attempts = 0;

		for (int i = 0; i < MAX_LENGTH; i++) //overridewrite clearTextInt Array with 0
		{
			clearTextInt[i] = 0;
		}

		while (true)
		{
			currentLength = clearText.length();

			if (bnewChar == true)
			{
				DEBUG << "New Char" << std::endl;
				clearText.push_back('!');
				bnewChar = false;
			}

			for (int cIndex = 0; cIndex < currentLength; cIndex++)
			{
				int alValue = clearTextInt[cIndex];
				clearText.at(cIndex) = asciiList(alValue);
			}

			for (int chkNum = 0; chkNum < currentLength; chkNum++)
			{
				if (clearTextInt[chkNum] == 93)
				{
					if (chkNum == currentLength - 1) { bnewChar = true; }

					clearTextInt[chkNum] = 0;
					clearTextInt[chkNum + 1] = clearTextInt[chkNum + 1] + 1;
				}
				else if (chkNum == 0) { clearTextInt[0] = clearTextInt[0] + 1; }
			}

			attempts = attempts + 1;
			DEBUG << clearText << std::endl;
			if (md5(clearText) == MD5Hash) { success = true; break; }
		} //end of while

		return success;
	}

	bool wordlist(std::string MD5Hash, std::string wordlist)
	{
		bool success = false;

		if (wordlist.empty()) { wordlist = "wordlist.txt"; }
		std::ifstream WORDLIST(wordlist);
		std::string line;

		if (WORDLIST.is_open())
		{
			while (getline(WORDLIST, line))
			{
				if (md5(line) == MD5Hash) { success = true; break; }
			}
		}
		else
		{
			ERROR << "There was no file found with the name \"" << wordlist << "\"" << std::endl;
		}

		return success;
	}
}