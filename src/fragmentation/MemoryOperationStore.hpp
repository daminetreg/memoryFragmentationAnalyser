#ifndef FRAGMENTATION_MEMORYOPERATIONSTORE_HPP
#define FRAGMENTATION_MEMORYOPERATIONSTORE_HPP

#include <boost/shared_ptr.hpp>
#include <boost/container/list.hpp>

#include <fragmentation/AnalysisData.hpp>

namespace fragmentation {

    /**
     * \brief The MemoryOperationStore simply contains the different memory operations which occured in the different application threads.
     * 
     * \author daminetreg (damien.buhl@lecbna.org)
     */
    class MemoryOperationStore {
        public:
            MemoryOperationStore();
            virtual ~MemoryOperationStore();
            
            /**
             * \brief This can be used to store operations in the MemoryOperationStore
             */
            void put(const MemoryOperation memoryOperation);

            /**
             * \sa m_memoryOperations
             */
            boost::shared_ptr<boost::container::list<MemoryOperation> > memoryOperations() const {
                return m_memoryOperations;
            }

        private:

            /**
             * \brief Memory Operations which occured in the watched application
             */
            boost::shared_ptr<boost::container::list<MemoryOperation> > m_memoryOperations;
    };
}

#endif
