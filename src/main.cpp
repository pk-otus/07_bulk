#include <iostream>

#include "data_reader.h"

int main(int, char *[])
{
	try
	{
		bulk_handler handler(3);
		data_reader reader(std::cin, &handler);
		reader.Perform();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
