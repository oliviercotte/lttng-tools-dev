/*
 * Copyright (C) 2014 - Jérémie Galarneau <jeremie.galarneau@efficios.com>
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

#define _GNU_SOURCE
#include <inttypes.h>
#include <popt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <common/config/config.h>
#include "../command.h"

static char *opt_input_path;
static char *opt_session_name;
static int opt_force;
static int opt_load_all;

enum {
	OPT_HELP = 1,
	OPT_ALL,
	OPT_FORCE,
};

static struct poptOption load_opts[] = {
	/* longName, shortName, argInfo, argPtr, value, descrip, argDesc */
	{"help",        'h',  POPT_ARG_NONE, 0, OPT_HELP, 0, 0},
	{"all",         'a',  POPT_ARG_NONE, 0, OPT_ALL, 0, 0},
	{"session",     's',  POPT_ARG_STRING, &opt_session_name, 0, 0, 0},
	{"input-path",  'i',  POPT_ARG_STRING, &opt_input_path, 0, 0, 0},
	{"force",       'f',  POPT_ARG_NONE, 0, OPT_FORCE, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};

/*
 * usage
 */
static void usage(FILE *ofp)
{
	fprintf(ofp, "usage: lttng load [OPTIONS]\n");
	fprintf(ofp, "\n");
	fprintf(ofp, "Options:\n");
	fprintf(ofp, "  -h, --help           Show this help\n");
	fprintf(ofp, "  -a, --all            Load all sessions (default)\n");
	fprintf(ofp, "  -s, --session        Load a specific session\n");
	fprintf(ofp, "  -i, --input-path     Input path of the session configuration(s)\n");
	fprintf(ofp, "  -f, --force          Override existing session configuration(s)\n");
}

/*
 * The 'load <options>' first level command
 */
int cmd_load(int argc, const char **argv)
{
	int ret = CMD_SUCCESS;
	int opt;
	poptContext pc;

	pc = poptGetContext(NULL, argc, argv, load_opts, 0);
	poptReadDefaultConfig(pc, 0);

	while ((opt = poptGetNextOpt(pc)) != -1) {
		switch (opt) {
		case OPT_HELP:
			usage(stdout);
			goto end;
		case OPT_ALL:
			opt_load_all = 1;
			break;
		case OPT_FORCE:
			opt_force = 1;
			break;
		default:
			usage(stderr);
			ret = CMD_UNDEFINED;
			goto end;
		}
	}

	if (opt_session_name && opt_load_all) {
		WARN("Conflicting session options, loading session %s",
			opt_session_name);
	}

	ret = config_load_session(opt_input_path, opt_session_name, opt_force);
	if (ret) {
		ret = CMD_ERROR;
	}
end:
	poptFreeContext(pc);
	return ret;
}
