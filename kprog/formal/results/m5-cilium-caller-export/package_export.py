"""Package one unchanged CompCert export; reconstruct it byte for byte."""
from pathlib import Path
import hashlib,json,re,sys

source=Path(sys.argv[1]);target=Path(sys.argv[2])
raw=source.read_bytes();text=raw.decode()
namespace=re.search(r'^namespace (\w+)$',text,re.M)[1]
begin=text.index('def _LICENSE')
suffix=re.search(r'end '+namespace+r'\n+\Z',text)[0]
assert text.endswith(suffix)
prefix=text[:begin];body=text[begin:-len(suffix)]
starts=[m.start() for m in re.finditer(r'^(?:@\[[^\n]+\] )?def ',body,re.M)]
assert starts and starts[0]==0
declarations=[body[a:b] for a,b in zip(starts,starts[1:]+[len(body)])]
groups=[];current=''
for declaration in declarations:
 if current and len((current+declaration).encode())>750000:
  groups.append(current);current=''
 current+=declaration
if current:groups.append(current)
directory=target.with_name(target.stem+'Parts');directory.mkdir(exist_ok=True)
module='KProgFormal.Clight.Arm64CiliumCallerParts.'
records=[];reconstructed=prefix
for index,group in enumerate(groups):
 name='Part'+str(index).zfill(3);path=directory/(name+'.lean')
 header=prefix if index==0 else 'import '+module+'Part'+str(index-1).zfill(3)+'\nopen CC\n\nnamespace '+namespace+'\n\n'
 complete=header+group+suffix
 path.write_text(complete)
 actual=path.read_text()
 assert actual.startswith(header) and actual.endswith(suffix)
 payload=actual[len(header):-len(suffix)]
 assert payload==group
 reconstructed+=payload
 records.append({'path':str(path.resolve().relative_to(Path(__file__).resolve().parents[2])),'header_bytes':len(header.encode()),'body_bytes':len(group.encode()),'sha256':hashlib.sha256(actual.encode()).hexdigest()})
reconstructed+=suffix
assert reconstructed.encode()==raw
target.write_text('import '+module+'Part'+str(len(groups)-1).zfill(3)+'\n')
record={'original_export_sha256':hashlib.sha256(raw).hexdigest(),'original_export_bytes':len(raw),'original_export_lines':text.count('\n'),'declarations':len(declarations),'parts':records,'reconstruction_byteequal':True,'scope':'Only import/namespace packaging changes;every original declaration,including all functions,globals,types,source metadata and complete caller body,is retained in order.'}
Path(__file__).with_name('packaging.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps({k:v for k,v in record.items() if k!='parts'},indent=2));print('parts',len(records))
