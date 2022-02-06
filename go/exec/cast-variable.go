/*
	item 5.2 pag. 65
*/

package main

import "fmt"

type ListadeCompras []string

func (lista ListadeCompras) Categorizar() ([]string, []string, []string) {
	var vegetais, carnes, outros []string

	for _, e := range lista {
		switch e {
		case "Alface", "Pepino":
			vegetais = append(vegetais, e)
		case "Frango", "Atum":
			carnes = append(carnes, e)
		default:
			outros = append(outros, e)
		}
	}

	return vegetais, carnes, outros
}

func imprimirSlice(slice []string) {
	fmt.Println("slice: ", slice)
}

func imprimirLista(lista ListadeCompras) {
	fmt.Println("lista: ", lista)
}

func main() {

	lista := ListadeCompras{"Alface", "Atum", "Azeite"}
	slice := []string{"Alface", "Atum", "Azeite"}

	imprimirSlice([]string(lista))
	imprimirLista(ListadeCompras(slice))

}
