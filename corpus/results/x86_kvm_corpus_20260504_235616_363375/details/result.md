# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T23:56:32.183831+00:00",
  "kinsn_modules": {
    "captured_at": "2026-05-04T23:56:16.394744+00:00",
    "daemon_binary": "daemon/target/release/bpfrejit-daemon",
    "expected_modules": [
      "bpf_bulk_memory",
      "bpf_endian",
      "bpf_extract",
      "bpf_prefetch",
      "bpf_rotate",
      "bpf_select"
    ],
    "module_load": {
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "failed_modules": [],
      "invoked_at": "2026-05-04T23:56:16.394679+00:00",
      "loaded_count": 6,
      "loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loader": "runner.libs.kinsn.load_kinsn_modules",
      "module_dir": "/artifacts/kinsn",
      "newly_loaded_modules": [],
      "snapshot_after": {
        "captured_at": "2026-05-04T23:56:16.394672+00:00",
        "expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "loaded_bpf_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "missing_expected_modules": [],
        "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_prefetch           12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
        "resident_expected_modules": [
          "bpf_bulk_memory",
          "bpf_endian",
          "bpf_extract",
          "bpf_prefetch",
          "bpf_rotate",
          "bpf_select"
        ],
        "source": "lsmod"
      },
      "status": "ok",
      "total_count": 6
    },
    "module_snapshot_before_daemon": {
      "captured_at": "2026-05-04T23:56:16.379060+00:00",
      "expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loaded_bpf_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "missing_expected_modules": [],
      "raw_output": "bpf_select             12288  0\nbpf_rotate             12288  0\nbpf_prefetch           12288  0\nbpf_extract            12288  0\nbpf_endian             12288  0\nbpf_bulk_memory        12288  0",
      "resident_expected_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "source": "lsmod"
    }
  },
  "manifest": "/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_apps.yaml",
  "per_program": [],
  "results": [
    {
      "app": "calico/felix",
      "baseline": null,
      "error": "network wrk load failed via /usr/bin/wrk -t2 -c10 -d1s http://198.18.0.2:18080/: unable to connect to 198.18.0.2:18080 Connection timed out\n--- felix stderr tail ---\nf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: failed to pin map: File exists\nlibbpf: failed to pin map: File exists\nlibbpf: failed to pin map: File exists\n--- felix stdout tail ---\n2026-05-04 23:56:17.642 [WARNING][2097] felix/winutils.go 154: error creating inClusterConfig, falling back to default config: unable to load in-cluster configuration, KUBERNETES_SERVICE_HOST and KUBERNETES_SERVICE_PORT must be defined\n2026-05-04 23:56:17.651 [WARNING][2097] felix/daemon.go 378: BPF conntrack mode Auto,BPFProgram is not supported and will be deprecated soon. Falling back to userspace cleaner.\n2026-05-04 23:56:17.653 [WARNING][2097] felix/int_dataplane.go 1456: Failed to auto-detect host MTU - no interfaces matched the MTU interface pattern. To use auto-MTU, set mtuIfacePattern to match your host's interfaces\n2026-05-04 23:56:17.726 [WARNING][2097] felix/feature_detect_linux.go 383: Iptables backend specified does not match the detected backend, using specified backend detectedBackend=\"legacy\" specifiedBackend=\"nft\"\n2026-05-04 23:56:18.854 [WARNING][2097] felix/int_dataplane.go 1034: Failed to detach connect-time load balancer. Ignoring. error=error querying cgroup 11 : no such file or directory\nerror querying cgroup 15 : no such file or directory\nerror querying cgroup 20 : no such file or directory\nerror querying cgroup 10 : no such file or directory\nerror querying cgroup 14 : no such file or directory\nerror querying cgroup 19 : no such file or directory\n2026-05-04 23:56:19.059 [WARNING][2097] felix/int_dataplane.go 1456: Failed to auto-detect host MTU - no interfaces matched the MTU interface pattern. To use auto-MTU, set mtuIfacePattern to match your host's interfaces",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "calico",
      "selected_workload": "network",
      "status": "error"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 0,
    "per_program_geomean": null,
    "program_count": 0,
    "wins": 0
  },
  "workload_seconds": 1.0
}
```
