/*
 item4.1 pag.
*/
package main

import "fmt"

func main() {

	var a [3]int
	numeros := [5]int{1, 2, 3, 4, 5}
	primos := [...]int{2, 3, 5, 7, 11, 13}

	nomes := [2]string{}
	fmt.Println(a, numeros, primos, nomes)

	var multArr [2][2]int
	multArr[0][0], multArr[0][1] = 3, 5
	multArr[1][0], multArr[1][1] = 7, -2

	multBArr := [2][2]int{{2, 13}, {-1, 6}}

	fmt.Println("Multi A", multArr)
	fmt.Println("Muli B", multBArr)

}
