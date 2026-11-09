Grouped resident native-body census

26/27 native bodies have an actual representative outcome, covering 274/275 weighted instances.

| Failure class | Native bodies | Weighted instances |
| --- | ---: | ---: |
| verifier_stack_access | 11 | 123 |
| verifier_scalar_memory_access | 10 | 106 |
| compiler_stack_storage | 1 | 33 |
| generation_failed | 3 | 11 |
| pending | 1 | 1 |
| verifier_rejected | 1 | 1 |

Each body is the complete linked native proof ELF with its executable bytes, data and relocation identities. Members retain their resident IDs and original resource/context inputs. The table weights a representative observation by body membership; the source program IDs identify the actual submissions.

Complete representative outcome records, including every diagnostic character, are stored losslessly in outcomes.json.gz, keyed by body SHA256. The compact table retains the class, actual stage and resident membership.

Model epoch: 4f5b7ae6db02414f6ad69648677fc22ec8bf6795. Retained completed requests supply their original raw records. Remaining representatives use separate stock-kernel guests and host compilers across CPUs8-19, one representative per body. Each guest uses one vCPU and2GiB. Application execution requests:0. The benchmark framework retains its frozen definition.

The initial549-instance census and this275-instance grouped continuation retain separate epochs and counts. Runtime resources and BTF differences remain visible in membership.json; weighted body classes describe this census sampling rule.
