//
//  M88.hpp
//  CyberMatrix
//
//  Created by Six Pack Abs on 5/29/26.
//

#ifndef M88_hpp
#define M88_hpp

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <cstring>

class M88 {
public:
    M88();
    
    void                                        Reset();
    void                                        Print() const;
    

    std::uint8_t                                mData[64];

    // ignores bytes 1 and 2, uses last byte to unroll
    void                                        Dispatch(std::uint8_t *pOperationData,
                                                         std::size_t pOperationIndex,
                                                         std::uint8_t *pSource,
                                                         std::size_t pSourceIndex,
                                                         std::uint8_t *pDestination,
                                                         std::size_t pDestinationIndex,
                                                         std::uint8_t pUnrollDomainWord,
                                                         std::uint8_t pArgADomainWord,
                                                         std::uint8_t pArgBDomainWord,
                                                         std::uint8_t pArgCDomainWord,
                                                         std::uint8_t pArgDDomainWord);
    
    void                                        Dispatch(std::uint8_t *pOperationData,
                                                         std::size_t pOperationIndex,
                                                         std::uint8_t *pSource,
                                                         std::size_t pSourceIndex,
                                                         std::uint8_t *pDestination,
                                                         std::size_t pDestinationIndex);

    
};

#endif /* M88_hpp */
