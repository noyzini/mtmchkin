
#ifndef MTMCHKIN_H_EXCEPTION_H
#define MTMCHKIN_H_EXCEPTION_H

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
public:

    DeckFileFormatError(int line) : m_lineError(line)
    {
    }

    const char * what() const noexcept override
    {
        std::string s = "Deck File Error: File format error in line " + std::to_string(m_lineError);
        return s.c_str();
    };
};


#endif //MTMCHKIN_H_EXCEPTION_H
