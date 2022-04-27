/*******************************************************************************
 * Copyright 2008-2018 by Aerospike.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/

#pragma once


//==========================================================
// Includes
//

#include <stdio.h>

#include <aerospike/aerospike.h>
#include <aerospike/as_key.h>
#include <aerospike/as_operations.h>
#include <aerospike/as_record.h>
#include <xkeycheck.h>


//==========================================================
// Example Logging Macros
//

#define LOG(_fmt, ...) { printf(_fmt "\n", ##__VA_ARGS__); fflush(stdout); }

#ifdef SHOW_DETAIL
#define DETAIL(_fmt, ...) { printf(_fmt "\n", ##__VA_ARGS__); fflush(stdout); }
#else
#define DETAIL(_fmt, ...)
#endif


//==========================================================
// Example Namespace and Set
//

#define MAX_NAMESPACE_SIZE 32	// based on current server limit
#define MAX_SET_SIZE 64			// based on current server limit
#define MAX_HOST_SIZE 1024
#define MAX_KEY_STR_SIZE 1024

extern char g_namespace[MAX_NAMESPACE_SIZE];
extern char g_set[MAX_SET_SIZE];

//==========================================================
// Example Test Key (for basic single-key examples)
//
extern as_key g_key;

//==========================================================
// Example Test Key Count (for multiple-key examples)
//
extern uint32_t g_n_keys;
//------------------------------------------------
// The host info used by all basic examples.
// Obtained using command line options:
// -h <host name>
// -p <port>
//
extern char g_host[];
extern int g_port;

//------------------------------------------------
// The optional user/password.
// Obtained using command line options:
// -U <user name>
// -P [<password>]
//
extern char g_user[AS_USER_SIZE];
extern char g_password[AS_PASSWORD_SIZE];

//------------------------------------------------
// The (string) value of the test key used by all
// basic examples. From command line option:
// -k <key string>
//
extern char g_key_str[MAX_KEY_STR_SIZE];







//==========================================================
// Example Command Line Options
//

#define EXAMPLE_BASIC_OPTS 0
#define EXAMPLE_MULTI_KEY_OPTS 1

// Must be called first!
bool example_get_opts(int argc, char* argv[], int which_opts);


//==========================================================
// Example Utilities
//

bool example_create_event_loop();
void example_connect_to_aerospike(aerospike* p_as);
void example_connect_to_aerospike_with_udf_config(aerospike* p_as,
		const char* lua_user_path);
void example_cleanup(aerospike* p_as);
bool example_read_test_record(aerospike* p_as);
void example_remove_test_record(aerospike* p_as);
bool example_read_test_records(aerospike* p_as);
void example_remove_test_records(aerospike* p_as);
bool example_register_udf(aerospike* p_as, const char* filename);
bool example_remove_udf(aerospike* p_as, const char* filename);
bool example_create_integer_index(aerospike* p_as, const char* bin,
		const char* index);
bool example_create_2dsphere_index(aerospike* p_as, const char* bin,
		const char* index);
void example_remove_index(aerospike* p_as, const char* index);
void example_dump_record(const as_record* p_rec);
void example_dump_operations(const as_operations* p_ops);
int  example_handle_udf_error(as_error* err, const char* prefix);
