"""MIR lowering for all eligible independent scalar u32 pairs into whole words.

Inputs must be pre-PEI physical MIR;
all selected slot accesses must be direct STW32/LDW32 at offset zero.
"""
import argparse
import json
from pathlib import Path
import re


def registers(line):
    return {int(n) for n in re.findall(r'\$[rw](\d+)', line)}


def lower(path, low, high):
    return lower_text(path.read_text(), low, high)


def lower_text(text, low, high, *, require_final=True, reuse_dead_source=False, save_live_scratch=False):
    head, body = text.split('body:             |', 1)
    slots = {int(i): (int(n), int(a)) for i, n, a in re.findall(
        r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+), alignment: (\d+),', head)}
    if low >= high or (require_final and high != max(slots)) or slots[low] != (4, 8) or slots[high] != (4, 8):
        raise ValueError('Expected two scalar4/aligned8 slots, with the last slot selected second')
    scratch_slots = {int(n): int(slot) for n, slot in re.findall(
        r'^# kprog_spill_scratch_(\d+): (\d+)$', head, re.M)}

    def scratch_slot(number):
        nonlocal head
        if number not in scratch_slots:
            ids = list(map(int, re.findall(r'^  - \{ id: (\d+),', head, re.M)))
            slot = max(ids)+1
            definition = f"  - {{ id: {slot}, name: '', type: spill-slot, offset: 0, size: 8, alignment: 8,\n" \
                "      stack-id: default, callee-saved-register: '', callee-saved-restored: true,\n" \
                "      debug-info-variable: '', debug-info-expression: '', debug-info-location: '' }\n"
            head = head.replace('stack:\n', 'stack:\n'+definition, 1)
            head += f'# kprog_spill_scratch_{number}: {slot}\n'
            scratch_slots[number] = slot
        return scratch_slots[number]
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
            match = re.match(r'\s*(?:dead )?\$[rw](\d+) =', read_text)
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
            load = re.fullmatch(r'\s*(?:dead )?\$w(\d+) = LDW32 %stack\.(\d+), 0(?:, debug-location !\d+)?', line)
            if not (store or load) or len(selected) != 1:
                raise ValueError(f'Unsupported selected spill access: {line}')
            replacement = []
            if store:
                source, slot = map(int, store.groups())
                free = sorted(set(range(10)) - live - after - used)
                reuse = reuse_dead_source and source < 10 and source not in after and len(free) < 2
                required = 1 if reuse else 2
                saved = []
                scratch = free[:required]
                if save_live_scratch:
                    for reg in sorted(set(range(10))-used-set(scratch)):
                        if len(scratch) == required:
                            break
                        saved.append((reg, scratch_slot(len(saved))))
                        scratch.append(reg)
                if len(scratch) < required:
                    raise ValueError(f'No two dead scratch registers at bb.{block}: {line}')
                first, second = (scratch[0], source) if reuse else scratch
                replacement += [f'STD killed $r{reg}, %stack.{slot_id}, 0' for reg, slot_id in saved]
                replacement.append(f'$r{first} = LDD %stack.{low}, 0')
                if slot == low:
                    replacement += [f'$r{first} = SRL_ri killed $r{first}, 32',
                                    f'$r{first} = SLL_ri killed $r{first}, 32']
                else:
                    # A self COPY of wN is removed after register allocation.
                    # Explicit shifts retain the required high-half truncation.
                    replacement += [f'$r{first} = SLL_ri killed $r{first}, 32',
                                    f'$r{first} = SRL_ri killed $r{first}, 32']
                if not reuse:
                    replacement.append(f'$w{second} = COPY $w{source}, implicit-def $r{second}')
                elif slot == low:
                    replacement += [f'$r{second} = SLL_ri killed $r{second}, 32',
                                    f'$r{second} = SRL_ri killed $r{second}, 32']
                if slot == high:
                    replacement.append(f'$r{second} = SLL_ri killed $r{second}, 32')
                replacement += [f'$r{first} = OR_rr killed $r{first}, killed $r{second}',
                                f'STD killed $r{first}, %stack.{low}, 0']
                replacement += [f'$r{reg} = LDD %stack.{slot_id}, 0' for reg, slot_id in reversed(saved)]
                record = dict(block=block, original=line.strip(), scratch=[first, second])
                if reuse:
                    record['reuses_dead_source'] = True
                if saved:
                    record['saved_live_registers'] = [dict(register=reg, slot=slot_id) for reg, slot_id in saved]
                changes.append(record)
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


def automatic(path):
    documents = path.read_text().split('\n---\n')
    records = []
    for index, document in enumerate(documents):
        if 'body:             |' not in document:
            continue
        head = document.split('body:             |', 1)[0]
        slots = {int(i): (int(n), int(a)) for i, n, a in re.findall(
            r'  - \{ id: (\d+),[^\n]*type: spill-slot,[^\n]*size: (\d+), alignment: (\d+),', head)}
        eligible = sorted(slot for slot, shape in slots.items() if shape == (4, 8))
        for low, high in zip(eligible[-2::-2], eligible[::-2]):
            document, changes = lower_text(document, low, high, require_final=False,
                                          reuse_dead_source=True, save_live_scratch=True)
            records.append(dict(document=index, low=low, high=high, changes=changes))
        documents[index] = document
    return '\n---\n'.join(documents), records


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('mir', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--low', type=int)
    parser.add_argument('--high', type=int)
    parser.add_argument('--report', type=Path,
                        help='Write lowering observations independently of the MIR output path')
    args = parser.parse_args()
    if (args.low is None) != (args.high is None):
        parser.error('--low and --high are supplied together')
    if args.low is None:
        output, changes = automatic(args.mir)
    else:
        output, changes = lower(args.mir, args.low, args.high)
    args.output.write_text(output)
    report = args.report if args.report is not None else args.output.with_suffix('.lowering.json')
    report.write_text(json.dumps(dict(
        source=str(args.mir), low=args.low, high=args.high, changes=changes,
        scope='Compiler-private spill storage transformation; actual stock verification follows.'), indent=2) + '\n')
