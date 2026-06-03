package rosuppgo

/*
#cgo LDFLAGS: -L${SRCDIR}/lib -lrosu -lm
#include <stdint.h>
#include "lib/librosu.h"
*/
import "C"

type CalculatorResult struct {
	PP           float64
	PPAim        float64
	PPSpeed      float64
	PPFlashlight float64
	PPAcc        float64
	Stars        float64
}

type Params struct {
	params *C.CalculatorParams
}

func NewParams() *Params {
	return &Params{
		params: C.create_calculator_params(),
	}
}

func (p *Params) Close() {
	p.params = nil
}

func (p *Params) Mode(mode uint8) *Params {
	C.params_set_mode(p.params, C.uint8_t(mode))
	return p
}

func (p *Params) Combo(combo uint32) *Params {
	C.params_set_combo(p.params, C.uint32_t(combo))
	return p
}

func (p *Params) N300(count uint32) *Params {
	C.params_set_n300(p.params, C.uint32_t(count))
	return p
}

func (p *Params) N100(count uint32) *Params {
	C.params_set_n100(p.params, C.uint32_t(count))
	return p
}

func (p *Params) N50(count uint32) *Params {
	C.params_set_n50(p.params, C.uint32_t(count))
	return p
}

func (p *Params) NMiss(count uint32) *Params {
	C.params_set_nmiss(p.params, C.uint32_t(count))
	return p
}

func (p *Params) NGeki(count uint32) *Params {
	C.params_set_ngeki(p.params, C.uint32_t(count))
	return p
}

func (p *Params) NKatu(count uint32) *Params {
	C.params_set_nkatu(p.params, C.uint32_t(count))
	return p
}

func (p *Params) Mods(mods uint32) *Params {
	C.params_set_mods(p.params, C.uint32_t(mods))
	return p
}

func (p *Params) Accuracy(acc float64) *Params {
	C.params_set_accuracy(p.params, C.double(acc))
	return p
}
