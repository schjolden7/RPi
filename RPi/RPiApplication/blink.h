/* 
 * File:   blink.h
 * Author: schjolden
 *
 * Created on 6. september 2015, 11:21
 */

#ifndef BLINK_H
#define	BLINK_H

#ifdef	__cplusplus
extern "C" {
#endif

/*global functions*/
void blink_setup(void);
void blink_toggle(void);
void blink_close(void);
void blink_set_high(void);
void blink_set_low(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BLINK_H */

