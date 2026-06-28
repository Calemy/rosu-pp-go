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

type ffiResult uint32

const (
	Ok ffiResult = iota
	Done
	ParseError
	NullPointer
	InvalidArgument
	TooSuspicious
	None
)

func (r ffiResult) Check() error {
	switch r {
	case ParseError:
		return errors.New("something went wrong while parsing")
	case NullPointer:
		return errors.New("null pointer received")
	case InvalidArgument:
		return errors.New("invalid argument received")
	case TooSuspicious:
		return errors.New("this has been recognized as too suspicious")
	case None:
		return errors.New("this value would return None")
	default:
		return nil
	}
}

type GameMode uint32

const (
	Osu GameMode = iota
	Taiko
	Catch
	Mania
)

func (m *GameMode) FromString(s string) (*GameMode, error) {
	cstr := C.CString(s)
	defer C.free(unsafe.Pointer(cstr))

	var mode uint32

	var result ffiResult = ffiResult(C.rosu_pp_mode_from_str(cstr, &mode))
	if result == InvalidArgument {
		return nil, result.Check()
	}

	gamemode := GameMode(mode)

	return &gamemode, nil
}
