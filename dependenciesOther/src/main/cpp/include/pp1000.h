#ifndef _VF_PP1000_H_
#define _VF_PP1000_H_

#include "UserType.h"
#include "PINPAD.h"

#define KEY_CANCEL  27
#define	KEY_CR		13
#define	PIN_BYPASS	28

#define STX 0x02
#define ETX 0x03
#define EOT 0x04
#define ACK 0x06
#define NAK 0x15
 
#define	SI					0x0f
#define	SO					0x0e
#define	_SI					0        /* packet begin of SI */
#define	_SO					0        /* packet end of SO */
#define	_STX				1        /* packet begin of STX */
#define	_ETX				1        /* packet end of ETX */
#define	_ETB				2

#define	NO_DISP_ON_PIN		0        /* request string input */
#define	DISP_ON_PIN			1        /* request string input */
#define PINPAD_CAL_TIMOUT   10

#define SEND_BUF_SIZE 256
#define RECV_BUF_SIZE 256

/* Definitions for various error types */

#define ERR_COM_OPEN                    (-10) /* port open failed                   */
#define ERR_COM_INIT                    (-11) /* Error setting port parameters      */
#define ERR_COM_CLOSE                   (-12) /* port close failed                  */
#define ERR_COM_SEND                    (-13) /* Write to Com port failed           */
#define ERR_COM_NAK                     (-14) /* Did not receive ACK for last write */
#define ERR_COM_READ                    (-15) /* Error setting port parameters      */
#define ERR_COM_WRITE                   (-16) /* Error setting port parameters      */
#define ERR_COM_TIMEOUT                 (-17) /* Error setting port parameters      */
#define ERR_COM_RECV                    (-18) /* Error setting port parameters      */

#define VS_SUCCESS            0             /* General purpose error code */
#define VS_ERR              (-1)
#define VS_ERROR            (-1)            /* Operator error */
#define VS_FAILURE          (-2)            /* System-level error */
#define VS_ESCAPE           (-3)            /* Operator quit transaction */
#define VS_TIMEOUT          (-4)            /* Time out */
#define VS_CARRIER          (-5)            /* Modem Lost Carrier */
#define VS_EOB              (-6)            /* End of Batch */
#define VS_ABORT            (-99)           /* Operation Aborted (obsolete) */

#define PINPAD_PIN_RESP_LEN 27      /* Normal length of resp pkt for PIN */
#define PINPAD_BUFFER_SIZE  256
#define LAST                0       /* Used in MACing */
#define TIMEOUT_DELAY       10      /* Timeout needed for PinPad */

#define CLR                 0x1A    /* Clear the pinpad screen or not */
#define MAX_ACT_RETRYS      3       /* Account Entry Max retries */

#define PP_MAX_RETRYS      3       /* Maximum number of retries */
#define PINPAD_BUF_SIZE     250     /* Max size for PP RX and TX buffers */

/* timeout (in secs) for pinpad response */
#define PINPAD_RX_TIMOUT  	2
#define PINPAD_MAC_TIMOUT 	10
#define PINPAD_PIN_TIMOUT 	25


#define VS_FALSE            0
#define VS_TRUE             1




/* ���� */
int inSendPinPadData(char *pchMsg, int inTimeout, int fWaitForAck);
int inRecvPinPadData(char *pchRecvBuf, int inTimeout, int inMaxRecSize, int fSendAck, int fCancel);
int PP1000_receive(char *r, int s, int t);


void PP1000_SetHandle(int handle);
void PP1000_SetMKeyFormat(usint key_format);

int PP1000_ConnectTest(usint pp_mode, char *device_name);                  /* initialization of PIN Pad */
int PP1000_Idle(void);
int PP1000_SetIdleMsg(char *msg);
int PP1000_DisplayMsg(char *pinmsg);
int PP1000_DisplayMsgRotating(char *msg1, char *msg2, char *msg3); //for PP1000se V3

int PP1000_SelectMKey(usint number);
int PP1000_CheckMKey(usint number);
int PP1000_LoadKTK(usint pp_mode, byte* KLK);
int PP1000_CheckKLK(void);
int PP1000_LoadDefaultKTK(usint pp_mode);
int PP1000_LoadMKey(usint pp_mode, byte *key, usint number);
int PP1000_GetPIN(usint pp_mode, byte *card_holder_pin, char *Amount, byte *cardno, byte* pinkey, int minlen, int maxlen, usint timeout, usint number);
int PP1000_GetMAC(usint pp_mode, byte *out, byte *str, int len, usint KeyIndex, byte *MacKey);
int PP1000_PlainPIN(usint pp_mode, byte *inPIN, usint *len,char *Amount, int minlen, int maxlen, usint timeout);

int PP1000_Connect_CheckMode(void);
int PP1000_Switch2Reader(void);
int PP1000_Switch2Ped(void);
int PP1000_GetDeviceMode(void);
int PP1000_Connect(void);

void PP1000_SetErrorStatus (int err_status);
int PP1000_GetErrorStatus (void);

//int PP1000_GetDeviceInfo(PP1000_DEVICE_INFO *pInfo);

#endif
