package main

import (
	"encoding/hex"
	"encoding/json"
	"fmt"
	ebpf "github.com/cilium/ebpf"
	"os"
)

func main() {
	rows := []map[string]any{}
	for _, path := range os.Args[1:] {
		coll, err := ebpf.LoadCollectionSpec(path)
		if err != nil {
			panic(err)
		}
		v := coll.Variables["inverse_pac_mask"]
		if v == nil {
			panic("missing actual inverse_pac_mask")
		}
		m := coll.Maps[v.SectionName]
		if m == nil || len(m.Contents) != 1 {
			panic("missing original data map contents")
		}
		bytes, ok := m.Contents[0].Value.([]byte)
		if !ok {
			panic(fmt.Sprintf("unexpected data representation %T", m.Contents[0].Value))
		}
		size := v.Size()
		if size != 8 {
			panic("unexpected actual mask width")
		}
		before := hex.EncodeToString(bytes[v.Offset : v.Offset+size])
		if err := v.Set(^uint64(0)); err != nil {
			panic(err)
		}
		var got uint64
		if err := v.Get(&got); err != nil {
			panic(err)
		}
		rows = append(rows, map[string]any{"input_elf": path, "section": v.SectionName, "offset": v.Offset, "size": size, "variable_after_Set": fmt.Sprintf("%016x", got), "map_contents_before_Set": before, "map_contents_after_Set": hex.EncodeToString(bytes[v.Offset : v.Offset+size]), "input_to_direct_NewMap_unchanged": before == hex.EncodeToString(bytes[v.Offset:v.Offset+size]), "Variables_count": len(coll.Variables), "scope": "Parser/API reproduction only; no map/program syscall, no runtime constant override. Sentinel models a legitimate nonzero app-written value."})
	}
	e := json.NewEncoder(os.Stdout)
	e.SetIndent("", "  ")
	if err := e.Encode(rows); err != nil {
		panic(err)
	}
}
