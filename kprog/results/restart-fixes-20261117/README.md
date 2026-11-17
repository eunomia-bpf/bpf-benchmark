# Fixes made before the 2026-11-11 restart (audit detour-20261117T03Z)

e6808c073 restarted the shim, loader and linker from their 2026-05-29 source. commits.txt lists every commit from
2026-05-29 02:22 UTC to the restart that touched bpfopt/shim, kprog/libnativeloader or the native_link sources
(146 commits; 13 name a fix, a fallback or retention). The coordinator checks each against the current tree;
the shim fallback (7734afc52) returned in c03737bf4.
