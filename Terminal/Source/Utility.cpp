/*
 * Utility.cpp
 *
 *  Created on: Nov 2, 2013
 *      Author: Cfyz
 */

#include "Utility.hpp"
#include "Log.hpp"

namespace BearLibTerminal
{
	bool try_parse(const std::wstring& s, bool& out)
	{
		if (s == L"true" || s == L"1")
		{
			out = true;
			return true;
		}
		else if (s == L"false" || s == L"0")
		{
			out = false;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool try_parse(const std::wstring& s, uint16_t& out)
	{
		if (s.empty()) return false;

		if (s.length() > 2 && ((s[0] == L'0' && (s[1] == L'x' || s[1] == L'X')) || (s[0] == L'U' && s[1] == L'+')))
		{
			std::wistringstream stream(s.substr(2));
			stream >> std::hex;
			stream >> out;
			return !(stream.fail() || stream.bad());
		}
		else if (s.length() == 3 && s[0] == L'\'' && s[2] == L'\'')
		{
			out = (uint16_t)s[1];
			return true;
		}
		else
		{
			std::wistringstream stream(s);
			stream >> out;
			return !(stream.fail() || stream.bad());
		}
	}

	bool try_parse(const std::wstring& s, uint64_t& out)
	{
		if (s.empty()) return false; // Hard to find anything less than 32-bit now

		if (s.length() > 2 && s[0] == L'0' && (s[1] == L'x' || s[1] == L'X'))
		{
			std::wistringstream stream(s.substr(2));
			stream >> std::hex;
			stream >> out;
			return !(stream.fail() || stream.bad());
		}
		else
		{
			std::wistringstream stream(s);
			stream >> out;
			return !(stream.fail() || stream.bad());
		}
	}

	bool try_parse(const std::wstring& s, wchar_t& out)
	{
		uint16_t temp;
		if (!try_parse(s, temp)) return false;
		out = (wchar_t)temp;
		return true;
	}
}
