/*
 * Copyright (c) 2009-2016, Christian Ferrari <tiian@users.sourceforge.net>
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
 *
 * This file is part of the libraries provided by LIXA.
 * In addition, as a special exception, the copyright holders of LIXA gives
 * Globetom Holdings (Pty) Ltd / 92 Regency Drive / Route 21 Corporate Park /
 * Nellmapius Drive / Centurion / South Africa
 * the permission to redistribute this file and/or modify it under the terms
 * of the GNU Lesser General Public License version 2.1 as published
 * by the Free Software Foundation.
 * The above special grant is perpetual and restricted to
 * Globetom Holdings (Pty) Ltd: IN NO WAY it can be automatically transferred
 * to a different company or to different people. "In no way" contemplates:
 * merge, acquisition and any other possible form of corportate change.
 * IN NO WAY, the above special grant can be assimilated to a patent or
 * any other form of asset.
 */
#ifndef LIXA_SYSLOG_H
# define LIXA_SYSLOG_H



#include <lixa_defines.h>



/* This file contains only syslog messages: they are specified as macros
   because every message must be used only once inside the source code;
   used prefixes:
   LXC: LiXa Client
   LXD: LiXa Daemon (server)
   used messages code:
   D: LOG_DEBUG
   I: LOG_INFO
   N: LOG_NOTICE
   W: LOG_WARNING
   E: LOG_ERR
   C: LOG_CRIT
*/
#define LIXA_SYSLOG_LXC000I "LXC000I this process is starting a new LIXA " \
    "transaction manager (%s package version is %s)"
#define LIXA_SYSLOG_LXC001E "LXC001E transaction '%s' can NOT be recovered " \
    "because current config digest '%s' does NOT match server stored config " \
    "digest '%s'"
#define LIXA_SYSLOG_LXC002E "LXC002E unable to connect to LIXA server at " \
    "address %s, port " IN_PORT_T_FORMAT
#define LIXA_SYSLOG_LXC003C "LXC003C resource manager '%s' returned an " \
    "error (%d) while committing (xa_commit) during recovery phase for " \
    "transaction '%s'"
#define LIXA_SYSLOG_LXC004C "LXC004C resource manager '%s' returned an " \
    "error (%d) while rolling back (xa_rollback) during recovery phase for " \
    "transaction '%s'"
#define LIXA_SYSLOG_LXC005W "LXC005W unable to recover transaction id '%s'; " \
    "this transaction must be manually recovered and the correlated " \
    "record(s) must be manually fixed in lixad server status file"
#define LIXA_SYSLOG_LXC006N "LXC006N resource manager '%s' returned " \
    "XA_RDONLY (%d) while committing (xa_commit) during recovery phase for " \
    "transaction '%s'"
#define LIXA_SYSLOG_LXC007N "LXC007N resource manager '%s' returned " \
    "XA_RDONLY (%d) while rolling back (xa_rollback) during recovery phase " \
    "for transaction '%s'"
#define LIXA_SYSLOG_LXC008I "LXC008I resource manager '%s' returned " \
    "XAER_NOTA during recovery commit: the resource manager already " \
    "committed the transaction with xid '%s'"
#define LIXA_SYSLOG_LXC009W "LXC009W resource manager '%s' (rmid=%d) " \
    "returned XAER_DUPID for xid='%s' and this should NOT happen"
#define LIXA_SYSLOG_LXC010W "LXC010W resource manager '%s' (rmid=%d) " \
    "returned XAER_PROTO for xid='%s' and this should NOT happen"
#define LIXA_SYSLOG_LXC011W "LXC011W the transaction with xid '%s' has not " \
    "completely committed (%s)"
#define LIXA_SYSLOG_LXC012W "LXC012W the transaction with xid '%s' has not " \
    "completely backed out (%s)"
#define LIXA_SYSLOG_LXC013W "LXC013W Resource Manager '%s' (rmid=%d) " \
    "returned XA_RETRY but the Transaction Manager does not use TMNOWAIT " \
    "flag when calling xa_start(): this is a bug inside the RM"
#define LIXA_SYSLOG_LXC014W "LXC014W Resource Manager '%s' (rmid=%d) " \
    "returned %d, the Transaction Manager called xa_start() without " \
    "TMRESUME/TMJOIN flag: there probably is a bug inside the RM code"
#define LIXA_SYSLOG_LXC015W "LXC015W Resource Manager '%s' (rmid=%d) " \
    "returned XA_NOMIGRATE for xid '%s', but the Transaction Manager called " \
    "xa_end() without " \
    "TMSUSPEND/TMMIGRATE flag: there probably is a bug inside the RM code"
#define LIXA_SYSLOG_LXC016W "LXC016W Resource Manager '%s' (rmid=%d) " \
    "returned %d to xa_prepare() and %d to xa_rollback(): the Application " \
    "Program called tx_commit() for this transaction ('%s') and this is " \
    "an hazard condition"
#define LIXA_SYSLOG_LXC017W "LXC017W Resource Manager '%s' (rmid=%d) " \
    "returned XA_RB* (%d) for xid '%s', but the Transaction Manager called " \
    "xa_commit() without TMONEPHASE flag: there probably is a bug inside " \
    "the RM code"
#define LIXA_SYSLOG_LXC018I "LXC018I Resource Manager '%s' returned " \
    "XAER_NOTA during recovery rollback: the Resource Manager already " \
    "rolled back the transaction with xid '%s'"
#define LIXA_SYSLOG_LXC019W "LXC019W Resource Manager '%s' (rmid=%d) " \
    "returned an unexpected return code (%d) to xa_close() call; this might " \
    "be the symptom of a bug inside the Resource Manager code"
#define LIXA_SYSLOG_LXC020W "LXC020W Resource Manager '%s' (rmid=%d) " \
    "returned XAER_ASYNC for xid '%s', but the Transaction Manager called " \
    "xa_forget() without TMASYNC flag: there probably is a bug inside " \
    "the RM code"
#define LIXA_SYSLOG_LXC021N "LXC021N Resource Manager '%s' (rmid=%d) " \
    "returned XAER_RMERR to xa_forget() for xid '%s', it has not forgotten " \
    "the transaction " \
    "branch; this condition will not be notified to the Application Program"
#define LIXA_SYSLOG_LXC022N "LXC022N Resource Manager '%s' (rmid=%d) " \
    "returned XAER_NOTA to xa_forget() for xid '%s', it has not recognized " \
    "the transaction as heuristically completed; this condition will not be " \
    "notified to the Application Program"
#define LIXA_SYSLOG_LXC023W "LXC023W Resource Manager '%s' (rmid=%d) " \
    "returned XAER_NOTA to xa_prepare() for xid '%s', but it did not " \
    "return XAER_NOTA to xa_end(): this might be a bug inside resource " \
    "manager code; this condition will not be " \
    "notified to the Application Program"
#define LIXA_SYSLOG_LXC024E "LXC024E Resource Manager '%s' (rmid=%d) returned %d while performing xa_recover() with flags=0x%lx and count=%d"
#define LIXA_SYSLOG_LXC025C "LXC025C Resource Manager '%s' (rmid=%d) returned %d while performing xa_recover() with flags=0x%lx and count=%d: the stack pointer could be now corrupted and the process will be interrupted as soon as possible; this might be a bug inside resource manager code"
#define LIXA_SYSLOG_LXC026W "LXC026W Resource Manager '%s' (rmid=%d) " \
    "returned XA_RETRY (%d) for xid '%s', but the Transaction Manager " \
    "called xa_commit() with TMONEPHASE flag: there probably is a bug " \
    "inside the RM code. The transaction is marked as completed: " \
    "consistency matters are delegated to Resource Manager behavior"
#define LIXA_SYSLOG_LXC027N "LXC027N can not send a message to the server " \
    "because it has disconnected the socket (pid=" PID_T_FORMAT "/tid=" \
    PTHREAD_T_FORMAT "); sending data would generate SIGPIPE signal"
#define LIXA_SYSLOG_LXC028N "LXC028N the server closed the connection " \
    "after a query recovery (step=8) message: it might be crashed"



#define LIXA_SYSLOG_LXD000N "LXD000N this process is starting a new LIXA " \
    "server (%s package version is %s)"
#define LIXA_SYSLOG_LXD001E "LXD001E failed to parse options: %s"
#define LIXA_SYSLOG_LXD002W "LXD002W dump option overrides daemon option"
#define LIXA_SYSLOG_LXD003E "LXD003E configuration error ('%s'), premature " \
    "exit"
#define LIXA_SYSLOG_LXD004E "LXD004E error (%s) while starting manager(s), " \
    "premature exit"
#define LIXA_SYSLOG_LXD005E "LXD005E error (%s) running listener(s), " \
    "premature exit"
#define LIXA_SYSLOG_LXD006N "LXD006N server terminated activities"
#define LIXA_SYSLOG_LXD007W "LXD007W first status file ('%s') did not pass " \
    "integrity check"
#define LIXA_SYSLOG_LXD008W "LXD008W second status file ('%s') did not pass " \
    "integrity check"
#define LIXA_SYSLOG_LXD009E "LXD009E both status files did not pass " \
    "integrity check; the server can not start-up"
#define LIXA_SYSLOG_LXD010C "LXD010C memory mapped status files are " \
    "different after copy. INTERNAL ERROR"
#define LIXA_SYSLOG_LXD011W "LXD011W a client is performing recovery " \
    "but config file changed in the meantime for job '%s' and transaction " \
    "'%s'"
#define LIXA_SYSLOG_LXD012W "LXD012W a client notified recovery failed " \
    "condition for the transaction registered in status file %d and block " \
    UINT32_T_FORMAT
#define LIXA_SYSLOG_LXD013W "LXD013W unable to switch client; recovery not " \
    "performed"
#define LIXA_SYSLOG_LXD014N "LXD014N LIXA server entered daemon status"
#define LIXA_SYSLOG_LXD015W "LXD015W unable to open pid file '%s' (errno=%d '%s')"
#define LIXA_SYSLOG_LXD016E "LXD016E config file error: unable to find property '%s' in tag '%s'"
#define LIXA_SYSLOG_LXD017E "LXD017E intercommunication pipes initialization error"
#define LIXA_SYSLOG_LXD018C "LXD018C internal thread id=%d raised unexpected expection (server_manager_thread: excp=%d,ret_cod=%d,errno=%d); immediate shutdown will terminate the server"
#define LIXA_SYSLOG_LXD019N "LXD019N received signal %d, server %s shutdown in progress..."
#define LIXA_SYSLOG_LXD020N "LXD020N the server is operating in MAINTENANCE MODE ONLY"
#define LIXA_SYSLOG_LXD021I "LXD021I transaction '%s' is in recovery failed status; removing it from status file"
#define LIXA_SYSLOG_LXD022N "LXD022N the server is going to clean all the previous recovery failed transactions"
#define LIXA_SYSLOG_LXD023E "LXD023E the listener got a non recoverable error while polling its own socket (poll revents=0x%hx, errno=%d '%s'); starting premature quiesce shutdown..."
#define LIXA_SYSLOG_LXD024N "LXD024N the server is not able to remove the file '%s' (errno=%d '%s')"
#define LIXA_SYSLOG_LXD025E "LXD025E the server is not able to open the file '%s' (errno=%d '%s')"
#define LIXA_SYSLOG_LXD026I "LXD026I parameter '%s' set to value %ld"
#define LIXA_SYSLOG_LXD027I "LXD027I parameter '%s' set to value '%s'"
#define LIXA_SYSLOG_LXD028N "LXD026N value %ld is invalid for parameter '%s', fixing it to %ld"



#define LIXA_SYSLOG_LXR000I "LXR000I LIXA recovery process is starting " \
    "(%s package version is %s)"
#define LIXA_SYSLOG_LXR001E "LXR001E failed to parse options: %s"
#define LIXA_SYSLOG_LXR002I "LXR002I this LIXA recovery process is terminating"
#define LIXA_SYSLOG_LXR003E "LXR003E unable to perform tx_open() (rc=%d)"
#define LIXA_SYSLOG_LXR004W "LXR004W Resource Manager returned %d while performing cold commit recovery, xa_forget will be issued to clean-up transaction '%s'"
#define LIXA_SYSLOG_LXR005W "LXR005W Resource Manager returned %d while performing cold rollback recovery, xa_forget will be issued to clean-up transaction '%s'"



#endif /* LIXA_SYSLOG_H */
