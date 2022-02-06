/*
	item 3.1 pag 30
*/

package main

import (
	"fmt"
	"os"
	"strings"
)

func colherEstatisticas(dictionary []string) map[string]int {

	estatisticas := make(map[string]int)

	for _, palavra := range dictionary {

		inicial := strings.ToUpper(string(palavra[0]))
		contador, encontrado := estatisticas[inicial]

		if encontrado {
			estatisticas[inicial] = contador + 1
		} else {
			estatisticas[inicial] = 1
		}
	}

	return estatisticas

}

func imprimir(estatisticas map[string]int) {
	fmt.Println("contagem")
	for inicial, contador := range estatisticas {
		fmt.Printf("%s = %d\n", inicial, contador)
	}
}

func main() {

	dictionary := os.Args[1:]
	estatisticas := colherEstatisticas(dictionary)
	imprimir(estatisticas)

}
