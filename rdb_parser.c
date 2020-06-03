#include "./rdb_parser.h"
#include "./file.h"


int parse_rdb(const char* filepath) {
  printf("%s\n", __func__);

  // open file
  FILE *fp = fopen(filepath, "r");
  if (fp == NULL) {
    printf("%s open fail.\n", filepath);
  }

  rdbRead(NULL, NULL, 0);

  return 0;
}
