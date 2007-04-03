/*   $OSSEC, decoder.h, v0.2, 2006/01/04, Daniel B. Cid$   */

/* Copyright (C) 2005,2006 Daniel B. Cid <dcid@ossec.net>
 * All right reserved.
 *
 * This program is a free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation
 */


#ifndef __DECODER_H

#define __DECODER_H


/* We need the eventinfo and os_regex in here */
#include "os_regex/os_regex.h"

#define AFTER_PARENT    0x001   /* 1   */
#define AFTER_PREMATCH  0x002   /* 2   */
#define AFTER_PREVREGEX 0x004   /* 4   */ 
#define AFTER_ERROR     0x010   



/* Decoder structure */
typedef struct
{
    u_int8_t  get_next;
    u_int8_t  type;
    u_int8_t  use_own_name;

    u_int16_t  id;
    u_int16_t regex_offset;
    u_int16_t prematch_offset;
    
    int fts;
    char *parent;
    char *name;
    char *ftscomment;
    
    OSRegex *regex;
    OSRegex *prematch;
    OSMatch *program_name;
    
    void (*plugindecoder)(void *lf);
    void (**order)(void *lf, char *field);
}OSDecoderInfo;

/* List structure */
typedef struct _OSDecoderNode
{
    struct _OSDecoderNode *next;
    struct _OSDecoderNode *child;
    OSDecoderInfo *osdecoder;
}OSDecoderNode;



/* Functions to Create the list, Add a osdecoder to the
 * list and to get the first osdecoder.
 */
void OS_CreateOSDecoderList();
int OS_AddOSDecoder(OSDecoderInfo *pi);
OSDecoderNode *OS_GetFirstOSDecoder();


#endif

/* EOF */
