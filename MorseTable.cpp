#include "MorseTable.hpp"

Encode::MorseEncoder::MorseEncoder(){ initialEncode(); } //calling initialEncode at instantiation
                                                                    //to load data just once
bool Encode::MorseEncoder::validate(char character)
{
    //note: when comparing, character it's turned to upper case
    //just in case, to take all posible cases
    for(const auto &c: encoded) 
        if(c.first == toUpperCase(character)) return true;

    return false;
}

bool Encode::MorseEncoder::validateMorse(std::string morse)
{
    for(const auto &c: decoded)
         if(c.first == morse) return true;

   return false;
}

const std::string Encode::MorseEncoder::getEncoded(char character)
{   //turning character to upper case before returning the encoded
    return encoded[toUpperCase(character)];
}

char Encode::MorseEncoder::getDecoded(std::string letter)
{   //turning character to upper case before returning the encoded
    return decoded[letter];
}

void Encode::MorseEncoder::initialEncode()
{

        const std::string lettersMorseCharacter[] = 
        {
                ".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
                "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                "..-", "...-", ".--", "-..-", "-.--", "--.."
        };

        const std::string numericMorseCharacter[] = 
        {
                "-----", ".----", "..---", "...--",
                "....-", ".....", "-....", "--...", "---..", "----."
        };
        


    int indexAlph = 0;
    int indexNumber = 0;

    for(char character = 'A'; character < 'Z' + 1; character++){
        //when character reaches Z latter then add numbers from 0-9 to the std::map
        if(character == 'Z')
        {
            for(char i = '0'; i < '9' + 1; i++){
                encoded[i] = numericMorseCharacter[indexNumber];
                decoded[ numericMorseCharacter[indexNumber] ] = i;
                indexNumber++;
            }
        }
        encoded[character] = lettersMorseCharacter[indexAlph];
        decoded[ lettersMorseCharacter[indexAlph] ] = character;
        indexAlph++;
    }
}

char Encode::MorseEncoder::toUpperCase(char character)
{   //casting to unsigned character avoiding signed characters
    char upper = std::toupper( static_cast<unsigned char>(character) );
    return static_cast<char>(upper);
}

Encode::MorseEncoder::~MorseEncoder(){ encoded.clear(); decoded.clear(); /*destructor*/}
