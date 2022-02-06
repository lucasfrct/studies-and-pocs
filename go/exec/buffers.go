/*

item 7.3 pag. 108
*/

package main

import (
	"fmt"
	"sync"
	"time"
)

var wg sync.WaitGroup

func produtor(channel chan int) {
	channel <- 10
	channel <- 20
	channel <- 55
	close(channel)
}

func produtorOnlySend(channel chan<- int) {
	channel <- 100
	channel <- 200
	channel <- 550
	close(channel)
}

func consumir(channel <-chan int) {

	duration := time.Duration(1) * time.Second

	value := <-channel

	if value == 0 {
		wg.Done()
	}

	go time.AfterFunc(duration, func() {
		fmt.Println("buffer consumer: ", value)
		consumir(channel)

	})

}

func main() {

	//channel <- 33 // enviando dados pelo canal (armazena 33 no canal)

	channel := make(chan int, 3)
	channel1 := make(chan int, 3)
	channel4 := make(chan int, 4)

	go produtor(channel)
	go produtorOnlySend(channel1)

	for value := range channel {
		fmt.Println("buffer: ", value)
	}

	for value := range channel1 {
		fmt.Println("buffer only send: ", value)
	}

	wg.Add(1)
	go consumir(channel4)

	channel4 <- 14
	channel4 <- 24
	channel4 <- 34
	channel4 <- 44

	close(channel4)
	wg.Wait()

}
