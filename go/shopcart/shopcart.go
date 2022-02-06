package main

import (
	"fmt"
)

type Product struct {
	name     string
	price    float64
	discount float64
	quantity int16
	limit    int16 `default:"100"`
	total    float64
}

func (p *Product) add() {
	p.selLimit(100)
	p.quantity += 1
	p.quantity = p.limiter(p.quantity)
}

func (p *Product) sub() {
	p.selLimit(100)
	p.quantity -= 1
	p.quantity = p.limiter(p.quantity)
}

func (p *Product) limiter(value int16) int16 {
	if value < 1 {
		value = 1
	}

	if value > p.limit {
		value = p.limit
	}

	return value
}

func (p *Product) selLimit(limit int16) int16 {
	p.limit = limit
	return p.limit
}

func (p *Product) subTotal() float64 {
	p.total = (p.price * float64(p.quantity)) - p.discount
	return p.total
}

type ShotCart struct {
	products []Product
	total    float64
	discount float64
	freight  float64
}

func (s *ShotCart) add(product Product) {
	s.products = append(s.products, product)
}

func (s *ShotCart) resume() float64 {

	for _, product := range s.products {
		product.subTotal()
		s.total += (product.total + s.freight) - s.discount
	}

	return s.total
}

func main() {

	product01 := Product{name: "relogio", price: 12.77, discount: 1.83, quantity: 1}
	product02 := Product{name: "carro", price: 120.27, discount: 1.43, quantity: 5}

	product01.sub()
	product01.sub()
	product01.sub()
	for i := 0; i <= 1000; i++ {
		product02.add()
	}

	shop := &ShotCart{discount: 1.37, freight: 25.93}

	shop.add(product01)
	shop.add(product02)

	fmt.Println("total: ", shop.resume(), product01, product02)
}
