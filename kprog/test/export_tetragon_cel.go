// Export real upstream-generated CEL bodies without changing application source.
package main

import (
	"bytes"
	"encoding/binary"
	"encoding/hex"
	"encoding/json"
	"fmt"
	"math"
	"os"

	"github.com/cilium/tetragon/pkg/celbpf"
	"github.com/cilium/tetragon/pkg/k8s/apis/cilium.io/v1alpha1"
)

type example struct {
	expression string
	values     []any
	expected   int
}

type exported struct {
	Expression string   `json:"expression"`
	Code       string   `json:"code"`
	Offsets    []uint64 `json:"offsets"`
	Values     string   `json:"values"`
	Expected   int      `json:"expected"`
}

func run() error {
	cases := []example{}
	for _, value := range []uint64{0, 41, 42, 43, math.MaxUint64} {
		expected := 0
		if value == 42 {
			expected = 1
		}
		cases = append(cases, example{"arg0 == 42u", []any{value}, expected})
	}
	for _, value := range []uint32{0, 42, 43, math.MaxUint32} {
		expected := 0
		if value == 42 {
			expected = 1
		}
		cases = append(cases, example{"arg0 == uint32(42u)", []any{value}, expected})
	}
	for _, values := range [][3]int32{{0, 0, 0}, {42, 0, 42}, {-1, 17, -1}, {math.MinInt32, 0, math.MinInt32}, {42, 0, 43}} {
		expected := 0
		if values[0] == values[2] {
			expected = 1
		}
		cases = append(cases, example{"arg2 == arg0", []any{values[0], uint64(values[1]), values[2]}, expected})
	}
	for _, values := range [][2]int32{{30, 42}, {31, 42}, {0, 12}, {math.MinInt32, math.MinInt32 + 12}, {math.MaxInt32 - 12, math.MaxInt32}} {
		expected := 0
		if int64(values[1])-10 == 2+int64(values[0]) {
			expected = 1
		}
		cases = append(cases, example{"arg2 - int32(10) == int32(2) + arg0", []any{values[0], uint64(0), values[1]}, expected})
	}
	result := []exported{}
	for _, test := range cases {
		offsets := []uint64{math.MaxInt64, math.MaxInt64, math.MaxInt64, math.MaxInt64, math.MaxInt64}
		var data bytes.Buffer
		signature := []v1alpha1.KProbeArg{}
		for i, value := range test.values {
			offsets[i] = uint64(data.Len())
			kind := ""
			switch value.(type) {
			case uint64:
				kind = "uint64"
			case uint32:
				kind = "uint32"
			case int32:
				kind = "int32"
			}
			if err := binary.Write(&data, binary.LittleEndian, value); err != nil {
				return err
			}
			signature = append(signature, v1alpha1.KProbeArg{Type: kind})
		}
		instructions, _, err := celbpf.CompileFn("cel_expression", test.expression, signature)
		if err != nil {
			return fmt.Errorf("compile %s: %w", test.expression, err)
		}
		var code bytes.Buffer
		if err := instructions.Marshal(&code, binary.LittleEndian); err != nil {
			return err
		}
		result = append(result, exported{test.expression, hex.EncodeToString(code.Bytes()), offsets,
			hex.EncodeToString(data.Bytes()), test.expected})
	}
	encoder := json.NewEncoder(os.Stdout)
	encoder.SetIndent("", "  ")
	return encoder.Encode(result)
}

func main() {
	if err := run(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}
