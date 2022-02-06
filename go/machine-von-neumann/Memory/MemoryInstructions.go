package main

type MemoryIntructions struct {
	Instruction []string
}

func (m *MemoryIntructions) Load() {
	m.Instruction = append(m.Instruction, "sum")
	m.Instruction = append(m.Instruction, "sub")
	m.Instruction = append(m.Instruction, "compare")
	m.Instruction = append(m.Instruction, "bigger")
	m.Instruction = append(m.Instruction, "less")
	m.Instruction = append(m.Instruction, "deviation")
}

/*
formato da instrucao = OpCode + Op
Opcode = identificador da instrução
Op = [operando] identificador do registro que será operado
*/

/*
Instrucao Registrador-Memória - carrega dados da memoria par ao registrador
Load = carrega dados da memoria para o registrador
*/
func (r *MemoryIntructions) IRMLoad() {
}

/*
Intrucao Regitrador-Registrador - carrega 2 dados de 2 registradores e manda para a ALU
Store carrega dadcos do registrador para a memóriqa
*/
func (r *MemoryIntructions) IRMStore() {
}

func (r *MemoryIntructions) IRR() {

}
