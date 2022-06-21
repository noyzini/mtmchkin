#ifndef MTMCHKIN_H_EXCEPTION_H
#define MTMCHKIN_H_EXCEPTION_H

#include <iostream>
#include <exception>
/*
* Exception if the file we want to use is not find at the directory
*/
class DeckFileNotFound : public std::runtime_error
{
public:

    DeckFileNotFound() : std::runtime_error("Deck File Error: File not found")
    {
    }
};

/*
* Exception throws error if the number of arg in the file is wrong
*/
class DeckFileInvalidSize : public std::runtime_error
{
public:

    DeckFileInvalidSize() : std::runtime_error("Deck File Error: Deck size is invalid")
    {
    }

};

/*
* Exception throws error if the arg in the file is not according to conventions
*/
class DeckFileFormatError : public std::runtime_error
{
public:

    DeckFileFormatError(int line) : std::runtime_error("Deck File Error: File format error in line " + std::to_string(line))
    {
    }
};


#endif //MTMCHKIN_H_EXCEPTION_H
