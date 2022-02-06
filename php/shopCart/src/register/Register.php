<?php

class Register {
    
    public function product(Product $product): Product {
        $id = hash("ripemd160", "asdfas", false);
        $product->changePId($id);
        return $product;
    }
}
