# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T23:10:24.062210+00:00",
  "kop_modules": {
    "captured_at": "2026-05-04T23:10:07.995106+00:00",
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
      "invoked_at": "2026-05-04T23:10:07.995043+00:00",
      "loaded_count": 6,
      "loaded_modules": [
        "bpf_bulk_memory",
        "bpf_endian",
        "bpf_extract",
        "bpf_prefetch",
        "bpf_rotate",
        "bpf_select"
      ],
      "loader": "runner.libs.kop.load_kop_modules",
      "module_dir": "/artifacts/kop",
      "newly_loaded_modules": [],
      "snapshot_after": {
        "captured_at": "2026-05-04T23:10:07.995035+00:00",
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
      "captured_at": "2026-05-04T23:10:07.981959+00:00",
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
      "error": "network wrk load failed via /usr/bin/wrk -t2 -c10 -d1s http://198.18.0.2:18080/: unable to connect to 198.18.0.2:18080 Connection timed out\n--- felix stderr tail ---\n_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: failed to pin map: File exists\n--- felix stdout tail ---\npVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 640: Skipping expected chain chainName=\"mangle-FORWARD\" ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 640: Skipping expected chain chainName=\"mangle-OUTPUT\" ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 640: Skipping expected chain chainName=\"raw-cali-untracked-policy\" ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 640: Skipping expected chain chainName=\"mangle-POSTROUTING\" ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 640: Skipping expected chain chainName=\"raw-OUTPUT\" ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 640: Skipping expected chain chainName=\"nat-PREROUTING\" ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 640: Skipping expected chain chainName=\"nat-POSTROUTING\" ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 640: Skipping expected chain chainName=\"nat-cali-fip-snat\" ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 649: Finished loading nftables state ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 1115: Update ended up being no-op, skipping call to nftables. ipVersion=0x4 table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 804: Invalidating dataplane cache ipVersion=0x4 reason=\"post-write\" table=\"calico\"\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/table.go 894: Calculating reschedule time lastReadToNow=-5.222498ms refreshInterval=3m0s\n2026-05-04 23:10:19.600 [DEBUG][2103] felix/int_dataplane.go 2745: Asked to reschedule. delay=9.985892982s\n2026-05-04 23:10:19.600 [INFO][2103] felix/summary.go 100: Summarising 1 dataplane reconciliation loops over 5s: avg=11ms longest=11ms (resync-calico-v4,resync-filter-v4,resync-mangle-v4,resync-nat-v4,resync-raw-v4)",
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
