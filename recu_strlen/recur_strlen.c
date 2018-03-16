#include <iostream>
#include <string>

const char* update_ptr(const char* s);
unsigned find_strlen(const char* str);

int main(int argc, char* argv[]) //C++ style but functions are C style
{
  std::string s;
  unsigned length = 0;
  std::cout << "Please enter an input string: " << std::endl;
  getline (std::cin, s);
  length = find_strlen(s.c_str()); //does not modify original string
  if (length >= 0) {
  	std::cout << "String length: " << length << std::endl;
	return (0);
  }
  else {
	std::cout << "Error finding string length!" << std::endl;
	return (-1);
  }
};

unsigned find_strlen(const char* str) //wrapper
{
	const char* addr_beg = str;
	const char* addr_end = update_ptr(addr_beg);
	std::cout << "Address of start: " << &str << std::endl;
	std::cout << "Address of end: " << &addr_end << std::endl;
	unsigned len = (unsigned)((&addr_end - &str)*sizeof(char*));
	return len;
};

const char* update_ptr(const char* s)
{
	if(*s != '\0'){
		std::cout << "Address of S: " << &s << std::endl;
		update_ptr(++s);
	}
	else {return s;}
};
