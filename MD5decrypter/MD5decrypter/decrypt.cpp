#include "dependencies.h"
#include "md5.h"

#define INFO std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [INFO]  >> "
#define DEBUG std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [DEBUG] >> "
#define ERROR std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [ERROR] >> "

static std::time_t time_now = std::time(nullptr);

namespace decrypt
{
	bool bruteforce(std::string MD5Hash)
	{
		bool success = false;
		std::string clearText;
		int attempts = 0;

		while (success == false)
		{
			attempts++;
		}

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