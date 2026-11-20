"""Describe actual client execution separately from stock verification."""
import json
from pathlib import Path
import sys
import tarfile

raw=Path(sys.argv[1]);here=Path(__file__).resolve().parent
cases=[]
for row in json.loads((raw/'cases.json').read_text()):
    directory=raw/row['name']
    outputs=[json.loads(line) for line in (directory/'stdout').read_text().splitlines() if line.startswith('{')]
    with tarfile.open(directory/'service.tar.gz') as archive:
        requests=[json.loads(line) for line in archive.extractfile('service/requests/requests.jsonl')]
    cases.append(dict(row,client_outputs=outputs,requests=requests,
                      stderr=(directory/'stderr').read_text()))
report=dict(program_source='092e14062',source_commit=(raw/'source-commit').read_text().strip(),
    raw=str(raw),make_exit=int((raw/'exit-code').read_text()),
    tools=json.loads((raw/'tools.json').read_text()),cases=cases,
    scope='One control and twelve native probe contract inputs. Existing client TEST_RUN retval2 means its native self-checks passed; service receipts separately record stock B acceptance and checked/direct installation. The original client source is a return2 control, not separately executed generated B. No app publication, paired stock/native behavior run, partial-copy-prefix fault, full memory-policy equivalence, formal proof or performance claim.')
(here/'kernel-cases-result.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(dict(make_exit=report['make_exit'],cases=[dict(name=r['name'],returncode=r['returncode'],
    paths=[x.get('execution_path') for x in r['requests']]) for r in cases]),indent=2))
