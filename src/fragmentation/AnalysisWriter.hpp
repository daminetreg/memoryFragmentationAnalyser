#ifndef FRAGMENTATION_ANALYSISWRITER_HPP
#define FRAGMENTATION_ANALYSISWRITER_HPP

#include <boost/spirit/include/karma.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <fragmentation/AnalysisData.hpp>

namespace fragmentation {

    /**
     * \brief This writes the given freeOperation on the given sink
     * \param sink This can be any OutputIterator e.g. std::back_insert_iterator<std::string> sink(outputString); 
     * \param freeOperation
     */
    template <typename OutputIterator>
    bool writeFreeOperation(OutputIterator sink, const FreeOperation& freeOperation) {
        using boost::spirit::karma::dword;
        using boost::spirit::karma::_1;
        using boost::spirit::karma::generate;

        return generate(sink,
            (
                'f' << dword[_1 = freeOperation.address] << '\n'
            )
        );
    } 
}

#endif
