//*****************************************************************************
// MKS22F12 startup code for use with MCUXpresso IDE
//
// Version : 051217
//*****************************************************************************
//
// The Clear BSD License
// Copyright 2016-2017 NXP
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted (subject to the limitations in the
// disclaimer below) provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
// GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
// HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
// BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//*****************************************************************************

#if defined (DEBUG)
#pragma GCC push_options
#pragma GCC optimize ("Og")
#endif // (DEBUG)

#if defined (__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#else
//*****************************************************************************
//
// The entry point for the C++ library startup
//
//*****************************************************************************
extern "C" {
    extern void __libc_init_array(void);
}
#endif
#endif

#define WEAK __attribute__ ((weak))
#define WEAK_AV __attribute__ ((weak, section(".after_vectors")))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

//*****************************************************************************
#if defined (__cplusplus)
extern "C" {
#endif


#ifdef CONFIG_DISABLE_NMI_PIN
    #define FALSH_WORD_FOUR_VALUE 0xFFFFFBFE
#else
    #define FALSH_WORD_FOUR_VALUE 0xFFFFFFFE
#endif

//*****************************************************************************
// Flash Configuration block : 16-byte flash configuration field that stores
// default protection settings (loaded on reset) and security information that
// allows the MCU to restrict access to the Flash Memory module.
// Placed at address 0x400 by the linker script.
//*****************************************************************************
__attribute__ ((used,section(".FlashConfig"))) const struct {
    unsigned int word1;
    unsigned int word2;
    unsigned int word3;
    unsigned int word4;
} Flash_Config = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, FALSH_WORD_FOUR_VALUE};
//*****************************************************************************
// Declaration of external SystemInit function
//*****************************************************************************
#if defined (__USE_CMSIS)
extern void SystemInit(void);
#endif // (__USE_CMSIS)



//*****************************************************************************
// Forward declaration of the core exception handlers.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions
//*****************************************************************************
void ResetISR(void);
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void MemManage_Handler(void);
WEAK void BusFault_Handler(void);
WEAK void UsageFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void DebugMon_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void IntDefaultHandler(void);

//*****************************************************************************
// Declaration of external SystemWDOGInit function
//*****************************************************************************
WEAK void SystemWDOGInit(void);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void DMA0_IRQHandler(void);
WEAK void DMA1_IRQHandler(void);
WEAK void DMA2_IRQHandler(void);
WEAK void DMA3_IRQHandler(void);
WEAK void DMA4_IRQHandler(void);
WEAK void DMA5_IRQHandler(void);
WEAK void DMA6_IRQHandler(void);
WEAK void DMA7_IRQHandler(void);
WEAK void DMA8_IRQHandler(void);
WEAK void DMA9_IRQHandler(void);
WEAK void DMA10_IRQHandler(void);
WEAK void DMA11_IRQHandler(void);
WEAK void DMA12_IRQHandler(void);
WEAK void DMA13_IRQHandler(void);
WEAK void DMA14_IRQHandler(void);
WEAK void DMA15_IRQHandler(void);
WEAK void DMA_Error_IRQHandler(void);
WEAK void MCM_IRQHandler(void);
WEAK void FTF_IRQHandler(void);
WEAK void Read_Collision_IRQHandler(void);
WEAK void LVD_LVW_IRQHandler(void);
WEAK void LLWU_IRQHandler(void);
WEAK void WDOG_EWM_IRQHandler(void);
WEAK void RNG_IRQHandler(void);
WEAK void LPI2C0_IRQHandler(void);
WEAK void LPI2C1_IRQHandler(void);
WEAK void SPI0_IRQHandler(void);
WEAK void SPI1_IRQHandler(void);
WEAK void I2S0_Tx_IRQHandler(void);
WEAK void I2S0_Rx_IRQHandler(void);
WEAK void LPUART0_IRQHandler(void);
WEAK void UART0_RX_TX_IRQHandler(void);
WEAK void UART0_ERR_IRQHandler(void);
WEAK void UART1_RX_TX_IRQHandler(void);
WEAK void UART1_ERR_IRQHandler(void);
WEAK void UART2_RX_TX_IRQHandler(void);
WEAK void UART2_ERR_IRQHandler(void);
WEAK void Reserved53_IRQHandler(void);
WEAK void Reserved54_IRQHandler(void);
WEAK void ADC0_IRQHandler(void);
WEAK void CMP0_IRQHandler(void);
WEAK void Reserved57_IRQHandler(void);
WEAK void TPM0_IRQHandler(void);
WEAK void TPM1_IRQHandler(void);
WEAK void TPM2_IRQHandler(void);
WEAK void Reserved61_IRQHandler(void);
WEAK void RTC_IRQHandler(void);
WEAK void RTC_Seconds_IRQHandler(void);
WEAK void PIT0_IRQHandler(void);
WEAK void PIT1_IRQHandler(void);
WEAK void PIT2_IRQHandler(void);
WEAK void PIT3_IRQHandler(void);
WEAK void PDB0_IRQHandler(void);
WEAK void USB0_IRQHandler(void);
WEAK void Reserved70_IRQHandler(void);
WEAK void Reserved71_IRQHandler(void);
WEAK void DAC0_IRQHandler(void);
WEAK void MCG_IRQHandler(void);
WEAK void LPTMR0_IRQHandler(void);
WEAK void PORTA_IRQHandler(void);
WEAK void PORTB_IRQHandler(void);
WEAK void PORTC_IRQHandler(void);
WEAK void PORTD_IRQHandler(void);
WEAK void PORTE_IRQHandler(void);
WEAK void SWI_IRQHandler(void);
WEAK void Reserved81_IRQHandler(void);
WEAK void Reserved82_IRQHandler(void);
WEAK void Reserved83_IRQHandler(void);
WEAK void Reserved84_IRQHandler(void);
WEAK void Reserved85_IRQHandler(void);
WEAK void FLEXIO_IRQHandler(void);
WEAK void Reserved87_IRQHandler(void);
WEAK void Reserved88_IRQHandler(void);
WEAK void Reserved89_IRQHandler(void);
WEAK void Reserved90_IRQHandler(void);
WEAK void CAN0_ORed_Message_buffer_IRQHandler(void);
WEAK void CAN0_Bus_Off_IRQHandler(void);
WEAK void CAN0_Error_IRQHandler(void);
WEAK void CAN0_Tx_Warning_IRQHandler(void);
WEAK void CAN0_Rx_Warning_IRQHandler(void);
WEAK void CAN0_Wake_Up_IRQHandler(void);
WEAK void Reserved97_IRQHandler(void);
WEAK void Reserved98_IRQHandler(void);
WEAK void Reserved99_IRQHandler(void);
WEAK void Reserved100_IRQHandler(void);
WEAK void Reserved101_IRQHandler(void);
WEAK void Reserved102_IRQHandler(void);
WEAK void Reserved103_IRQHandler(void);
WEAK void I2S1_Tx_IRQHandler(void);
WEAK void I2S1_Rx_IRQHandler(void);
WEAK void Reserved106_IRQHandler(void);
WEAK void Reserved107_IRQHandler(void);
WEAK void Reserved108_IRQHandler(void);
WEAK void Reserved109_IRQHandler(void);
WEAK void CAN1_ORed_Message_buffer_IRQHandler(void);
WEAK void CAN1_Bus_Off_IRQHandler(void);
WEAK void CAN1_Error_IRQHandler(void);
WEAK void CAN1_Tx_Warning_IRQHandler(void);
WEAK void CAN1_Rx_Warning_IRQHandler(void);
WEAK void CAN1_Wake_Up_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the IntDefaultHandler, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void DMA0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA4_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA5_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA6_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA7_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA8_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA9_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA10_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA11_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA12_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA13_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA14_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA15_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA_Error_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MCM_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FTF_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Read_Collision_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LVD_LVW_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LLWU_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void WDOG_EWM_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RNG_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPI2C0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPI2C1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SPI0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SPI1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void I2S0_Tx_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void I2S0_Rx_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPUART0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UART0_RX_TX_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UART0_ERR_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UART1_RX_TX_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UART1_ERR_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UART2_RX_TX_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UART2_ERR_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved53_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved54_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ADC0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CMP0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved57_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TPM0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TPM1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void TPM2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved61_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void RTC_Seconds_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIT0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIT1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIT2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PIT3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PDB0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void USB0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved70_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved71_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DAC0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MCG_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPTMR0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PORTA_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PORTB_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PORTC_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PORTD_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PORTE_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SWI_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved81_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved82_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved83_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved84_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved85_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FLEXIO_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved87_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved88_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved89_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved90_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CAN0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved97_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved98_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved99_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved100_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved101_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved102_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved103_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void I2S1_Tx_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void I2S1_Rx_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved106_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved107_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved108_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved109_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CAN1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);

//*****************************************************************************
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//*****************************************************************************
#if defined (__REDLIB__)
extern void __main(void);
#endif
extern int main(void);

//*****************************************************************************
// External declaration for the pointer to the stack top from the Linker Script
//*****************************************************************************
extern void _vStackTop(void);
//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif
//*****************************************************************************
// The vector table.
// This relies on the linker script to place at correct location in memory.
//*****************************************************************************
extern void (* const g_pfnVectors[])(void);
extern void * __Vectors __attribute__ ((alias ("g_pfnVectors")));

__attribute__ ((used, section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    // Core Level - CM4
    &_vStackTop,                       // The initial stack pointer
    ResetISR,                          // The reset handler
    NMI_Handler,                       // The NMI handler
    HardFault_Handler,                 // The hard fault handler
    MemManage_Handler,                 // The MPU fault handler
    BusFault_Handler,                  // The bus fault handler
    UsageFault_Handler,                // The usage fault handler
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall handler
    DebugMon_Handler,                  // Debug monitor handler
    0,                                 // Reserved
    PendSV_Handler,                    // The PendSV handler
    SysTick_Handler,                   // The SysTick handler

    // Chip Level - MKS22F12
    DMA0_IRQHandler,                      // 16 : DMA Channel 0 Transfer Complete
    DMA1_IRQHandler,                      // 17 : DMA Channel 1 Transfer Complete
    DMA2_IRQHandler,                      // 18 : DMA Channel 2 Transfer Complete
    DMA3_IRQHandler,                      // 19 : DMA Channel 3 Transfer Complete
    DMA4_IRQHandler,                      // 20 : DMA Channel 4 Transfer Complete
    DMA5_IRQHandler,                      // 21 : DMA Channel 5 Transfer Complete
    DMA6_IRQHandler,                      // 22 : DMA Channel 6 Transfer Complete
    DMA7_IRQHandler,                      // 23 : DMA Channel 7 Transfer Complete
    DMA8_IRQHandler,                      // 24 : DMA Channel 8 Transfer Complete
    DMA9_IRQHandler,                      // 25 : DMA Channel 9 Transfer Complete
    DMA10_IRQHandler,                     // 26 : DMA Channel 10 Transfer Complete
    DMA11_IRQHandler,                     // 27 : DMA Channel 11 Transfer Complete
    DMA12_IRQHandler,                     // 28 : DMA Channel 12 Transfer Complete
    DMA13_IRQHandler,                     // 29 : DMA Channel 13 Transfer Complete
    DMA14_IRQHandler,                     // 30 : DMA Channel 14 Transfer Complete
    DMA15_IRQHandler,                     // 31 : DMA Channel 15 Transfer Complete
    DMA_Error_IRQHandler,                 // 32 : DMA Error Interrupt
    MCM_IRQHandler,                       // 33 : Normal Interrupt
    FTF_IRQHandler,                       // 34 : FTFA Command complete interrupt
    Read_Collision_IRQHandler,            // 35 : Read Collision Interrupt
    LVD_LVW_IRQHandler,                   // 36 : Low Voltage Detect, Low Voltage Warning
    LLWU_IRQHandler,                      // 37 : Low Leakage Wakeup Unit
    WDOG_EWM_IRQHandler,                  // 38 : WDOG Interrupt
    RNG_IRQHandler,                       // 39 : RNG Interrupt
    LPI2C0_IRQHandler,                    // 40 : LPI2C0 interrupt
    LPI2C1_IRQHandler,                    // 41 : LPI2C1 interrupt
    SPI0_IRQHandler,                      // 42 : SPI0 Interrupt
    SPI1_IRQHandler,                      // 43 : SPI1 Interrupt
    I2S0_Tx_IRQHandler,                   // 44 : I2S0 transmit interrupt
    I2S0_Rx_IRQHandler,                   // 45 : I2S0 receive interrupt
    LPUART0_IRQHandler,                   // 46 : LPUART0 status/error interrupt
    UART0_RX_TX_IRQHandler,               // 47 : UART0 Status Sources interrupt
    UART0_ERR_IRQHandler,                 // 48 : UART0 Error Sources interrupt
    UART1_RX_TX_IRQHandler,               // 49 : UART1 Status Sources interrupt
    UART1_ERR_IRQHandler,                 // 50 : UART1 Error Sources interrupt
    UART2_RX_TX_IRQHandler,               // 51 : UART2 Status Sources interrupt
    UART2_ERR_IRQHandler,                 // 52 : UART2 Error Sources interrupt
    Reserved53_IRQHandler,                // 53 : Reserved interrupt
    Reserved54_IRQHandler,                // 54 : Reserved interrupt
    ADC0_IRQHandler,                      // 55 : ADC0 interrupt
    CMP0_IRQHandler,                      // 56 : CMP0 interrupt
    Reserved57_IRQHandler,                // 57 : Reserved interrupt
    TPM0_IRQHandler,                      // 58 : TPM0 Timer Overflow and Channels interrupt
    TPM1_IRQHandler,                      // 59 : TPM1 Timer Overflow and Channels interrupt
    TPM2_IRQHandler,                      // 60 : TPM2 Timer Overflow and Channels interrupt
    Reserved61_IRQHandler,                // 61 : Reserved interrupt
    RTC_IRQHandler,                       // 62 : RTC alarm interrupt
    RTC_Seconds_IRQHandler,               // 63 : RTC seconds interrupt
    PIT0_IRQHandler,                      // 64 : PIT timer channel 0 interrupt
    PIT1_IRQHandler,                      // 65 : PIT timer channel 1 interrupt
    PIT2_IRQHandler,                      // 66 : PIT timer channel 2 interrupt
    PIT3_IRQHandler,                      // 67 : PIT timer channel 3 interrupt
    PDB0_IRQHandler,                      // 68 : PDB0 Interrupt
    USB0_IRQHandler,                      // 69 : USB0 interrupt
    Reserved70_IRQHandler,                // 70 : Reserved interrupt
    Reserved71_IRQHandler,                // 71 : Reserved interrupt
    DAC0_IRQHandler,                      // 72 : DAC0 interrupt
    MCG_IRQHandler,                       // 73 : MCG Interrupt
    LPTMR0_IRQHandler,                    // 74 : LPTimer interrupt
    PORTA_IRQHandler,                     // 75 : Port A interrupt
    PORTB_IRQHandler,                     // 76 : Port B interrupt
    PORTC_IRQHandler,                     // 77 : Port C interrupt
    PORTD_IRQHandler,                     // 78 : Port D interrupt
    PORTE_IRQHandler,                     // 79 : Port E interrupt
    SWI_IRQHandler,                       // 80 : Software interrupt
    Reserved81_IRQHandler,                // 81 : Reserved interrupt
    Reserved82_IRQHandler,                // 82 : Reserved interrupt
    Reserved83_IRQHandler,                // 83 : Reserved interrupt
    Reserved84_IRQHandler,                // 84 : Reserved interrupt
    Reserved85_IRQHandler,                // 85 : Reserved interrupt
    FLEXIO_IRQHandler,                    // 86 : Flexible IO interrupt
    Reserved87_IRQHandler,                // 87 : Reserved interrupt
    Reserved88_IRQHandler,                // 88 : Reserved interrupt
    Reserved89_IRQHandler,                // 89 : Reserved interrupt
    Reserved90_IRQHandler,                // 90 : Reserved interrupt
    CAN0_ORed_Message_buffer_IRQHandler,  // 91 : CAN0 OR'd message buffers interrupt
    CAN0_Bus_Off_IRQHandler,              // 92 : CAN0 bus off interrupt
    CAN0_Error_IRQHandler,                // 93 : CAN0 error interrupt
    CAN0_Tx_Warning_IRQHandler,           // 94 : CAN0 Tx warning interrupt
    CAN0_Rx_Warning_IRQHandler,           // 95 : CAN0 Rx warning interrupt
    CAN0_Wake_Up_IRQHandler,              // 96 : CAN0 wake up interrupt
    Reserved97_IRQHandler,                // 97 : Reserved interrupt
    Reserved98_IRQHandler,                // 98 : Reserved interrupt
    Reserved99_IRQHandler,                // 99 : Reserved interrupt
    Reserved100_IRQHandler,               // 100: Reserved interrupt
    Reserved101_IRQHandler,               // 101: Reserved interrupt
    Reserved102_IRQHandler,               // 102: Reserved interrupt
    Reserved103_IRQHandler,               // 103: Reserved interrupt
    I2S1_Tx_IRQHandler,                   // 104: I2S1 transmit interrupt
    I2S1_Rx_IRQHandler,                   // 105: I2S1 receive interrupt
    Reserved106_IRQHandler,               // 106: Reserved interrupt
    Reserved107_IRQHandler,               // 107: Reserved interrupt
    Reserved108_IRQHandler,               // 108: Reserved interrupt
    Reserved109_IRQHandler,               // 109: Reserved interrupt
    CAN1_ORed_Message_buffer_IRQHandler,  // 110: CAN0 OR'd message buffers interrupt
    CAN1_Bus_Off_IRQHandler,              // 111: CAN1 bus off interrupt
    CAN1_Error_IRQHandler,                // 112: CAN1 error interrupt
    CAN1_Tx_Warning_IRQHandler,           // 113: CAN1 Tx warning interrupt
    CAN1_Rx_Warning_IRQHandler,           // 114: CAN1 Rx warning interrupt
    CAN1_Wake_Up_IRQHandler,              // 115: CAN1 wake up interrupt
}; /* End of g_pfnVectors */

//*****************************************************************************
// Functions to carry out the initialization of RW and BSS data sections. These
// are written as separate functions rather than being inlined within the
// ResetISR() function in order to cope with MCUs with multiple banks of
// memory.
//*****************************************************************************
__attribute__ ((section(".after_vectors.init_data")))
void data_init(unsigned int romstart, unsigned int start, unsigned int len) {
	unsigned int *pulDest = (unsigned int*) start;
	unsigned int *pulSrc = (unsigned int*) romstart;
	unsigned int loop;
	for (loop = 0; loop < len; loop = loop + 4)
		*pulDest++ = *pulSrc++;
}

__attribute__ ((section(".after_vectors.init_bss")))
void bss_init(unsigned int start, unsigned int len) {
	unsigned int *pulDest = (unsigned int*) start;
	unsigned int loop;
	for (loop = 0; loop < len; loop = loop + 4)
		*pulDest++ = 0;
}

//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Global Section Table". This table is
// created by the linker via the Code Red managed linker script mechanism. It
// contains the load address, execution address and length of each RW data
// section and the execution and length of each BSS (zero initialized) section.
//*****************************************************************************
extern unsigned int __data_section_table;
extern unsigned int __data_section_table_end;
extern unsigned int __bss_section_table;
extern unsigned int __bss_section_table_end;


//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
__attribute__ ((section(".after_vectors.reset")))
void ResetISR(void) {

    // Disable interrupts
    __asm volatile ("cpsid i");

#if defined (__USE_CMSIS)
// If __USE_CMSIS defined, then call CMSIS SystemInit code
    SystemInit();

#else

    SystemWDOGInit();

#endif // (__USE_CMSIS)

    //
    // Copy the data sections from flash to SRAM.
    //
	unsigned int LoadAddr, ExeAddr, SectionLen;
	unsigned int *SectionTableAddr;

	// Load base address of Global Section Table
	SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
	while (SectionTableAddr < &__data_section_table_end) {
		LoadAddr = *SectionTableAddr++;
		ExeAddr = *SectionTableAddr++;
		SectionLen = *SectionTableAddr++;
		data_init(LoadAddr, ExeAddr, SectionLen);
	}

	// At this point, SectionTableAddr = &__bss_section_table;
	// Zero fill the bss segment
	while (SectionTableAddr < &__bss_section_table_end) {
		ExeAddr = *SectionTableAddr++;
		SectionLen = *SectionTableAddr++;
		bss_init(ExeAddr, SectionLen);
	}

#if !defined (__USE_CMSIS)
// Assume that if __USE_CMSIS defined, then CMSIS SystemInit code
// will enable the FPU
#if defined (__VFP_FP__) && !defined (__SOFTFP__)
    //
    // Code to enable the Cortex-M4 FPU only included
    // if appropriate build options have been selected.
    // Code taken from Section 7.1, Cortex-M4 TRM (DDI0439C)
    //
    // Read CPACR (located at address 0xE000ED88)
    // Set bits 20-23 to enable CP10 and CP11 coprocessors
    // Write back the modified value to the CPACR
	asm volatile ("LDR.W R0, =0xE000ED88\n\t"
                  "LDR R1, [R0]\n\t"
                  "ORR R1, R1, #(0xF << 20)\n\t"
                  "STR R1, [R0]");
#endif // (__VFP_FP__) && !(__SOFTFP__)
#endif // (__USE_CMSIS)

#if !defined (__USE_CMSIS)
// Assume that if __USE_CMSIS defined, then CMSIS SystemInit code
// will setup the VTOR register

    // Check to see if we are running the code from a non-zero
    // address (eg RAM, external flash), in which case we need
    // to modify the VTOR register to tell the CPU that the
    // vector table is located at a non-0x0 address.
    unsigned int * pSCB_VTOR = (unsigned int *) 0xE000ED08;
    if ((unsigned int *)g_pfnVectors!=(unsigned int *) 0x00000000) {
        *pSCB_VTOR = (unsigned int)g_pfnVectors;
    }
#endif // (__USE_CMSIS)

#if defined (__cplusplus)
    //
    // Call C++ library initialisation
    //
    __libc_init_array();
#endif

    // Reenable interrupts
    __asm volatile ("cpsie i");

#if defined (__REDLIB__)
	// Call the Redlib library, which in turn calls main()
	__main();
#else
	main();
#endif

	//
	// main() shouldn't return, but if it does, we'll just enter an infinite loop
	//
	while (1) {
		;
	}
}

//*****************************************************************************
// Default core exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
WEAK_AV void NMI_Handler(void)
{ while(1) {}
}

WEAK_AV void HardFault_Handler(void)
{ while(1) {}
}

WEAK_AV void MemManage_Handler(void)
{ while(1) {}
}

WEAK_AV void BusFault_Handler(void)
{ while(1) {}
}

WEAK_AV void UsageFault_Handler(void)
{ while(1) {}
}

WEAK_AV void SVC_Handler(void)
{ while(1) {}
}

WEAK_AV void DebugMon_Handler(void)
{ while(1) {}
}

WEAK_AV void PendSV_Handler(void)
{ while(1) {}
}

WEAK_AV void SysTick_Handler(void)
{ while(1) {}
}

//*****************************************************************************
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//*****************************************************************************
WEAK_AV void IntDefaultHandler(void)
{ while(1) {}
}

//*****************************************************************************
// Default application exception handlers. Override the ones here by defining
// your own handler routines in your application code. These routines call
// driver exception handlers or IntDefaultHandler() if no driver exception
// handler is included.
//*****************************************************************************
WEAK void DMA0_IRQHandler(void)
{   DMA0_DriverIRQHandler();
}

WEAK void DMA1_IRQHandler(void)
{   DMA1_DriverIRQHandler();
}

WEAK void DMA2_IRQHandler(void)
{   DMA2_DriverIRQHandler();
}

WEAK void DMA3_IRQHandler(void)
{   DMA3_DriverIRQHandler();
}

WEAK void DMA4_IRQHandler(void)
{   DMA4_DriverIRQHandler();
}

WEAK void DMA5_IRQHandler(void)
{   DMA5_DriverIRQHandler();
}

WEAK void DMA6_IRQHandler(void)
{   DMA6_DriverIRQHandler();
}

WEAK void DMA7_IRQHandler(void)
{   DMA7_DriverIRQHandler();
}

WEAK void DMA8_IRQHandler(void)
{   DMA8_DriverIRQHandler();
}

WEAK void DMA9_IRQHandler(void)
{   DMA9_DriverIRQHandler();
}

WEAK void DMA10_IRQHandler(void)
{   DMA10_DriverIRQHandler();
}

WEAK void DMA11_IRQHandler(void)
{   DMA11_DriverIRQHandler();
}

WEAK void DMA12_IRQHandler(void)
{   DMA12_DriverIRQHandler();
}

WEAK void DMA13_IRQHandler(void)
{   DMA13_DriverIRQHandler();
}

WEAK void DMA14_IRQHandler(void)
{   DMA14_DriverIRQHandler();
}

WEAK void DMA15_IRQHandler(void)
{   DMA15_DriverIRQHandler();
}

WEAK void DMA_Error_IRQHandler(void)
{   DMA_Error_DriverIRQHandler();
}

WEAK void MCM_IRQHandler(void)
{   MCM_DriverIRQHandler();
}

WEAK void FTF_IRQHandler(void)
{   FTF_DriverIRQHandler();
}

WEAK void Read_Collision_IRQHandler(void)
{   Read_Collision_DriverIRQHandler();
}

WEAK void LVD_LVW_IRQHandler(void)
{   LVD_LVW_DriverIRQHandler();
}

WEAK void LLWU_IRQHandler(void)
{   LLWU_DriverIRQHandler();
}

WEAK void WDOG_EWM_IRQHandler(void)
{   WDOG_EWM_DriverIRQHandler();
}

WEAK void RNG_IRQHandler(void)
{   RNG_DriverIRQHandler();
}

WEAK void LPI2C0_IRQHandler(void)
{   LPI2C0_DriverIRQHandler();
}

WEAK void LPI2C1_IRQHandler(void)
{   LPI2C1_DriverIRQHandler();
}

WEAK void SPI0_IRQHandler(void)
{   SPI0_DriverIRQHandler();
}

WEAK void SPI1_IRQHandler(void)
{   SPI1_DriverIRQHandler();
}

WEAK void I2S0_Tx_IRQHandler(void)
{   I2S0_Tx_DriverIRQHandler();
}

WEAK void I2S0_Rx_IRQHandler(void)
{   I2S0_Rx_DriverIRQHandler();
}

WEAK void LPUART0_IRQHandler(void)
{   LPUART0_DriverIRQHandler();
}

WEAK void UART0_RX_TX_IRQHandler(void)
{   UART0_RX_TX_DriverIRQHandler();
}

WEAK void UART0_ERR_IRQHandler(void)
{   UART0_ERR_DriverIRQHandler();
}

WEAK void UART1_RX_TX_IRQHandler(void)
{   UART1_RX_TX_DriverIRQHandler();
}

WEAK void UART1_ERR_IRQHandler(void)
{   UART1_ERR_DriverIRQHandler();
}

WEAK void UART2_RX_TX_IRQHandler(void)
{   UART2_RX_TX_DriverIRQHandler();
}

WEAK void UART2_ERR_IRQHandler(void)
{   UART2_ERR_DriverIRQHandler();
}

WEAK void Reserved53_IRQHandler(void)
{   Reserved53_DriverIRQHandler();
}

WEAK void Reserved54_IRQHandler(void)
{   Reserved54_DriverIRQHandler();
}

WEAK void ADC0_IRQHandler(void)
{   ADC0_DriverIRQHandler();
}

WEAK void CMP0_IRQHandler(void)
{   CMP0_DriverIRQHandler();
}

WEAK void Reserved57_IRQHandler(void)
{   Reserved57_DriverIRQHandler();
}

WEAK void TPM0_IRQHandler(void)
{   TPM0_DriverIRQHandler();
}

WEAK void TPM1_IRQHandler(void)
{   TPM1_DriverIRQHandler();
}

WEAK void TPM2_IRQHandler(void)
{   TPM2_DriverIRQHandler();
}

WEAK void Reserved61_IRQHandler(void)
{   Reserved61_DriverIRQHandler();
}

WEAK void RTC_IRQHandler(void)
{   RTC_DriverIRQHandler();
}

WEAK void RTC_Seconds_IRQHandler(void)
{   RTC_Seconds_DriverIRQHandler();
}

WEAK void PIT0_IRQHandler(void)
{   PIT0_DriverIRQHandler();
}

WEAK void PIT1_IRQHandler(void)
{   PIT1_DriverIRQHandler();
}

WEAK void PIT2_IRQHandler(void)
{   PIT2_DriverIRQHandler();
}

WEAK void PIT3_IRQHandler(void)
{   PIT3_DriverIRQHandler();
}

WEAK void PDB0_IRQHandler(void)
{   PDB0_DriverIRQHandler();
}

WEAK void USB0_IRQHandler(void)
{   USB0_DriverIRQHandler();
}

WEAK void Reserved70_IRQHandler(void)
{   Reserved70_DriverIRQHandler();
}

WEAK void Reserved71_IRQHandler(void)
{   Reserved71_DriverIRQHandler();
}

WEAK void DAC0_IRQHandler(void)
{   DAC0_DriverIRQHandler();
}

WEAK void MCG_IRQHandler(void)
{   MCG_DriverIRQHandler();
}

WEAK void LPTMR0_IRQHandler(void)
{   LPTMR0_DriverIRQHandler();
}

WEAK void PORTA_IRQHandler(void)
{   PORTA_DriverIRQHandler();
}

WEAK void PORTB_IRQHandler(void)
{   PORTB_DriverIRQHandler();
}

WEAK void PORTC_IRQHandler(void)
{   PORTC_DriverIRQHandler();
}

WEAK void PORTD_IRQHandler(void)
{   PORTD_DriverIRQHandler();
}

WEAK void PORTE_IRQHandler(void)
{   PORTE_DriverIRQHandler();
}

WEAK void SWI_IRQHandler(void)
{   SWI_DriverIRQHandler();
}

WEAK void Reserved81_IRQHandler(void)
{   Reserved81_DriverIRQHandler();
}

WEAK void Reserved82_IRQHandler(void)
{   Reserved82_DriverIRQHandler();
}

WEAK void Reserved83_IRQHandler(void)
{   Reserved83_DriverIRQHandler();
}

WEAK void Reserved84_IRQHandler(void)
{   Reserved84_DriverIRQHandler();
}

WEAK void Reserved85_IRQHandler(void)
{   Reserved85_DriverIRQHandler();
}

WEAK void FLEXIO_IRQHandler(void)
{   FLEXIO_DriverIRQHandler();
}

WEAK void Reserved87_IRQHandler(void)
{   Reserved87_DriverIRQHandler();
}

WEAK void Reserved88_IRQHandler(void)
{   Reserved88_DriverIRQHandler();
}

WEAK void Reserved89_IRQHandler(void)
{   Reserved89_DriverIRQHandler();
}

WEAK void Reserved90_IRQHandler(void)
{   Reserved90_DriverIRQHandler();
}

WEAK void CAN0_ORed_Message_buffer_IRQHandler(void)
{   CAN0_DriverIRQHandler();
}

WEAK void CAN0_Bus_Off_IRQHandler(void)
{   CAN0_DriverIRQHandler();
}

WEAK void CAN0_Error_IRQHandler(void)
{   CAN0_DriverIRQHandler();
}

WEAK void CAN0_Tx_Warning_IRQHandler(void)
{   CAN0_DriverIRQHandler();
}

WEAK void CAN0_Rx_Warning_IRQHandler(void)
{   CAN0_DriverIRQHandler();
}

WEAK void CAN0_Wake_Up_IRQHandler(void)
{   CAN0_DriverIRQHandler();
}

WEAK void Reserved97_IRQHandler(void)
{   Reserved97_DriverIRQHandler();
}

WEAK void Reserved98_IRQHandler(void)
{   Reserved98_DriverIRQHandler();
}

WEAK void Reserved99_IRQHandler(void)
{   Reserved99_DriverIRQHandler();
}

WEAK void Reserved100_IRQHandler(void)
{   Reserved100_DriverIRQHandler();
}

WEAK void Reserved101_IRQHandler(void)
{   Reserved101_DriverIRQHandler();
}

WEAK void Reserved102_IRQHandler(void)
{   Reserved102_DriverIRQHandler();
}

WEAK void Reserved103_IRQHandler(void)
{   Reserved103_DriverIRQHandler();
}

WEAK void I2S1_Tx_IRQHandler(void)
{   I2S1_Tx_DriverIRQHandler();
}

WEAK void I2S1_Rx_IRQHandler(void)
{   I2S1_Rx_DriverIRQHandler();
}

WEAK void Reserved106_IRQHandler(void)
{   Reserved106_DriverIRQHandler();
}

WEAK void Reserved107_IRQHandler(void)
{   Reserved107_DriverIRQHandler();
}

WEAK void Reserved108_IRQHandler(void)
{   Reserved108_DriverIRQHandler();
}

WEAK void Reserved109_IRQHandler(void)
{   Reserved109_DriverIRQHandler();
}

WEAK void CAN1_ORed_Message_buffer_IRQHandler(void)
{   CAN1_DriverIRQHandler();
}

WEAK void CAN1_Bus_Off_IRQHandler(void)
{   CAN1_DriverIRQHandler();
}

WEAK void CAN1_Error_IRQHandler(void)
{   CAN1_DriverIRQHandler();
}

WEAK void CAN1_Tx_Warning_IRQHandler(void)
{   CAN1_DriverIRQHandler();
}

WEAK void CAN1_Rx_Warning_IRQHandler(void)
{   CAN1_DriverIRQHandler();
}

WEAK void CAN1_Wake_Up_IRQHandler(void)
{   CAN1_DriverIRQHandler();
}


WEAK void SystemWDOGInit(void) {
    // Disable Watchdog
    //  Write 0xC520 to watchdog unlock register
    *((volatile unsigned short *)0x4005200E) = 0xC520;
    //  Followed by 0xD928 to complete the unlock
    *((volatile unsigned short *)0x4005200E) = 0xD928;
    // Now disable watchdog via STCTRLH register
    *((volatile unsigned short *)0x40052000) = 0x01D2u;
}

//*****************************************************************************

#if defined (DEBUG)
#pragma GCC pop_options
#endif // (DEBUG)
