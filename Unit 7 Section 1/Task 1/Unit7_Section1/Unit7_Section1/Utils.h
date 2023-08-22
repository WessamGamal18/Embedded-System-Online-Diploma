/*
 * Utils.h
 *
 * Created: 21-Aug-23 5:53:15 PM
 *  Author: Ahmed & Wessam
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define Set_Bit(reg,bit)  (reg = reg |(1<<bit))
#define Reset_Bit(reg,bit)  (reg = reg &~(1<<bit))
#define Read_Bit(reg,bit)  ((reg>>bit)&1)
#define Toggle_Bit(reg,bit)  (reg = reg ^(1<<bit))



#endif /* UTILS_H_ */