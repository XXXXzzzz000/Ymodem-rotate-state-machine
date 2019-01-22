#ifndef __YMODEM_H__
#define __YMODEM_H__

#include "ymodem_port.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
/* packet 定义 */
#define PACKET_SEQNO_INDEX (1)
#define PACKET_SEQNO_COMP_INDEX (2)
#define PACKET_HEADER (3)  /*< start, block, block-complement */
#define PACKET_TRAILER (2) /*< CRC bytes */
#define PACKET_OVERHEAD (PACKET_HEADER + PACKET_TRAILER)
#define PACKET_SIZE (128)
#define PACKET_1K_SIZE (1024)
#define PACKET_TIMEOUT (1)

/* 文件相关定义 */
#define FILE_NAME_LENGTH (64)
#define FILE_SIZE_LENGTH (16)

/* 返回值 */
#define YMODEM_OK 0
#define YMODEM_ERR 1       /*< 校验包是否有问题，只能是“YMODEM_ERR==”而不应该“YMODEM_OK!=” */
#define YMODEM_PAC_EMPTY 2 /*< 包校验正确，但是里面是空值，在（IDLE状态，判断是否需要结束，退出） */

/* 接收时最大错误数,达到最大错误数则退出: */
#define MAX_ERRORS (5)

//*注：接收——只有ymodem_rx_start()是接收到消息的时候调用，其它都是用户实现，ymodem自动调用
//*注：发送——用户调用ymodem_tx_header()只有ymodem_tx_start()是接收到消息的时候调用，其它都是用户实现，ymodem自动调用
void ymodem_rx_put(char *buf, size_t rx_sz);
void ymodem_tx_put(char *buf, size_t rx_sz);

#endif //__YMODEM_H__
