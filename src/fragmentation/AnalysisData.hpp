#ifndef FRAGMENTATION_ANALYSERDATA_HPP
#define FRAGMENTATION_ANALYSERDATA_HPP

#include <boost/cstdint.hpp>

namespace fragmentation {
    
    /**
     * \brief A MemoryOperation base structure, it only contains an adress because any Memory operation relates to some adress.
     */
    typedef struct MemoryOperation {
        MemoryOperation(boost::uint32_t address) : address(address) {}
        MemoryOperation() : address(0) {}
        boost::uint32_t address;

    } MemoryOperation;

    /**
     * \brief Stores the Free operations which only frees a preallocated address. How much is freed is known from the previous allocation operation.
     */
    typedef struct FreeOperation : public MemoryOperation {
        FreeOperation(boost::uint32_t address) : MemoryOperation(address) {}
        FreeOperation() : MemoryOperation(0) {}
    } FreeOperation;

    /**
     * \brief Stores the Malloc operations at the given address of the given size.
     */
    typedef struct MallocOperation : public MemoryOperation {
        MallocOperation(boost::uint32_t address, boost::uint32_t allocSize) : MemoryOperation(address), allocSize(allocSize) {}
        MallocOperation() : MemoryOperation(), allocSize(0) {}
        boost::uint32_t address;
        boost::uint32_t allocSize;
    } MallocOperation;

    /**
     * \brief Stores the Realloc operations at the given address of the given size.
     * While not having more fields than fragmentation::MallocOperation it is of a different type, so that we can show how some has grown.
     */
    typedef struct ReallocOperation : public MallocOperation {
        ReallocOperation(boost::uint32_t address, boost::uint32_t allocSize) : MallocOperation(address, allocSize) {}
        ReallocOperation() : MallocOperation(0, 0) {}
    } ReallocOperation;


}

#endif
