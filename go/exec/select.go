/*

	item 7.5 pag. 111
*/

package main

import "fmt"

func separar(nums []int, channelImpar, channelPar chan<- int, channelBool chan<- bool) {
	for _, number := range nums {
		if number%2 == 0 {
			channelPar <- number
		} else {
			channelImpar <- number
		}
	}

	channelBool <- true
}

func main() {

	channelImpar, channelPar, channelBool := make(chan int), make(chan int), make(chan bool)

	nums := []int{1, 23, 42, 5, 8, 6, 7, 4, 99, 100}

	go separar(nums, channelImpar, channelPar, channelBool)

	var impares, pares []int
	fim := false

	for !fim {
		select {
		case n := <-channelImpar:
			impares = append(impares, n)
		case n := <-channelPar:
			pares = append(pares, n)
		case fim = <-channelBool:
		}
	}

	fmt.Println("->>: ", impares, pares, fim)

}
