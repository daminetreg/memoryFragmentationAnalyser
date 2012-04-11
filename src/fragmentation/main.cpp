#include <fragmentation/AnalysisReader.hpp>
#include <fragmentation/AnalysisWriter.hpp>
#include <fragmentation/MemoryOperationStore.hpp>

#include <iostream>
#include <string>

std::string byteArrayToHexString(const char in[], unsigned int inLength) {
    char ch = 0x00;
    unsigned int i = 0; 

    if (in == NULL || inLength <= 0)
        return NULL;

    const char pseudo[] = {'0', '1', '2',
    '3', '4', '5', '6', '7', '8',
    '9', 'A', 'B', 'C', 'D', 'E',
    'F'};

    std::string out;
    while (i < inLength) {

        ch = (char) (in[i] & 0xF0); // Strip off high nibble
        ch = (char) (ch >> 4); // shift the bits down
        ch = (char) (ch & 0x0F); // must do this is high order bit is on!

        out.push_back(pseudo[static_cast<int>(ch)]); // convert the nibble to a String Character

        ch = (char) (in[i] & 0x0F); // Strip off low nibble 
        out.push_back(pseudo[static_cast<int>(ch)]); // convert the nibble to a String Character
        i++;
    }

    return out;
} 


using namespace fragmentation;

int main()
{
    std::string str;
    FreeOperation freeOperation(0x115f);

    std::cout << freeOperation.address << std::endl;
    
    std::back_insert_iterator<std::string> sink(str);
    writeFreeOperation(sink, freeOperation);

    std::cout << "My serialized free operation (" << str << ") : " << byteArrayToHexString(str.data(), str.length()) << std::endl;

    MemoryOperationStore memoryOperationStore;
    parseFreeOperation(str.begin(), str.end(), memoryOperationStore);

    while (getline(std::cin, str))
    {
        if (str.empty() || str[0] == 'q' || str[0] == 'Q')
            break;

        str += '\n'; // Add the newline, because getline doesn't include it

        if (fragmentation::parseFreeOperation(str.begin(), str.end(), memoryOperationStore))
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing succeeded\n";
            std::cout << "\n-------------------------\n";
        }
        else
        {
            std::cout << "-------------------------\n";
            std::cout << "Parsing failed\n";
            std::cout << "-------------------------\n";
        }
    }

    std::cout << "Bye... :-) \n\n";
    return 0;
}

