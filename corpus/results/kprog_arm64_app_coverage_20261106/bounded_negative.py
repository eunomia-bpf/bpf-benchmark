"""Prove a reachable omitted dispatch target cannot become an accepted proof."""
import json
from pathlib import Path
import shutil
import sys
import coverage

phase=Path(sys.argv[1]).resolve()
if sys.argv[2]=='generate':
    original=phase.parent/'bounded-return-v2'
    phase.mkdir()
    for directory in ['simulator','formal','sources','inputs']:
        shutil.copytree(original/directory,phase/directory)
    rows=coverage.records(original)
    row=next(r for r in rows if r['name']=='bounded_branch_1')
    source=phase/'sources'/Path(row['source']).name
    lines=source.read_text().splitlines(True)
    removed=[line for line in lines if 'case 0x' in line and 'goto arm64_l_' in line and 'break;' in line]
    # The second ADR candidate is the selector=1 edge in this fixture. Keep
    # the actual runtime switch/default and every native instruction unchanged.
    if len(removed)!=2:
        raise RuntimeError(f'expected exactly two local indirect choices: {removed}')
    lines.remove(removed[1])
    source.write_text(''.join(lines))
    row.update(source=str(source),input_file=str(phase/'inputs'/Path(row['input_file']).name),
               note='intentionally removed reachable second BR case; verifier must reject default')
    (phase/'removed-case.txt').write_text(removed[1])
    (phase/'programs.jsonl').write_text(json.dumps(row)+'\n')
else:
    code=int((phase/'verify/bounded_branch_1.rc').read_text())
    log=(phase/'verify/bounded_branch_1.verifier.log').read_text()
    if code==0 or 'invalid func unknown#-1' not in log:
        raise RuntimeError(f'omitted reachable edge did not reject at PC default: rc={code}\n{log}')
    print('reachable omitted BR target rejects at the invalid-helper PC default')
