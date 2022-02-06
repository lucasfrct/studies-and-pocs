/*
	item 7.1 pag. 104
*/

package main

import (
	"fmt"
	"math"
	"runtime"
	"sync"
	"time"
)

var wg sync.WaitGroup

func imprimir(n int) {
	for i := 0; i < 3; i++ {
		fmt.Println(n)
		time.Sleep(200 * time.Millisecond)
	}
	wg.Done()
}

func dormir(callback func(msg string)) {
	fmt.Println("Dormir")
	time.Sleep(2 * time.Second)
	callback("acordar")
	wg.Done()
}

func produzir(c chan int) {
	c <- 34
	c <- 35
	c <- 36

	close(c)
}

func calcular(base float64, control *sync.WaitGroup) {
	defer control.Done()

	n := 0.0

	for i := 0; i < 100000000; i++ {
		n += base / math.Pi * math.Sin(2)
	}

	fmt.Println(n)
}

func main() {

	runtime.GOMAXPROCS(runtime.NumCPU())

	c := make(chan int, 3)

	//c <- 33 // enviando dados pelo canal (armazena 33 no canal)
	go produzir(c)

	//valor := <-c // ler o dado no canal
	//fmt.Println("Buffer: ", valor, <-c, <-c, <-c)

	for {
		valor, ok := <-c
		if ok {
			fmt.Println(">>>", valor)
		} else {
			break
		}
	}

	inicio := time.Now()

	wg.Add(6)

	imprimir(8)
	go imprimir(6)

	go dormir(func(msg string) {
		fmt.Println("msg: ", msg)
	})

	go calcular(9.37, &wg)
	go calcular(6.94, &wg)
	go calcular(42.57, &wg)

	wg.Wait()

	fmt.Printf("fim %s\n", time.Since(inicio))

	//fmt.Println("Main")
	//time.Sleep(3 * time.Second)
	//fmt.Println("acordar main")*/
}
