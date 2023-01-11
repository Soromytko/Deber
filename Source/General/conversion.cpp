#include "conversion.h"

namespace conversion
{
	int bytesToInt(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
	{
		return ((int)b0 << 24) + ((int)b1 << 16) + ((int)b2 << 8) + (int)b3;
	}

	std::vector<uint8_t> hexStrToBytes(const std::string& hex)
	{
		std::vector<uint8_t> bytes;

		for (unsigned int i = 0; i < hex.length(); i += 2)
		{
			std::string byteString = hex.substr(i, 2);
			char byte = (uint8_t)strtol(byteString.c_str(), nullptr, 16);
			bytes.push_back(byte);
		}

		return bytes;
	}

	uint8_t hexStrToByte(char* hex)
	{
		return (uint8_t)strtol(hex, nullptr, 16);
	}
}
