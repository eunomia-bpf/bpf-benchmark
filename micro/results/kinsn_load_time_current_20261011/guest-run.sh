#!/bin/bash
# Runs inside the vng guest (see host-run.sh).  It arms kprobe events on the
# kernel's BPF_PROG_LOAD path, runs the repository's in-guest micro step
# (`make __runtime-vm-micro`, the same command `make micro` passes to vng),
# and saves the raw trace.  Nothing is built here.
#
# usage: guest-run.sh <out_dir>
#   <out_dir>/premods     one line: directory of .ko files to insmod before the suite
#                         starts, or "-" (used for the June-module arm; the suite and the
#                         image's bpfrejit-install skip kinsn modules already resident).
#   <out_dir>/make-vars   one make variable assignment per line (RUN_MAKE_VARS etc.).
# (Arguments live in files because virtme passes the --exec command on the kernel
# command line, whose 2 KiB limit a full RUN_MAKE_VARS list exceeds.)
set -uo pipefail
ROOT=/home/yunwei37/workspace/bpf-benchmark-rerun-20261009
out=$1
premods=$(cat "$out/premods")
mapfile -t make_vars < "$out/make-vars"
mkdir -p "$out"
exec > >(tee "$out/guest.log") 2>&1

echo "guest-start $(date -u +%FT%TZ)"
uname -a
cat /proc/cmdline
nproc
grep -m1 "model name" /proc/cpuinfo
dmesg | grep -m3 -i "tsc: \(refined\|detected\)" || true

T=/sys/kernel/tracing
[ -e "$T/kprobe_events" ] || mount -t tracefs nodev "$T"
echo 0 > "$T/tracing_on"
echo > "$T/trace"
echo x86-tsc > "$T/trace_clock"
echo 32768 > "$T/buffer_size_kb"
echo 1 > "$T/options/record-tgid"
echo > "$T/kprobe_events"
# union bpf_attr (UAPI): prog_type@0 insn_cnt@4 log_level@24 prog_name@48.
# struct bpf_prog: len@12 jited_len@16 aux@80; struct bpf_prog_aux: verified_insns@992
# (offsets from `pahole -C bpf_prog/bpf_prog_aux vendor/build/x86/linux/vmlinux`).
# lower_kinsn_proof_regions (kinsn proof lowering) and do_check_common (the verifier's
# path walk, once per main/global subprogram) are static but not inlined (System.map: t).
# validate_kinsn_proof_seq(env, kinsn, buf, cnt): one event per lowered kinsn call with the
# operation's instantiate_insn symbol (struct bpf_kinsn: instantiate_insn@16) and proof length.
while IFS= read -r probe; do
    echo "$probe" >> "$T/kprobe_events" || echo "kprobe definition failed: $probe"
done <<'EOF'
p:kl/load bpf_prog_load ptype=+0(%di):u32 insn_cnt=+4(%di):u32 log_level=+24(%di):u32 name=+48(%di):string
r:kl/load_ret bpf_prog_load ret=$retval:s32
p:kl/check bpf_check
r:kl/check_ret bpf_check ret=$retval:s32
p:kl/sel bpf_prog_select_runtime len=+12(%di):u32 vi=+992(+80(%di)):u32
r:kl/sel_ret bpf_prog_select_runtime jlen=+16($retval):u32
p:kl/lower lower_kinsn_proof_regions
r:kl/lower_ret lower_kinsn_proof_regions ret=$retval:s32
p:kl/docheck do_check_common
r:kl/docheck_ret do_check_common ret=$retval:s32
p:kl/proof validate_kinsn_proof_seq fn=+16(%si):symbol cnt=%cx:u32
EOF
cat "$T/kprobe_events" > "$out/kprobe_events.txt"
grep -q ':kl/load_ret ' "$out/kprobe_events.txt" && grep -q '^p:kl/load ' "$out/kprobe_events.txt" || {
    echo "required kprobes missing"; echo "rc=96" > "$out/guest-rc.txt"; exit 96; }

if [ "$premods" != "-" ]; then
    for ko in "$premods"/*.ko; do
        echo "premodule insmod $ko"
        insmod "$ko" || { echo "premodule insmod failed: $ko"; echo "rc=97" > "$out/guest-rc.txt"; exit 97; }
    done
fi

echo 1 > "$T/events/kl/enable"
echo 1 > "$T/tracing_on"
echo "suite-start $(date -u +%FT%TZ)"
make -C "$ROOT" __runtime-vm-micro "${make_vars[@]}"
rc=$?
echo "suite-end $(date -u +%FT%TZ) rc=$rc"
echo 0 > "$T/tracing_on"
cat "$T/trace" > "$out/kprobe-trace.txt"
cat "$T/per_cpu/cpu0/stats" > "$out/trace-stats-cpu0.txt" 2>/dev/null || true
for c in "$T"/per_cpu/cpu*; do echo "$(basename "$c") $(grep -E '^(overrun|dropped)' "$c/stats" | tr '\n' ' ')"; done > "$out/trace-overruns.txt"
grep '^bpf_' /proc/modules > "$out/modules-after.txt" || true
for m in /sys/module/bpf_x86_* /sys/module/bpf_arm64_*; do
    [ -d "$m" ] && echo "$(basename "$m") $(cat "$m/srcversion" 2>/dev/null)"
done > "$out/module-srcversions.txt"
dmesg > "$out/dmesg.txt"
echo "rc=$rc" > "$out/guest-rc.txt"
sync
exit "$rc"
