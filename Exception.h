
#ifndef MTMCHKIN_H_EXCEPTION_H
#define MTMCHKIN_H_EXCEPTION_H

#include <iostream>
#include <exception>

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
