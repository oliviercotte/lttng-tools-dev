/*
 * Copyright (C) 2011 - David Goulet <david.goulet@polymtl.ca>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2 only,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _LTTNG_CMD_H
#define _LTTNG_CMD_H

#include <lttng/lttng.h>
#include <common/common.h>
#include <common/defaults.h>

#include "conf.h"
#include "utils.h"

enum cmd_error_code {
	CMD_SUCCESS = 0,
	CMD_ERROR,
	CMD_UNDEFINED,
	CMD_FATAL,
	CMD_WARNING,
	CMD_UNSUPPORTED,
};

struct cmd_struct {
	const char *name;
	int (*func)(int argc, const char **argv);
};

extern int cmd_list(int argc, const char **argv);
extern int cmd_create(int argc, const char **argv);
extern int cmd_destroy(int argc, const char **argv);
extern int cmd_start(int argc, const char **argv);
extern int cmd_stop(int argc, const char **argv);
extern int cmd_enable_events(int argc, const char **argv);
extern int cmd_disable_events(int argc, const char **argv);
extern int cmd_enable_channels(int argc, const char **argv);
extern int cmd_disable_channels(int argc, const char **argv);
extern int cmd_add_context(int argc, const char **argv);
extern int cmd_set_session(int argc, const char **argv);
extern int cmd_version(int argc, const char **argv);
extern int cmd_calibrate(int argc, const char **argv);
extern int cmd_view(int argc, const char **argv);
extern int cmd_enable_consumer(int argc, const char **argv);
extern int cmd_disable_consumer(int argc, const char **argv);
extern int cmd_snapshot(int argc, const char **argv);
extern int cmd_save(int argc, const char **argv);

#endif /* _LTTNG_CMD_H */
