# bpftrace Real End-to-End Benchmark

- Generated: `2026-04-29T10:42:34.725896+00:00`
- Duration per phase: `5s`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Error: `tcplife baseline failed: daemon session exited early (rc=1); biosnoop baseline failed: daemon session exited early (rc=1); runqlat baseline failed: daemon session exited early (rc=1); tcpretrans baseline failed: daemon session exited early (rc=1); capable baseline failed: daemon session exited early (rc=1); vfsstat baseline failed: daemon session exited early (rc=1)`

## tcplife

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "PID   COMM       LADDR           LPORT RADDR           RPORT TX_KB RX_KB MS\n10508 stress-ng- 127.0.0.1       55642 127.0.0.1       22087      0 408328 34\n10508 stress-ng- 127.0.0.1       22087 127.0.0.1       55642  408328     0 34"
}
```

## biosnoop

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "10393        7     0        fio              10551        2\n10393        7     0        fio              10551        2\n10394        7     0        fio              10551        2\n10394        7     0        fio              10551        2\n10394        7     0        fio              10551        2\n10394        7     0        fio              10551        3\n10394        7     0        fio              10551        3\n10395        7     0        fio              10551        3\n10395        7     0        fio              10551        3\n10395        7     0        fio              10551        3\n10395        7     0        fio              10551        3\n10395        7     0        fio              10551        4\n10395        7     0        fio              10551        1\n10410        7     0        fio              10546        0\n10411        7     0        fio              10546        0\n10413        7     0        fio              10546        1\n10415        7     0        fio              10546        2\n10416        7     0        fio              10546        0\n10416        7     0        fio              10546        0\n10416        7     0        fio              10546        0\n10417        7     0        fio              10546        1\n10417        7     0        fio              10546        0\n10417        7     0        fio              10546        0\n10417        7     0        fio              10546        0\n10418        7     0        fio              10546        0\n10421        7     0        fio              10546        2\n10421        7     0        fio              10546        0\n10422        7     0        fio              10546        0\n10422        7     0        fio              10546        0\n10423        7     0        fio              10546        0\n10425        7     0        fio              10546        2\n10426        7     0        fio              10546        0\n10427        7     0        fio              10546        0\n10429        7     0        fio              10546        2\n10429        7     0        fio              10546        0\n10429        7     0        fio              10546        0\n10430        7     0        fio              10546        0\n10430        7     0        fio              10546        0\n10430        7     0        fio              10546        0\n10430        7     0        fio              10546        0"
}
```

## runqlat

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "Tracing CPU scheduler... Hit Ctrl-C to end.\n@usecs:\n[0]                 4249 |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n[1]                   58 |                                                    |\n[2, 4)               448 |@@@@@                                               |\n[4, 8)               118 |@                                                   |\n[8, 16)              271 |@@@                                                 |\n[16, 32)             140 |@                                                   |\n[32, 64)             116 |@                                                   |\n[64, 128)            105 |@                                                   |\n[128, 256)            26 |                                                    |\n[256, 512)             2 |                                                    |\n[512, 1K)              5 |                                                    |\n[1K, 2K)               2 |                                                    |\n[2K, 4K)               1 |                                                    |"
}
```

## tcpretrans

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "Tracing tcp retransmits. Hit Ctrl-C to end.\nTIME     PID               LADDR:LPORT           RADDR:RPORT  STATE"
}
```

## capable

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "10:42:15  0      12190  stress-ng        21   CAP_SYS_ADMIN        2\n10:42:15  0      12190  stress-ng        21   CAP_SYS_ADMIN        2\n10:42:15  0      12190  stress-ng        21   CAP_SYS_ADMIN        2\n10:42:15  0      12190  stress-ng        21   CAP_SYS_ADMIN        2\n10:42:15  0      12190  stress-ng        21   CAP_SYS_ADMIN        2\n10:42:15  0      12190  stress-ng        21   CAP_SYS_ADMIN        2\n10:42:15  0      12191  stress-ng-timer  24   CAP_SYS_RESOURCE     2\n10:42:15  0      12191  stress-ng-timer  21   CAP_SYS_ADMIN        0\n10:42:15  0      12191  stress-ng-timer  21   CAP_SYS_ADMIN        0\n10:42:15  0      12191  stress-ng-timer  21   CAP_SYS_ADMIN        0\n10:42:15  0      12191  stress-ng-timer  21   CAP_SYS_ADMIN        0\n10:42:15  0      12192  python3          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        2\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        0\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        0\n10:42:15  0      12192  bpftool          39   CAP_BPF              0\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        0\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        0\n10:42:15  0      12192  bpftool          39   CAP_BPF              0\n10:42:15  0      12192  bpftool          39   CAP_BPF              0\n10:42:15  0      12192  bpftool          39   CAP_BPF              0\n10:42:15  0      12192  bpftool          39   CAP_BPF              0\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        0\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        0\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        0\n10:42:15  0      12192  bpftool          21   CAP_SYS_ADMIN        0"
}
```

## vfsstat

### Baseline

```json
{
  "measurement": null,
  "phase": "baseline",
  "reason": "daemon session exited early (rc=1)",
  "status": "error"
}
```

### Post-ReJIT

```json
null
```

### ReJIT Result

```json
null
```

### Process Output

```json
{
  "returncode": 0,
  "stderr_tail": "",
  "stdout_tail": "@[vfs_open]: 11781\n10:42:24\n@[vfs_write]: 162\n10:42:25\n@[vfs_read]: 1\n@[vfs_write]: 1\n10:42:26\n@[vfs_read]: 1\n@[vfs_write]: 1\n10:42:27\n@[vfs_write]: 2\n@[vfs_read]: 3\n10:42:28\n@[vfs_readv]: 1\n@[vfs_writev]: 1\n@[vfs_create]: 1\n@[vfs_fsync]: 2\n@[vfs_write]: 183\n@[vfs_read]: 1518\n@[vfs_open]: 2733\n10:42:29\n@[vfs_create]: 30\n@[vfs_write]: 34\n@[vfs_read]: 39\n@[vfs_open]: 112\n10:42:30\n@[vfs_create]: 25\n@[vfs_write]: 29\n@[vfs_read]: 37\n@[vfs_open]: 98\n10:42:31\n@[vfs_create]: 21\n@[vfs_write]: 22\n@[vfs_read]: 28\n@[vfs_open]: 78\n10:42:32\n@[vfs_create]: 22\n@[vfs_write]: 23\n@[vfs_read]: 30\n@[vfs_open]: 84"
}
```

