"""Read concrete ARRAY metadata and imported C helpers from retained requests."""
import io
import json
from pathlib import Path
import sys
import tarfile

archive, output = map(Path, sys.argv[1:])
rows = []
with tarfile.open(archive) as service:
    completions = service.extractfile('service/requests/requests.jsonl').read().decode().splitlines()
    for line in completions:
        completion = json.loads(line)
        member = Path(completion['artifact_archive'] if completion['status'] == 0
                      else completion['failure_archive']).name
        with tarfile.open(fileobj=io.BytesIO(service.extractfile('service/requests/'+member).read())) as request:
            facts = json.load(request.extractfile('request/kernel.facts.json'))
            metadata = json.load(request.extractfile('request/generation.metadata.json'))
            names = request.getnames()
            helper_member = 'request/generated/checked-simulator.helpers.txt'
            helpers = (request.extractfile(helper_member).read().decode().splitlines()
                       if helper_member in names else None)
            rows.append(dict(
                request=completion['request_id'], status=completion['status'],
                entry=request.extractfile('request/kernel.entry').read().decode().strip(),
                execution_path=completion.get('execution_path'),
                imported_helpers=helpers,
                actual_map_shapes=facts['maps'],
                concrete_arrays=[dict(map) for map in metadata['maps']
                                 if map['map_type'] == 2 and map.get('value_offset') is None],
                helper_source_member='request/generated/checked-simulator.helpers.c'
                    if 'request/generated/checked-simulator.helpers.c' in names else None))
result = dict(archive=str(archive), requests=rows,
    selected_array_requests=[row['request'] for row in rows
        if row['imported_helpers'] is not None and '__kprog_array_lookup' in row['imported_helpers']],
    scope='Retained source selection and map metadata. A missing helper-list artifact is reported '
          'as null, not inferred to mean no helper. No call-frequency or final-instruction claim.')
output.write_text(json.dumps(result, indent=2)+'\n')
print(json.dumps({key: value for key, value in result.items() if key != 'requests'}))
