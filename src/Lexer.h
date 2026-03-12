#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

// Token types
enum class TokenType {
    IDENTIFIER,
    KEYWORD,
    SYMBOL,
    NUMBER,
    STRING,
    ARABIC,
    CHINESE,
    EGYPTIAN,
    EOF
};

// Token structure
struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;
};

class Lexer {
public:
    Lexer(const std::string& src);
    std::vector<Token> tokenize();
private:
    void nextChar();
    void skipWhitespace();
    Token lexIdentifier();
    Token lexNumber();
    Token lexString();
    Token lexSymbol();
    Token lexArabic();
    Token lexChinese();
    Token lexEgyptian();
    std::string source;
    int position;
    int line;
    int column;
};

#endif // LEXER_H
