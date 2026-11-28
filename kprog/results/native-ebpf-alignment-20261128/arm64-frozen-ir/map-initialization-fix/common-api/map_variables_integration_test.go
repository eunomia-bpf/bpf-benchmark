//go:build integration && linux

// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

package tracer

import (
	"bytes"
	"testing"

	cebpf "github.com/cilium/ebpf"
	"github.com/cilium/ebpf/btf"
	"github.com/stretchr/testify/require"
	"go.opentelemetry.io/ebpf-profiler/support"
)

func TestLoadAllMapsInitializesConfiguredVariables(t *testing.T) {
	spec, err := support.LoadCollectionSpec()
	require.NoError(t, err)
	const section = ".rodata.var"
	layout, ok := spec.Maps[section].Value.(*btf.Datasec)
	require.True(t, ok)
	input := &cebpf.CollectionSpec{Maps: map[string]*cebpf.MapSpec{section: spec.Maps[section]}, Variables: spec.Variables}
	expected := make(map[uint32][]byte)
	for _, field := range layout.Vars {
		variable := input.Variables[field.Type.TypeName()]
		require.NotNil(t, variable)
		value := bytes.Repeat([]byte{0xa5}, int(field.Size))
		require.NoError(t, variable.Set(value))
		expected[field.Offset] = value
	}
	maps := make(map[string]*cebpf.Map)
	require.NoError(t, loadAllMaps(input, &Config{}, maps))
	t.Cleanup(func() {
		for _, m := range maps {
			m.Close()
		}
	})
	data := make([]byte, maps[section].ValueSize())
	require.NoError(t, maps[section].Lookup(uint32(0), &data))
	for offset, value := range expected {
		require.Equal(t, value, data[int(offset):int(offset)+len(value)])
	}
}
