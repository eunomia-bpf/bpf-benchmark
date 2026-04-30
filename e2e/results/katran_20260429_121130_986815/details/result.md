# Katran End-to-End Benchmark

```json
{
  "baseline": {
    "measurement": {
      "bpf": {
        "3246": {
          "avg_ns_per_run": 218.8599442586399,
          "bytes_jited": 176,
          "bytes_xlated": 136,
          "id": 3246,
          "name": "xdp_root",
          "run_cnt_delta": 269100,
          "run_time_ns_delta": 58895211,
          "type": "xdp"
        },
        "3252": {
          "avg_ns_per_run": null,
          "bytes_jited": 13629,
          "bytes_xlated": 23840,
          "id": 3252,
          "name": "balancer_ingress",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "xdp"
        },
        "3254": {
          "avg_ns_per_run": null,
          "bytes_jited": 541,
          "bytes_xlated": 1000,
          "id": 3254,
          "name": "healthcheck_encap",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "sched_cls"
        }
      },
      "duration_s": 5,
      "metric": "ops/s",
      "throughput": 8968.65296393022
    },
    "phase": "baseline",
    "reason": "",
    "status": "ok"
  },
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "duration_s": 5,
  "error_message": "prog 3246: bpfverify --verifier-states-out failed for prog 3246: subprocess \"bpfverify\" \"--prog-type\" \"xdp\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/verified_original.bin\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/verifier_states.json\" failed: func#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: .1....6... (18) r2 = 0xffff8d943924c400\n      3: .12...6... (b7) r3 = 0\n      4: .123..6... (85) call bpf_tail_call#12\n      5: ......6... (bf) r1 = r6\n      6: .1....6... (18) r2 = 0xffff8d943924c400\n      8: .12...6... (b7) r3 = 1\n      9: .123..6... (85) call bpf_tail_call#12\n     10: ......6... (bf) r1 = r6\n     11: .1........ (18) r2 = 0xffff8d943924c400\n     13: .12....... (b7) r3 = 2\n     14: .123...... (85) call bpf_tail_call#12\n     15: .......... (b7) r0 = 2\n     16: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (bf) r6 = r1                       ; R1=ctx() R6=ctx()\n1: (18) r2 = 0xffff8d943924c400       ; R2=map_ptr(map=root_array,ks=4,vs=4)\n3: (b7) r3 = 0                        ; R3=0; prog 3252: bpfverify --verifier-states-out failed for prog 3252: subprocess \"bpfverify\" \"--prog-type\" \"xdp\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/verified_original.bin\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/verifier_states.json\" failed: lar() fp-96=????mm0 fp-104=scalar(id=1591) fp-112=scalar(id=1592) fp-120=mmmmmmmm fp-128=mmmmscalar(smin=smin32=0,smax=umax=smax32=umax32=3,var_off=(0x0; 0x3)) fp-136=mmmm???? fp-144=pkt_end() fp-152=Pscalar(smin=smin32=0,smax=umax=smax32=umax32=0xffff,var_off=(0x0; 0xffff)) fp-160=map_value(map=vip_map,ks=20,vs=8) fp-168=map_ptr(map=fallback_cache,ks=40,vs=16) fp-176=map_value(map=stats,ks=4,vs=16) fp-184=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\nmark_precise: frame0: last_idx 1041 first_idx 1032 subseq_idx 1042 \nmark_precise: frame0: regs=r7 stack=-152 before 1041: (85) call bpf_map_lookup_elem#1\nmark_precise: frame0: regs=r7 stack=-152 before 1039: (18) r1 = 0xffffcff7cb0d5000\nmark_precise: frame0: regs=r7 stack=-152 before 1038: (07) r2 += -32\nmark_precise: frame0: regs=r7 stack=-152 before 1037: (bf) r2 = r10\nmark_precise: frame0: regs=r7 stack=-152 before 1036: (63) *(u32 *)(r10 -32) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1035: (63) *(u32 *)(r10 -48) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1034: (61) r1 = *(u32 *)(r0 +0)\nmark_precise: frame0: regs=r7 stack=-152 before 1033: (7b) *(u64 *)(r0 +8) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1032: (2d) if r3 > r2 goto pc+10\nmark_precise: frame0: parent state regs=r7 stack=-152:  R0=map_value(map=fallback_cache,ks=40,vs=16) R1=scalar() R2=0x6fc23ac00 R3=scalar() R6=ctx() R7=P0 R8=0 R9=scalar() R10=fp0 fp-32=????523 fp-48=mmmmmmmm fp-56=mmmm000 fp-64=scalar(id=1591) fp-72=scalar(id=1592) fp-80=scalar() fp-88=scalar() fp-96=????mm0 fp-104=scalar(id=1591) fp-112=scalar(id=1592) fp-120=mmmmmmmm fp-128=mmmmscalar(smin=smin32=0,smax=umax=smax32=umax32=3,var_off=(0x0; 0x3)) fp-136=mmmm???? fp-144=pkt_end() fp-152=Pscalar(smin=smin32=0,smax=umax=smax32=umax32=0xffff,var_off=(0x0; 0xffff)) fp-160=map_value(map=vip_map,ks=20,vs=8) fp-168=map_ptr(map=fallback_cache,ks=40,vs=16) fp-176=map_value(map=stats,ks=4,vs=16) fp-184=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\nmark_precise: frame0: last_idx 1031 first_idx 1019 subseq_idx 1032 \nmark_precise: frame0: regs=r7 stack=-152 before 1031: (b7) r8 = 0\nmark_precise: frame0: regs=r7 stack=-152 before 1029: (18) r2 = 0x6fc23ac00\nmark_precise: frame0: regs=r7 stack=-152 before 1028: (1f) r3 -= r2\nmark_precise: frame0: regs=r7 stack=-152 before 1027: (bf) r3 = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1026: (79) r2 = *(u64 *)(r0 +8)\nmark_precise: frame0: regs=r7 stack=-152 before 1025: (bf) r0 = r8\nmark_precise: frame0: regs=r7 stack=-152 before 1024: (bf) r1 = r0; prog 3254: bpfverify final verification failed for prog 3254: subprocess \"bpfverify\" \"--prog-type\" \"sched_cls\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
  "generated_at": "2026-04-29T12:11:51.347163+00:00",
  "host": {
    "git_sha": null,
    "git_sha_error": "[Errno 2] No such file or directory: 'git'",
    "hostname": "virtme-ng",
    "kernel": "7.0.0-rc2",
    "platform": "Linux-7.0.0-rc2-x86_64-with-glibc2.39",
    "python": "3.12.3"
  },
  "post_rejit": {
    "measurement": {
      "bpf": {
        "3246": {
          "avg_ns_per_run": 219.7889999588322,
          "bytes_jited": 176,
          "bytes_xlated": 136,
          "id": 3246,
          "name": "xdp_root",
          "run_cnt_delta": 267199,
          "run_time_ns_delta": 58727401,
          "type": "xdp"
        },
        "3252": {
          "avg_ns_per_run": null,
          "bytes_jited": 13629,
          "bytes_xlated": 23840,
          "id": 3252,
          "name": "balancer_ingress",
          "run_cnt_delta": 0,
          "run_time_ns_delta": 0,
          "type": "xdp"
        },
        "3254": {
          "avg_ns_per_run": 263.0,
          "bytes_jited": 541,
          "bytes_xlated": 1000,
          "id": 3254,
          "name": "healthcheck_encap",
          "run_cnt_delta": 1,
          "run_time_ns_delta": 263,
          "type": "sched_cls"
        }
      },
      "duration_s": 5,
      "metric": "ops/s",
      "throughput": 8905.436552803783
    },
    "phase": "post_rejit",
    "reason": "prog 3246: bpfverify --verifier-states-out failed for prog 3246: subprocess \"bpfverify\" \"--prog-type\" \"xdp\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/verified_original.bin\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/verifier_states.json\" failed: func#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: .1....6... (18) r2 = 0xffff8d943924c400\n      3: .12...6... (b7) r3 = 0\n      4: .123..6... (85) call bpf_tail_call#12\n      5: ......6... (bf) r1 = r6\n      6: .1....6... (18) r2 = 0xffff8d943924c400\n      8: .12...6... (b7) r3 = 1\n      9: .123..6... (85) call bpf_tail_call#12\n     10: ......6... (bf) r1 = r6\n     11: .1........ (18) r2 = 0xffff8d943924c400\n     13: .12....... (b7) r3 = 2\n     14: .123...... (85) call bpf_tail_call#12\n     15: .......... (b7) r0 = 2\n     16: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (bf) r6 = r1                       ; R1=ctx() R6=ctx()\n1: (18) r2 = 0xffff8d943924c400       ; R2=map_ptr(map=root_array,ks=4,vs=4)\n3: (b7) r3 = 0                        ; R3=0; prog 3252: bpfverify --verifier-states-out failed for prog 3252: subprocess \"bpfverify\" \"--prog-type\" \"xdp\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/verified_original.bin\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/verifier_states.json\" failed: lar() fp-96=????mm0 fp-104=scalar(id=1591) fp-112=scalar(id=1592) fp-120=mmmmmmmm fp-128=mmmmscalar(smin=smin32=0,smax=umax=smax32=umax32=3,var_off=(0x0; 0x3)) fp-136=mmmm???? fp-144=pkt_end() fp-152=Pscalar(smin=smin32=0,smax=umax=smax32=umax32=0xffff,var_off=(0x0; 0xffff)) fp-160=map_value(map=vip_map,ks=20,vs=8) fp-168=map_ptr(map=fallback_cache,ks=40,vs=16) fp-176=map_value(map=stats,ks=4,vs=16) fp-184=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\nmark_precise: frame0: last_idx 1041 first_idx 1032 subseq_idx 1042 \nmark_precise: frame0: regs=r7 stack=-152 before 1041: (85) call bpf_map_lookup_elem#1\nmark_precise: frame0: regs=r7 stack=-152 before 1039: (18) r1 = 0xffffcff7cb0d5000\nmark_precise: frame0: regs=r7 stack=-152 before 1038: (07) r2 += -32\nmark_precise: frame0: regs=r7 stack=-152 before 1037: (bf) r2 = r10\nmark_precise: frame0: regs=r7 stack=-152 before 1036: (63) *(u32 *)(r10 -32) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1035: (63) *(u32 *)(r10 -48) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1034: (61) r1 = *(u32 *)(r0 +0)\nmark_precise: frame0: regs=r7 stack=-152 before 1033: (7b) *(u64 *)(r0 +8) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1032: (2d) if r3 > r2 goto pc+10\nmark_precise: frame0: parent state regs=r7 stack=-152:  R0=map_value(map=fallback_cache,ks=40,vs=16) R1=scalar() R2=0x6fc23ac00 R3=scalar() R6=ctx() R7=P0 R8=0 R9=scalar() R10=fp0 fp-32=????523 fp-48=mmmmmmmm fp-56=mmmm000 fp-64=scalar(id=1591) fp-72=scalar(id=1592) fp-80=scalar() fp-88=scalar() fp-96=????mm0 fp-104=scalar(id=1591) fp-112=scalar(id=1592) fp-120=mmmmmmmm fp-128=mmmmscalar(smin=smin32=0,smax=umax=smax32=umax32=3,var_off=(0x0; 0x3)) fp-136=mmmm???? fp-144=pkt_end() fp-152=Pscalar(smin=smin32=0,smax=umax=smax32=umax32=0xffff,var_off=(0x0; 0xffff)) fp-160=map_value(map=vip_map,ks=20,vs=8) fp-168=map_ptr(map=fallback_cache,ks=40,vs=16) fp-176=map_value(map=stats,ks=4,vs=16) fp-184=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\nmark_precise: frame0: last_idx 1031 first_idx 1019 subseq_idx 1032 \nmark_precise: frame0: regs=r7 stack=-152 before 1031: (b7) r8 = 0\nmark_precise: frame0: regs=r7 stack=-152 before 1029: (18) r2 = 0x6fc23ac00\nmark_precise: frame0: regs=r7 stack=-152 before 1028: (1f) r3 -= r2\nmark_precise: frame0: regs=r7 stack=-152 before 1027: (bf) r3 = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1026: (79) r2 = *(u64 *)(r0 +8)\nmark_precise: frame0: regs=r7 stack=-152 before 1025: (bf) r0 = r8\nmark_precise: frame0: regs=r7 stack=-152 before 1024: (bf) r1 = r0; prog 3254: bpfverify final verification failed for prog 3254: subprocess \"bpfverify\" \"--prog-type\" \"sched_cls\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
    "status": "error"
  },
  "process": {
    "returncode": -2,
    "stderr_tail": "I20260429 12:11:31.839987 31282 KatranGrpcService.cpp:69] Starting Katran\nE20260429 12:11:31.841341 31282 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260429 12:11:31.841347 31282 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260429 12:11:31.842790 31282 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260429 12:11:31.842794 31282 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260429 12:11:31.842938 31282 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(21) .eh_frame\nE20260429 12:11:31.842942 31282 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(22) .rel.eh_frame for section(21) .eh_frame\nE20260429 12:11:31.893643 31282 BaseBpfAdapter.cpp:144] libbpf: elf: skipping unrecognized data section(20) .eh_frame\nE20260429 12:11:31.893690 31282 BaseBpfAdapter.cpp:144] libbpf: elf: skipping relo section(21) .rel.eh_frame for section(20) .eh_frame",
    "stdout_tail": ""
  },
  "programs": [
    {
      "btf_id": 3639,
      "bytes_jited": 176,
      "bytes_memlock": 4096,
      "bytes_xlated": 136,
      "gpl_compatible": true,
      "id": 3246,
      "jited": true,
      "loaded_at": 1777464691,
      "map_ids": [
        3829
      ],
      "name": "xdp_root",
      "orphaned": false,
      "run_cnt": 5,
      "run_time_ns": 4002,
      "tag": "379b2b6068914ad4",
      "type": "xdp",
      "uid": 0
    },
    {
      "btf_id": 3650,
      "bytes_jited": 13629,
      "bytes_memlock": 24576,
      "bytes_xlated": 23840,
      "gpl_compatible": true,
      "id": 3252,
      "jited": true,
      "loaded_at": 1777464691,
      "map_ids": [
        3831,
        3833,
        3835,
        3834,
        3841,
        3846,
        3837,
        3848,
        3832,
        3838,
        3836,
        3840,
        3839,
        3844
      ],
      "name": "balancer_ingress",
      "orphaned": false,
      "tag": "90e1a12c30a4bce5",
      "type": "xdp",
      "uid": 0
    },
    {
      "btf_id": 3651,
      "bytes_jited": 541,
      "bytes_memlock": 4096,
      "bytes_xlated": 1000,
      "gpl_compatible": true,
      "id": 3254,
      "jited": true,
      "loaded_at": 1777464691,
      "map_ids": [
        3849,
        3850,
        3851
      ],
      "name": "healthcheck_encap",
      "orphaned": false,
      "run_cnt": 5,
      "run_time_ns": 5292,
      "tag": "3c65776e77a1eec5",
      "type": "sched_cls",
      "uid": 0
    }
  ],
  "rejit_result": {
    "applied": false,
    "changed": false,
    "enabled_passes": [
      "wide_mem",
      "rotate",
      "cond_select",
      "extract",
      "endian_fusion",
      "map_inline",
      "const_prop",
      "dce",
      "bounds_check_merge",
      "skb_load_bytes_spec",
      "bulk_memory"
    ],
    "error": "prog 3246: bpfverify --verifier-states-out failed for prog 3246: subprocess \"bpfverify\" \"--prog-type\" \"xdp\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/verified_original.bin\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/verifier_states.json\" failed: func#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: .1....6... (18) r2 = 0xffff8d943924c400\n      3: .12...6... (b7) r3 = 0\n      4: .123..6... (85) call bpf_tail_call#12\n      5: ......6... (bf) r1 = r6\n      6: .1....6... (18) r2 = 0xffff8d943924c400\n      8: .12...6... (b7) r3 = 1\n      9: .123..6... (85) call bpf_tail_call#12\n     10: ......6... (bf) r1 = r6\n     11: .1........ (18) r2 = 0xffff8d943924c400\n     13: .12....... (b7) r3 = 2\n     14: .123...... (85) call bpf_tail_call#12\n     15: .......... (b7) r0 = 2\n     16: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (bf) r6 = r1                       ; R1=ctx() R6=ctx()\n1: (18) r2 = 0xffff8d943924c400       ; R2=map_ptr(map=root_array,ks=4,vs=4)\n3: (b7) r3 = 0                        ; R3=0; prog 3252: bpfverify --verifier-states-out failed for prog 3252: subprocess \"bpfverify\" \"--prog-type\" \"xdp\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/verified_original.bin\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/verifier_states.json\" failed: lar() fp-96=????mm0 fp-104=scalar(id=1591) fp-112=scalar(id=1592) fp-120=mmmmmmmm fp-128=mmmmscalar(smin=smin32=0,smax=umax=smax32=umax32=3,var_off=(0x0; 0x3)) fp-136=mmmm???? fp-144=pkt_end() fp-152=Pscalar(smin=smin32=0,smax=umax=smax32=umax32=0xffff,var_off=(0x0; 0xffff)) fp-160=map_value(map=vip_map,ks=20,vs=8) fp-168=map_ptr(map=fallback_cache,ks=40,vs=16) fp-176=map_value(map=stats,ks=4,vs=16) fp-184=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\nmark_precise: frame0: last_idx 1041 first_idx 1032 subseq_idx 1042 \nmark_precise: frame0: regs=r7 stack=-152 before 1041: (85) call bpf_map_lookup_elem#1\nmark_precise: frame0: regs=r7 stack=-152 before 1039: (18) r1 = 0xffffcff7cb0d5000\nmark_precise: frame0: regs=r7 stack=-152 before 1038: (07) r2 += -32\nmark_precise: frame0: regs=r7 stack=-152 before 1037: (bf) r2 = r10\nmark_precise: frame0: regs=r7 stack=-152 before 1036: (63) *(u32 *)(r10 -32) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1035: (63) *(u32 *)(r10 -48) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1034: (61) r1 = *(u32 *)(r0 +0)\nmark_precise: frame0: regs=r7 stack=-152 before 1033: (7b) *(u64 *)(r0 +8) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1032: (2d) if r3 > r2 goto pc+10\nmark_precise: frame0: parent state regs=r7 stack=-152:  R0=map_value(map=fallback_cache,ks=40,vs=16) R1=scalar() R2=0x6fc23ac00 R3=scalar() R6=ctx() R7=P0 R8=0 R9=scalar() R10=fp0 fp-32=????523 fp-48=mmmmmmmm fp-56=mmmm000 fp-64=scalar(id=1591) fp-72=scalar(id=1592) fp-80=scalar() fp-88=scalar() fp-96=????mm0 fp-104=scalar(id=1591) fp-112=scalar(id=1592) fp-120=mmmmmmmm fp-128=mmmmscalar(smin=smin32=0,smax=umax=smax32=umax32=3,var_off=(0x0; 0x3)) fp-136=mmmm???? fp-144=pkt_end() fp-152=Pscalar(smin=smin32=0,smax=umax=smax32=umax32=0xffff,var_off=(0x0; 0xffff)) fp-160=map_value(map=vip_map,ks=20,vs=8) fp-168=map_ptr(map=fallback_cache,ks=40,vs=16) fp-176=map_value(map=stats,ks=4,vs=16) fp-184=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\nmark_precise: frame0: last_idx 1031 first_idx 1019 subseq_idx 1032 \nmark_precise: frame0: regs=r7 stack=-152 before 1031: (b7) r8 = 0\nmark_precise: frame0: regs=r7 stack=-152 before 1029: (18) r2 = 0x6fc23ac00\nmark_precise: frame0: regs=r7 stack=-152 before 1028: (1f) r3 -= r2\nmark_precise: frame0: regs=r7 stack=-152 before 1027: (bf) r3 = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1026: (79) r2 = *(u64 *)(r0 +8)\nmark_precise: frame0: regs=r7 stack=-152 before 1025: (bf) r0 = r8\nmark_precise: frame0: regs=r7 stack=-152 before 1024: (bf) r1 = r0; prog 3254: bpfverify final verification failed for prog 3254: subprocess \"bpfverify\" \"--prog-type\" \"sched_cls\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
    "error_programs": [
      {
        "applied": false,
        "changed": false,
        "error": "bpfverify --verifier-states-out failed for prog 3246: subprocess \"bpfverify\" \"--prog-type\" \"xdp\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/verified_original.bin\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-639/verifier_states.json\" failed: func#0 @0\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: .1....6... (18) r2 = 0xffff8d943924c400\n      3: .12...6... (b7) r3 = 0\n      4: .123..6... (85) call bpf_tail_call#12\n      5: ......6... (bf) r1 = r6\n      6: .1....6... (18) r2 = 0xffff8d943924c400\n      8: .12...6... (b7) r3 = 1\n      9: .123..6... (85) call bpf_tail_call#12\n     10: ......6... (bf) r1 = r6\n     11: .1........ (18) r2 = 0xffff8d943924c400\n     13: .12....... (b7) r3 = 2\n     14: .123...... (85) call bpf_tail_call#12\n     15: .......... (b7) r0 = 2\n     16: 0......... (95) exit\n0: R1=ctx() R10=fp0\n0: (bf) r6 = r1                       ; R1=ctx() R6=ctx()\n1: (18) r2 = 0xffff8d943924c400       ; R2=map_ptr(map=root_array,ks=4,vs=4)\n3: (b7) r3 = 0                        ; R3=0",
        "exit_code": 1,
        "prog_id": 3246
      },
      {
        "applied": false,
        "changed": false,
        "error": "bpfverify --verifier-states-out failed for prog 3252: subprocess \"bpfverify\" \"--prog-type\" \"xdp\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/prog.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/verified_original.bin\" \"--verifier-states-out\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-640/verifier_states.json\" failed: lar() fp-96=????mm0 fp-104=scalar(id=1591) fp-112=scalar(id=1592) fp-120=mmmmmmmm fp-128=mmmmscalar(smin=smin32=0,smax=umax=smax32=umax32=3,var_off=(0x0; 0x3)) fp-136=mmmm???? fp-144=pkt_end() fp-152=Pscalar(smin=smin32=0,smax=umax=smax32=umax32=0xffff,var_off=(0x0; 0xffff)) fp-160=map_value(map=vip_map,ks=20,vs=8) fp-168=map_ptr(map=fallback_cache,ks=40,vs=16) fp-176=map_value(map=stats,ks=4,vs=16) fp-184=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\nmark_precise: frame0: last_idx 1041 first_idx 1032 subseq_idx 1042 \nmark_precise: frame0: regs=r7 stack=-152 before 1041: (85) call bpf_map_lookup_elem#1\nmark_precise: frame0: regs=r7 stack=-152 before 1039: (18) r1 = 0xffffcff7cb0d5000\nmark_precise: frame0: regs=r7 stack=-152 before 1038: (07) r2 += -32\nmark_precise: frame0: regs=r7 stack=-152 before 1037: (bf) r2 = r10\nmark_precise: frame0: regs=r7 stack=-152 before 1036: (63) *(u32 *)(r10 -32) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1035: (63) *(u32 *)(r10 -48) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1034: (61) r1 = *(u32 *)(r0 +0)\nmark_precise: frame0: regs=r7 stack=-152 before 1033: (7b) *(u64 *)(r0 +8) = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1032: (2d) if r3 > r2 goto pc+10\nmark_precise: frame0: parent state regs=r7 stack=-152:  R0=map_value(map=fallback_cache,ks=40,vs=16) R1=scalar() R2=0x6fc23ac00 R3=scalar() R6=ctx() R7=P0 R8=0 R9=scalar() R10=fp0 fp-32=????523 fp-48=mmmmmmmm fp-56=mmmm000 fp-64=scalar(id=1591) fp-72=scalar(id=1592) fp-80=scalar() fp-88=scalar() fp-96=????mm0 fp-104=scalar(id=1591) fp-112=scalar(id=1592) fp-120=mmmmmmmm fp-128=mmmmscalar(smin=smin32=0,smax=umax=smax32=umax32=3,var_off=(0x0; 0x3)) fp-136=mmmm???? fp-144=pkt_end() fp-152=Pscalar(smin=smin32=0,smax=umax=smax32=umax32=0xffff,var_off=(0x0; 0xffff)) fp-160=map_value(map=vip_map,ks=20,vs=8) fp-168=map_ptr(map=fallback_cache,ks=40,vs=16) fp-176=map_value(map=stats,ks=4,vs=16) fp-184=scalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff))\nmark_precise: frame0: last_idx 1031 first_idx 1019 subseq_idx 1032 \nmark_precise: frame0: regs=r7 stack=-152 before 1031: (b7) r8 = 0\nmark_precise: frame0: regs=r7 stack=-152 before 1029: (18) r2 = 0x6fc23ac00\nmark_precise: frame0: regs=r7 stack=-152 before 1028: (1f) r3 -= r2\nmark_precise: frame0: regs=r7 stack=-152 before 1027: (bf) r3 = r1\nmark_precise: frame0: regs=r7 stack=-152 before 1026: (79) r2 = *(u64 *)(r0 +8)\nmark_precise: frame0: regs=r7 stack=-152 before 1025: (bf) r0 = r8\nmark_precise: frame0: regs=r7 stack=-152 before 1024: (bf) r1 = r0",
        "exit_code": 1,
        "prog_id": 3252
      },
      {
        "applied": false,
        "changed": false,
        "error": "bpfverify final verification failed for prog 3254: subprocess \"bpfverify\" \"--prog-type\" \"sched_cls\" \"--map-fds\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/map_fds.json\" \"--input\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/opt.bin\" \"--output\" \"/var/tmp/bpfrejit-runtime/run.x86-kvm.e2e.0dd57fa1/bpfrejit-daemon-optimize-1798-641/verified.bin\" failed: BPF_PROG_LOAD dry-run failed: Permission denied (os error 13)",
        "exit_code": 1,
        "prog_id": 3254
      }
    ],
    "exit_code": 1,
    "program_counts": {
      "applied": 0,
      "not_applied": 3,
      "requested": 3
    }
  },
  "status": "error",
  "workload_spec": {
    "kind": "network"
  }
}
```
