/*** FILEHEADER ****************************************************************
 *
 *	FILENAME:    types.h
 *	DATE:        21.11.2004
 *	AUTHOR:		 Christian Stadler
 *
 *	DESCRIPTION: Definition of common types.
 *
 ******************************************************************************/

/*** HISTORY OF CHANGE *********************************************************
 *
 *	$Log: /pic/_inc/types.h $
 * 
 * 3     1.11.10 11:42 Stadler
 * - type definitons dependend on compiler
 * 
 * 2     26.02.05 18:44 Stadler
 * added bool type
 * 
 ******************************************************************************/

#ifndef TYPES_H
#define TYPES_H

/*---------------------------------------------------------------------------*/
/* Type definitions for Microchip x8 Compiler                               */
/*---------------------------------------------------------------------------*/
#if defined(__18CXX)

typedef unsigned char bool;
typedef signed char sint8;
typedef signed int sint16;
typedef signed long sint32;
typedef unsigned char  uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;

/*---------------------------------------------------------------------------*/
/* Configuration for Microchip x16 Compiler                                  */
/*---------------------------------------------------------------------------*/
#elif defined(__PIC24H__)

typedef unsigned char bool;
typedef signed char sint8;
typedef signed int sint16;
typedef signed long sint32;
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;

#endif


#endif /*_TYPES_H */
