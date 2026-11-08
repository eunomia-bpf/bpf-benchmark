Tetragon paired-source local-length replay

Original execve_send uses both recorded source edits: counted path loop and existing bounded local read length. Native and original upstream BPF resource object share edited source bytes. The source0 producer prepares original maps/BTF and program context through libbpf prepare. This load-only component retains original object-default globals; whole-application work keeps its own phase. Runtime admission additions0.
