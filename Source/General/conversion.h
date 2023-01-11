#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include <vector>

namespace conversion
{
	int bytesToInt(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3);
	std::vector<uint8_t> hexStrToBytes(const std::string& hex);
	uint8_t hexStrToByte(char* hex);
}

#endif


