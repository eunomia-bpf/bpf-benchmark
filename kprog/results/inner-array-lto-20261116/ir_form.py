"""Retain the canonical P's first O3 IR for diagnosing actual type-flow forms."""
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile

raw = Path(sys.argv[1])
source = Path('/workspaces/repository/vendor/build/native-bpf/x86/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o')
with source.open('rb') as stream:
    bitcode = ELFFile(stream).get_section_by_name('.llvmbc').data()
with (raw/'inspect.stderr').open('w') as errors:
    subprocess.run(['opt-18','-passes=default<O3>','-S','-o',str(raw/'first-o3.ll'),'-'],
                   input=bitcode,stderr=errors,check=True)
