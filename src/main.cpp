// A simple program designed to determine if a passed file is a binary file for x32 or x64.

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Please pass the path to the binary you wish to check." << std::endl;
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Could not open file." << std::endl;
        return 1;
    }

    // Turn the whole file into a c string.
    // First convert to std string
    std::string file_string;
    file.seekg(0, std::ios::end);
    file_string.reserve(file.tellg());
    file.seekg(0, std::ios::beg);
    file_string.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Then convert to c string
    char* file_c_string = new char[file_string.size() + 1];
    strcpy(file_c_string, file_string.c_str());
    
    // Get character at 0x3C, which informs us of the offset of the PE header.
    char* pe_header_offset = file_c_string + 0x3C;
    int pe_header_offset_int = *(int*)pe_header_offset;

    // Get the PE header, which is at the offset of the PE header.
    char* pe_header = file_c_string + pe_header_offset_int;

    // First byte is P, second byte is E, third and fourth bytes are null, and fifth and sixth byte make up a 2 byte hex value representing machine type.
    // Check the machine type to determine if the file is x32 or x64.
    char* machine_type_start = pe_header + 4;

    // Use some bitwise magic to get the machine type.
    unsigned short machine_type;
    machine_type = machine_type_start[1];
    machine_type <<= 8;
    machine_type |= machine_type_start[0];

    if (machine_type == 0x014C)
    {
        std::cout << "The selected binary is 32 bit." << std::endl;
    }
    else if (machine_type == 0x8664)
    {
        std::cout << "The selected binary is 64 bit." << std::endl;
    }
    else
    {
        std::cout << "Could not determine if the binary is 32 bit or 64 bit." << std::endl
                  << "This could mean it was compiled for another platform, or it is not reognized." << std::endl;
    }

    // print out machine type as hex
    std::cout << "Machine type: " << std::hex << machine_type << std::endl;
}