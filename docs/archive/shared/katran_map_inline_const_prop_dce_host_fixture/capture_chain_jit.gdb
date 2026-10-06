set pagination off
set confirm off
break katran_chain_runner::loader::run_bpftestrun
commands
  silent
  shell bash -lc 'set -euo pipefail; art=/home/yunwei37/workspace/bpf-benchmark/docs/tmp/katran_host_loader_jit_map_inline_const_dce_20260513; rm -rf "$art"; mkdir -p "$art"; bpftool -j prog show > "$art/prog_show_all.json"; id=$(jq -r "[.[] | select((.name | startswith(\"balancer_ingres\")) and .type == \"xdp\")] | max_by(.id).id // empty" "$art/prog_show_all.json"); test -n "$id"; echo "$id" > "$art/prog_id.txt"; bpftool -j -p prog show id "$id" > "$art/prog_show.json"; bpftool prog dump xlated id "$id" > "$art/xlated.disasm"; bpftool prog dump xlated id "$id" opcodes > "$art/xlated.opcodes"; bpftool prog dump jited id "$id" opcodes > "$art/jited.opcodes"; bpftool prog dump jited id "$id" file "$art/jited.bin"; objdump -D -b binary -m i386:x86-64 "$art/jited.bin" > "$art/jited.objdump"; chmod 0644 "$art"/*; jq "{id, name, type, bytes_xlated, bytes_jited, tag, loaded_at}" "$art/prog_show.json" > "$art/summary.json"'
  quit
end
run
