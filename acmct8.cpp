#include <iostream>
#include <string>
#include <boost/spirit/include/qi.hpp>

#define USE_SIMPLE_CODE

namespace qi = boost::spirit::qi;

/* Example for EBNF:
low3 = low_case_letter , low_case_letter , low_case_letter.
low_case_letter = 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm’  | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z’.
*/
template <typename Iterator>
struct grammar_simple : qi::grammar<Iterator>{
    grammar_simple() : grammar_simple::base_type(low3){
        low3 = low_case_letter >> low_case_letter >> low_case_letter;
        low_case_letter = a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z;
        a = 'a';
        b = 'b';
        c = 'c';
        d = 'd';
        e = 'e';
        f = 'f';
        g = 'g';
        h = 'h';
        i = 'i';
        j = 'j';
        k = 'k';
        l = 'l';
        m = 'm';
        n = 'n';
        o =	'o';
        p =	'p';
        q =	'q';
        r =	'r';
        s =	's';
        t =	't';
        u =	'u';
        v =	'v';
        w =	'w';
        x =	'x';
        y =	'y';
        z =	'z';
    }

    qi::rule<Iterator> low3, low_case_letter, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
};

#ifdef USE_SIMPLE_CODE
int main(){
	std::string text = "qtv";

    typedef std::string     str_t;
    typedef str_t::iterator str_t_it;

    grammar_simple<str_t_it> gs;

    str_t_it begin = text.begin(), end = text.end();

    bool success = qi::parse(begin, end, gs);
    std::cout << std::boolalpha << success;

    if(!success || begin != end){
        std::cout << "\nStopped at: \"" << str_t(begin, end) << "\"\n";
	}
}

#else
int main(){
    std::cout << "Welcome to the low3 parser!\n\n";
    std::cout << "Type an low3 or [q or Q] to quit\n\n";

    typedef std::string     str_t;
    typedef str_t::iterator str_t_it;

    str_t low3;

    grammar_simple<str_t_it> gs;

    while(true){
        std::getline(std::cin, low3);
        if(low3 == "q" || low3 == "Q") break;
        str_t_it begin = low3.begin(), end = low3.end();

        bool success = qi::parse(begin, end, gs);

        std::cout << "---------------------\n";
        if(success && begin == end)
                std::cout << "Parsing succeeded\n";
        else
                std::cout << "Parsing failed\nstopped at: \""
                          << str_t(begin, end) << "\"\n";
        std::cout << "---------------------\n";
    }
}
#endif