package rosuppgo

/*
#cgo LDFLAGS: -L${SRCDIR}/lib -lrosu -lm -Wl,-rpath,${SRCDIR}/lib
#include <stdint.h>
#include "lib/librosu.h"
*/
import "C"

type Performance struct {
	handle *C.rosu_pp_PerformanceHandle
}

func (p *Performance) Free() {
	C.rosu_pp_performance_free(p.handle)
}
