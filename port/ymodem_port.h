#ifndef __YMODEM_PORT_H__
#define __YMODEM_PORT_H__
#include <stddef.h>
#include <stdint.h>
//必须实现的函数
//上层函数
//接收函数
uint8_t ymodem_rx_header(char *fil_nm, size_t fil_sz);             //当检测到包头的时候，自动调用此函数（打开文件）
uint8_t ymodem_rx_finish(uint8_t status);                          //返回结束原因，成功还是出错（关闭文件）
uint8_t ymodem_rx_pac_get(char *buf, size_t offset, size_t size);  //(写文件)
                                                                   //发送函数
uint8_t ymodem_tx_header(char **fil_nm, size_t *fil_sz);           //系统调用，用来获取文件名称和大小（用来封头包）
uint8_t ymodem_tx_finish(uint8_t status);                          //返回结束原因，成功还是出错(关闭文件)
uint8_t ymodem_tx_pac_get(char *buf, size_t offset, size_t sz_st); //得到待传输的数据(读文件)

//此函数由[用户主动调用]，启动文件传输(自己胡乱实现的，不属于标准接口函数，它用来告诉要传输的文件名)
uint8_t ymodem_tx_set_fil(char *fil_nm);
//底层函数
void __putchar(char ch);
void __putbuf(char *buf, size_t len);

void *__malloc(size_t size);
void __free(void *ptr);

#endif