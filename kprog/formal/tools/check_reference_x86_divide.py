#!/usr/bin/env python3
"""Check architectural DIV/IDIV widths, full dividends, #DE and read-fault precedence."""
import copy
from check_reference import assert_native_state
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parent.parent
MASK = (1 << 64)-1
FLAGS = 0xAD7
DEFINED = MASK ^ 0x8D5


def main():
    cases = []

    def add(width, low, high, divisor, *, memory=False, read_fault=False, source=1, lane=0, rex=False, signed=False):
        prefix = "66" if width==16 else "48" if width==64 else "40" if rex else ""
        opcode = "f6" if width==8 else "f7"
        modrm = 0x31 if memory else 0xF4 if lane else 0xF0+source
        if signed: modrm += 8
        code = bytes.fromhex(prefix+opcode+f"{modrm:02x}")
        state = dict(registers=[(0xABCDEF0123450000+i)&MASK for i in range(16)],
            flags=FLAGS,pc=0x1000,xmm0=(1 << 127)+7,fs_base=0,gs_base=0,memory=[])
        state["registers"][0] = low & MASK
        state["registers"][2] = high & MASK
        if memory:
            state["registers"][1] = 0x2003
            state["memory"] = [dict(address=0x2003+i,value=(divisor>>(8*i))&255,
                readable=not (read_fault and i==width//8-1),writable=False,initialized=False) for i in range(width//8)]
        elif source not in (0,2,4) and not lane:
            state["registers"][source] = divisor & MASK
        # Aliases are read from the original register file before either write.
        actual_divisor = divisor & ((1 << width)-1) if memory else \
            (state["registers"][0 if lane else source] >> lane) & ((1 << width)-1)
        expected = copy.deepcopy(state)
        events = []
        fault = None
        if read_fault:
            fault = dict(kind="read",address=0x2003,bytes=width//8)
        else:
            if memory:
                events.append(dict(kind="read",address=0x2003,value=[c["value"] for c in state["memory"]],initialized=False))
            mask = (1 << width)-1
            dividend = state["registers"][0]&65535 if width==8 else \
                ((state["registers"][2]&mask)<<width)|(state["registers"][0]&mask)
            if signed:
                if dividend & (1 << (2*width-1)): dividend -= 1 << (2*width)
                if actual_divisor & (1 << (width-1)): actual_divisor -= 1 << width
                quotient = abs(dividend)//abs(actual_divisor) if actual_divisor else 0
                if (dividend < 0) != (actual_divisor < 0): quotient = -quotient
                remainder = dividend - quotient*actual_divisor
                overflow = quotient < -(1 << (width-1)) or quotient >= (1 << (width-1))
            else:
                quotient,remainder = divmod(dividend,actual_divisor) if actual_divisor else (0,0)
                overflow = quotient > mask
            if actual_divisor==0 or overflow:
                fault = dict(kind="divide")
            else:
                quotient &= mask
                remainder &= mask
                def write(reg,value,bits):
                    expected["registers"][reg] = ((expected["registers"][reg]&~((1<<bits)-1))|value) if bits<32 else value
                if width==8: write(0,quotient+256*remainder,16)
                else:
                    write(0,quotient,width)
                    write(2,remainder,width)
                expected["pc"] += len(code)
        if fault: events.append(dict(kind="fault",fault=fault))
        expected.update(events=events,fault=fault,defined_flags=MASK if fault else DEFINED)
        cases.append((dict(native_bytes=list(code),state=state),expected))

    seed=0x1937ABCD0F017281
    for width in (8,16,32,64):
        mask=(1 << width)-1
        for divisor in (0,1,2,3,mask//2,mask-1,mask):
            for high in (0,max(0,divisor-1),divisor,mask):
                for memory in (False,True):
                    low=(mask*0x1020304050607081)&MASK
                    if width==8: low=(low&~65535)|((high&255)<<8)|(low&255)
                    add(width,low,high,divisor,memory=memory)
        for _ in range(128):
            seed=(seed*6364136223846793005+1)&MASK;low=seed
            seed=(seed*6364136223846793005+1)&MASK;high=seed
            seed=(seed*6364136223846793005+1)&MASK;divisor=seed
            add(width,low,high,divisor)
            add(width,low,high,divisor,memory=True)
        for source in (0,2):
            for low,high in ((0,0),(MASK,0),(0,1),(MASK,MASK)):
                add(width,low,high,0,source=source)
        add(width,MASK,MASK,0,memory=True,read_fault=True)
        add(width,MASK,MASK,mask,memory=True,read_fault=True)
    for low in (0,255,256,65535,MASK):
        add(8,low,0,0,source=0,lane=8)
        add(8,low,0,0,source=4,rex=True)
    # Signed boundaries retain the complete high:low dividend at every width.
    unsigned_count = len(cases)
    for width in (8,16,32,64):
        mask=(1 << width)-1
        limit=1 << (width-1)
        values=(0,1,-1,limit-1,limit,-limit,-limit-1,(1 << (2*width-1))-1,-(1 << (2*width-1)))
        for dividend in values:
            raw=dividend & ((1 << (2*width))-1)
            low=raw if width==8 else raw&mask
            high=raw>>width
            for divisor in (0,1,-1,2,-2,limit-1,-limit):
                for memory in (False,True):
                    add(width,low,high,divisor,memory=memory,signed=True)
        for source in (0,2):
            for low,high in ((0,0),(MASK,0),(0,1),(MASK,MASK)):
                add(width,low,high,0,source=source,signed=True)
        for divisor in (0,-1):
            add(width,MASK,MASK,divisor,memory=True,read_fault=True,signed=True)
    for low in (0,255,256,65535,MASK):
        add(8,low,0,0,source=0,lane=8,signed=True)
        add(8,low,0,0,source=4,rex=True,signed=True)
    run=subprocess.run([str(ROOT/".lake/build/bin/reference")],
        input="".join(json.dumps(r)+"\n" for r,_ in cases),text=True,stdout=subprocess.PIPE,check=True)
    outputs=[json.loads(line) for line in run.stdout.splitlines()]
    assert len(outputs)==len(cases)
    for (request,expected),actual in zip(cases,outputs): assert_native_state(actual, expected, (request,actual,expected))
    faults=sum(e["fault"] is not None for _,e in cases)
    print(f"x86 DIV/IDIV reference: {unsigned_count} unsigned and {len(cases)-unsigned_count} signed full-state cases; {len(cases)} full-state cases including {faults} divide/read faults; 128-bit dividends, aliases and ordered effects OK")


if __name__=="__main__":
    main()
