#ifndef MTMCHKIN_H_EXCEPTION_H
#define MTMCHKIN_H_EXCEPTION_H

#include <iostream>
#include <exception>
/*
* Exception if the file we want to use is not find at the directory
*/
class DeckFileNotFound : public std::exception
{
public:

    DeckFileNotFound()
    {
    }

    const char * what() const noexcept override
    {
        return "Deck File Error: File not found";
    };
};

/*
* Exception throws error if the number of arg in the file is wrong
*/
class DeckFileInvalidSize : public std::exception
{
public:

    DeckFileInvalidSize()
    {
    }

    const char * what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    };
};

/*
* Exception throws error if the arg in the file is not according to conventions
*/
class DeckFileFormatError : public std::exception
{
    int m_lineError;
    std::string m_error;
public:

    DeckFileFormatError(int line) : m_lineError(line) ,
    m_error("Deck File Error: File format error in line " + std::to_string(m_lineError))
    {
    }

    const char * what() const noexcept override
    {
        return m_error.c_str();
    };
};


#endif //MTMCHKIN_H_EXCEPTION_H
