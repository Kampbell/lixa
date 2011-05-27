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



/* PostgreSQL front-end */
#include <libpq-fe.h>



/**
 * This struct contains the pointers to XA methods and properties
 */
struct xa_switch_t xapqls;



/**
 * Used to build an array of connections; useful when there are two or more
 * PostgreSQL resource managers in the same transaction
 */
struct lixa_pq_status_rm_s {
    /** Resource Manager ID */
    int     rmid;
    struct {
        /** Resource Manager State:
         *  0=Un-initialized,
         *  1=Initialized */
        int R;
        /** Transaction Branch Association State:
         *  0=Not Associated,
         *  1=Associated,
         *  2=Association Suspended (UNSUPPORTED) */
        int T;
        /** Transaction Branch State:
         *  0=Non-existent Transaction,
         *  1=Active,
         *  2=Idle,
         *  3=Prepared,
         *  4=Rollback Only,
         *  5=Heuristically Completed */
        int S;
    } state;
    /** Transaction ID as passed by the Transaction Manager */
    XID     xid;
    /** PostgreSQL connection */
    PGconn *conn;
};



/**
 * This is the status record associated to a thread
 */
struct lixa_pq_status_s {
    /** Store the context of every PostgreSQL resource manager used by the
     *  transaction */
    GArray *rm;
};



typedef struct lixa_pq_status_s lixa_pq_status_t;



/**
 * A string used to serialize a XID and use it with PostgreSQL.
 * NOTE: this is not XA standard compliant, but it just works in
 * conjunction with LIXA Transaction Manager.
 * 200 chars are documented for 'PREPARE TRANSACTION' command:
 * "The identifier must be written as a string literal, and must be less
 * than 200 bytes long."
 */
typedef char lixa_pq_ser_xid_t[200];



/**
 * Retrieve the LIXA format ID serialized; it's useful to query PostgreSQL
 * and retrieve all the current prepared transactions (xa_recover function)
 * @param lpsx OUT the serialized format ID
 */
void lixa_pq_ser_xid_formatid(lixa_pq_ser_xid_t lpsx);



/**
 * Serialize XID to a string compatible with PostgreSQL
 * @param lpsx OUT the serialized XID
 * @param xid IN the XID to be serialized
 * @return TRUE if serialization was completed, FALSE if there was an error
 */
int lixa_pq_ser_xid_serialize(lixa_pq_ser_xid_t lpsx, XID *xid);



/**
 * Deserialize a string compatible with PostgreSQL to a XID
 * @param lpsx IN the string must be deserialized
 * @param xid OUT the deserialized XID
 * @return TRUE if deserialization was completed, FALSE if there was an error
 */
int lixa_pq_ser_xid_deserialize(lixa_pq_ser_xid_t lpsx, XID *xid);



/**
 * Reset the content of an object
 * @param lps IN/OUT object reference
 */
static inline void lixa_pq_status_init(lixa_pq_status_t *lps) {
    lps->rm = g_array_new(FALSE, FALSE, sizeof(struct lixa_pq_status_rm_s));
}


/**
 * Reset the content of an object
 * @param lpsr IN/OUT object reference
 */
static inline void lixa_pq_status_rm_init(struct lixa_pq_status_rm_s *lpsr) {
    lpsr->rmid = 0;
    lpsr->state.R = lpsr->state.T = lpsr->state.S = 0;
    memset(&(lpsr->xid), 0, sizeof(XID));
    lpsr->conn = NULL;
}



/**
 * Retrieve a pointer to the status of the resource manager for the current
 * thread
 * @param rmid IN Resource Manager ID
 * @return the pointer to the desired status or NULL
 */
struct lixa_pq_status_rm_s *lixa_pq_status_rm_get(int rmid);



/**
 * Destroy an object of type @ref lixa_pq_status_t
 * @param data IN reference to the object
 */
void lixa_pq_status_destroy(gpointer data);


    
/**
 * Implementation of "xa_open" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_open(char *xa_info, int rmid, long flags);


    
/**
 * Implementation of "xa_close" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_close(char *xa_info, int rmid, long flags);


    
/**
 * Implementation of "xa_start" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_start(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_end" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_end(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_rollback" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_rollback(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_prepare" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_prepare(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_commit" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_commit(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_recover" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_recover(XID *xids, long count, int rmid, long flags);


    
/**
 * Implementation of "xa_forget" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_forget(XID *xid, int rmid, long flags);


    
/**
 * Implementation of "xa_complete" for PostgreSQL;
 * refer to "Distributed Transaction Processing: The XA Specification" for
 * a complete description
 */
int lixa_pq_complete(int *handle, int *retval, int rmid, long flags);



#endif /* LIBLIXAPQ_H */