/*
 * Copyright (C) 2014   - Jonathan Rajotte <jonathan.r.julien@gmail.com>
 *                      - Olivier Cotte <olivier.cotte@polymtl.ca>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License, version 2 only, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <common/config/config.h>
#include "mi-internal.h"
#include "mi.h"

/* Strings related to command */
const char * const mi_element_command                           = "command";
const char * const mi_element_command_version                   = "version";
const char * const mi_element_command_list                      = "list";

/* Strings related to command: version */
const char * const mi_element_version_str                       = "string";
const char * const mi_element_version_web                       = "url";
const char * const mi_element_version_name                      = "name";
const char * const mi_element_version_major                     = "major";
const char * const mi_element_version_minor                     = "minor";
const char * const mi_element_version_license                   = "license";
const char * const mi_element_version_patch_level               = "patchLevel";
const char * const mi_element_version_description               = "description";

/* Strings related to command: list */
const char * const mi_element_list_kernel_event_tracepoint      = "LTTNG_EVENT_TRACEPOINT";
const char * const mi_element_list_kernel_event_function        = "LTTNG_EVENT_FUNCTION";
const char * const mi_element_list_kernel_event_probe           = "LTTNG_EVENT_PROBE";
const char * const mi_element_list_kernel_event_function_entry  = "LTTNG_EVENT_FUNCTION_ENTRY";
const char * const mi_element_list_kernel_event_syscall         = "LTTNG_EVENT_SYSCALL";
const char * const mi_element_list_kernel_event_noop            = "LTTNG_EVENT_NOOP";
const char * const mi_element_list_kernel_event_all             = "LTTNG_EVENT_ALL";
const char * const mi_element_list_event_type                   = "type";
const char * const mi_element_list_event_name                   = "name";
const char * const mi_element_list_loglevel_type                = "loglevel_type";
const char * const mi_element_list_loglevel                     = "loglevel";
const char * const mi_element_list_event_enabled                = "enabled";
const char * const mi_element_list_event_exclusion              = "exclusion";
const char * const mi_element_list_event_filter                 = "filter";
const char * const mi_element_list_loglevel_str                 = "loglevel_string";
const char * const mi_element_list_event_enabled_str            = "enabled_string";
const char * const mi_element_list_event_exclusion_str          = "exclusion_string";
const char * const mi_element_list_event_filter_str             = "filter_string";
const char * const mi_element_list_event_addr                   = "addr";
const char * const mi_element_list_event_offset                 = "offset";
const char * const mi_element_list_event_symbol                 = "symbol";

const char * const mi_element_list_ust_jul_events               = "jul_events";
const char * const mi_element_list_ust_curr_pid                 = "curr_pid";
const char * const mi_element_list_ust_cmdline                  = "cmdline";

LTTNG_HIDDEN
mi_writer *mi_writer_create(int fd_output)
{
    return config_writer_create(fd_output);
}

LTTNG_HIDDEN
int mi_writer_destroy(mi_writer *writer)
{
    return config_writer_destroy(writer);
}

LTTNG_HIDDEN
int mi_writer_command_open(mi_writer *writer, const char* command)
{
    int ret;
    ret = mi_writer_open_element(writer, mi_element_command);
    if (ret) {
        goto end;
    }
    ret = mi_writer_open_element(writer, command);
end:
    return ret;
}

LTTNG_HIDDEN
int mi_writer_command_close(mi_writer *writer)
{
    return mi_writer_close_element(writer);
}

LTTNG_HIDDEN
int mi_writer_open_element(mi_writer *writer,
		const char *element_name)
{
    return config_writer_open_element(writer, element_name);
}

LTTNG_HIDDEN
int mi_writer_close_element(mi_writer *writer)
{
    return config_writer_close_element(writer);
}

LTTNG_HIDDEN
int mi_writer_write_element_unsigned_int(mi_writer *writer,
		const char *element_name, uint64_t value)
{
    return config_writer_write_element_unsigned_int(writer, element_name, value);
}

LTTNG_HIDDEN
int mi_writer_write_element_signed_int(mi_writer *writer,
		const char *element_name, int64_t value)
{
    return config_writer_write_element_signed_int(writer, element_name, value);
}

LTTNG_HIDDEN
int mi_writer_write_element_bool(mi_writer *writer,
		const char *element_name, int value)
{
    return config_writer_write_element_bool(writer, element_name, value);
}

LTTNG_HIDDEN
int mi_writer_write_element_string(mi_writer *writer,
		const char *element_name, const char *value)
{
    return config_writer_write_element_string(writer, element_name, value);
}

