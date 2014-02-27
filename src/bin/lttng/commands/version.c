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

#define _GNU_SOURCE
#include <popt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <config.h>

#include <common/config/config.h>

#include "../command.h"


static int opt_xml;

enum {
	OPT_HELP = 1,
	OPT_XML,
	OPT_LIST_OPTIONS,
};

static struct poptOption long_options[] = {
	/* longName, shortName, argInfo, argPtr, value, descrip, argDesc */
	{"xml",      'x', POPT_ARG_NONE, 0, OPT_XML, 0, 0},
	{"help",      'h', POPT_ARG_NONE, 0, OPT_HELP, 0, 0},
	{"list-options", 0, POPT_ARG_NONE, NULL, OPT_LIST_OPTIONS, NULL, NULL},
	{0, 0, 0, 0, 0, 0, 0}
};

/*
 * usage
 */
static void usage(FILE *ofp)
{
	fprintf(ofp, "usage: lttng version [OPTIONS]\n");
	fprintf(ofp, "\n");
	fprintf(ofp, "Options:\n");
	fprintf(ofp, "  -x, --xml                Xml output\n");
	fprintf(ofp, "  -h, --help               Show this help\n");
	fprintf(ofp, "      --list-options       Simple listing of options\n");
	fprintf(ofp, "\n");
}

static
int mi_version_print(struct config_writer *writer)
{
	int ret;

	ret = config_writer_write_element_string(writer,"versionStr",VERSION);
	if (ret) {
		goto end;
	}
	ret = config_writer_write_element_unsigned_int(writer,"majorNum",VERSION_MAJOR);
	if (ret) {
		goto end;
	}
	ret = config_writer_write_element_unsigned_int(writer,"minorNum",VERSION_MINOR);
	if (ret) {
		goto end;
	}
	ret = config_writer_write_element_unsigned_int(writer,"patchLevel",VERSION_PATCHLEVEL);
	if (ret) {
		goto end;
	}
	ret = config_writer_write_element_string(writer,"name",VERSION_NAME);
	if (ret) {
		goto end;
	}
	ret = config_writer_write_element_string(writer,"description",VERSION_DESCRIPTION);
	if (ret) {
		goto end;
	}

end:
	return ret;
}

/*
 *  cmd_version
 */
int cmd_version(int argc, const char **argv)
{
	int opt, ret = CMD_SUCCESS;
	static poptContext pc;
	struct config_writer *miWriter = NULL;

	pc = poptGetContext(NULL, argc, argv, long_options, 0);
	poptReadDefaultConfig(pc, 0);

	while ((opt = poptGetNextOpt(pc)) != -1) {
		switch (opt) {
		case OPT_HELP:
			usage(stdout);
			goto end;
		case OPT_LIST_OPTIONS:
			list_cmd_options(stdout, long_options);
			goto end;
		case OPT_XML:
			opt_xml = 1;
			break;
		default:
			usage(stderr);
			ret = CMD_UNDEFINED;
			goto end;
		}
	}

	/* Mi check */
	if (opt_xml) {
		miWriter = config_writer_create(fileno(stdout));
		if (!miWriter) {
			ret = LTTNG_ERR_NOMEM;
			goto end;
		}

		ret = config_writer_open_element(miWriter,"command");
		if (ret) {
			ret = LTTNG_ERR_MI_IO_FAIL;
			goto end;
		}

		ret = config_writer_write_element_string(miWriter,"name","version");
		if (ret) {
			ret = LTTNG_ERR_MI_IO_FAIL;
			goto end;
		}

		ret = config_writer_open_element(miWriter,"output");
		if (ret) {
			ret = LTTNG_ERR_MI_IO_FAIL;
			goto end;
		}

		ret = mi_version_print(miWriter);
		if (ret) {
			goto end;
		}

		/* output  */
		ret = config_writer_close_element(miWriter);
		if (ret) {
			ret = LTTNG_ERR_MI_IO_FAIL;
			goto end;
		}
		/* command  */
		ret = config_writer_close_element(miWriter);
		if (ret) {
			ret = LTTNG_ERR_MI_IO_FAIL;
			goto end;
		}

	} else {

		MSG("LTTng version " VERSION " - " VERSION_NAME);
		MSG("\n" VERSION_DESCRIPTION "\n");
		MSG("Web site: " PACKAGE_URL "\n");
		MSG("LTTng is free software and under the GPL license and part LGPL");
	}

end:
	if ( miWriter && config_writer_destroy(miWriter)) {
		/* Preserve original error code */
		ret = ret ? ret : LTTNG_ERR_MI_IO_FAIL;
	}
	poptFreeContext(pc);
	return ret;
}
