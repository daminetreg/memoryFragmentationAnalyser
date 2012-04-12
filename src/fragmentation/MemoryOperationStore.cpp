#include <fragmentation/MemoryOperationStore.hpp>


using namespace fragmentation;

MemoryOperationStore::MemoryOperationStore() {
    boost::shared_ptr<boost::container::list<MemoryOperation> > memoryOperations(new boost::container::list<MemoryOperation>());

    m_memoryOperations = memoryOperations;
}

MemoryOperationStore::~MemoryOperationStore() {
}

void MemoryOperationStore::put(const MemoryOperation memoryOperation) {
    m_memoryOperations->push_back(memoryOperation);
}
