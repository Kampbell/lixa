/*
 * Copyright (c) 2009-2011, Christian Ferrari <tiian@users.sourceforge.net>
 * All rights reserved.
 *
 * This file is part of LIXA.
 *
 * LIXA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * LIXA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LIXA.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBLIXAPQ_H
# define LIBLIXAPQ_H



#include <config.h>



#ifdef HAVE_STRING_H
# include <string.h>
#endif



/* Utilities for resource manager without standard switch file */
#include <lixa_sw.h>
/* MySQL front-end */
#include <mysql.h>



/**
 * This struct contains the pointers to XA methods and properties
 */
struct xa_switch_t xapqls;



/**
 * This struct is used to split xa_info passed from configuration file
 * (lixac_conf.xml) to broken down values that can be passed to
 * mysql_real_connect() function. The field of the structure are the same
 * of the parameter of mysql_real_connect(); the _buffer fields are used to
 * avoid useless dynamic allocation (xa_info is a length contrained string)
 */
struct lixa_mysql_real_connect_s {
    char         *host;
    char          host_buffer[RMNAMESZ];
    char         *user;
    char          user_buffer[RMNAMESZ];
    char         *passwd;
    char          passwd_buffer[RMNAMESZ];
    char         *db;
    char          db_buffer[RMNAMESZ];
    unsigned int  port;
    char         *unix_socket;
    char          unix_socket_buffer[RMNAMESZ];
    unsigned long client_flag;
};



/**
 * Char used to separe a key=value field from the following one
 */
#define LIXA_MYSQL_XA_INFO_SEPARATOR ','
/**
 * Char used to separe a key from a value
 */
#define LIXA_MYSQL_XA_INFO_ASSIGN    '='



/**
 * Parses an xa_info string and creates a broken down structure with the
 * fields necessary to invoke mysql_real_connect() function
 * @param xa_info IN the string passed to xa_open from lixac_conf.xml file
 * @param lmrc OUT the corresponding broken down structure
 * @return a reason code
 */
int lixa_my_parse_xa_info(const char *xa_info,
                          struct lixa_mysql_real_connect_s *lmrc);



/**
 * Implementation of "xa_open" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_open(char *xa_info, int rmid, long flags);


    
/**
 * Implementation of "xa_close" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_close(char *xa_info, int rmid, long flags);


    
/**
 * Implementation of "xa_start" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_start(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_end" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_end(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_rollback" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_rollback(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_prepare" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_prepare(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_commit" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_commit(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_recover" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description.
 * Unfortunately TMSTARTRSCAN and TMENDRSCAN are not implemented as the
 * standard explains because an open cursor need an open block (transaction)
 * and inside an open block "ROLLBACK PREPARED" cannot be used. For the sake of
 * LIXA usage a single scan is good enought, but this is not the standard
 * behavior
 */
int lixa_my_recover(XID *xids, long count, int rmid, long flags);


    
/**
 * Implementation of "xa_forget" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_forget(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_complete" for MySQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_my_complete(int *handle, int *retval, int rmid, long flags);



#endif /* LIBLIXAPQ_H */