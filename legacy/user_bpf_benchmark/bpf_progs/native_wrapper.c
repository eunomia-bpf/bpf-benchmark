#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
uint64_t get_time_ns() {
  struct timespec ts;
  int err = clock_gettime(CLOCK_MONOTONIC, &ts);
  assert(err == 0);
  return (uint64_t)ts.tv_sec * 1000000000 + (uint64_t)ts.tv_nsec;
}

extern uint64_t bpf_main(void *);
int main(int argc, const char **argv) {
  void *memory = NULL;
  if (argc == 2) {
    FILE *fp = fopen(argv[1], "r");
    assert(fp != NULL);
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    memory = malloc(file_size);
    fread(memory, 1, file_size, fp);
  }
  uint64_t start = get_time_ns();
  uint64_t ret = bpf_main(memory);
  uint64_t end = get_time_ns();
  printf("0 %" PRIu64 " %" PRIu64 "\n", end - start, ret);
  free(memory);
  return 0;
}
