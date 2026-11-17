#!/bin/bash
set -euo pipefail
main() {
    cd /workspaces/repository
    root=/workspaces/kprog-raw/perf/current-link-capture-20261117
    raw="$root/batch-$(date -u +%Y%m%dT%H%M%SZ)-$$"
    install -d "$raw"
    trap 'status=$?; printf "%s batch exit=%s raw=%s\n" "$(date -u +%FT%TZ)" "$status" "$raw" >> "$root/progress.log"' EXIT
    printf '%s waiting batch EX then timing SH/image SH raw=%s\n' "$(date -u +%FT%TZ)" "$raw" >> "$root/progress.log"
    exec 7>/workspaces/.agent-state/kprog-lanes/locks/batch
    flock -x 7
    exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing
    flock -s 8
    exec 9>/workspaces/.agent-state/kprog-lanes/locks/image
    flock -s 9
    ulimit -v 100663296
    export PYTHONDONTWRITEBYTECODE=1
    git rev-parse HEAD > "$raw/source-commit.txt"
    stat -Lc '%n %s %y' .cache/container-images/x86_64-runner-runtime.image.tar \
        /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage > "$raw/image-inputs.txt"
    install -d corpus/results/current-link-capture-20261117/captures
    ln kprog/results/current-link-capture-20261117/capture_link.py \
        corpus/results/current-link-capture-20261117/capture-link
    local overall=0
    for app in otelcol-ebpf-profiler/profiling bcc/set cilium/agent tetragon/observer tracee/monitor katran; do
        name=${app//\//_}
        install -d "$raw/$name"
        taskset -c 19 python3 - "$raw/$name/before.json" <<'PY'
from pathlib import Path
import json,sys
p=Path('/workspaces/repository/corpus/results/current-link-capture-20261117/captures')
Path(sys.argv[1]).write_text(json.dumps(sorted(f.name for f in p.iterdir() if f.is_dir()))+'\n')
PY
        printf '%s start %s raw=%s\n' "$(date -u +%FT%TZ)" "$app" "$raw" >> "$root/progress.log"
        if make -f kprog/results/current-link-capture-20261117/capture.mk capture \
            APPS="$app" CPUS=8-15 SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1 \
            LOGS="$raw/$name" > "$raw/$name/guest.log" 2>&1; then rc=0; else rc=$?; overall=1; fi
        printf '%s end %s rc=%s\n' "$(date -u +%FT%TZ)" "$app" "$rc" >> "$root/progress.log"
        if taskset -c 19 python3 kprog/results/current-link-capture-20261117/index.py \
            --before "$raw/$name/before.json" --app "$app" --returncode "$rc" \
            --output "$raw/$name/index.json" > "$raw/$name/index.txt" 2>&1; then :; else overall=1; fi
        exec 6>/workspaces/.agent-state/kprog-lanes/locks/git
        flock -x 6
        out=kprog/results/current-link-capture-20261117
        cp "$raw/$name/index.json" "$out/$name.json"
        printf '%s app=%s rc=%s raw=%s\n' "$(date -u +%FT%TZ)" "$app" "$rc" "$raw" >> "$out/summary.txt"
        local paths=("$out/$name.json" "$out/summary.txt")
        if [ "$rc" -eq 0 ]; then
            printf '\n%s — Current-link functional capture %s: the frozen successful-run cleanup removes only /var/tmp/kprog-tmp/one-image/var-tmp/bpf-benchmark-docker.img, the rebuildable guest container store. Raw result/capture/log directories remain under /workspaces.\n' \
                "$(date -u +%FT%TZ)" "$app" >> kprog/docs/cleanup-log.md
            paths+=(kprog/docs/cleanup-log.md)
        fi
        git status --short --branch --untracked-files=no > "$raw/$name/git-status.txt"
        git diff --check -- "${paths[@]}"
        git add -- "${paths[@]}"
        git commit --only -m "record $name functional link-input capture" \
            -- "${paths[@]}" > "$raw/$name/commit.log" 2>&1
        git push origin master > "$raw/$name/push.log" 2>&1
        flock -u 6
    done
    printf '%s complete status=%s raw=%s\n' "$(date -u +%FT%TZ)" "$overall" "$raw" >> "$root/progress.log"
    return "$overall"
}
main
