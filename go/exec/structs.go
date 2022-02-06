/*
item 5.4 pag. 70
*/

package main

import "fmt"

type Arquivo struct {
	nome       string
	tamanho    float64
	caracteres int
	palavras   int
	linhas     int
}

func (arq *Arquivo) TamanhoMedioDePalavra() float64 {
	return float64(arq.caracteres) / float64(arq.palavras)
}

func (arq *Arquivo) MediaDePalavrasPorLinha() float64 {
	return float64(arq.palavras) / float64(arq.linhas)
}

func main() {

	arquivo := Arquivo{"artigo.txt", 12.68, 12986, 1862, 220}
	codigofonte := Arquivo{tamanho: 1.12, nome: "programa.go"}
	pArquivo := &Arquivo{tamanho: 7.29, nome: "arqui.txt"}

	fmt.Println(arquivo, codigofonte, arquivo.nome, *pArquivo)
	fmt.Println("media pro linha: ", arquivo.MediaDePalavrasPorLinha())
	fmt.Println("tamanho medio: ", arquivo.TamanhoMedioDePalavra())

}
