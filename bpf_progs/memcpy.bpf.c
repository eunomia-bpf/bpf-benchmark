unsigned long long bpf_main(char *mem) {
  char *p1 = mem;
  char *p2 = mem + (1 << 20);
  for (unsigned int i = 0; i < (1 << 20); i++) {
    p2[i] = p1[i];
  }
  return 0;
}
