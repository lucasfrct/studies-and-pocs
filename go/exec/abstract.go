/*
 item 5.3 pag. 67

*/

package main

import "fmt"

type ListaGenerica []interface{}

func (lista *ListaGenerica) RemoverIndice(indice int) interface{} {
	l := *lista
	removido := l[indice]
	*lista = append(l[0:indice], l[indice+1:]...)
	return removido
}

func (lista *ListaGenerica) RemoverInicio() interface{} {
	return lista.RemoverIndice(0)
}

func (lista *ListaGenerica) RemoveFim() interface{} {
	return lista.RemoverIndice(len(*lista) - 1)
}

func main() {
	lista := ListaGenerica{1, "Café", 42, true, "Bola", 3.14, false}
	fmt.Println("Lista: ", lista)
	fmt.Println("Lista remove inicio: ", lista.RemoverInicio(), lista)
	fmt.Println("Lista remove fim: ", lista.RemoveFim(), lista)
	fmt.Println("Lista remove indice: ", lista.RemoverIndice(2), lista)
}
