#include <sstream>
#include "StringCalculator.h"
#include <stdexcept>
bool is_there_another_number(std::string& str, int & number,std::string const&delim, bool is_user_delim)
{
	std::string::size_type pos;
	if(is_user_delim) {
		pos = str.find(delim,0);
	}
	else
	 pos = str.find_first_of(delim,0);

	if(pos == std::string::npos){
		return false;
	}
	++pos;
	str = str.substr(pos,str.size() - pos);
	std::stringstream ss(str);
	ss>>number;
	str = str.substr(ss.tellg(),str.size() - ss.tellg());

	return true;
}

bool contains_user_delim(std::string &str, std::string& delim)
{
	if(str[0]=='/' && str[1]=='/'){
		delim = str[2];
		str = str.substr(4,str.size() - 4);
		return true;
	}
	return false;
}

void is_negative_number_present(int result){
	if(result<0)throw std::runtime_error("negative number not allowed");
}

int number_empty(std::string numbers){
	if(numbers.empty()){
		return 0 ;
	}
}

int StringCalculator::add(std::string numbers)
{
	number_empty(numbers);
	std::string delim("\n,");
	bool user_delim = contains_user_delim(numbers,delim);

	int result;
	std::stringstream ss(numbers);
	ss>>result;
	//is_negative_number_present(result);
	numbers = numbers.substr(ss.tellg(), numbers.size() - ss.tellg());
	int next;
	while(is_there_another_number(numbers,next,delim,user_delim))
	{
		if(next<0)throw std::runtime_error("negative number not allowed");
		result += next;
	}
	return result;
}
