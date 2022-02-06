package Processor

type ControlUnit struct {
}

/*
	Direct Memory Access: Controla o Barramento CPU<=> Memória
*/
func (c *ControlUnit) DMA() string {
	return "DMA"
}
