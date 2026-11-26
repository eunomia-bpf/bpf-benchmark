# Divide handler confirmation after the compiler rebuild

The existing check_x86_divide_handler.py passed on2026-11-26 after the reported compile-sim-ir rebuild. It checked18,432 actual CPU/encoded register, memory and high-byte results,9 valid BPF compiles,9 retained zero/overflow/AX-alias fault markers, and2 narrow-result controls. This is a focused semantic confirmation; the whole formal suite retains its separately recorded scope.

Command: python3 tools/check_x86_divide_handler.py from kprog/formal, under shared timing, CPU17 and32GiB. Full raw log and exit metadata: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z/x86-divide-handler-resume-20261126.{log,json}.
