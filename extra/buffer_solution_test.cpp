#include <iostream>
#include <string>

int main(void)
{

    u_int8_t MCDB = 0b00100001;
    
    u_int8_t MCDBS = 0b00000000;



    std::cout << "MCDB at start: " << std::to_string(MCDB) << "\n";
    std::cout << "MCDBS at start: " << std::to_string(MCDBS) << "\n";

    
    // Retrieve data size

    MCDBS = MCDB; // Copy the buffer
    MCDBS = MCDBS >> 5; // Shift out the data bits, placing data size bits at the LSB position

    std::cout << "Shift >> 5 MCDBS: " << std::to_string(MCDBS) << "\n";


    // Set bit at next loc for '-'
    MCDB = MCDB | (1 << MCDBS);

    // unset bit at next loc for '.'
    MCDB = MCDB & ~(1 << MCDBS);

    MCDB += 0b00100000; // Data sec starts at bit 5 (32); this line is incrementing data section by 1



    std::cout << "MCDB at end: " << std::to_string(MCDB) << "\n";





    return 0;
}