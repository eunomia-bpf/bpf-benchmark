//go:build integration && linux

// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

package tracer

import (
	"bytes"
	"testing"

	cebpf "github.com/cilium/ebpf"
	"github.com/stretchr/testify/require"
	"go.opentelemetry.io/ebpf-profiler/support"
)

func TestLoadAllMapsInitializesConfiguredVariables(t *testing.T) {
	spec, err := support.LoadCollectionSpec()
	require.NoError(t, err)
	section := spec.Variables["inverse_pac_mask"].SectionName
	input := &cebpf.CollectionSpec{Maps: map[string]*cebpf.MapSpec{section: spec.Maps[section]}, Variables: spec.Variables}
	expected := make(map[uint32][]byte)
	for _, variable := range input.Variables {
		if variable.SectionName != section {
			continue
		}
		value := bytes.Repeat([]byte{0xa5}, int(variable.Size()))
		require.NoError(t, variable.Set(value))
		expected[variable.Offset] = value
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
