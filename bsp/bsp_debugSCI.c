#include "driverlib.h"
#include "device.h"
#include <stdint.h>
#include <stdio.h>
#include <file.h>
#include <bsp/launchxl_sci_io_driverlib.h>



//
// Select which SCI/UART pinout is desired -
// Must configure switch S2 on LaunchPad board accordingly
//
#define SCIPinout  0    // GPIO28/29
//#define SCIPinout  1    // GPIO15/56


//
// scia_init - SCIA  8-bit word, baud rate 0x001A, default, 1 STOP bit,
// no parity
//
void scia_init()
{
    //
    // GPIO28 is the SCI Rx pin.
    //

    GPIO_setPinConfig(DEVICE_GPIO_CFG_SCIRXDA);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SCIRXDA, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SCIRXDA, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SCIRXDA, GPIO_QUAL_ASYNC);

    //
    // GPIO29 is the SCI Tx pin.
    //

    GPIO_setPinConfig(DEVICE_GPIO_CFG_SCITXDA);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_SCITXDA, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_SCITXDA, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(DEVICE_GPIO_PIN_SCITXDA, GPIO_QUAL_ASYNC);


    //
    // Note: Clocks were turned on to the SCIA peripheral
    // in the InitSysCtrl() function
    //

    //
    // 1 stop bit,  No loopback, No parity,8 char bits, async mode,
    // idle-line protocol
    //
    SCI_performSoftwareReset(SCIA_BASE);

    SCI_setConfig(SCIA_BASE, DEVICE_LSPCLK_FREQ, 115200, (SCI_CONFIG_WLEN_8 |
                                                        SCI_CONFIG_STOP_ONE |
                                                        SCI_CONFIG_PAR_NONE));

    SCI_resetChannels(SCIA_BASE);
//    SCI_resetRxFIFO(SCIA_BASE);
//    SCI_resetTxFIFO(SCIA_BASE);
//    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXFF | SCI_INT_RXFF);
//    SCI_enableFIFO(SCIA_BASE);
    SCI_enableInterrupt(SCIA_BASE, SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
    SCI_enableModule(SCIA_BASE);
    SCI_performSoftwareReset(SCIA_BASE);

    return;
}
void bsp_DebugSCI_init(){
    scia_init();

    //
    // Redirect STDOUT to SCI
    //
    add_device("scia", _SSA, SCI_open, SCI_close, SCI_read, SCI_write,
                            SCI_lseek, SCI_unlink, SCI_rename);
    fopen("scia","w");
    freopen("scia:", "w", stdout);
        setvbuf(stdout, NULL, _IONBF, 0);
}
