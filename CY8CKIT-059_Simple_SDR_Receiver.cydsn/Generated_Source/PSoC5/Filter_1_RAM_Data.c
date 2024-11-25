#include "Filter_1.h"
#include "Filter_1_PVT.h"

const uint8 CYCODE Filter_1_control[] = 
{
    0x20u, 0x13u, 0x00u, 0x25u, 0x61u, 0x17u, 0x80u, 0x26u,
    0x01u, 0x00u, 0x80u, 0x26u, 0x01u, 0x00u, 0x80u, 0x26u,
    0x01u, 0x00u, 0x80u, 0x26u, 0xE0u, 0x0Eu, 0x80u, 0x26u,
    0xC2u, 0x0Cu, 0x80u, 0x26u, 0x02u, 0x00u, 0x80u, 0x06u,
    0x65u, 0x87u, 0x18u, 0x6Du, 0x64u, 0x09u, 0x18u, 0x3Eu,
    0x00u, 0x00u, 0x80u, 0x26u, 0x03u, 0x20u, 0x80u, 0x26u,
    0x21u, 0x02u, 0x18u, 0x7Fu, 0xE6u, 0x0Eu, 0x80u, 0x26u,
    0xC8u, 0x0Cu, 0x80u, 0x26u, 0x00u, 0x00u, 0x80u, 0x06u,
    0x6Bu, 0x87u, 0x18u, 0x6Du, 0x6Au, 0x09u, 0x18u, 0x3Eu,
    0x00u, 0x00u, 0x80u, 0x26u, 0x01u, 0x20u, 0x80u, 0x26u,
    0x21u, 0x02u, 0x18u, 0x7Fu, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
   };

const uint8 CYCODE Filter_1_data_a[] = 
{
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
   };

const uint8 CYCODE Filter_1_data_b[] = 
{
    0xAAu, 0xFEu, 0xFFu, 0x00u, 0x67u, 0xFEu, 0xFFu, 0x00u,
    0xEBu, 0xFDu, 0xFFu, 0x00u, 0x69u, 0xFDu, 0xFFu, 0x00u,
    0x22u, 0xFDu, 0xFFu, 0x00u, 0x71u, 0xFDu, 0xFFu, 0x00u,
    0xC7u, 0xFEu, 0xFFu, 0x00u, 0xB3u, 0x01u, 0x00u, 0x00u,
    0xE1u, 0x06u, 0x00u, 0x00u, 0x19u, 0x0Fu, 0x00u, 0x00u,
    0x39u, 0x1Bu, 0x00u, 0x00u, 0x30u, 0x2Cu, 0x00u, 0x00u,
    0xF0u, 0x42u, 0x00u, 0x00u, 0x61u, 0x60u, 0x00u, 0x00u,
    0x53u, 0x85u, 0x00u, 0x00u, 0x6Au, 0xB2u, 0x00u, 0x00u,
    0x0Du, 0xE8u, 0x00u, 0x00u, 0x56u, 0x26u, 0x01u, 0x00u,
    0x03u, 0x6Du, 0x01u, 0x00u, 0x6Eu, 0xBBu, 0x01u, 0x00u,
    0x87u, 0x10u, 0x02u, 0x00u, 0xD4u, 0x6Au, 0x02u, 0x00u,
    0x76u, 0xC8u, 0x02u, 0x00u, 0x3Eu, 0x27u, 0x03u, 0x00u,
    0xB8u, 0x84u, 0x03u, 0x00u, 0x48u, 0xDEu, 0x03u, 0x00u,
    0x47u, 0x31u, 0x04u, 0x00u, 0x1Fu, 0x7Bu, 0x04u, 0x00u,
    0x6Fu, 0xB9u, 0x04u, 0x00u, 0x22u, 0xEAu, 0x04u, 0x00u,
    0x91u, 0x0Bu, 0x05u, 0x00u, 0x94u, 0x1Cu, 0x05u, 0x00u,
    0x94u, 0x1Cu, 0x05u, 0x00u, 0x91u, 0x0Bu, 0x05u, 0x00u,
    0x22u, 0xEAu, 0x04u, 0x00u, 0x6Fu, 0xB9u, 0x04u, 0x00u,
    0x1Fu, 0x7Bu, 0x04u, 0x00u, 0x47u, 0x31u, 0x04u, 0x00u,
    0x48u, 0xDEu, 0x03u, 0x00u, 0xB8u, 0x84u, 0x03u, 0x00u,
    0x3Eu, 0x27u, 0x03u, 0x00u, 0x76u, 0xC8u, 0x02u, 0x00u,
    0xD4u, 0x6Au, 0x02u, 0x00u, 0x87u, 0x10u, 0x02u, 0x00u,
    0x6Eu, 0xBBu, 0x01u, 0x00u, 0x03u, 0x6Du, 0x01u, 0x00u,
    0x56u, 0x26u, 0x01u, 0x00u, 0x0Du, 0xE8u, 0x00u, 0x00u,
    0x6Au, 0xB2u, 0x00u, 0x00u, 0x53u, 0x85u, 0x00u, 0x00u,
    0x61u, 0x60u, 0x00u, 0x00u, 0xF0u, 0x42u, 0x00u, 0x00u,
    0x30u, 0x2Cu, 0x00u, 0x00u, 0x39u, 0x1Bu, 0x00u, 0x00u,
    0x19u, 0x0Fu, 0x00u, 0x00u, 0xE1u, 0x06u, 0x00u, 0x00u,
    0xB3u, 0x01u, 0x00u, 0x00u, 0xC7u, 0xFEu, 0xFFu, 0x00u,
    0x71u, 0xFDu, 0xFFu, 0x00u, 0x22u, 0xFDu, 0xFFu, 0x00u,
    0x69u, 0xFDu, 0xFFu, 0x00u, 0xEBu, 0xFDu, 0xFFu, 0x00u,
    0x67u, 0xFEu, 0xFFu, 0x00u, 0xAAu, 0xFEu, 0xFFu, 0x00u,
    0xAAu, 0xFEu, 0xFFu, 0x00u, 0x67u, 0xFEu, 0xFFu, 0x00u,
    0xEBu, 0xFDu, 0xFFu, 0x00u, 0x69u, 0xFDu, 0xFFu, 0x00u,
    0x22u, 0xFDu, 0xFFu, 0x00u, 0x71u, 0xFDu, 0xFFu, 0x00u,
    0xC7u, 0xFEu, 0xFFu, 0x00u, 0xB3u, 0x01u, 0x00u, 0x00u,
    0xE1u, 0x06u, 0x00u, 0x00u, 0x19u, 0x0Fu, 0x00u, 0x00u,
    0x39u, 0x1Bu, 0x00u, 0x00u, 0x30u, 0x2Cu, 0x00u, 0x00u,
    0xF0u, 0x42u, 0x00u, 0x00u, 0x61u, 0x60u, 0x00u, 0x00u,
    0x53u, 0x85u, 0x00u, 0x00u, 0x6Au, 0xB2u, 0x00u, 0x00u,
    0x0Du, 0xE8u, 0x00u, 0x00u, 0x56u, 0x26u, 0x01u, 0x00u,
    0x03u, 0x6Du, 0x01u, 0x00u, 0x6Eu, 0xBBu, 0x01u, 0x00u,
    0x87u, 0x10u, 0x02u, 0x00u, 0xD4u, 0x6Au, 0x02u, 0x00u,
    0x76u, 0xC8u, 0x02u, 0x00u, 0x3Eu, 0x27u, 0x03u, 0x00u,
    0xB8u, 0x84u, 0x03u, 0x00u, 0x48u, 0xDEu, 0x03u, 0x00u,
    0x47u, 0x31u, 0x04u, 0x00u, 0x1Fu, 0x7Bu, 0x04u, 0x00u,
    0x6Fu, 0xB9u, 0x04u, 0x00u, 0x22u, 0xEAu, 0x04u, 0x00u,
    0x91u, 0x0Bu, 0x05u, 0x00u, 0x94u, 0x1Cu, 0x05u, 0x00u,
    0x94u, 0x1Cu, 0x05u, 0x00u, 0x91u, 0x0Bu, 0x05u, 0x00u,
    0x22u, 0xEAu, 0x04u, 0x00u, 0x6Fu, 0xB9u, 0x04u, 0x00u,
    0x1Fu, 0x7Bu, 0x04u, 0x00u, 0x47u, 0x31u, 0x04u, 0x00u,
    0x48u, 0xDEu, 0x03u, 0x00u, 0xB8u, 0x84u, 0x03u, 0x00u,
    0x3Eu, 0x27u, 0x03u, 0x00u, 0x76u, 0xC8u, 0x02u, 0x00u,
    0xD4u, 0x6Au, 0x02u, 0x00u, 0x87u, 0x10u, 0x02u, 0x00u,
    0x6Eu, 0xBBu, 0x01u, 0x00u, 0x03u, 0x6Du, 0x01u, 0x00u,
    0x56u, 0x26u, 0x01u, 0x00u, 0x0Du, 0xE8u, 0x00u, 0x00u,
    0x6Au, 0xB2u, 0x00u, 0x00u, 0x53u, 0x85u, 0x00u, 0x00u,
    0x61u, 0x60u, 0x00u, 0x00u, 0xF0u, 0x42u, 0x00u, 0x00u,
    0x30u, 0x2Cu, 0x00u, 0x00u, 0x39u, 0x1Bu, 0x00u, 0x00u,
    0x19u, 0x0Fu, 0x00u, 0x00u, 0xE1u, 0x06u, 0x00u, 0x00u,
    0xB3u, 0x01u, 0x00u, 0x00u, 0xC7u, 0xFEu, 0xFFu, 0x00u,
    0x71u, 0xFDu, 0xFFu, 0x00u, 0x22u, 0xFDu, 0xFFu, 0x00u,
    0x69u, 0xFDu, 0xFFu, 0x00u, 0xEBu, 0xFDu, 0xFFu, 0x00u,
    0x67u, 0xFEu, 0xFFu, 0x00u, 0xAAu, 0xFEu, 0xFFu, 0x00u,
   };

const uint8 CYCODE Filter_1_acu[] = 
{
    0xBFu, 0x1Fu, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0xFFu, 0x3Fu, 0x00u, 0x00u,
    0x40u, 0x20u, 0x00u, 0x00u, 0x40u, 0x20u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
   };

const uint8 CYCODE Filter_1_cfsm[] = 
{
    0x21u, 0xF8u, 0x05u, 0x01u, 0x44u, 0xF8u, 0x0Bu, 0x40u,
    0x67u, 0xF8u, 0x1Bu, 0x80u, 0x81u, 0xF8u, 0x05u, 0x01u,
    0xA6u, 0xF8u, 0x19u, 0x01u, 0xC2u, 0xF8u, 0x07u, 0x01u,
    0x85u, 0x61u, 0x92u, 0x21u, 0x09u, 0xF9u, 0x29u, 0x01u,
    0x21u, 0xF9u, 0x05u, 0x01u, 0x88u, 0xA2u, 0xA2u, 0x21u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
   };
