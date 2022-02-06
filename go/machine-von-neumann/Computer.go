package main

import ControlUnit . "Processor/ControlUnit"

type Computer struct {
	ControlUnit ControlUnit
}

func (c *Computer) run() string {
	ctlU = new c.ControlUnit
	return ctlU.DMA()
}
