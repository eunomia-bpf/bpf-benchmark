# Published x86 generated simulator source refresh

The43generated simulator C files now carry the already-published generator representation: named scalar stack-value word selections, direct operation-body calls, and bounded finite helper/subprogram dispatch. The generator, simulator and source native instructions retain their published definitions. This closes the43generated-source paths held in S19's backlog. Original micro workload C/config files remain at their frozen definitions.

The build receipt uses a read-only Git export of the committed generated sources, simulator, generated contracts and native input headers. Clang18 compiles each generated B with the existing BPF target,4096stack setting and existing include paths. Full commands, logs, object hashes and actual compiler statuses publish after the detached batch closes. The existing kernel safety fixture sources and annotations retain their published definitions.
