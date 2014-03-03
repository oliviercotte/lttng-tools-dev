

#include <common/config/config.h>
#include "mi.h"

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

