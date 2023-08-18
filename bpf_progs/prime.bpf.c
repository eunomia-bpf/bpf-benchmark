int main() {
  long cnt = 0;
  for (int i = 1; i < 1e4; i++) {
    int ok = 1;
    for (int j = 1; j * j <= i && ok; j++) {
      if (i % j == 0)
        ok = 0;
    }
    cnt += ok;
  }
  return cnt;
}
