#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"
#include <assert.h>


//string构造函数
hsy::string::string(const char* str)
{
	//数组容量 = 数组实际存放字符个数
	_capacity = _size = strlen(str);
	//在堆上为字符串申请空间，大小为str的长度+1
	_str = new char[_size + 1];
	//将str拷贝到对象成员变量_str所指向的内存空间,strcpy拷贝时也会将'\0'拷贝
	strcpy(_str, str);
}

//string拷贝构造函数
hsy::string::string(const string& s)
{
	//将s的size和capacity赋值给待构造的对象
	_size = s._size;
	_capacity = s._capacity;
	//堆上申请字符串空间，并将s的字符串成员变量_str拷贝到申请的空间
	_str = new char[_size + 1];
	strcpy(_str, s._str);
}

//string赋值运算
hsy::string& hsy::string::operator=(const hsy::string &s)
{
	//避免自己给自己赋值
	if (this != &s)
	{
		//释放原有字符串空间
		delete[] _str;
		//新开辟字符串空间，并将s的字符串拷贝到其中
		_str = new char[s._size + 1];
		strcpy(_str, s._str);
		//更新_size和_capacity
		_size = s._size;
		_capacity = s._capacity;
	}
	//以上代码也可以直接用swap(s)代替
	return *this;
}

//string析构函数
hsy::string::~string()
{
	delete[] _str;
	_str = nullptr;
	_size = _capacity = 0;
}

//iterator迭代器（类似于指针）
hsy::string::iterator hsy::string::begin()
{
	return _str;
}

hsy::string::iterator hsy::string::end()
{
	return _str + _size;
}

//modify
//insert(_size, c)
void hsy::string::push_back(char c)
{
	if (_size + 1 > _capacity)
	{
		size_t new_capacity = _capacity == 0 ? 4 : _capacity * 2;
		reserve(new_capacity);
	}

	_str[_size] = c;
	_str[_size + 1] = '\0';
	_size++;
}

hsy::string& hsy::string::operator+=(char c)
{
	push_back(c);

	return *this;
}
//insert(_size, str)
void hsy::string::append(const char* str)
{
	size_t len = strlen(str) + _size;
	if (len > _capacity)
	{
		reserve(len);
	}
	
	strcpy(_str + _size, str);
	_size = len;
}

hsy::string& hsy::string::operator+=(const char* str)
{
	append(str);

	return *this;
}

void hsy::string::clear()
{
	_str[0] = '\0';
	_size = 0;
}

//直接用swap(*this, s)会发生深拷贝，因此这里交换成员变量提升效率
void hsy::string::swap(string& s)
{
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}

//Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string)
//representing the current value of the string object.
const char* hsy::string::c_str()const
{
	return _str;
}

//capacity

size_t hsy::string::size()const
{
	return _size;
}

size_t hsy::string::capacity()const
{
	return _capacity;
}

bool hsy::string::empty()const
{
	return _size == 0 ? true : false;
}

void hsy::string::resize(size_t n, char c)
{
	if (n < _capacity)
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		if (n > _capacity)
		{
			reserve(n);
		}
		
		for (size_t i = _size; i < n; i++)
		{
			_str[i] = c;
		}
		_str[n] = '\0';
		_size = n;
	}
}

void hsy::string::reserve(size_t n)
{
	if (n > _capacity)
	{
		_capacity = n;

		char* str = new char[n + 1];
		strncpy(str, _str, _size);

		delete[] _str;
		_str = str;
	}
}

// access

char& hsy::string::operator[](size_t index)
{
	assert(index < _size);

	return _str[index];
}

const char& hsy::string::operator[](size_t index)const
{
	assert(index < _size);

	return _str[index];
}

//relational operators

bool hsy::string::operator<(const string& s)
{
	return strcmp(_str, s._str) < 0 ? true : false;


bool hsy::string::operator<=(const string& s)
{
	return strcmp(_str, s._str) <= 0 ? true : false;
}

bool hsy::string::operator>(const string& s)
{
	return !(*this <= s);
}

bool hsy::string::operator>=(const string& s)
{
	return !(*this < s);
}

bool hsy::string::operator==(const string& s)
{
	return strcmp(_str, s._str) == 0 ? true : false;
}

bool hsy::string::operator!=(const string& s)
{
	return !(*this == s);
}



// 返回c在string中第一次出现的位置

size_t hsy::string::find(char c, size_t pos) const
{
	for (size_t i = pos; i < _size; i++)
	{
		if (_str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

// 返回子串s在string中第一次出现的位置

size_t hsy::string::find(const char* s, size_t pos) const
{
	char* ret;
	if ((ret = strstr(_str + pos, s)) != NULL)
	{
		return ret - _str;
	}

	return -1;
}

// 在pos位置上插入字符c/字符串str，并返回该字符的位置

hsy::string& hsy::string::insert(size_t pos, char c)
{
	/*assert(pos < _capacity);
	reserve(_capacity * 2);
	
	if (pos >= _size)
	{
		_str[pos] = c;
	}
	else
	{
		for (size_t i = _size - 1; i > pos; i++)
		{
			_str[i + 1] = _str[i];
		}
		_str[pos] = c;
	}
	
	return *this;*/
	assert(pos < _size);
	if (_size == _capacity)
	{
		size_t new_capacity = _capacity == 0 ? 4 : _capacity * 2;
		reserve(new_capacity);
	}
	
	int end = _size + 1;
	while (end > pos)
	{
		_str[end] = _str[end - 1];
		end--;
	}
	_str[pos] = c;
	_size++;

	return *this;
}

hsy::string& hsy::string::insert(size_t pos, const char* str)
{
	/*assert(pos < _size);

	size_t len = strlen(str) + _size;
	if (len > _capacity)
	{
		reserve(len);
	}

	int l = strlen(str);
	while (l)
	{
		for (size_t i = _size - 1; i > pos; i--)
		{
			_str[i + 1] = _str[i];
		}

		l--;
	}
	

	for (size_t i = pos; i < strlen(str); i++)
	{
		_str[i] = str[i - pos];
	}*/

	assert(pos < _size);

	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}

	char* end = _str + _size;
	while (end >= _str + pos)
	{
		*(end + len) = *end;
		end--;
	}

	strncpy(_str + pos, str, len);
	_size += len;

	return *this;
}



// 删除pos位置上的元素

hsy::string& hsy::string::erase(size_t pos, size_t len)
{
	/*assert(pos < _size);
	if (len == -1)
	{
		for (size_t i = pos; i < _size; i++)
		{
			_str[i] = '\0';
		}
	}
	else
	{
		for (size_t i = pos; i <  len; i++)
		{
			if (i < _size)
			{
				_str[i] = '\0';
			}
			else
			{
				break;
			}
		}
	}

	return *this;*/
	assert(pos < _size);

	size_t leftLen = _size - pos;
	if (len >= leftLen)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		strcpy(_str + pos, _str + pos + len);
		_size -= len;
	}

	return *this;
}