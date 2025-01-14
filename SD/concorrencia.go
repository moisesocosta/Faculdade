package main

import (
	"fmt"
	"sync"
)

func main() {

	algum_dado := 0
	var wait sync.WaitGroup

	wait.Add(5)
	for i := 0; i < 5; i++ {
		go func(valor int) {
			wait.Done()
			algum_dado += valor
		}(i)
	}
	wait.Wait()

	fmt.Println(algum_dado)

}
