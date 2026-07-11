# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-05T01:12:06.174708+00:00",
  "kop_modules": {
    "captured_at": "2026-05-05T01:11:50.363336+00:00",
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
      "invoked_at": "2026-05-05T01:11:50.363272+00:00",
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
        "captured_at": "2026-05-05T01:11:50.363265+00:00",
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
      "captured_at": "2026-05-05T01:11:50.342376+00:00",
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
      "error": "network wrk load failed via /usr/bin/wrk -t2 -c10 -d1s http://198.18.0.2:18080/: unable to connect to 198.18.0.2:18080 Connection timed out\n--- felix stderr tail ---\n_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_ip_sets):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.\nlibbpf: failed to pin map: File exists\n--- felix stdout tail ---\n.033 [INFO][2095] felix/iface_monitor.go 246: Netlink address update for known interface.  addr=\"fe80::f8e6:c6ff:fea9:df9f\" exists=true ifIndex=6\n2026-05-05 01:11:54.033 [INFO][2095] felix/int_dataplane.go 1781: Linux interface addrs changed. addrs=set.Set{fe80::f8e6:c6ff:fea9:df9f} ifaceName=\"bpfout.cali\"\n2026-05-05 01:11:54.523 [INFO][2095] felix/iface_monitor.go 246: Netlink address update for known interface.  addr=\"fe80::e823:19ff:fea4:1ca6\" exists=true ifIndex=7\n2026-05-05 01:11:54.523 [INFO][2095] felix/int_dataplane.go 1781: Linux interface addrs changed. addrs=set.Set{fe80::e823:19ff:fea4:1ca6} ifaceName=\"bpfin.cali\"\n2026-05-05 01:11:54.533 [INFO][2095] felix/table.go 816: Updating nftables took >1s applyTime=1.064692029s ipVersion=0x4 reasonForApply=\"post-write\" table=\"calico\"\n2026-05-05 01:11:54.533 [INFO][2095] felix/status_combiner.go 95: Endpoint up for at least one IP version id=bpfbench-hep ipVersion=0x4 status=\"up\"\n2026-05-05 01:11:54.533 [INFO][2095] felix/status_combiner.go 114: Reporting combined status. id=bpfbench-hep status=\"up\"\n2026-05-05 01:11:54.533 [INFO][2095] felix/int_dataplane.go 2307: Completed first update to dataplane. secsSinceStart=3.19590107\n2026-05-05 01:11:54.537 [INFO][2095] felix/health.go 204: Health of component changed name=\"InternalDataplaneMainLoop\" newReport=\"live,ready\" oldReport=\"live,non-ready\"\n2026-05-05 01:11:54.537 [INFO][2095] felix/int_dataplane.go 2442: Received interface addresses update msg=&intdataplane.ifaceAddrsUpdate{Name:\"bpfout.cali\", Addrs:set.Typed[string]{\"fe80::f8e6:c6ff:fea9:df9f\":set.v{}}}\n2026-05-05 01:11:54.537 [INFO][2095] felix/int_dataplane.go 2442: Received interface addresses update msg=&intdataplane.ifaceAddrsUpdate{Name:\"bpfin.cali\", Addrs:set.Typed[string]{\"fe80::e823:19ff:fea4:1ca6\":set.v{}}}\n2026-05-05 01:11:54.537 [INFO][2095] felix/int_dataplane.go 2323: Dataplane updates throttled\n2026-05-05 01:11:56.492 [INFO][2095] felix/int_dataplane.go 2279: Dataplane updates no longer throttled",
      "post_rejit": null,
      "rejit_result": {},
      "runner": "calico",
      "selected_workload": "network",
      "status": "error"
    }
  ],
  "samples": 30,
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
