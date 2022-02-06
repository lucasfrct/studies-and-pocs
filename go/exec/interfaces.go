/*
ITEM 5.5 pag.73
*/

package main

import "fmt"

type Operacao interface {
	Calcular() int
	String() string
}

type Soma struct {
	operando1, operando2 int
}

func (s *Soma) Calcular() int {
	return s.operando1 + s.operando2
}

func (s *Soma) String() string {
	return fmt.Sprintf("%d + %d = ", s.operando1, s.operando2)
}

type Subtracao struct {
	operando1, operando2 int
}

func (sub *Subtracao) Calcular() int {
	return sub.operando1 - sub.operando2
}

func (sub *Subtracao) String() string {
	return fmt.Sprintf("%d - %d = ", sub.operando1, sub.operando2)
}

func main() {

	var soma Operacao
	soma = &Soma{10, 20}
	var sub Operacao
	sub = &Subtracao{30, 20}

	fmt.Println("Soma: ", soma.Calcular())
	fmt.Println("Subtracao: ", sub.Calcular())

	operacoes := make([]Operacao, 4)
	operacoes[0] = &Soma{25, 15}
	operacoes[1] = &Subtracao{50, 20}
	operacoes[2] = &Soma{190, 270}
	operacoes[3] = &Subtracao{520, 250}

	acumulador := 0

	for e, op := range operacoes {
		valor := op.Calcular()
		fmt.Println(e, op.Calcular())
		acumulador += valor
	}

	fmt.Println("Acumulador ", acumulador)

}
