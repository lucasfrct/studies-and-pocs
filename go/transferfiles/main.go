package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	fmt.Print("Entre com a pasta de origem: ")
	readerOrigin := bufio.NewReader(os.Stdin)
	origin, err := readerOrigin.ReadString('\n')
	if err != nil {
		fmt.Println("An error occured while reading input. Please try again", err)
		return
	}

	fmt.Println("")
	fmt.Print("Entre com a pasta de destino: ")
	readerDestination := bufio.NewReader(os.Stdin)
	destination, err := readerDestination.ReadString('\n')
	if err != nil {
		fmt.Println("An error occured while reading input. Please try again", err)
		return
	}

	fmt.Println("")
	fmt.Println("----------------------------------------------")
	fmt.Printf("- Movendo Pasta: ... %s", origin)
	fmt.Printf("- Para pasta: ...... %s", destination)
	fmt.Println("----------------------------------------------")
	fmt.Println("")
	fmt.Println("")

	// oldLocation := "/var/www/html/test.txt"
	// newLocation := "/var/www/html/src/test.txt"
	// err := os.Rename(oldLocation, newLocation)
	// if err != nil {
	// 	log.Fatal(err)
	// }
}
