/*
	item 7.6 pag. 115
*/

package main

import (
	"fmt"
	"time"
)

func executar(c chan<- bool) {
	time.Sleep(1 * time.Second)
	c <- true
}

func main() {

	c := make(chan bool, 1)

	go executar(c)
	fmt.Println("esperando")

	fim := false

	for !fim {
		select {
		case fim = <-c:
			fmt.Println("FIM")
		case <-time.After(2 * time.Second):
			fmt.Println("Timeout")
			fim = true
		}
	}
}
