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

#ifndef _MI_H
#define _MI_H

#include <common/config/config.h>
#include <common/error.h>
#include <common/macros.h>
#include <stdint.h>

/* Instance of a machine interface writer. */
typedef struct config_writer mi_writer;

/*
 * Create an instance of a machine interface writer.
 *
 * fd_output File to which the XML content must be written. The file will be
 * closed once the mi_writer has been destroyed.
 *
 * Returns an instance of a machine interface writer on success, NULL on
 * error.
 */
LTTNG_HIDDEN
mi_writer *mi_writer_create(int fd_output);

/*
 * Destroy an instance of a configuration writer.
 *
 * writer An instance of a configuration writer.
 *
 * Returns zero if the XML document could be closed cleanly. Negative values
 * indicate an error.
 */
LTTNG_HIDDEN
int mi_writer_destroy(mi_writer *writer);


LTTNG_HIDDEN
int mi_writer_command_open(mi_writer *writer, const char* command);

LTTNG_HIDDEN
int mi_writer_command_close(mi_writer *writer);

/*
 * Open an element tag.
 *
 * writer An instance of a configuration writer.
 *
 * element_name Element tag name.
 *
 * Returns zero if the XML document could be closed cleanly.
 * Negative values indicate an error.
 */
LTTNG_HIDDEN
int mi_writer_open_element(mi_writer *writer,
		const char *element_name);

/*
 * Close the current element tag.
 *
 * writer An instance of a configuration writer.
 *
 * Returns zero if the XML document could be closed cleanly.
 * Negative values indicate an error.
 */
LTTNG_HIDDEN
int mi_writer_close_element(mi_writer *writer);

/*
 * Write an element of type unsigned int.
 *
 * writer An instance of a configuration writer.
 *
 * element_name Element name.
 *
 * value Unsigned int value of the element
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
LTTNG_HIDDEN
int mi_writer_write_element_unsigned_int(mi_writer *writer,
		const char *element_name, uint64_t value);

/*
 * Write an element of type signed int.
 *
 * writer An instance of a configuration writer.
 *
 * element_name Element name.
 *
 * value Signed int value of the element
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
LTTNG_HIDDEN
int mi_writer_write_element_signed_int(mi_writer *writer,
		const char *element_name, int64_t value);

/*
 * Write an element of type boolean.
 *
 * writer An instance of a configuration writer.
 *
 * element_name Element name.
 *
 * value Boolean value of the element
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
LTTNG_HIDDEN
int mi_writer_write_element_bool(mi_writer *writer,
		const char *element_name, int value);

/*
 * Write an element of type string.
 *
 * writer An instance of a configuration writer.
 *
 * element_name Element name.
 *
 * value String value of the element
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
LTTNG_HIDDEN
int mi_writer_write_element_string(mi_writer *writer,
		const char *element_name, const char *value);


#endif /* _MI_H */
