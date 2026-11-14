"""Experimental MIR lowering for two scalar u32 spills into one whole word.

No production compiler uses this tool. Inputs must be pre-PEI physical MIR;
all selected slot accesses must be direct STW32/LDW32 at offset zero.
"""
import argparse
import json
from pathlib import Path
import re


def registers(line):
    return {int(n) for n in re.findall(r'\$[rw](\d+)', line)}


def lower(path, low, high):
    head, body = path.read_text().split('body:             |', 1)
    slots = {int(i): (int(n), int(a)) for i, n, a in re.findall(
        r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+), alignment: (\d+),', head)}
    if low >= high or high != max(slots) or slots[low] != (4, 8) or slots[high] != (4, 8):
        raise ValueError('Expected two scalar4/aligned8 slots, with the last slot selected second')
    blocks, current = {}, None
    for line in body.splitlines():
        match = re.match(r'  bb\.(\d+)[^:]*:', line)
        if match:
            current = int(match[1])
            blocks[current] = dict(label=line, lines=[], successors=[], liveins=set())
        elif current is not None:
            data = blocks[current]
            data['lines'].append(line)
            if line.strip().startswith('successors:'):
                data['successors'] = list(map(int, re.findall(r'%bb\.(\d+)', line)))
            if line.strip().startswith('liveins:'):
                data['liveins'] = registers(line)
    changes = []
    for block, data in blocks.items():
        live = set().union(*(blocks[n]['liveins'] for n in data['successors']))
        rewritten = []
        for line in reversed(data['lines']):
            if line.lstrip().startswith(('DBG_', 'liveins:', 'successors:')):
                if not re.search(r'%stack\.(' + str(low) + '|' + str(high) + r')(?!\d)', line):
                    rewritten.append(line)
                continue
            after = set(live)
            read_text, definitions = line, set()
            match = re.match(r'\s*\$[rw](\d+) =', read_text)
            if match:
                definitions.add(int(match[1]))
                read_text = read_text[match.end():]
            definition_pattern = r'(?:implicit-def|\bdef|early-clobber) (?:dead )?\$[rw](\d+)'
            definitions.update(map(int, re.findall(definition_pattern, read_text)))
            read_text = re.sub(definition_pattern, '', read_text)
            used = registers(read_text)
            live = (live - definitions) | used
            selected = set(map(int, re.findall(r'%stack\.(\d+)', line))) & {low, high}
            if not selected:
                rewritten.append(line)
                continue
            store = re.fullmatch(r'\s*STW32 (?:killed )?\$w(\d+), %stack\.(\d+), 0(?:, debug-location !\d+)?', line)
            load = re.fullmatch(r'\s*\$w(\d+) = LDW32 %stack\.(\d+), 0(?:, debug-location !\d+)?', line)
            if not (store or load) or len(selected) != 1:
                raise ValueError(f'Unsupported selected spill access: {line}')
            replacement = []
            if store:
                source, slot = map(int, store.groups())
                free = sorted(set(range(10)) - live - after - used)
                if len(free) < 2:
                    raise ValueError(f'No two dead scratch registers at bb.{block}: {line}')
                first, second = free[:2]
                replacement.append(f'$r{first} = LDD %stack.{low}, 0')
                if slot == low:
                    replacement += [f'$r{first} = SRL_ri killed $r{first}, 32',
                                    f'$r{first} = SLL_ri killed $r{first}, 32']
                else:
                    # A self COPY of wN is removed after register allocation.
                    # Explicit shifts retain the required high-half truncation.
                    replacement += [f'$r{first} = SLL_ri killed $r{first}, 32',
                                    f'$r{first} = SRL_ri killed $r{first}, 32']
                replacement.append(f'$w{second} = COPY $w{source}, implicit-def $r{second}')
                if slot == high:
                    replacement.append(f'$r{second} = SLL_ri killed $r{second}, 32')
                replacement += [f'$r{first} = OR_rr killed $r{first}, killed $r{second}',
                                f'STD killed $r{first}, %stack.{low}, 0']
                changes.append(dict(block=block, original=line.strip(), scratch=free[:2]))
            else:
                destination, slot = map(int, load.groups())
                replacement.append(f'$r{destination} = LDD %stack.{low}, 0')
                if slot == low:
                    replacement += [f'$r{destination} = SLL_ri killed $r{destination}, 32',
                                    f'$r{destination} = SRL_ri killed $r{destination}, 32']
                else:
                    replacement.append(f'$r{destination} = SRL_ri killed $r{destination}, 32')
                changes.append(dict(block=block, original=line.strip()))
            rewritten.extend(reversed(['    ' + instruction for instruction in replacement]))
        data['lines'] = list(reversed(rewritten))
    entry = blocks[next(iter(blocks))]
    free = sorted(set(range(10)) - entry['liveins'])
    if not free:
        raise ValueError('No dead entry register for initializing private packed word')
    # No selected address escapes, so initializing the other, unread half has
    # no externally observable effect. Initialization makes whole-word reads valid.
    index = next(i for i, line in enumerate(entry['lines']) if line.strip() and
                 not line.strip().startswith(('liveins:', 'successors:')))
    entry['lines'][index:index] = [f'    $r{free[0]} = MOV_ri 0',
                                  f'    STD killed $r{free[0]}, %stack.{low}, 0']
    pattern = r'(  - \{ id: ' + str(low) + r',[^\n]*type: spill-slot,[^\n]*size:) 4,'
    head, count = re.subn(pattern, r'\g<1> 8,', head)
    if count != 1:
        raise ValueError('Selected low spill definition not unique')
    pattern = r'  - \{ id: ' + str(high) + r',.*?debug-info-location: [^\n]*\}\n'
    head, count = re.subn(pattern, '', head, flags=re.S)
    if count != 1:
        raise ValueError('Selected high spill definition not unique')
    output = head + 'body:             |\n' + '\n'.join(
        data['label'] + '\n' + '\n'.join(data['lines']) for data in blocks.values()) + '\n'
    return output, changes


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mir', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--low', type=int, required=True)
    parser.add_argument('--high', type=int, required=True)
    args = parser.parse_args()
    output, changes = lower(args.mir, args.low, args.high)
    args.output.write_text(output)
    args.output.with_suffix('.lowering.json').write_text(json.dumps(dict(
        source=str(args.mir), low=args.low, high=args.high, changes=changes,
        scope='Run-only compiler prototype; requires actual stock verification. No native execution claim.'), indent=2) + '\n')
