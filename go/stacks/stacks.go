/*
	item 3.2 pag. 36
*/

package main

import (
	"errors"
	"fmt"
)

type Stack struct {
	Values []interface{}
}

func (stack *Stack) Tamanho() int {
	return len(stack.Values)
}

func (stack *Stack) Vazia() bool {
	return stack.Tamanho() == 0
}

func (stack *Stack) Empilhar(value interface{}) {
	stack.Values = append(stack.Values, value)
}

func (stack *Stack) Desempilhar() (interface{}, error) {

	if stack.Vazia() {
		return nil, errors.New("Pilha vazia!")
	}

	value := stack.Values[stack.Tamanho()-1]

	stack.Values = stack.Values[:stack.Tamanho()-1]
	return value, nil
}

func main() {

	stack := Stack{}

	fmt.Println("Pilha: ", stack.Tamanho(), " vazio: ", stack.Vazia())
	stack.Empilhar("Go")
	stack.Empilhar("C#")
	stack.Empilhar("Java")
	stack.Empilhar(2009)
	stack.Empilhar(3.14)

	fmt.Println("Pilha - Tamnho: ", stack.Tamanho(), " | vazia: ", stack.Vazia())

	for !stack.Vazia() {
		v, _ := stack.Desempilhar()
		fmt.Println("Desempilhando: ", v)
		fmt.Println("tamanho: ", stack.Tamanho(), " | vazia: ", stack.Vazia())
	}

	_, err := stack.Desempilhar()
	if err != nil {
		fmt.Println("Erro: ", err)
	}

}
