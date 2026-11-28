# Captured runtime plan review

The corrected finite job1339263 finished at2026-11-28T06:52:54Z. Its324 cache plans,1814 selected SHA-verified members,517 snapshots and1769 readonly-map value records are retained. Output byte counts and hashes were rechecked. Two captured ELF truncations remain explicit, with their plan rows retained.

| Architecture | App | Plans | Plans with resolved entry | Captured-proof gaps | Readonly value records |
| --- | --- | ---: | ---: | ---: | ---: |
| arm64 | otelcol-ebpf-profiler | 13 | 13 | 0 | 0 |
| x86 | bcc | 25 | 25 | 0 | 253 |
| x86 | cilium | 64 | 64 | 0 | 264 |
| x86 | katran | 1 | 1 | 0 | 0 |
| x86 | otelcol-ebpf-profiler | 14 | 14 | 0 | 0 |
| x86 | tetragon | 38 | 37 | 1 | 1175 |
| x86 | tracee | 169 | 168 | 1 | 77 |

All13 constant-only serialized-plan variation groups are Cilium entries. Actual changes include interface indices/MACs/NAT values and endpoint ID/address/security labels. Ordinary loader source hashes configured constant names/hex values and update-site fields in its cache key on both architectures; the plans retain those actual values. These groups establish per-load configuration variation, while object/symbol/cache identity and installed-code behavior have their separate evidence.

Readonly values are grouped by map shape and captured phase program-ID presence. Tracee value_size72 readonly data has the same observed hex in both phase-ID sets; an8-byte map occurs with other IDs. Tetragon readonly shapes of1/2/3 bytes each retain their own observed values across phase-ID sets. BCC capable16-byte data changes its first32-bit word from2585 to3264, while the native capable plans contain my_pid hex c00c0000 (3264). The actual capable loader sets obj->rodata->my_pid from getpid() (vendor/repos/bcc/libbpf-tools/capable.c330-331), so separate startup process IDs are expected in this field. Full program-to-map identity is a separate join; these map-name/shape records retain candidate scope.

The old OTel observer directly captured zero readonly array values on either ISA. Its actual plan constants and prior useful-work observations remain available; the prepared fixed-app live reader adds program map IDs and complete readonly array bytes.

One complete Tracee proof entry, trace_vfs_writev (cache8264eb4786c466b0), falls outside the old static inventory candidate list. The inventory preferred an exactly15-character function trace_vfs_write before considering longer siblings with that same kernel name. The same census issue covers Tetragon filter_char_buf and its equal/prefix/postfix siblings on both ISAs. This is inventory classification; the captured Tracee proof establishes the actual full entry. The following generic census correction preserves all prefix candidates where the manifest leaves symbol unspecified.
