# Raw Results: Current Cilium `map_inline` Engagement Audit

Date: 2026-09-24

The preflight exercised the complete declared audit path. It returned
`invalid/inconclusive`, so the plan's condition for a formal full run was not
met and no full run was started. The retained combined stdout/stderr below is
the deterministic preflight reproduction used for diagnosis.

## Preflight

```sh
timeout 120s python3 analysis/audit_loadtime_evidence.py corpus/results/x86_kvm_corpus_20260919_041801_813418 --app cilium/agent --expected-pass map_inline --expected-samples 1 --expected-workload-seconds 30
```

Exit code: 1

```text
error: invalid/inconclusive evidence: 244 integrity errors
{
  "artifact": {
    "core_files": [
      {
        "bytes": 675,
        "mtime_utc": "2026-09-19T04:35:30.554331+00:00",
        "path": "metadata.json"
      },
      {
        "bytes": 832,
        "mtime_utc": "2026-09-19T04:10:06.405237+00:00",
        "path": "provenance/start.json"
      },
      {
        "bytes": 40828,
        "mtime_utc": "2026-09-19T04:27:21.543432+00:00",
        "path": "details/apps/cilium__agent.json"
      },
      {
        "bytes": 308,
        "mtime_utc": "2026-09-19T04:22:30.719067+00:00",
        "path": "details/loadtime-plans/cilium__agent.json"
      },
      {
        "bytes": 583485,
        "mtime_utc": "2026-09-19T04:26:16.682361+00:00",
        "path": "details/loadtime-reports/cilium__agent.jsonl"
      },
      {
        "bytes": 304623,
        "mtime_utc": "2026-09-19T04:27:17.615901+00:00",
        "path": "details/shim-logs/cilium__agent.post_rejit.log"
      }
    ],
    "make_command": "env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=otelcol-ebpf-profiler/profiling,cilium/agent,tetragon/observer BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 WARMUPS=1 BPFREJIT_CORPUS_BPF_STATS=0 KEEP_WORKDIRS=1 RUN_TOKEN=corpus-five-app-trials-20260919-a87nyqy4-map make corpus -o runtime-kernel-image X86_RUNNER_RUNTIME_IMAGE=bpf-benchmark/katran-map-inline-trial:20260919-90kzng44 X86_RUNNER_RUNTIME_IMAGE_TAR=/tmp/katran-map-inline-trial-20260919-90kzng44/runtime.image.tar",
    "path": "corpus/results/x86_kvm_corpus_20260919_041801_813418",
    "publication": "backlog",
    "referenced_workdir_bytes": 2475653,
    "referenced_workdir_files": 2586,
    "referenced_workdirs": 169,
    "source_revision": "38476c24f6caf50b64956c4b44e80f464096dc78",
    "tracked_or_public": false
  },
  "bytecode_files": {
    "changed_workdirs": 122,
    "input_matches_reported_after": 122,
    "input_matches_reported_before": 0,
    "retained_output_next_0": 0
  },
  "integrity_errors": {
    "categories": [
      {
        "category": "missing_retained_output",
        "count": 122,
        "examples": [
          "loadtime_3945_29: missing output.next.0.bin",
          "loadtime_3945_34: missing output.next.0.bin",
          "loadtime_3945_39: missing output.next.0.bin"
        ]
      },
      {
        "category": "retained_input_not_before_image",
        "count": 122,
        "examples": [
          "loadtime_3945_29: input.bin bytes 680 != reported before bytes 2240",
          "loadtime_3945_34: input.bin bytes 7256 != reported before bytes 11704",
          "loadtime_3945_39: input.bin bytes 14256 != reported before bytes 15176"
        ]
      }
    ],
    "total": 244
  },
  "loads": {
    "failed_changed_loads": 0,
    "optimized_events": 122,
    "original_preflight_pass_throughs": 10,
    "other_candidate_errors": [],
    "successful_changed_loads": 122,
    "unpaired_optimized_events": 0
  },
  "outcome": "invalid/inconclusive",
  "reports": {
    "changed_insn_delta": -48070,
    "changed_insns_after": 106270,
    "changed_insns_before": 154340,
    "changed_load_instances": 122,
    "program_name_type_pairs": [
      {
        "changed_load_instances": 2,
        "prog_name": "cil_from_contai",
        "prog_type": "sched_cls",
        "sites_applied": 20
      },
      {
        "changed_load_instances": 9,
        "prog_name": "cil_from_host",
        "prog_type": "sched_cls",
        "sites_applied": 333
      },
      {
        "changed_load_instances": 9,
        "prog_name": "cil_from_netdev",
        "prog_type": "sched_cls",
        "sites_applied": 261
      },
      {
        "changed_load_instances": 2,
        "prog_name": "cil_lxc_policy",
        "prog_type": "sched_cls",
        "sites_applied": 122
      },
      {
        "changed_load_instances": 2,
        "prog_name": "cil_to_containe",
        "prog_type": "sched_cls",
        "sites_applied": 36
      },
      {
        "changed_load_instances": 9,
        "prog_name": "cil_to_host",
        "prog_type": "sched_cls",
        "sites_applied": 108
      },
      {
        "changed_load_instances": 9,
        "prog_name": "cil_to_netdev",
        "prog_type": "sched_cls",
        "sites_applied": 432
      },
      {
        "changed_load_instances": 2,
        "prog_name": "cil_xdp_entry",
        "prog_type": "xdp",
        "sites_applied": 4
      },
      {
        "changed_load_instances": 11,
        "prog_name": "tail_drop_notif",
        "prog_type": "sched_cls",
        "sites_applied": 53
      },
      {
        "changed_load_instances": 2,
        "prog_name": "tail_handle_arp",
        "prog_type": "sched_cls",
        "sites_applied": 4
      },
      {
        "changed_load_instances": 22,
        "prog_name": "tail_handle_ipv",
        "prog_type": "sched_cls",
        "sites_applied": 893
      },
      {
        "changed_load_instances": 9,
        "prog_name": "tail_handle_sna",
        "prog_type": "sched_cls",
        "sites_applied": 495
      },
      {
        "changed_load_instances": 2,
        "prog_name": "tail_ipv4_ct_eg",
        "prog_type": "sched_cls",
        "sites_applied": 108
      },
      {
        "changed_load_instances": 2,
        "prog_name": "tail_ipv4_ct_in",
        "prog_type": "sched_cls",
        "sites_applied": 116
      },
      {
        "changed_load_instances": 2,
        "prog_name": "tail_ipv4_polic",
        "prog_type": "sched_cls",
        "sites_applied": 78
      },
      {
        "changed_load_instances": 2,
        "prog_name": "tail_ipv4_to_en",
        "prog_type": "sched_cls",
        "sites_applied": 78
      },
      {
        "changed_load_instances": 6,
        "prog_name": "tail_no_service",
        "prog_type": "sched_cls",
        "sites_applied": 6
      },
      {
        "changed_load_instances": 18,
        "prog_name": "tail_nodeport_n",
        "prog_type": "sched_cls",
        "sites_applied": 594
      },
      {
        "changed_load_instances": 2,
        "prog_name": "tail_nodeport_r",
        "prog_type": "sched_cls",
        "sites_applied": 46
      }
    ],
    "rows": 169,
    "sites_applied": 3787,
    "sites_matched": 3787,
    "sites_skipped": 0
  },
  "workloads": {
    "baseline": {
      "components": [
        {
          "active_usec": 29952188,
          "delay_usec": 0,
          "duration_s": 30.07019809999997,
          "error_count": 0,
          "name": "cilium_endpoint_pktgen_forward",
          "packet_count": 23116422,
          "packets_per_second": 771777,
          "result_usec": 29952188
        },
        {
          "active_usec": 29933893,
          "delay_usec": 0,
          "duration_s": 30.089056939999978,
          "error_count": 0,
          "name": "cilium_endpoint_pktgen_reverse",
          "packet_count": 24098105,
          "packets_per_second": 805044,
          "result_usec": 29933893
        }
      ],
      "error_count_sum": 0,
      "packet_count_sum": 47214527,
      "packets_per_second_sum": 1576821
    },
    "policy_to_baseline_ratio": 1.0295093736067695,
    "post_rejit": {
      "components": [
        {
          "active_usec": 29942246,
          "delay_usec": 0,
          "duration_s": 30.080929062999985,
          "error_count": 0,
          "name": "cilium_endpoint_pktgen_forward",
          "packet_count": 23803853,
          "packets_per_second": 794992,
          "result_usec": 29942246
        },
        {
          "active_usec": 29941541,
          "delay_usec": 0,
          "duration_s": 30.071369784000012,
          "error_count": 0,
          "name": "cilium_endpoint_pktgen_reverse",
          "packet_count": 24802393,
          "packets_per_second": 828360,
          "result_usec": 29941541
        }
      ],
      "error_count_sum": 0,
      "packet_count_sum": 48606246,
      "packets_per_second_sum": 1623352
    }
  }
}
```

## Parameter-negative test

```sh
timeout 120s python3 analysis/audit_loadtime_evidence.py corpus/results/x86_kvm_corpus_20260919_041801_813418 --app cilium/agent --expected-pass const_prop --expected-samples 1 --expected-workload-seconds 30
```

Exit code: 1

```text
error: enabled passes ['map_inline'] != ['const_prop']
```

## Immediate interpretation

The report/log half of the evidence chain is internally consistent: 122
changed reports map to 122 optimized events and 122 successful `PROG_LOAD`
results, with no failed or unpaired changed-load event. The raw workload is a
single paired observation (1,576,821 versus 1,623,352 sender pps; ratio
1.0295093736067695), not a repeated performance estimate.

The predeclared file-level proof fails uniformly. All 122 changed workdirs
retain `input.bin` at the reported after-count, none at the before-count, and
none retain `output.next.0.bin`. Source inspection explains this shape:
`shim_loadtime.h` renames each step output over `input.bin`. The old artifact
therefore cannot independently reproduce the before/after bytecode comparison.
Per the plan, the mechanism result remains invalid/inconclusive and is not
promoted into the paper.
