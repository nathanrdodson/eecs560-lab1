#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <iostream>

class Executive
{
    private:
	std::string filename;

    public:
	
	Executive(std::string argIn);
	~Executive();

	bool isValidData(const std::string& input);
	void run();
	
};

#endif