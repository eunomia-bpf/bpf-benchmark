# Preserve the requested program section in generated B

The shared x86 generator carries `program_section` through every entry ABI. The existing kind selects its context representation, and the supplied section selects the original libbpf attachment identity. Kind-specific default sections remain available for micro generation.

The original kernel C global_func16 native object was compiled before and after with ingress and egress metadata through the canonical specializer. Before, both objects used cgroup_skb/egress. After, each uses its requested section. All four objects contain44 BPF instructions with identical program bytes (SHA25677130e46192593d6db03af4022a3015ef639aebe14838f05159584c5bfe6bf15); original native SHA256eae981f2b4b0b759cba3ff2ed6f6104cf81d9a749d6848375c91f08dade79b07 is shared. Existing actual BCC worker/map-alias regression exit0. These observations cover compilation and ELF metadata; kernel sweep outcomes remain with R.

Command: `make -f /workspaces/.agent-state/kprog-lanes/C/design-only/program-section/Makefile component`. Exact before/after source, original native object, commands, generated C/BPF and existing-worker log are in the archive. Runtime admission additions0.
