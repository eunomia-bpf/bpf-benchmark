#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    local root=/workspaces/kprog-raw/perf/helper-context-query-20261117
    local out=kprog/results/helper-context-query-20261117
    local configs=corpus/results/helper-context-query-20261117
    raw="$root/batch-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    trap 'status=$?; printf "%s exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> /workspaces/kprog-raw/perf/helper-context-query-20261117/progress.log' EXIT
    printf '%s waiting batch EX, timing SH, image SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch; flock -x 7
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image; flock -s 9
    ulimit -v 100663296
    export PYTHONDONTWRITEBYTECODE=1
    git rev-parse HEAD > "$raw/source-commit.txt"
    stat -Lc '%n %s %y' .cache/container-images/x86_64-runner-runtime.image.tar \
        /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage > "$raw/image-inputs.txt"
    taskset -c 19 python3 "$out/prepare.py" "$configs" > "$raw/prepare.txt" 2>&1
    local overall=0
    for mode in control query; do
        install -d "$raw/$mode"
        taskset -c 19 python3 - "$raw/$mode/before.json" <<'PY'
import json,sys
from pathlib import Path
p=Path('corpus/results/current-link-capture-20261117/captures')
Path(sys.argv[1]).write_text(json.dumps(sorted(f.name for f in p.iterdir() if f.is_dir()))+'\n')
PY
        printf '%s start %s raw=%s\n' "$(date -u +%FT%TZ)" "$mode" "$raw" >> "$root/progress.log"
        if make -f kprog/results/current-link-capture-20261117/capture.mk capture \
            APPS=bcc/set CPUS=8-15 SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1 \
            NATIVE_MANIFEST="/workspaces/repository/$configs/$mode-manifest.json" \
            LOGS="$raw/$mode" > "$raw/$mode/guest.log" 2>&1; then rc=0; else rc=$?; overall=1; fi
        printf '%s end %s rc=%s\n' "$(date -u +%FT%TZ)" "$mode" "$rc" >> "$root/progress.log"
        if taskset -c 19 python3 kprog/results/current-link-capture-20261117/index.py \
            --before "$raw/$mode/before.json" --app bcc/set --returncode "$rc" \
            --output "$raw/$mode/index.json" > "$raw/$mode/index.txt" 2>&1; then :; else overall=1; fi
        exec 6>/workspaces/.agent-state/kprog-lanes/locks/git; flock -x 6
        cp "$raw/$mode/index.json" "$out/$mode.json"
        printf '%s mode=%s rc=%s raw=%s\n' "$(date -u +%FT%TZ)" "$mode" "$rc" "$raw" >> "$out/summary.txt"
        local paths=("$out/$mode.json" "$out/summary.txt" "$configs/shipped-manifest.json" "$configs/$mode-manifest.json")
        if [ "$rc" -eq 0 ]; then
            printf '\n%s — BCC helper-context %s functional diagnostic: frozen successful-run cleanup removes only the rebuildable /var/tmp/kprog-tmp/one-image/var-tmp/bpf-benchmark-docker.img. All raw captures, console and corpus results remain under /workspaces.\n' "$(date -u +%FT%TZ)" "$mode" >> kprog/docs/cleanup-log.md
            paths+=(kprog/docs/cleanup-log.md)
        fi
        git status --short --branch --untracked-files=no > "$raw/$mode/git-status.txt"
        git diff --check -- "${paths[@]}"
        git add -- "${paths[@]}"
        git commit --only -m "record BCC helper-context $mode diagnostic" -- "${paths[@]}" > "$raw/$mode/commit.txt" 2>&1
        git push origin master > "$raw/$mode/push.txt" 2>&1
        flock -u 6
    done
    printf '%s complete rc=%s raw=%s\n' "$(date -u +%FT%TZ)" "$overall" "$raw" >> "$root/progress.log"
    return "$overall"
}
main
