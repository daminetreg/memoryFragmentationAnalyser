#ifndef FRAGMENTATION_ANALYSISREADER_HPP
#define FRAGMENTATION_ANALYSISREADER_HPP

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/qi_binary.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <fragmentation/AnalysisData.hpp>
#include <fragmentation/MemoryOperationStore.hpp>

#include <iostream>

namespace fragmentation {

    /**
     * \brief This function can be used to parse a free operation entry and stores it in a MemoryOperation storage.
     * \param first Begin of string on which to iterate
     * \param last End of string on which to iterate
     */
    template <typename Iterator>
    bool parseFreeOperation(Iterator first, Iterator last, MemoryOperationStore &store) {
        using boost::spirit::qi::dword;
        using boost::spirit::qi::_1;
        using boost::spirit::qi::parse;
        using boost::phoenix::ref;

        FreeOperation freeOperation; // Store it in central operation store

        bool success = parse(first, last,
                (
                   'f' >> dword[ref(freeOperation.address) = _1] >> '\n' 
                ));

        success = ( (success) && (first == last) );
        
        if (success) {
            store.put(freeOperation);
        }

        return success;
    }


    /**
     * \brief This function can be used to parse a malloc operation entry and stores it in a MemoryOperation storage. 
     * \param first Begin of string on which to iterate
     * \param last End of string on which to iterate
     */
    template <typename Iterator>
    bool parseMallocOperation(Iterator first, Iterator last, MemoryOperationStore &store) {
        using boost::spirit::qi::dword;
        using boost::spirit::qi::_1;
        using boost::spirit::qi::parse;
        using boost::phoenix::ref;

        MallocOperation mallocOperation; // Store it in central operation store

        bool success = parse(first, last,
                (
                   'm' >> dword[ref(mallocOperation.address) = _1] >> ' ' >> dword[ref(mallocOperation.allocSize) = _1] >> '\n' 
                ));
                
        success = ( (success) && (first == last) );
        
        if (success) {
            store.put(mallocOperation);
        }

        return success;
 
    }

    /**
     * \brief This function can be used to parse a realloc operation entry and stores it in a MemoryOperation storage. 
     * \param first Begin of string on which to iterate
     * \param last End of string on which to iterate
     */
    template <typename Iterator>
    bool parseReallocOperation(Iterator first, Iterator last, MemoryOperationStore &store) {
        using boost::spirit::qi::dword;
        using boost::spirit::qi::_1;
        using boost::spirit::qi::parse;
        using boost::phoenix::ref;

        ReallocOperation reallocOperation; // Store it in central operation store

        bool success = parse(first, last,
                (
                   'r' >> dword[ref(reallocOperation.address) = _1] >> ' ' >> dword[ref(reallocOperation.allocSize) = _1] >> '\n' 
                ));
                
        success = ( (success) && (first == last) );
        
        if (success) {
            store.put(reallocOperation);
        }

        return success;
 
    }
    
}
#endif
