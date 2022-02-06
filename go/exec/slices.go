/*
	item 4.2, pag.
*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Estado struct {
	Name      string
	Populacao int
	Capital   string
}

type ListaDeCompras []string

func (lista ListaDeCompras) Categorizar() ([]string, []string, []string) {
	var vegetais, carnes, outros []string

	for _, e := range lista {
		switch e {
		case "Alface", "Pepino":
			vegetais = append(vegetais, e)
		case "Atum", "Frango":
			carnes = append(carnes, e)
		default:
			outros = append(outros, e)
		}
	}

	return vegetais, carnes, outros
}

func main() {

	var a []int

	primos := []int{2, 3, 5, 7, 11, 13}
	nomes := []string{}

	fmt.Println(a, primos, nomes)

	b := make([]int, 10)
	fmt.Println(b, len(b), cap(b))

	c := make([]int, 10, 20)
	fmt.Println(c, len(c), cap(c))

	aa, bb := 0, 10

	for aa < bb {
		aa += 1
	}

	fmt.Println(aa)

	for i := 0; i < 100; i++ {
		fmt.Println(">> ", i)
	}

	numeros := []int{1, 2, 3, 4, 5}

	for indice, valor := range numeros {
		numeros[indice] *= 2
		fmt.Println(indice, valor, numeros[indice])
	}

	fmt.Println(numeros)

	rand.Seed(time.Now().UnixNano())
	n := 0

	for {
		n++

		i := rand.Intn(4200)
		fmt.Println(i)

		if i%42 == 0 {
			break
		}
	}

	fmt.Println("iteração: ", n)

	var i int

loop:
	for i = 0; i < 10; i++ {

		fmt.Println("for i: ", i)

		switch i {
		case 2, 3:
			fmt.Println("switch", i)
			break
		case 5:
			fmt.Println("loop: ", i)
			break loop
		}
	}

	fmt.Println(i)

	fib := []int{1, 1, 2, 3, 5, 8, 13}
	fmt.Println(fib)
	fmt.Println(fib[:3])
	fmt.Println(fib[2:])
	fmt.Println(fib[:])

	origin := []int{1, 2, 3, 4, 5}
	fmt.Println("Original: ", origin)

	novo := origin[1:3]
	fmt.Println("Novo: ", novo)

	origin[2] = 13

	fmt.Println("arr: ", origin, novo)

	as := []string{"paulo", "almoca", "em", "casa", "diariamente"}
	bs := as[:len(as)-1]
	cs := bs[:len(bs)-1]
	d := cs[:len(cs)-1]
	e := d[:len(d)-1]

	e[0] = "Tiago"

	fmt.Println(as, bs, cs, d, e)

	ad := append(as, "aqui")
	bd := []string{"joao e"}
	bd = append(bd, ad...)

	fmt.Println(bd)

	mapa := map[int]string{}
	mapa2 := make(map[int]string)
	mapa3 := make(map[int]string, 4096)

	fmt.Println(mapa, mapa2, mapa3)

	capitais := map[string]string{
		"GO": "Goiania",
		"PB": "João Pessoa",
		"PR": "Curitiba"}

	capitais["RN"] = "Natal"
	capitais["AM"] = "MAnaus"
	capitais["SE"] = "Aracaju"

	fmt.Println(len(capitais), capitais)

	populacao := make(map[string]int, 6)

	populacao["GO"] = 6434052
	populacao["PB"] = 3914418
	populacao["PR"] = 10997462

	fmt.Println(populacao)

	estados := make(map[string]Estado, 6)
	estados["GO"] = Estado{"Goiás", 6434052, "Goiânia"}
	estados["PB"] = Estado{"Paraiba", 3914418, "Joao Paessoa"}
	estados["AM"] = Estado{"Paraiba", 10997462, "MAnaus"}
	delete(estados, "PB")

	fmt.Println(estados)

	for sigle, estado := range estados {
		fmt.Println("s: ", sigle, " | UF: ", estado)
	}

	lista := make(ListaDeCompras, 6)

	lista[0] = "Alface"
	lista[1] = "Pepino"
	lista[2] = "Azeite"
	lista[3] = "Atum"
	lista[4] = "Frango"
	lista[5] = "Chocolate"

	fmt.Println(lista)

	vegetais, carnes, outros := lista.Categorizar()

	fmt.Println(vegetais, carnes, outros)

}
