//
//  M88.cpp
//  CyberMatrix
//
//  Created by Six Pack Abs on 5/29/26.
//

#include "M88.hpp"
#include "M88QuadSelectsA.hpp"
#include "M88QuadSelectsB.hpp"
#include "M88QuadSelectsC.hpp"
#include "M88QuadSelectsD.hpp"
#include <cstdio>

M88::M88() {
    Reset();
}

void M88::Reset() {
    for (std::size_t i = 0; i < 64U; i++) {
        mData[i] = static_cast<std::uint8_t>(i);
    }
}

void M88::Print() const {
    
    for (std::size_t y = 0; y < 8U; y++) {
        for (std::size_t x = 0; x < 8U; x++) {
            const std::size_t aIndex = y * 8U + x;
            std::printf("%3u ", static_cast<unsigned int>(mData[aIndex]));
        }
        
        std::printf("\n");
    }
    
    std::printf("\n");
}

void M88::Dispatch(std::uint8_t *pOperationData,
                   std::size_t pOperationIndex,
                   std::uint8_t *pSource,
                   std::size_t pSourceIndex,
                   std::uint8_t *pDestination,
                   std::size_t pDestinationIndex) {
    
    std::uint8_t *aSource = pSource + pSourceIndex;
    std::uint8_t *aDestination = pDestination + pDestinationIndex;
    memcpy(pDestination, aSource, 64U);
    
}

void M88::Dispatch(std::uint8_t *pOperationData,
                   std::size_t pOperationIndex,
                   std::uint8_t *pSource,
                   std::size_t pSourceIndex,
                   std::uint8_t *pDestination,
                   std::size_t pDestinationIndex,
                   std::uint8_t pUnrollDomainWord,
                   std::uint8_t pArgADomainWord,
                   std::uint8_t pArgBDomainWord,
                   std::uint8_t pArgCDomainWord,
                   std::uint8_t pArgDDomainWord) {
    
    std::uint8_t *aSource = pSource + pSourceIndex;
    std::uint8_t *aDestination = pDestination + pDestinationIndex;
    memcpy(pDestination, aSource, 64U);
    
}

