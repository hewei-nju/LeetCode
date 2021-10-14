package main

import (
	"fmt"
)


func main() {
	m := map[string]int{"foo" : 1, "bar" : 2}
	m["k"] = 23
	fmt.Println(m)
}