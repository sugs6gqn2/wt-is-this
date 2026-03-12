// Lexer.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

class Token {
public:
    enum class Type {
        IDENTIFIER,
        NUMBER,
        STRING,
        SYMBOL,
        END_OF_FILE,
        UNKNOWN
    };

    Token(Type type, const std::string &value) : type(type), value(value) {}

    Type type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string &src) : input(src), index(0) {}

    Token nextToken() {
        while (index < input.size() && std::isspace(input[index])) {
            index++;
        }

        if (index == input.size()) return Token(Token::Type::END_OF_FILE, "");

        char current = input[index];
        if (std::isalpha(current)) {
            return identifier();
        } else if (std::isdigit(current)) {
            return number();
        } else if (current == '"') {
            return string();
        } else {
            index++;
            return Token(Token::Type::SYMBOL, std::string(1, current));
        }
    }

private:
    std::string input;
    size_t index;

    Token identifier() {
        size_t start = index;
        while (index < input.size() && (std::isalnum(input[index]) || input[index] == '_')) {
            index++;
        }
        return Token(Token::Type::IDENTIFIER, input.substr(start, index - start));
    }

    Token number() {
        size_t start = index;
        while (index < input.size() && std::isdigit(input[index])) {
            index++;
        }
        return Token(Token::Type::NUMBER, input.substr(start, index - start));
    }

    Token string() {
        index++; // skip opening quotes
        size_t start = index;
        while (index < input.size() && input[index] != '"') {
            index++;
        }
        index++; // skip closing quotes
        return Token(Token::Type::STRING, input.substr(start, index - start - 1));
    }
};

// Example usage:
int main() {
    std::string source = "int x = 10; \n string message = \"Hello, World!\";";
    Lexer lexer(source);
    Token token;
    do {
        token = lexer.nextToken();
        std::cout << "Token: " << token.value << " Type: " << static_cast<int>(token.type) << '\n';
    } while (token.type != Token::Type::END_OF_FILE);
    return 0;
}