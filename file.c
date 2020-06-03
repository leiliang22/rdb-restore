#include "./file.h"

static size_t rioFileRead(rio *r, void *buf, size_t len) {
  return fread(buf, len, 1, r->fp);
}

static const rio rioFileIO = {
  rioFileRead,
  0,
  0,
  0,
  NULL
};

void rioInitWithFile(rio *r, FILE *fp) {
  *r = rioFileIO;
  r->fp = fp;
}
