#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_1_ChannelAFirCoefficients

/* Number of FIR filter taps are: 64 */

const uint8 CYCODE Filter_1_ChannelAFirCoefficients[Filter_1_FIR_A_SIZE] = 
{
 0xAAu, 0xFEu, 0xFFu, 0x00u, /* Tap(0), -4.07695770263672E-05 */

 0x67u, 0xFEu, 0xFFu, 0x00u, /* Tap(1), -4.87565994262695E-05 */

 0xEBu, 0xFDu, 0xFFu, 0x00u, /* Tap(2), -6.35385513305664E-05 */

 0x69u, 0xFDu, 0xFFu, 0x00u, /* Tap(3), -7.9035758972168E-05 */

 0x22u, 0xFDu, 0xFFu, 0x00u, /* Tap(4), -8.74996185302734E-05 */

 0x71u, 0xFDu, 0xFFu, 0x00u, /* Tap(5), -7.80820846557617E-05 */

 0xC7u, 0xFEu, 0xFFu, 0x00u, /* Tap(6), -3.73125076293945E-05 */

 0xB3u, 0x01u, 0x00u, 0x00u, /* Tap(7), 5.18560409545898E-05 */

 0xE1u, 0x06u, 0x00u, 0x00u, /* Tap(8), 0.000209927558898926 */

 0x19u, 0x0Fu, 0x00u, 0x00u, /* Tap(9), 0.00046074390411377 */

 0x39u, 0x1Bu, 0x00u, 0x00u, /* Tap(10), 0.000830769538879395 */

 0x30u, 0x2Cu, 0x00u, 0x00u, /* Tap(11), 0.00134849548339844 */

 0xF0u, 0x42u, 0x00u, 0x00u, /* Tap(12), 0.00204277038574219 */

 0x61u, 0x60u, 0x00u, 0x00u, /* Tap(13), 0.00294125080108643 */

 0x53u, 0x85u, 0x00u, 0x00u, /* Tap(14), 0.00406873226165771 */

 0x6Au, 0xB2u, 0x00u, 0x00u, /* Tap(15), 0.00544476509094238 */

 0x0Du, 0xE8u, 0x00u, 0x00u, /* Tap(16), 0.00708162784576416 */

 0x56u, 0x26u, 0x01u, 0x00u, /* Tap(17), 0.00898241996765137 */

 0x03u, 0x6Du, 0x01u, 0x00u, /* Tap(18), 0.0111392736434937 */

 0x6Eu, 0xBBu, 0x01u, 0x00u, /* Tap(19), 0.0135324001312256 */

 0x87u, 0x10u, 0x02u, 0x00u, /* Tap(20), 0.0161293745040894 */

 0xD4u, 0x6Au, 0x02u, 0x00u, /* Tap(21), 0.0188851356506348 */

 0x76u, 0xC8u, 0x02u, 0x00u, /* Tap(22), 0.021742582321167 */

 0x3Eu, 0x27u, 0x03u, 0x00u, /* Tap(23), 0.0246350765228271 */

 0xB8u, 0x84u, 0x03u, 0x00u, /* Tap(24), 0.0274877548217773 */

 0x48u, 0xDEu, 0x03u, 0x00u, /* Tap(25), 0.0302209854125977 */

 0x47u, 0x31u, 0x04u, 0x00u, /* Tap(26), 0.0327538251876831 */

 0x1Fu, 0x7Bu, 0x04u, 0x00u, /* Tap(27), 0.0350073575973511 */

 0x6Fu, 0xB9u, 0x04u, 0x00u, /* Tap(28), 0.0369089841842651 */

 0x22u, 0xEAu, 0x04u, 0x00u, /* Tap(29), 0.0383951663970947 */

 0x91u, 0x0Bu, 0x05u, 0x00u, /* Tap(30), 0.0394154787063599 */

 0x94u, 0x1Cu, 0x05u, 0x00u, /* Tap(31), 0.0399346351623535 */

 0x94u, 0x1Cu, 0x05u, 0x00u, /* Tap(32), 0.0399346351623535 */

 0x91u, 0x0Bu, 0x05u, 0x00u, /* Tap(33), 0.0394154787063599 */

 0x22u, 0xEAu, 0x04u, 0x00u, /* Tap(34), 0.0383951663970947 */

 0x6Fu, 0xB9u, 0x04u, 0x00u, /* Tap(35), 0.0369089841842651 */

 0x1Fu, 0x7Bu, 0x04u, 0x00u, /* Tap(36), 0.0350073575973511 */

 0x47u, 0x31u, 0x04u, 0x00u, /* Tap(37), 0.0327538251876831 */

 0x48u, 0xDEu, 0x03u, 0x00u, /* Tap(38), 0.0302209854125977 */

 0xB8u, 0x84u, 0x03u, 0x00u, /* Tap(39), 0.0274877548217773 */

 0x3Eu, 0x27u, 0x03u, 0x00u, /* Tap(40), 0.0246350765228271 */

 0x76u, 0xC8u, 0x02u, 0x00u, /* Tap(41), 0.021742582321167 */

 0xD4u, 0x6Au, 0x02u, 0x00u, /* Tap(42), 0.0188851356506348 */

 0x87u, 0x10u, 0x02u, 0x00u, /* Tap(43), 0.0161293745040894 */

 0x6Eu, 0xBBu, 0x01u, 0x00u, /* Tap(44), 0.0135324001312256 */

 0x03u, 0x6Du, 0x01u, 0x00u, /* Tap(45), 0.0111392736434937 */

 0x56u, 0x26u, 0x01u, 0x00u, /* Tap(46), 0.00898241996765137 */

 0x0Du, 0xE8u, 0x00u, 0x00u, /* Tap(47), 0.00708162784576416 */

 0x6Au, 0xB2u, 0x00u, 0x00u, /* Tap(48), 0.00544476509094238 */

 0x53u, 0x85u, 0x00u, 0x00u, /* Tap(49), 0.00406873226165771 */

 0x61u, 0x60u, 0x00u, 0x00u, /* Tap(50), 0.00294125080108643 */

 0xF0u, 0x42u, 0x00u, 0x00u, /* Tap(51), 0.00204277038574219 */

 0x30u, 0x2Cu, 0x00u, 0x00u, /* Tap(52), 0.00134849548339844 */

 0x39u, 0x1Bu, 0x00u, 0x00u, /* Tap(53), 0.000830769538879395 */

 0x19u, 0x0Fu, 0x00u, 0x00u, /* Tap(54), 0.00046074390411377 */

 0xE1u, 0x06u, 0x00u, 0x00u, /* Tap(55), 0.000209927558898926 */

 0xB3u, 0x01u, 0x00u, 0x00u, /* Tap(56), 5.18560409545898E-05 */

 0xC7u, 0xFEu, 0xFFu, 0x00u, /* Tap(57), -3.73125076293945E-05 */

 0x71u, 0xFDu, 0xFFu, 0x00u, /* Tap(58), -7.80820846557617E-05 */

 0x22u, 0xFDu, 0xFFu, 0x00u, /* Tap(59), -8.74996185302734E-05 */

 0x69u, 0xFDu, 0xFFu, 0x00u, /* Tap(60), -7.9035758972168E-05 */

 0xEBu, 0xFDu, 0xFFu, 0x00u, /* Tap(61), -6.35385513305664E-05 */

 0x67u, 0xFEu, 0xFFu, 0x00u, /* Tap(62), -4.87565994262695E-05 */

 0xAAu, 0xFEu, 0xFFu, 0x00u, /* Tap(63), -4.07695770263672E-05 */
};


/*******************************************************************************
* ChannelB filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelBFirCoefficients Filter_1_ChannelBFirCoefficients

/* Number of FIR filter taps are: 64 */

const uint8 CYCODE Filter_1_ChannelBFirCoefficients[Filter_1_FIR_B_SIZE] = 
{
 0xAAu, 0xFEu, 0xFFu, 0x00u, /* Tap(0), -4.07695770263672E-05 */

 0x67u, 0xFEu, 0xFFu, 0x00u, /* Tap(1), -4.87565994262695E-05 */

 0xEBu, 0xFDu, 0xFFu, 0x00u, /* Tap(2), -6.35385513305664E-05 */

 0x69u, 0xFDu, 0xFFu, 0x00u, /* Tap(3), -7.9035758972168E-05 */

 0x22u, 0xFDu, 0xFFu, 0x00u, /* Tap(4), -8.74996185302734E-05 */

 0x71u, 0xFDu, 0xFFu, 0x00u, /* Tap(5), -7.80820846557617E-05 */

 0xC7u, 0xFEu, 0xFFu, 0x00u, /* Tap(6), -3.73125076293945E-05 */

 0xB3u, 0x01u, 0x00u, 0x00u, /* Tap(7), 5.18560409545898E-05 */

 0xE1u, 0x06u, 0x00u, 0x00u, /* Tap(8), 0.000209927558898926 */

 0x19u, 0x0Fu, 0x00u, 0x00u, /* Tap(9), 0.00046074390411377 */

 0x39u, 0x1Bu, 0x00u, 0x00u, /* Tap(10), 0.000830769538879395 */

 0x30u, 0x2Cu, 0x00u, 0x00u, /* Tap(11), 0.00134849548339844 */

 0xF0u, 0x42u, 0x00u, 0x00u, /* Tap(12), 0.00204277038574219 */

 0x61u, 0x60u, 0x00u, 0x00u, /* Tap(13), 0.00294125080108643 */

 0x53u, 0x85u, 0x00u, 0x00u, /* Tap(14), 0.00406873226165771 */

 0x6Au, 0xB2u, 0x00u, 0x00u, /* Tap(15), 0.00544476509094238 */

 0x0Du, 0xE8u, 0x00u, 0x00u, /* Tap(16), 0.00708162784576416 */

 0x56u, 0x26u, 0x01u, 0x00u, /* Tap(17), 0.00898241996765137 */

 0x03u, 0x6Du, 0x01u, 0x00u, /* Tap(18), 0.0111392736434937 */

 0x6Eu, 0xBBu, 0x01u, 0x00u, /* Tap(19), 0.0135324001312256 */

 0x87u, 0x10u, 0x02u, 0x00u, /* Tap(20), 0.0161293745040894 */

 0xD4u, 0x6Au, 0x02u, 0x00u, /* Tap(21), 0.0188851356506348 */

 0x76u, 0xC8u, 0x02u, 0x00u, /* Tap(22), 0.021742582321167 */

 0x3Eu, 0x27u, 0x03u, 0x00u, /* Tap(23), 0.0246350765228271 */

 0xB8u, 0x84u, 0x03u, 0x00u, /* Tap(24), 0.0274877548217773 */

 0x48u, 0xDEu, 0x03u, 0x00u, /* Tap(25), 0.0302209854125977 */

 0x47u, 0x31u, 0x04u, 0x00u, /* Tap(26), 0.0327538251876831 */

 0x1Fu, 0x7Bu, 0x04u, 0x00u, /* Tap(27), 0.0350073575973511 */

 0x6Fu, 0xB9u, 0x04u, 0x00u, /* Tap(28), 0.0369089841842651 */

 0x22u, 0xEAu, 0x04u, 0x00u, /* Tap(29), 0.0383951663970947 */

 0x91u, 0x0Bu, 0x05u, 0x00u, /* Tap(30), 0.0394154787063599 */

 0x94u, 0x1Cu, 0x05u, 0x00u, /* Tap(31), 0.0399346351623535 */

 0x94u, 0x1Cu, 0x05u, 0x00u, /* Tap(32), 0.0399346351623535 */

 0x91u, 0x0Bu, 0x05u, 0x00u, /* Tap(33), 0.0394154787063599 */

 0x22u, 0xEAu, 0x04u, 0x00u, /* Tap(34), 0.0383951663970947 */

 0x6Fu, 0xB9u, 0x04u, 0x00u, /* Tap(35), 0.0369089841842651 */

 0x1Fu, 0x7Bu, 0x04u, 0x00u, /* Tap(36), 0.0350073575973511 */

 0x47u, 0x31u, 0x04u, 0x00u, /* Tap(37), 0.0327538251876831 */

 0x48u, 0xDEu, 0x03u, 0x00u, /* Tap(38), 0.0302209854125977 */

 0xB8u, 0x84u, 0x03u, 0x00u, /* Tap(39), 0.0274877548217773 */

 0x3Eu, 0x27u, 0x03u, 0x00u, /* Tap(40), 0.0246350765228271 */

 0x76u, 0xC8u, 0x02u, 0x00u, /* Tap(41), 0.021742582321167 */

 0xD4u, 0x6Au, 0x02u, 0x00u, /* Tap(42), 0.0188851356506348 */

 0x87u, 0x10u, 0x02u, 0x00u, /* Tap(43), 0.0161293745040894 */

 0x6Eu, 0xBBu, 0x01u, 0x00u, /* Tap(44), 0.0135324001312256 */

 0x03u, 0x6Du, 0x01u, 0x00u, /* Tap(45), 0.0111392736434937 */

 0x56u, 0x26u, 0x01u, 0x00u, /* Tap(46), 0.00898241996765137 */

 0x0Du, 0xE8u, 0x00u, 0x00u, /* Tap(47), 0.00708162784576416 */

 0x6Au, 0xB2u, 0x00u, 0x00u, /* Tap(48), 0.00544476509094238 */

 0x53u, 0x85u, 0x00u, 0x00u, /* Tap(49), 0.00406873226165771 */

 0x61u, 0x60u, 0x00u, 0x00u, /* Tap(50), 0.00294125080108643 */

 0xF0u, 0x42u, 0x00u, 0x00u, /* Tap(51), 0.00204277038574219 */

 0x30u, 0x2Cu, 0x00u, 0x00u, /* Tap(52), 0.00134849548339844 */

 0x39u, 0x1Bu, 0x00u, 0x00u, /* Tap(53), 0.000830769538879395 */

 0x19u, 0x0Fu, 0x00u, 0x00u, /* Tap(54), 0.00046074390411377 */

 0xE1u, 0x06u, 0x00u, 0x00u, /* Tap(55), 0.000209927558898926 */

 0xB3u, 0x01u, 0x00u, 0x00u, /* Tap(56), 5.18560409545898E-05 */

 0xC7u, 0xFEu, 0xFFu, 0x00u, /* Tap(57), -3.73125076293945E-05 */

 0x71u, 0xFDu, 0xFFu, 0x00u, /* Tap(58), -7.80820846557617E-05 */

 0x22u, 0xFDu, 0xFFu, 0x00u, /* Tap(59), -8.74996185302734E-05 */

 0x69u, 0xFDu, 0xFFu, 0x00u, /* Tap(60), -7.9035758972168E-05 */

 0xEBu, 0xFDu, 0xFFu, 0x00u, /* Tap(61), -6.35385513305664E-05 */

 0x67u, 0xFEu, 0xFFu, 0x00u, /* Tap(62), -4.87565994262695E-05 */

 0xAAu, 0xFEu, 0xFFu, 0x00u, /* Tap(63), -4.07695770263672E-05 */
};

