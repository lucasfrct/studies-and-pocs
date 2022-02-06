/*
	item 2.4 pag 16
*/

package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {

	if len(os.Args) < 3 {
		fmt.Println("Uso: conversor <valores> <unidade>")
		os.Exit(1)
	}

	unidadeDeOrigem := os.Args[len(os.Args)-1]
	valoresDeOrigem := os.Args[1 : len(os.Args)-1]

	var unidadeDeDestino string

	if unidadeDeOrigem == "celsius" {
		unidadeDeDestino = "fahrenheit"
	} else if unidadeDeOrigem == "quilometros" {
		unidadeDeDestino = "milhas"
	} else {
		fmt.Printf("%s não é uma unidade conhecida", unidadeDeDestino)
		os.Exit(1)
	}

	fmt.Println(unidadeDeOrigem, valoresDeOrigem, unidadeDeDestino)

	for i, v := range valoresDeOrigem {
		valorDeOrigem, err := strconv.ParseFloat(v, 64)

		if err != nil {
			fmt.Printf("O valor %s na posição %d não é ua número válido", v, i)
			os.Exit(1)
		}

		var valorDeDestino float64

		if unidadeDeOrigem == "celsius" {
			valorDeDestino = valorDeOrigem*1.8 + 32
		} else {
			valorDeDestino = valorDeOrigem / 1.60934
		}

		fmt.Printf("%.2f %s = %.2f %s\n", valorDeOrigem, unidadeDeOrigem, valorDeDestino, unidadeDeDestino)
	}

}
