#!/usr/bin/env python3
"""Attribute an archived clang -E output to source macros using line markers."""
import argparse
from collections import Counter
import json
from pathlib import Path
import re
import tarfile


def measure(source, archive, member):
    lines = source.read_text().splitlines()
    macros, counts, headers, locations = (Counter() for _ in range(4))
    total = directives = lineno = 0
    filename = ''
    with tarfile.open(archive, 'r|gz') as captured:
        for entry in captured:
            if entry.name != member:
                continue
            for line in captured.extractfile(entry):
                total += len(line)
                marker = re.match(rb'\s*#\s+(\d+)\s+"([^"]+)"', line)
                if marker:
                    lineno, filename = int(marker[1]), marker[2].decode(errors='replace')
                    directives += len(line)
                    continue
                if Path(filename).name == source.name and 0 < lineno <= len(lines):
                    macro = re.search(r'\b(X86_SIM_[A-Z0-9_]+)\s*\(', lines[lineno - 1])
                    key = macro[1] if macro else 'generated-C-other'
                    macros[key] += len(line)
                    counts[key] += 1
                    locations[lineno] += len(line)
                else:
                    headers[filename] += len(line)
                lineno += 1
            if total != entry.size:
                raise ValueError('archive member did not stream completely')
            break
        else:
            raise ValueError('preprocessor member is absent: ' + member)
    return dict(preprocessed_bytes=total, generated_c_bytes=source.stat().st_size,
                expansion_ratio=total/source.stat().st_size, line_directive_bytes=directives,
                macro_expanded_bytes=dict(macros.most_common()), expanded_line_counts=dict(counts),
                header_bytes=dict(headers.most_common()), largest_source_lines=[
                    dict(line=n, expanded_bytes=b, source=lines[n-1][:250])
                    for n, b in locations.most_common(12)])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, required=True)
    parser.add_argument('--archive', type=Path, required=True)
    parser.add_argument('--member', required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = measure(args.source, args.archive, args.member)
    args.output.write_text(json.dumps(result, indent=2) + '\n')


if __name__ == '__main__':
    main()
