package rosuppgo

/*
#cgo LDFLAGS: -L${SRCDIR}/lib -lrosu -lm -Wl,-rpath,${SRCDIR}/lib
#include <stdint.h>
#include "lib/librosu.h"
*/
import "C"

import (
	"errors"
	"unsafe"
)

type Beatmap struct {
	handle *C.rosu_pp_BeatmapHandle
}

func (b *Beatmap) Free() {
	C.rosu_pp_beatmap_free(b.handle)
	b.handle = nil
}

func (b *Beatmap) Calculator() Performance {
	return Performance{
		handle: C.rosu_pp_performance_new(b.handle),
	}
}

func BeatmapFromPath(path string) (*Beatmap, error) {
	var handle *C.rosu_pp_BeatmapHandle
	cpath := C.CString(path)
	defer C.free(unsafe.Pointer(cpath))

	res := C.rosu_pp_beatmap_from_path(cpath, &handle)

	if res != 0 {
		return nil, errors.New("failed to load beatmap")
	}

	return &Beatmap{handle: handle}, nil
}

func BeatmapFromBytes(data []byte) (*Beatmap, error) {
	var handle *C.rosu_pp_BeatmapHandle

	if len(data) == 0 {
		return nil, errors.New("beatmap data is empty")
	}

	res := C.rosu_pp_beatmap_from_bytes((*C.uint8_t)(unsafe.Pointer(&data[0])), C.ulong(len(data)), &handle)

	if res != 0 {
		return nil, errors.New("failed to load beatmap from bytes")
	}

	return &Beatmap{handle: handle}, nil
}
