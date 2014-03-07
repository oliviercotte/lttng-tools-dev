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

#ifndef MI_INTERNAL_H
#define MI_INTERNAL_H

// Strings related to command
const char * const mi_element_command;
const char * const mi_element_command_version;
const char * const mi_element_command_list;

// Strings related to command: version
const char * const mi_element_version_str;
const char * const mi_element_version_web;
const char * const mi_element_version_name;
const char * const mi_element_version_major;
const char * const mi_element_version_minor;
const char * const mi_element_version_license;
const char * const mi_element_version_patch_level;
const char * const mi_element_version_description;

// Strings related to command: list -k (kernel)
const char * const mi_element_list_kernel_event_tracepoint;
const char * const mi_element_list_kernel_event_function;
const char * const mi_element_list_kernel_event_probe;
const char * const mi_element_list_kernel_event_function_entry;
const char * const mi_element_list_kernel_event_syscall;
const char * const mi_element_list_kernel_event_noop;
const char * const mi_element_list_kernel_event_all;
const char * const mi_element_list_events_flag;
const char * const mi_element_list_event_flag;
const char * const mi_element_list_event_type;
const char * const mi_element_list_event_name;
const char * const mi_element_list_loglevel_type;
const char * const mi_element_list_loglevel;
const char * const mi_element_list_event_enabled;
const char * const mi_element_list_event_exclusion;
const char * const mi_element_list_event_filter;
const char * const mi_element_list_loglevel_str;
const char * const mi_element_list_event_enabled_str;
const char * const mi_element_list_event_exclusion_str;
const char * const mi_element_list_event_filter_str;
const char * const mi_element_list_event_addr;
const char * const mi_element_list_event_offset;
const char * const mi_element_list_event_symbol;


// Strings related to command: list -u (userspace)
const char * const mi_element_list_ust_jul_events;
const char * const mi_element_list_ust_curr_pid;
const char * const mi_element_list_ust_cmdline;

#endif /* MI_INTERNAL_H */
