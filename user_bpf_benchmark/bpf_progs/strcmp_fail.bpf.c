long long bpf_main(const char *buf) {
  const char *p1 = buf;
  const char *p2 = buf + (1 << 20);
  while (*p1 && (*p1 == *p2)) {
    p1++;
    p2++;
  }
  return *p1 - *p2;
}
