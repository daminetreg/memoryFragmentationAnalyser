#include <fragmentation/MemoryOperationStore.hpp>

#include <fragmentation/AnalysisData.hpp>

using namespace fragmentation;

MemoryOperationStore::MemoryOperationStore() {
    boost::shared_ptr<boost::container::list<const MemoryOperation> > memoryOperations(new boost::container::list<const MemoryOperation>());

    m_memoryOperations = memoryOperations;
}

MemoryOperationStore::~MemoryOperationStore() {
}

void MemoryOperationStore::put(const MemoryOperation memoryOperation) {
    m_memoryOperations.push_back(memoryOperation);
}
