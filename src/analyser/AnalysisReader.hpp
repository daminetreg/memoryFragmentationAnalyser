#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/qi_binary.hpp>

#include <iostream>
#include <string>

namespace fragmentation {
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    struct FreeOperation {
        boost::uint32_t address;
    }

    template <typename Iterator>
    bool parseFreeOperation(Iterator first, Iterator last) {
        using boost::spirit::qi::dword; 
        using boost::spirit::qi::_1;
        using boost::spirit::qi::parse;
        using boost::phoenix::ref;

        FreeOperation freeOperation; // Store it in central operation store

        bool success = parse(first, last,
                (
                   'f' >> dword[ref(freeOperation.address) = _1] >> '\n' 
                ));
                
        return ( (success) && (first == last) );
    }

    
}
