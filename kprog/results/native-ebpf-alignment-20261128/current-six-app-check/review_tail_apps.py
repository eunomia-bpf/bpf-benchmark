"""Actual Tracee worker/hook and Katran pktgen/entry receipts from the closed same chain."""
from pathlib import Path
import hashlib,json,re,sys
HERE=Path(__file__).resolve().parent;COLLECTION=Path(sys.argv[1]);r=dict(same_chain_pid=1481233,collection=str(COLLECTION),scope='Existing closed Tracee/Katran only, no execution. Hook/worker engagement and packetentry matching do not prove emitted-event/fullpacketdelivery equivalence or performance acceptance.',apps={})
for key in ['tracee__monitor','katran']:
 p=HERE/'cases'/key/'review.json';d=json.loads(p.read_text());app=dict(review=dict(path=str(p),sha256=hashlib.sha256(p.read_bytes()).hexdigest()),phases={})
 for ph,x in d['phases'].items():
  packets=[];stress=[]
  for w in x['workers']:
   text=w.get('stdout','');m=re.findall(r'pkts-sofar:\s*(\d+)\s+errors:\s*(\d+)',text)
   if m:packets.append(dict(packets=int(m[-1][0]),send_errors=int(m[-1][1]),returncode=w.get('returncode'),duration_s=w.get('duration_s')))
   status={}
   for name in ['passed','failed','skipped','metrics untrustworthy']:
    a=re.findall(r'\b'+re.escape(name)+r':\s*(\d+)',text)
    if a:status[name]=int(a[-1])
   if status:stress.append(dict(status=status,returncode=w.get('returncode'),duration_s=w.get('duration_s')))
  programs=list(x['programs'].values());row=dict(workers=len(x['workers']),worker_returncodes=[w.get('returncode') for w in x['workers']],stress_status=stress,pktgen=packets,sys_enter=[v for v in programs if v['name']=='trace_sys_enter'],sys_exit=[v for v in programs if v['name']=='trace_sys_exit'])
  if key=='katran':
   prog=[v for v in programs if v['name']=='balancer_ingres'];assert len(prog)==1 and len(packets)==4;row.update(balancer=prog[0],sent_packets=sum(v['packets'] for v in packets),send_errors=sum(v['send_errors'] for v in packets),entry_equals_sum_sent=prog[0]['run_cnt_delta']==sum(v['packets'] for v in packets))
  app['phases'][ph]=row
 r['apps'][key]=app
r['limits']=['Katran senderrors are preserved, not rounded tozero or declared deliveredpackets.','Tracee entry/exit counters and all7passing stressors establish hookengagement, not known frontendfield_exists correctness or eventconsumer equality.','Rawparameters/stressorrows including futex durations remain in immutable case reviews; no benchmark/timing normalization or exclusion introduced.']
with COLLECTION.with_name('tail-app-work.json').open('x') as f:f.write(json.dumps(r,indent=2)+'\n')
for key,x in r['apps'].items():
 for ph,z in x['phases'].items():print(key,ph,json.dumps({k:v for k,v in z.items() if k not in ['sys_enter','sys_exit','pktgen','balancer']}), 'entry',[v['run_cnt_delta'] for v in z['sys_enter']],'exit',[v['run_cnt_delta'] for v in z['sys_exit']])
