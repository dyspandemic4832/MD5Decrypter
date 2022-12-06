#pragma once
#include "dependencies.h"

namespace decrypt
{
	bool bruteforce(std::string MD5Hash);
	bool wordlist(std::string MD5Hash, std::string wordlist);
}