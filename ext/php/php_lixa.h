/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef PHP_LIXA_H
#define PHP_LIXA_H

extern zend_module_entry lixa_module_entry;
#define phpext_lixa_ptr &lixa_module_entry

#ifdef PHP_WIN32
# define PHP_LIXA_API __declspec(dllexport)
#else
# define PHP_LIXA_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(lixa);
PHP_MSHUTDOWN_FUNCTION(lixa);
PHP_RINIT_FUNCTION(lixa);
PHP_RSHUTDOWN_FUNCTION(lixa);
PHP_MINFO_FUNCTION(lixa);

ZEND_NAMED_FUNCTION(_wrap_xid_t_formatID_set);
ZEND_NAMED_FUNCTION(_wrap_xid_t_formatID_get);
ZEND_NAMED_FUNCTION(_wrap_xid_t_gtrid_length_set);
ZEND_NAMED_FUNCTION(_wrap_xid_t_gtrid_length_get);
ZEND_NAMED_FUNCTION(_wrap_xid_t_bqual_length_set);
ZEND_NAMED_FUNCTION(_wrap_xid_t_bqual_length_get);
ZEND_NAMED_FUNCTION(_wrap_xid_t_data_set);
ZEND_NAMED_FUNCTION(_wrap_xid_t_data_get);
ZEND_NAMED_FUNCTION(_wrap_new_xid_t);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_xid_set);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_xid_get);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_when_return_set);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_when_return_get);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_transaction_control_set);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_transaction_control_get);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_transaction_timeout_set);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_transaction_timeout_get);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_transaction_state_set);
ZEND_NAMED_FUNCTION(_wrap_tx_info_t_transaction_state_get);
ZEND_NAMED_FUNCTION(_wrap_new_tx_info_t);
ZEND_NAMED_FUNCTION(_wrap_tx_begin);
ZEND_NAMED_FUNCTION(_wrap_tx_close);
ZEND_NAMED_FUNCTION(_wrap_tx_commit);
ZEND_NAMED_FUNCTION(_wrap_tx_info);
ZEND_NAMED_FUNCTION(_wrap_tx_open);
ZEND_NAMED_FUNCTION(_wrap_tx_rollback);
ZEND_NAMED_FUNCTION(_wrap_tx_set_commit_return);
ZEND_NAMED_FUNCTION(_wrap_tx_set_transaction_control);
ZEND_NAMED_FUNCTION(_wrap_tx_set_transaction_timeout);
#endif /* PHP_LIXA_H */