#include "ePaperScreen.h"

#define CONCAT_(A, B) A ## B
#define CONCAT(A, B) CONCAT_(A, B)
#define GPIOCONCAT_(A) A ## _GPIO
#define GPIOCONCAT(A) GPIOCONCAT_(A)
#define PINCONCAT_(A) A ## _PIN
#define PINCONCAT(A) PINCONCAT_(A)

#define OUTPUT_LOW(_pin) 	GPIO_PinWrite(GPIOCONCAT(_pin), PINCONCAT(_pin), 0)
#define OUTPUT_HIGH(_pin) 	GPIO_PinWrite(GPIOCONCAT(_pin), PINCONCAT(_pin), 1)

static void ePaperScreen_Reset(void)
{
	OUTPUT_HIGH(BOARD_INITEPAPERPINS_EPAPER_RST);
    OSA_TimeDelay(20);
    OUTPUT_LOW(BOARD_INITEPAPERPINS_EPAPER_RST);
    OSA_TimeDelay(20);
    OUTPUT_HIGH(BOARD_INITEPAPERPINS_EPAPER_RST);
    OSA_TimeDelay(20);
}

static void WriteBytes(uint8_t *pBuf, uint32_t Len)
{
	LPSPI_SetFrameSize(LPSPI1, Len*8);
	lpspi_transfer_t data =
	{
			.txData = pBuf,
			.rxData = NULL,
			.dataSize = Len,
			.configFlags = kLPSPI_MasterPcs3 | kLPSPI_MasterByteSwap
	};
	LPSPI_MasterTransferBlocking(LPSPI1, &data);
}

void ePaperScreen_SendCommandByte(uint8_t cmd)
{
	OUTPUT_LOW(BOARD_INITEPAPERPINS_EPAPER_DC);
    WriteBytes(&cmd, 1);
}


void ePaperScreen_SendDataByte(uint8_t data)
{
	OUTPUT_HIGH(BOARD_INITEPAPERPINS_EPAPER_DC);
    WriteBytes(&data, 1);
}

/******************************************************************************
function :	Wait until the busy_pin goes LOW
parameter:
******************************************************************************/
void ePaperScreen_CheckNotBusy(void)
{
    while(GPIO_PinRead(BOARD_INITEPAPERPINS_EPAPER_BUSY_GPIO, BOARD_INITEPAPERPINS_EPAPER_BUSY_PIN) == 1)
    {
        OSA_TimeDelay(100);
    }
}

static void ePaperScreen_SetDisplayWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend)
{
    ePaperScreen_SendCommandByte(0x44);
    ePaperScreen_SendDataByte((Xstart >> 3) & 0xFF);
    ePaperScreen_SendDataByte((Xend >> 3) & 0xFF);

    ePaperScreen_SendCommandByte(0x45);
    ePaperScreen_SendDataByte(Ystart & 0xFF);
    ePaperScreen_SendDataByte((Ystart >> 8) & 0xFF);
    ePaperScreen_SendDataByte(Yend & 0xFF);
    ePaperScreen_SendDataByte((Yend >> 8) & 0xFF);
}

void ePaperScreen_SetCursorPosition(uint16_t x, uint16_t y)
{
    ePaperScreen_SendCommandByte(0x4E);
    ePaperScreen_SendDataByte(x & 0xFF);

    ePaperScreen_SendCommandByte(0x4F);
    ePaperScreen_SendDataByte(y & 0xFF);
    ePaperScreen_SendDataByte((y >> 8) & 0xFF);
}

void ePaperScreen_RefreshDisplay(void)
{
    ePaperScreen_SendCommandByte(0x22);
    ePaperScreen_SendDataByte(0xF7);
    ePaperScreen_SendCommandByte(0x20);
    ePaperScreen_CheckNotBusy();
}

void ePaperScreen_Init(void)
{
    ePaperScreen_Reset();
	OSA_TimeDelay(100);
	
	ePaperScreen_CheckNotBusy();
	ePaperScreen_SendCommandByte(0x12);
	ePaperScreen_CheckNotBusy();

	ePaperScreen_SendCommandByte(0x01);
	ePaperScreen_SendDataByte(0x27);
	ePaperScreen_SendDataByte(0x01);
	ePaperScreen_SendDataByte(0x00);

	ePaperScreen_SendCommandByte(0x11);
	ePaperScreen_SendDataByte(0x03);

	ePaperScreen_SendCommandByte(0x21);
	ePaperScreen_SendDataByte(0x00);
	ePaperScreen_SendDataByte(0x80);

	ePaperScreen_SetDisplayWindow(0, 0, LCD_HEIGHT-1, LCD_WIDTH-1);
	ePaperScreen_SetCursorPosition(0, 0);
	ePaperScreen_CheckNotBusy();
}
