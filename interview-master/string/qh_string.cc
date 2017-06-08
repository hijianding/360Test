#include "qh_string.h"

#include <string.h>

namespace qh
{
	// TODO 将在这里写实现代码

	string::string()
		: data_(NULL), len_(0)
	{
	}

	string::string(const char* s)
	{
		if (!s)
		{
			data_ = NULL;
			len_ = 0;
		}
		else
		{
			len_ = strlen(s);
			data_ = new char[len_ + 1];
			strcpy(data_, s);
		}
	}

	string::string(const char* s, size_t len)
	{
		if (!s)
		{
			data_ = NULL;
			len_ = 0;
		}
		else
		{
			len_ = len;
			//len输入负数返回空
			if (static_cast<int>(len) < 0)
			{
				data_ = NULL;
				len_ = 0;
			}
			else
			{
				data_ = new char[len_ + 1];
				strncpy(data_, s, len);
				data_[len] = 0;
				len_ = strlen(data_);
			}
		}
	}

	string::string(const string& rhs)
	{
		if (!rhs.data_)
		{
			data_ = NULL;
			len_ = rhs.len_;
		}
		else
		{
			len_ = rhs.len_;
			data_ = new char[len_ + 1];
			strcpy(data_, rhs.data_);
		}

	}

	string& string::operator=(const string& rhs)
	{
		if (this!=&rhs)
		{
			delete[] data_;
			len_ = rhs.len_;
			data_ = new char[len_ + 1];
			strcpy(data_, rhs.data_);
		}
		return *this;
	}

	string::~string()
	{
		delete[] data_;
	}

	size_t string::size() const
	{
		return len_;
	}

	const char* string::data() const
	{
		if (data_==NULL)
			return NULL;
		char *rt = new char[len_ + 1]();
		memcpy(rt, data_, len_ + 1);
		return rt;
	}

	const char* string::c_str() const
	{
		if (data_ == NULL)
			return NULL;
		int len = strlen(data_);
		char *rt = new char[len + 1]();
		strcpy(rt, data_);
		return rt;
	}

	char* string::operator[](size_t index)
	{
		if (data_ == NULL || static_cast<int>(index) < 0)
			return NULL;
		if (index <= len_)
			return &(data_[index]);
		return NULL;
	}
}

