/* 
 * File:   tcp.h
 * Author: schjolden
 *
 * Created on 13. september 2015, 13:28
 */

#ifndef TCP_H
#define	TCP_H

#ifdef	__cplusplus
extern "C" {
#endif
    
/*defines*/
#define OFF     0
#define ON      1    
/*GLOBAL FUNCTIONS*/
void tcp_init(void);
void tcp_handler(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TCP_H */

