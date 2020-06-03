#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdint.h>

#define RIO_FLAG_READ_ERROR (1<<0)

struct _rio {
  size_t (*read)(struct _rio *, void *buf, size_t len);
  size_t processed_bytes;
  size_t max_processing_chunk;
  uint64_t flags;
  FILE *fp;
};

typedef struct _rio rio;

static inline size_t rdbRead(rio *r, void *buf, size_t len) {
  printf("%s\n", __func__);
  while (len) {
    size_t bytes_to_read = (r->max_processing_chunk && r->max_processing_chunk < len) ? r->max_processing_chunk : len;
    if (r->read(r, buf, bytes_to_read) == 0) {
      r->flags |= RIO_FLAG_READ_ERROR;
      return 0;
    }
    buf = (char*)buf + bytes_to_read;
    len -= bytes_to_read;
    r->processed_bytes += bytes_to_read;
  }
  return 1;
}

void rioInitWithFile(rio *r, FILE *fp);

#endif  // _FILE_H_
