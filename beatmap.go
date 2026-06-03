package rosuppgo

/*
#cgo LDFLAGS: -L${SRCDIR}/lib -lrosu -lm
#include <stdint.h>
#include "lib/librosu.h"
*/
import "C"

import (
	"errors"
	"unsafe"
)

type Beatmap struct {
	handle *C.BeatmapHandle
}

func LoadBeatmap(path string) (*Beatmap, error) {
	cpath := C.CString(path)
	defer C.free(unsafe.Pointer(cpath))

	handle := C.load_beatmap(cpath)
	if handle == nil {
		return nil, errors.New("failed to load beatmap")
	}

	return &Beatmap{
		handle: handle,
	}, nil
}

func (b *Beatmap) Calculate(params *Params) *CalculatorResult {
	result := C.calculate_beatmap(
		b.handle,
		params.params,
	)

	if result == nil {
		return nil
	}

	return &CalculatorResult{
		PP:           float64(result.pp),
		PPAim:        float64(result.pp_aim),
		PPSpeed:      float64(result.pp_speed),
		PPFlashlight: float64(result.pp_flashlight),
		PPAcc:        float64(result.pp_acc),
		Stars:        float64(result.stars),
	}
}

func (b *Beatmap) Close() {
	if b.handle != nil {
		C.free_beatmap(b.handle)
		b.handle = nil
	}
}
