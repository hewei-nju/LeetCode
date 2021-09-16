#include<iostream>
#include <ostream>
namespace Color {
    enum Code {
    FG_BLACK = 30,
    FG_RED = 31,
    FG_GREEN = 32,
    FG_YELLOW = 33,
    FG_BLUE = 34,
    FG_MAGENTA = 35,
    FG_CYAN = 36,
    FG_WHITE = 37,

    BG_BLACK = 40,
    BG_RED = 41,
    BG_GREEN = 42,
    BG_YELLOW = 43,
    BG_BLUE = 44,
    BG_MAGENTA = 45,
    BG_CYAN = 46,
    BG_WHITE = 47,

    RESET = 0,
    BOLD = 1,
    UNDERLINE = 4,
    INVERSE = 7,
    BOLD_OFF = 21,
    UNDERLINE_OFF = 24,
    INVERSE_OFF = 27,

};
class Modifier {
    Code code;

public:
    Modifier(Code pCode) : code(pCode) { }
    friend std::ostream& operator<<(std::ostream& os, const Modifier& mod) {
        return os << "\033[" << mod.code << "m";
    }
};
}

int main()
{
    Color::Modifier red(Color::FG_RED);
    Color::Modifier reset(Color::RESET);
    std::cout << red << "hello world" << reset << '\n';
}