package main

import (
	"fmt"
	"strings"
)

func main() {

	toUpperCase("teste", func(v string) {
		fmt.Printf("Callback %s\n", v)
	})

}

func toUpperCase(word string, f func(string)) {
	f(strings.ToUpper(word))
}
