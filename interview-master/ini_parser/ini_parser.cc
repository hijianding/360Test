#include "ini_parser.h"

namespace qh
{
	INIParser::INIParser()
	{
		configs[curSessions];
	}
	INIParser::~INIParser()
	{}
	bool INIParser::Parse(const std::string& ini_file_path)
	{
		std::ifstream infs(ini_file_path);
		if (!infs)
			throw new std::exception();
		std::string line;
		while (!infs.eof())
		{
			try
			{
				std::getline(infs, line);
				ParseLine(line);
			}
			catch (std::exception ex)
			{
				infs.close();
				throw ex;
			}
		}
		infs.close();
		return true;
	}
	//"a=1\nb=2\n"
	bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator)
	{
		std::string data(ini_data);
		size_t cur = 0;
		std::string line;
		while (cur<data.size()-1)
		{
			try
			{
				SkipStr(data, cur, line_seperator);//skip line_seperator in data;
				line.assign(&data[cur], FindLineEnd(data, cur, line_seperator) - cur);
				cur += line.size();
				ParseLine(line, key_value_seperator);
			}
			catch (std::exception ex)
			{
				throw ex;
				return false;
			}
		}
		return true;
	}
	const std::string& INIParser::Get(const std::string& key, bool* found)
	{
		return configs[""][key];
	}

	const std::string& INIParser::Get(const std::string& section, const std::string& key, bool* found)
	{
		return configs[section][key];;
	}

	void INIParser::SkipStr(std::string& data, size_t& beg, const std::string& skipStr)
	{
		int len = data.size();
		int skipLen = skipStr.size();
		int cur = 0;
		int pos = 0;
		//trim begin
		while (true)
		{
			pos = data.find(skipStr, beg);
			if (pos == beg)
			{
				beg += skipLen;
			}
			else
			{
				break;
			}
		} 
		/*
		//trim end
		while (true)
		{
			len = data.size();
			cur = len - skipLen;
			pos = data.rfind(skipStr);
			if (pos == cur)
			{
				data = data.substr(0, cur);
			}
			else
			{
				break;
			}
		}*/
	}

	size_t INIParser::FindLineEnd(std::string& data, const size_t& beg, const std::string& line_seperator)
	{
		size_t end = data.find(line_seperator, beg);
		return end == data.npos ? data.size() : end;
	}

	void INIParser::ParseLine(std::string& line, const std::string key_value_seperator)
	{
		//clean space 

		//判断是否是[session]标志
		size_t beg = line.find('[');
		if (beg != line.npos&&beg == 0)
		{
			size_t end = line.find(']');
			if (end != line.npos&&end == line.size() - 1)
			{
				curSessions = line.substr(beg + 1, line.size() - 2);
				configs[curSessions];
				return;
			}

		}
		else
		{
			size_t mid = line.find(key_value_seperator);
			if (mid == line.npos)
			{
				return;
			}
			std::string key;
			std::string val;
			key.assign(&line[0], &line[mid]);
			mid += key_value_seperator.size();
			val.assign(&line[mid]);
			configs[curSessions][key] = val;
		}
	}
}