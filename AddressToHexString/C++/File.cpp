std::string AddressToHexString(intptr_t address) {
	std::stringstream stringStream;
	
	stringStream << "0x" << std::uppercase << std::hex << address;
	return stringStream.str();
}
