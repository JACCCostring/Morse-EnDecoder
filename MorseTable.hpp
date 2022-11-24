/*
This is a class for converting English alphabet from a-z and numbers from 0-9 to morse code
class is marked with Final specifier to avoid inheritance or extension, not need it for now.
Not template usage here because the class is target for an especific case.

g++ with C++17 were used to compile, std::map and std::toupper() as containers
and latter conversion from low case to upper case function were used, all the psible 
constructors and operator are deleted to avoid object copy, since for now a object copy
it's not need it.
*/

#ifndef __MORSE__

#define __MORSE__

#include <map>
#include <string>
#include <cctype> //for std::toupper()

namespace Encode
{
    class MorseEncoder final
    {

            public:
                                            MorseEncoder(); //constructor
            
            bool                            validate(char); //to validate any character exist in container
            const                           std::string getEncoded(char); //to substract morse code

                                            ~MorseEncoder(); //destructor



        //private methods, because of internal calls
            private:

            void                            initialEncode();
            char                            toUpperCase(char);


        /*note: 
        copy, move, assign copy and move copy constuctors and operators
        not need it for now
        */
            MorseEncoder(const MorseEncoder&) = delete;
            MorseEncoder(const MorseEncoder&&) = delete;
            MorseEncoder& operator = (const MorseEncoder&) = delete;
            MorseEncoder& operator = (const MorseEncoder&&) = delete;

//private members

            private:

            std::map<char, std::string>      encoded;
    };
}

#endif